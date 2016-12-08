#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

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
        Fruit fruits[8];
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
        int Find(string name);
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
//member functions
void OnlineSuperMarket::Init() {

    string names[8] = {"Banana", "Strawberry", "Orange", "Grapes", "Watermelon", "Apple", "Blueberry", "Mango"};
    float LO[8] = {0.5,2.1,3,2.15,0.2,1.5,3,0.75};
    float HI[8] = {0.85,3.5,3.5,4.5,0.45,3.2,4.5,1.25};

    srand(static_cast<float>(time(0)));

    for(int i = 0;i < 8;i++) {
        fruits[i].set_name(names[i]);
        fruits[i].set_price(LO[i]+rand()%(HI-LO));
        fruits[i].set_weight(10+rand()%40);
    }
    
}
void OnlineSuperMarket::Sort() {
    for(int i = 0;i < 7;i++) {
        for(int j = i+1;j < 8;j++) {
            if(fruits[j].get_name() < fruits[i].get_name()) {
                Fruit temp = fruits[j];
                fruits[j] = fruits[i];
                fruits[i] = temp;
            }
        } 
    }
}
void OnlineSuperMarket::Quit() {
    cout<<"Thank you for your visit and come again\n";
    exit(0);
}
int OnlineSuperMarket::Find(string name) {
    for(int i = 0;i < 8;i++) {
        if(fruits[i].get_name() == name) {
            return i;
        }
    }
    return -1;
}
void OnlineSuperMarket::Run() {
    cout<<market_name_<<endl<<web_address_<<endl;
    while(true) {
        cout<<"Enter a fruit name or XXX to end: ";
        string name;
        cin >>name;
        if(name == "XXX") {
            Quit();
        }
        int index = Find(name);
        if(index == -1) {
            cout<<"invalid fruit name";
            continue;
        }
        cout<<"\nEnter weight in lbs: ";
        float weight;
        cin >>weight;
        float price = fruits[index].Order(weight);
        if(price == -1) {
            cout<<"weight too large\n";
            continue;
        }
        float total_price = price + price*tax_rate;
        cout<<"Total cost: $"<<setprecision(2)<<total_price<<endl;
    }
}
void OnlineSuperMarket::ShowAll() {
    for(int i = 0;i < 8;i++) {
        fruits[i].Display();
    }
}

int main() {
    OnlineSuperMarket* super = NULL;
    OnlineSuperMarket *market = new OnlineSuperMarket("Foothill Supermarket","www.supermarket.com");
    super = market;
    return 0;
}
