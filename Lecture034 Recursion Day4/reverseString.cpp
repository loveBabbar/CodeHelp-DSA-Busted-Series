#include<iostream>
using namespace std;

string reverseString(int i, string &str){
    if(i >= str.length()/2){
        return str;
    }
    swap(str[i], str[str.length() - 1 - i]);
    return reverseString(i + 1, str);
}

int main() {

    string name = "abcde";
    
    reverseString(0, name);  
    
    cout << name << endl;

    return 0;
}
