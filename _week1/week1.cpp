#include <iostream>
#include <string>
using namespace std;

int main() {

    string dogName;
    int actualAge;
    int humanAge;

    cout << "How many years old is your dog?" << endl;
    cin >> actualAge;
    humanAge = actualAge * 7;
    cout << "What is your dog's name?" << endl;
    cin >> dogName;


    cout << dogName << "'s age is approximately " << "equivalent to a " << humanAge << " year old human." << endl;


    string s1 = "5";
    string s2 = "3";
    string s3 = s1 + s2;
    cout << s3 << endl;


    return 0;
}
