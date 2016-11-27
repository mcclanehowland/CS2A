//==============================================================
//File Name: main.cpp
//Author: McClane Howland
//Description: Inventory program that generates a random inventory and allows you to add 3 items.
//==============================================================
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Order {
    private:
        string customer_name_;
        string product_name_;
        double unit_price_;
        int quantity_;
        string order_date_;
    public:
        Order();
        Order(string customer_name,string product_name,double price,int quantity,string date);
        ~Order();

        string get_customer_name() const;
        void set_customer_name(string name);
        string get_product_name() const;
        void set_product_name(string name);
        double get_unit_price() const;
        void set_unit_price(double price);
        int get_quantity() const;
        void set_quantity(int quantity);
        string get_order_date() const;
        void set_order_date(string date);
};
Order::Order(): unit_price_(0),quantity_(0),order_date_("11/1/2016") {}
Order::Order(string customer_name,string product_name,double price,int quantity,string date): customer_name_(customer_name),product_name_(product_name),unit_price_(price),quantity_(quantity),order_date_(date) {}
Order::~Order() {
    cout<<"Order "<<customer_name_<<" "<<product_name_<<" dtor called ... \n";
}
string Order::get_customer_name() const {
    return customer_name_;
}
void Order::set_customer_name(string name) {
    customer_name_ = name;
}
string Order::get_product_name() const {
    return product_name_;
}
void Order::set_product_name(string name) {
    product_name_ = name;
}
double Order::get_unit_price() const {
    return unit_price_;
}
void Order::set_unit_price(double price) {
    unit_price_ = price;
}
int Order::get_quantity() const {
    return quantity_;
}
void Order::set_quantity(int quantity) {
    quantity_ = quantity;
}
string Order::get_order_date() const {
    return order_date_;
}
void Order::set_order_date(string date) {
    order_date_ = date;
}

class OrderProcessor {
    private:
        string company_name_;
        string company_web_site_;
        Order order_list[32];
        int order_count_;

    public:
        OrderProcessor(); 
        OrderProcessor(string name,string website);
        ~OrderProcessor();

        string get_company_name() const;
        void set_company_name(string name);
        string get_company_web_site()const;
        void set_company_web_site(string website);
        int get_order_count() const;
        void set_order_count(int count);

        void Init();
        void AddOrder();
        void ReportOrderDetails();
};
OrderProcessor::OrderProcessor():order_count_(0) {}
OrderProcessor::OrderProcessor(string name,string website):company_name_(name),company_web_site_(website) {}
OrderProcessor::~OrderProcessor(){
    cout<<"Orderprocessor dtor called ...\n";
}
//accessor/mutator
string OrderProcessor::get_company_name() const {
    return company_name_;
}
void OrderProcessor::set_company_name(string name) {
    company_name_ = name;
}
string OrderProcessor::get_company_web_site() const {
    return company_web_site_;
}
void OrderProcessor::set_company_web_site(string website) {
    company_web_site_ = website;
}
int OrderProcessor::get_order_count() const {
    return order_count_;
}
void OrderProcessor::set_order_count(int count) {
    order_count_ = count;
}
//member functions
void OrderProcessor::Init() {
    srand(static_cast<unsigned int>(time(0)));

    string customer_name;
    string product_name;
    double unit_price;
    int quantity;
    string order_date;

    string names[16] = {"Jack","Nick","Luke","Elizabeth","Mary","Jane","Josh","Campbelle","Jeni","Doug","McClane","Sally","Fiona","Kyle","Carolyn","Will"};
    for(int i = 0;i < 16;i++) {
        int rand_number = rand()%5;
        order_list[i] = Order();
        switch(rand_number) {
            case 0:
                product_name = "iPhone 7";
                unit_price = 200.00;
                break;
            case 1:
                product_name = "Samsung 52-inch SmartTV";
                unit_price = 500.00;
                break;
            case 2:
                product_name = "Dell XPS13";
                unit_price = 800.00;
                break;
            case 3:
                product_name = "MacBook Pro";
                unit_price = 1200.00;
                break;
            case 4:
                product_name = "MacBook Air";
                unit_price = 1000.00;
                break;
        }
        quantity = rand()%10+1;
        order_date = "11/"+to_string(rand()%30+1)+"/2016";
        customer_name = names[i];
        
        order_list[i].set_customer_name(customer_name);
        order_list[i].set_product_name(product_name);
        order_list[i].set_unit_price(unit_price);
        order_list[i].set_quantity(quantity);
        order_list[i].set_order_date(order_date);
    }
    order_count_ = 16;
}
void OrderProcessor::AddOrder() {
    string customer_name;
    string product_name;
    double unit_price;
    int quantity;
    string order_date;
    
    cout<<"enter customer name\n";
    cin >>customer_name;
    cout<<"enter product name\n";
    cin.ignore();
    getline(cin,product_name);
    cout<<"enter unit price\n";
    cin >>unit_price;
    cout<<"enter quantity\n";
    cin >>quantity;
    cout<<"enter date\n";
    cin >>order_date;

    
    order_list[order_count_].set_customer_name(customer_name);
    order_list[order_count_].set_product_name(product_name);
    order_list[order_count_].set_unit_price(unit_price);
    order_list[order_count_].set_quantity(quantity);
    order_list[order_count_].set_order_date(order_date);

    order_count_++;

}
void OrderProcessor::ReportOrderDetails() {
    cout<<"Company Name: "<<company_name_<<"\t\tCompany Website: "<<company_web_site_<<endl;
    for(int i = 0;i < order_count_;i++) {
        cout<<left<<setw(10)<<order_list[i].get_customer_name()<<"\t"<<setw(25)<<order_list[i].get_product_name()<<"\t"<<setw(5)<<order_list[i].get_quantity()<<"\t"<<setw(6)<<order_list[i].get_unit_price()<<"\t"<<order_list[i].get_unit_price() * order_list[i].get_quantity()<<"\t"<<setw(11)<<order_list[i].get_order_date()<<endl;
    }
}

int main() {
    OrderProcessor orderprocessor = OrderProcessor("Amazon","www.amazon.com");
    orderprocessor.Init();
    orderprocessor.ReportOrderDetails();
    for(int i = 0;i < 3;i++) {
        orderprocessor.AddOrder();
    }
    orderprocessor.ReportOrderDetails();
    return 0;
}




