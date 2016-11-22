//==============================================================
//File Name: main.cpp
//Author: McClane Howland
//Description: Prints out a movie ticket with data provided from the console
//==============================================================
#include <iostream>
#include <string>
using namespace std;

int printTicket() {
    string movie_name,time,AMPM,day,date,rating = " ";
    int location = 0;
    double fee = 0.0;
    //collect data
    cout<<"Please Enter\n";
    cout<<"Movie Name:";
    getline(cin,movie_name);
    cout<<"Show time:";
    cin >> time;
    cout<<"AM or PM:";
    cin >>AMPM;
    cout<<"Day:";
    cin >>day;
    cout<<"Date:";
    cin >>date;
    cout<<"Location/theater number:";
    cin >>location;
    cout<<"Rating:";
    cin >>rating;
    cout<<"Fee:";
    cin >>fee;


    
    //print ticket
    cout<< "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<"\t\t\t AMC Universal CityWalk\n";
    cout<<"\t\t\t   Presenting\n";
    cout<<"\t\t"<<movie_name<<endl;
    cout<<"\t\tShow Time: "<<time<<" "<<AMPM<<"  "<<day<<"  "<<date<<endl;
    cout<<"\t\tTheater: "<<location<<"\t"<<rating<<endl;
    cout<<"\t\tAdult Admission $"<<fee<<endl;
    cout<<"\t\tDon't forget to get your free small popcorn with 4 tickets or more!!!\n";
    cout<< "--------------------------------------------------------------------------------------------------------------------------------" << endl;


}
    

int main() {
    printTicket();
}

