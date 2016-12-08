#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Fruit {
    private:
        string name_;
        float weight_;
        float price_;
    public:
        //constructors/destructors
        Fruit();
        Fruit(string name,float weight,float price);
        ~Fruit();
        //accessor/mutator functions
        string get_name();
        void set_name(string name);
        float get_price();
        void set_price(float price);
        float get_weight();
        void set_weight(float weight);
        //member functions
        float Order(float weight);
        void Display();
};
Fruit::Fruit(): weight_(0),price_(0) {}
Fruit::Fruit(string name,float weight,float price): name_(name),weight_(weight),price_(price){}
Fruit::~Fruit() {
    cout<<"Destroyed Fruit: "<<name_<<", weight: "<<weight_<<endl;
}
string Fruit::get_name() {
    return name_;
}
void Fruit::set_name(string name) {
    name_ = name;
}
float Fruit::get_price() {
    return price_;
}
void Fruit::set_price(float price) {
    price_ = price;
}
float Fruit::get_weight() {
    return weight_;
}
void Fruit::set_weight(float weight) {
    weight_ = weight;
}
float Fruit::Order(float weight) {
    if(weight > weight_) {
        return -1;
    }
    weight_ = weight_-weight;
    return price_*weight;
}
void Fruit::Display() {
    cout<<fixed<<setw(10)<<name_<<setw(8)<<setprecision(2)<<price_<<setw(8)<<setprecision(2)<<weight_<<endl;
}




class OnlineSuperMarket {
    private: 
        Fruit fruits[];
        string market_name_;
        string web_address_;
        static double tax_rate;
    public:
        //constructors/destructors
        OnlineSuperMarket();
        OnlineSuperMarket(string name, string address);
        ~OnlineSuperMarket();
        //accessor/mutator
        string get_address();
        void set_address(string address);
        string get_name();
        void set_name(string name);
        //member functions
        void Init();
        void Sort();
        void Run();
        void Find(string name);
        void Quit();
        void ShowAll();
        static int get_tax_rate();
};
double OnlineSuperMarket::tax_rate = 0.085;
//constructor/destructor
OnlineSuperMarket::OnlineSuperMarket() {}
OnlineSuperMarket::OnlineSuperMarket(string name, string address): market_name_(name),web_address_(address) {}
OnlineSuperMarket::~OnlineSuperMarket() {
    cout<<"Online Supermarket at "<<web_address_<<" is closed...\n";
}
//accessor/mutator
string OnlineSuperMarket::get_address() {
    return web_address_;
}
void OnlineSuperMarket::set_address(string address) {
    web_address_ = address;
}
string OnlineSuperMarket::get_name() {
    return market_name_;
}
void OnlineSuperMarket::set_name(string name) {
    market_name_ = name;
}



int main() {
    return 0;
}
