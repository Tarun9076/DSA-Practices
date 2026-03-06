#include<iostream>
using namespace std;
int main(){
    cout <<"Hello World"<<endl;

    //Type casting
    char grade = 'A';
    int marks = grade; // Implicit type casting
    cout << "Marks: " << marks << endl;

    double pi = 3.14159;
    int truncatedPi = int(pi); // Explicit type casting
    cout << "Truncated Pi: " << truncatedPi << endl;

    int num ;
    cin >> num;   //To take input from user
    cout << "You entered: " << num << endl;

    int a = 10, b = 20;
    // int c = a++; // Post-increment: c gets the value of a (10), then a is incremented to 11
    // cout << "Value of c: " << c << endl; // Outputs 10
    // cout << "Value of a: " << a << endl; // Outputs 11

    int c = ++a; // Pre-increment: a is incremented to 11, then c gets the value of a (12)
    cout << "Value of c: " << c << endl; // Outputs 11
    cout << "Value of a: " << a << endl; // Outputs 11
}
