//==============================================================
//File Name: main.cpp
//Author: McClane Howland
//Description: Menu driven program that includes the sum of natural integers,leap year check, count vowels, and armstrong numbers.
//==============================================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

void Menu();
char GetChoice();

void HandleSum();
int ComputeSum(int n);

void HandleLeapYear();
bool IsLeapYear(int year);

void HandleVowelsCount();
int CountVowels(string text);
bool IsVowel(char c);

void DisplayArmstrongNumbers();

void HandleInvalidChoice();

void HandleExit();

int main() {
    do {
        Menu();
        switch(GetChoice()) {
            case 'S':
                HandleSum();
                break;
            case 's':
                HandleSum();
                break;
            case 'L':
                HandleLeapYear();
                break;
            case 'l':
                HandleLeapYear();
                break;
            case 'C':
                HandleVowelsCount();
                break;
            case 'c':
                HandleVowelsCount();
                break;
            case 'E':
                HandleExit();
                break;
            case 'e':
                HandleExit();
                break;
            case 'a':
                DisplayArmstrongNumbers();
                break;
            case 'A':
                DisplayArmstrongNumbers();
                break;
            default:
                HandleInvalidChoice();
                break;
        }
    } while(true);
    return 0;
}

void Menu() {
    cout<<"\t\t\t***********************************\n\t\t\t*\tGENERAL-PURPOSE MENU\t  *\n\t\t\t***********************************\n";
    cout<<"\t\t<S>um of natural integers\n\t\t<L>eap year check\n\t\t<C>ount vowels\n\t\t<A>rmstrong numbers\n\t\t<E>xit\n";
}

char GetChoice() {
    string input;
    if(cin.peek() == '\n')
        cin.ignore();
    getline(cin,input);
    return input.at(0);
}
 
void HandleInvalidChoice() {
    cout<<"Warning: invalid choice. Enter S,s or L,l or C,c or E,e only please.\n";
}

void HandleSum() {
    int n = 0;
    cout<<"Please Enter an Integer\n";
    cin >> n;
    cout<<"The sum of "<<n<<" integers is: 1+2+3+...+"<<n<<" = "<<ComputeSum(n)<<endl;
}
int ComputeSum(int n) {
    int sum = 0;
    for(int i = 1;i <= n;++i) {
        sum += i;
    }
    return sum;
}

void HandleLeapYear() {
    int year = 0;
    cout<<"Please enter a year\n";
    cin >> year;
    if(IsLeapYear(year)) {
        cout<<"True, Leap Year\n";
    }
    else {
        cout<<"False, Not Leap Year\n";
    }
}
bool IsLeapYear(int year) {
    if((year%4 == 0 && year%100 != 0) || year%400 == 0) {
        return true;
    }
    return false;
}

void HandleVowelsCount() {
    string text;
    cout<<"Please enter a string\n";
    if(cin.peek() == '\n')
        cin.ignore();
    getline(cin,text);
    cout<<"Total Vowel Count: "<<CountVowels(text)<<endl;
}
int CountVowels(string text) {
    int vowel_num = 0;
    for(int i = 0;i < text.length();i++) {
        if(IsVowel(text.at(i))) {
            vowel_num++;
        }
    }
    return vowel_num;
}
bool IsVowel(char c) {
    if(c == 'a'|| c == 'e' || c == 'i' || c == 'o'|| c == 'u' || c == 'A'|| c == 'E' || c == 'I' || c == 'O'|| c == 'U'){
        return true;
    }
    return false;
}

void DisplayArmstrongNumbers() {
    cout<<"Armstrong Numbers from 0-999: \n";
    for(int num = 0;num <= 999;num++) {
        if(pow(num%10,3)+pow((num/10)%10,3)+pow((num/100)%10,3) == num) {
            cout<<num<<endl;
        }
    }
}


void HandleExit() {
    cout<<"The fun is over. Have a nice day!!!\n";
    exit(0);
}
