//==============================================================
//File Name: main.cpp
//Author: McClane Howland
//Description: Simple mortgage calculation program that helps perspective borrowers calculate monthly mortgage payments and    property tax by asking for the property zip code, property full address, annual interest rate, number of years to pay off the loan, property value, and finally percentage of down payment.
//==============================================================
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double property_tax_rate = 1.5;

string getString(string question) {
    cout<<question;
    string answer = "";
    getline(cin,answer);
    return answer;
}

double getNum(string question) {
    cout<<question;
    double answer = 0.0;
    cin>>answer;
    return answer;
}

double downPayment(double principal,double down_payment_percent) {
    return principal * down_payment_percent/100;
}

double loanAmount(double principal,double down_payment_percent) {
    return principal * (1 - down_payment_percent/100);
}

double mortgagePayment(double loan_amount,double monthly_interest_rate,double number_of_years) {
    return loan_amount * monthly_interest_rate / ( 1 - (1 / pow(1 + monthly_interest_rate, number_of_years * 12)));
}

double monthlyPayment(double mortgage_payment,double property_tax_payment) {
    return mortgage_payment + property_tax_payment;
}

double totalPayment(double monthly_payment,double number_of_years) {
    return monthly_payment*12*number_of_years;
}

double propertyTaxPayment(double principal) {
    return principal * property_tax_rate/100/12;
}

void pause() {
    long count = 0;
        while (isspace(cin.peek()) && count != 30000000) {
            count++;
    }
}

int print(double interest_rate, double years, double principal, double down_payment_percent, string address, string zip_code) {

    double down_payment = downPayment(principal,down_payment_percent);
    double loan_amount = loanAmount(principal,down_payment_percent);
    double mortgage_monthly_payment = mortgagePayment(loanAmount(principal,down_payment_percent),interest_rate/1200,years);
    double total_monthly_payment = monthlyPayment(mortgagePayment(loanAmount(principal,down_payment_percent),interest_rate/1200,years),propertyTaxPayment(principal));         
    double total_payment = totalPayment(mortgage_monthly_payment,years);

    cout<<"Mortgage calculator is processing your data... Please wait... \n";
    pause();

    cout<<"\t**************************************\n";
    cout<<"\tMORTGAGE CALCULATOR RESULTS\n";
    cout<<"\t**************************************\n";

    cout<<"Property address: "<<address;
    cout<<"\nProperty value: "<<principal;                                               
    cout<<"\nDown payment: "<<down_payment;                                                 
    cout<<"\nLoan amount: "<<loan_amount;                                            
    cout<<"\nMortgage monthly payment: "<<mortgage_monthly_payment;                                
    cout<<"\nMonthly payment (property tax included): "<<total_monthly_payment;    
    cout<<"\nTotal payment: "<<total_payment<<endl;                                                

    return 0;

}

int main() {

    string zip_code, address = " ";
    double interest_rate, years, principal, down_payment_percent = 0.0;
    //get data
    zip_code = getString("Enter property zip zode:");
    address = getString("Enter property address:");
    interest_rate = getNum("Enter annual interest rate (in percentage %):");
    years = getNum("Enter number of years:");
    principal = getNum("Enter principal:");
    down_payment_percent = getNum("Please enter down payment (in percentage %):");

    print(interest_rate, years, principal, down_payment_percent,address,zip_code);

    return 0;
}
