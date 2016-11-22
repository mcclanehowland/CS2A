//==============================================================
//File Name: main.cpp
//Author: McClane Howland
//Description: Program that randomly generates a car inventory that can be searched through
//Revision History: none
//==============================================================

#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int g_kSize = 16;

void LoadVehicleInventory(string make_model_list[], int year_list[], float price_list[]);
void Menu();
int GetUserChoice();
void Run(string make_model_list[], int year_list[], float price_list[]);
void ShowVehicleInventory(string make_model_list[], int year_list[], float price_list[]);
void SearchByMakeModel(string make_model_list[],int year_list[],float price_list[]);
void Quit();

int main() {
    string make_model_list[g_kSize];
    int year_list[g_kSize];
    float price_list[g_kSize];

    LoadVehicleInventory(make_model_list,year_list,price_list);
    Run(make_model_list,year_list,price_list);

    return 0;
}
void LoadVehicleInventory(string make_model_list[], int year_list[], float price_list[]) {
    string make_model;
    int year = 0;
    float price = 0;
    int rand_number = 0;
    float LO = 9000.00;
    float HI = 27000.00;
    
    srand(static_cast<unsigned int>(time(0))); //generate a seed for the random generator
    cout<<"Welcome to Foothill Dealership ... Loading vehicles from DB ... Please wait ...\n\n";
    for(int i = 0;i < g_kSize;i++) {
        rand_number = rand()%4;
        switch(rand_number) {
            case 0: 
                make_model = "Ford Taurus";
                LO = 9000;
                HI = 27000;
                break;
            case 1:
                make_model = "Toyota Camry";
                LO = 12000;
                HI = 30000;
                break;
            case 2:
                make_model = "BMW 335i";
                LO = 39500;
                HI = 53500;
                break;
            case 3: 
                make_model = "Rolls-Royce Phantom Coupe";
                LO = 40000;
                HI = 99999;
                break;
        }
        price = LO + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(HI-LO)));
        year = 2010+rand()%8;

        make_model_list[i] = make_model;
        year_list[i] = year;
        price_list[i] = price;
    }
}
void Menu() {
    cout<<"\t\tSmart Car Inquiry\n1. View Vehicle Inventory\n2.Search by make and model\n3.Quit\n";
}
int GetUserChoice() {
    int choice = 0;
    cout<<"\tEnter your choice: ";
    cin >>choice;
    return choice;
}
void Run(string make_model_list[], int year_list[], float price_list[]) {
    while(true) {
        Menu();
        int choice = GetUserChoice();
        switch(choice) {
            case 1: 
                ShowVehicleInventory(make_model_list,year_list,price_list);
                break;
            case 2:
                SearchByMakeModel(make_model_list,year_list,price_list);
                break;
            case 3:
                Quit();
                break;
        }
    }
}
void ShowVehicleInventory(string make_model_list[], int year_list[], float price_list[]) {
    cout<<"\t--------------------------------------------\n\t|\tVEHICLE INVENTORY\t|\n\t--------------------------------------------\nMAKE & MODEL\t\tYEAR\tPRICE\n";

    for(int i = 0;i < g_kSize;i++) {
            cout<<left<<setw(25)<<make_model_list[i]<<"\t"<<setw(10)<<year_list[i]<<"$ "<<setw(10)<<price_list[i]<<endl;
    }
}
void SearchByMakeModel(string make_model_list[],int year_list[],float price_list[]) {
    string make_model;
    cout<<"\tEnter Make and Model: ";
    cin.ignore();
    getline(cin,make_model);
    for(int i = 0;i < g_kSize;i++) {
        if(make_model_list[i] == make_model) {
            cout<<left<<setw(25)<<make_model_list[i]<<"\t"<<setw(10)<<year_list[i]<<"$ "<<setw(10)<<price_list[i]<<endl;
        }
    }
}
void Quit() {
    cout<<"Thanks!\n";
    exit(0);
}
