#include <iostream>
#include<stdio.h>
#include<random>
#include<ctime>
#include<string>
#include<fstream>
#include<chrono>
#include<cstring>
#include<algorithm>
#include<conio.h>
#include "BST.h"
#include "BT.h"

using namespace std;
using namespace std::chrono;

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

void load_config(){
    cout<<"Loading config.ini"<<endl;
    ifstream fin;
    fin.open("config.ini",ios::in);
    if(!fin.good()){
        cout<<"Config.ini not found"<<endl;
        fin.close();
        return;
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
    return;
}

int main()
{
    load_config();
    if(!load_data(data_file_name,data_amount)){
        cout<<"Cannot load "<<data_amount<<" numbers from "<<data_file_name<<" file."<<endl;
    }
    if(tasks.size() == 0){
        cout<<"No tasks found to be performed."<<endl;
    }else{
        for(int i = 0;i < tasks.size(); i++){
            string structure = tasks[i][0];
            string operation = tasks[i][1];
            int min_size = stoi(tasks[i][2]);
            int max_size = stoi(tasks[i][3]);
            int step = stoi(tasks[i][4]);
            int number_of_repeats = stoi(tasks[i][5]);
            cout<<"Operation "<<operation<<" in "<<structure<<" in range from "<<min_size<<" to "<<max_size<<" with step "<<step<<" repeated "<<number_of_repeats<<" times"<<endl;
            if(min_size<1){
                cout<<"Cannot execute task. The array must to have at least 1 element.";
            }else if(number_of_repeats<1){
                cout<<"Cannot execute task. The minimum number of repetitions is 1.";
            }else{
                if(structure == "BST"){
                    if(operation == "create"){
                        for(int current_size = min_size; current_size <= max_size; current_size+=step){
                            cout<<"Creating binary search tree with "<<current_size<<" elements"<<endl;
                            high_resolution_clock::time_point t_start = high_resolution_clock::now();
                            high_resolution_clock::time_point t_end = high_resolution_clock::now();
                            duration<double> time_span = duration<double>(0);
                            for(int repeat = 0; repeat < number_of_repeats; repeat++){
                                t_start = high_resolution_clock::now();
                                BST* root = nullptr;
                                for(int j = 0; j < current_size; j++){
                                    BST_insert_node(root,data_vector[j]);
                                }
                                t_end = high_resolution_clock::now();
                                time_span += duration_cast<duration<double>>(t_end - t_start);
                                delete root;
                            }
                            Result BST_create_result = Result(structure,operation,current_size,time_span.count(),number_of_repeats);
                            results.push_back(BST_create_result.toString());
                        }
                    }else if(operation == "add"){
                        for(int current_size = min_size; current_size <= max_size; current_size+=step){
                            cout<<"Adding element to binary search tree with "<<current_size<<" elements"<<endl;
                            high_resolution_clock::time_point t_start = high_resolution_clock::now();
                            high_resolution_clock::time_point t_end = high_resolution_clock::now();
                            duration<double> time_span = duration<double>(0);
                            BST* root = nullptr;
                            for(int j = 0; j < current_size; j++){
                                BST_insert_node(root,data_vector[j]);
                            }
                            for(int repeat = 0; repeat < number_of_repeats; repeat++){
                                t_start = high_resolution_clock::now();
                                BST_insert_node(root,0);
                                t_end = high_resolution_clock::now();
                                BST_delete_node(root,0);
                                time_span += duration_cast<duration<double>>(t_end - t_start);
                            }
                            delete root;
                            Result BST_create_result = Result(structure,operation,current_size,time_span.count(),number_of_repeats);
                            results.push_back(BST_create_result.toString());
                        }

                    }else if(operation == "delete"){

                    }else if(operation == "search"){

                    }else{
                        cout<<"Cannot recognize operation "<<operation<<" in "<<structure<<" structure."; 
                    }

                }else if(structure == "BT"){
                    if(operation == "create"){
                        
                    }else if(operation == "add"){

                    }else if(operation == "delete"){

                    }else if(operation == "search"){

                    }else{
                        cout<<"Cannot recognize operation "<<operation<<" in "<<structure<<" structure."; 
                    }
                }else{
                    cout<<"Cannot recognize "<<structure<<" structure.";
                }
            }
        }
    }
    save_results(results_file_name);
    cout<<"Press any key to continue...";
    getch();
    return 0;
}
