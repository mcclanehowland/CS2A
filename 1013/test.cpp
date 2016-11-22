#include <iostream>
#include <string>

using namespace std;

int main() {
    int day = 13;
    const int & thursday = day;
    day = 44;
    cout << day << endl;
    cout << thursday << endl;
}


