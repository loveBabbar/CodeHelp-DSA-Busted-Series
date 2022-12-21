#include<bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<string,int> m;

    //insertion

    //1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);

    //2
    pair<string,int> p2("love",2);
    m.insert(p2);

    //3
    m["mere"] = 1;

    //what will happen 
    m["mere"] = 2; //it will overide previous value

    cout<<m["mera"]<<endl;
    cout<<m.at["babbar"]<<endl;


    cout<<m["unkownKey"]<<endl;
    cout<<m.at["unkownKey"]<<endl;


    //size
    cout<<m.size()<<endl;


    //to check presence
    cout<<m.count("love")<<endl;

    //erase
    m.erase["love"];
    cout<<m.size()<<endl;

    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first << " " <<it->second <<endl;
        it++;
    }

    return 0;

}