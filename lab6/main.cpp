#include <iostream>
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
        //member functions
        string GetName();
        void SetName(string name);
        float GetPrice();
        void SetPrice(float price);
        float GetWeight();
        void SetWeight(float weight);
        float Order(float weight);
        void Display();



};
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
OnlineSuperMarket::OnlineSuperMarket() {}
OnlineSuperMarket::OnlineSuperMarket(string name, string address): market_name_(name),web_address_(address) {}
int main() {
    return 0;
}
