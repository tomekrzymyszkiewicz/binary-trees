#include <iostream>
#include<stdio.h>
#include<random>
#include<ctime>
#include<string>
#include<fstream>
#include<chrono>
#include<cstring>
#include<algorithm>
#include "BST.h"
#include "BT.h"

using namespace std;

vector<int> data_vector;
vector<vector<string>> tasks;
vector<string> results;
string data_file_name = "";
int data_amount = 0;
string results_file_name = "";

struct Result{
    string structure;
    string operation;
    int size_of_structure;
    double time;
    int number_of_repeats;
    Result(string structure, string operation,int size_of_structure, double time, int number_of_repeats){
        this->structure = structure;
        this->operation = operation;
        this->size_of_structure = size_of_structure;
        this->time = time;
        this->number_of_repeats = number_of_repeats;
    }
    string toString(){
        return(structure+","+operation+","+to_string(size_of_structure)+","+to_string(time)+","+to_string(number_of_repeats));
    }
};

void save_results(string results_file_name){
    cout<<"Saving results"<<endl;
    fstream fout;
    fout.open(results_file_name,ios::out);
    fout<<"sort_algorithm,size_of_array,time_of_sort_s/memory_usage,number_of_repetitions,type_of_test"<<endl;
    for(int i = 0; i < results.size(); i++){
        fout<<results[i]<<endl;
    }
    fout.close();
    cout<<"Correctly saved "<<results.size()<<" results"<<endl;
}

bool load_data(string file_name, int amount){
    cout<<"Loading data from "<<file_name<<" file"<<endl;
    ifstream fin;
    fin.open(file_name,ios::in);
    if(!fin.good()){
        cout<<"Data file "<<file_name<<" not exist"<<endl;
        fin.close();
        return false;
    }
    string line;
    int data_loaded = 0;
    for(int i = 0; i < amount; i++){
        fin>>line;
        if(!fin.eof()){
            data_vector.push_back(stoi(line));
        }else{
            cout<<"Not enough elements in data file "<<file_name<<endl;
            return false;
        } 
        data_loaded++;
    }
    cout<<"Loaded correctly "<<data_loaded<<" numbers"<<endl;
    fin.close();
    return true;
}

bool load_config(){
    cout<<"Loading config.ini"<<endl;
    ifstream fin;
    fin.open("config.ini",ios::in);
    if(!fin.good()){
        cout<<"Config.ini not found"<<endl;
        fin.close();
        return false;
    }
    vector<string> row;
    string line;
    fin >> data_file_name >> data_amount;
    fin >> results_file_name;
    while(!fin.eof()){
        string structure, operation, min_size, max_size, step, number_of_repeats;
        fin>>structure>>operation>>min_size>>max_size>>step>>number_of_repeats;
        if(structure.size() == 0 || operation.size() == 0 || min_size.size() == 0 || max_size.size() == 0 || step.size() == 0 || number_of_repeats.size() == 0){
            break;
        }
        vector<string> task;
        task.push_back(structure);
        task.push_back(operation);
        task.push_back(min_size);
        task.push_back(max_size);
        task.push_back(step);
        task.push_back(number_of_repeats);
        tasks.push_back(task);
    }
    fin.close();
    cout<<"Config loaded correctly"<<endl;
    return true;
}

int main()
{
       

    return 0;
}
