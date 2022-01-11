#include <bits/stdc++.h>
#include <map>  //headerfile for implementing map as STL
using namespace std;

/*
map is a dataStructure in which data is stored with referencing to keys.
Here, every key is unique and each key can point to one value only.
Also, same key will not point to 2 different values but 2 different keys can point one value.
In map, the elements are printed in sorted order while in case of unorderedMap it is in random order.
In STL, map is implemented using Red-Black or Balanced Tree and
unorderedMap using Hash-table.
*/

int main()
{
    map <int, string> m;  //STL implementation of map
    
    m[1] = "Audi";  //here, '1' is key and 'Audi' is the value
    m[9] = "BMW";
    m[5] = "Mercedes";
    m.insert({2, "Porsche"});
    m.insert({6, "Volkswagen"});
    cout<<"keys of map: ";
    for(auto i:m) {
        cout<<i.first<<" ";  //printing just keys of map
    }
    cout<<endl;
    cout<<"keys and values of map are: "<<endl;
    for(auto i:m) {
        cout<<i.first<<"->"<<i.second<<endl;  //printing both keys and values of map
    }
    cout<<endl;

    cout<<"present or not: "<<m.count(2)<<endl;  //tells whether the element specified is present or not (returns boolean value)

    auto it = m.find(6);
    cout<<"printing elements from specified element 6: ";
    for(auto i=it;i!=m.end();i++) {
        cout<<(*i).first<<" ";
    }
    cout<<endl;

    /*checking how erase works in map*/
    cout<<"before erase: "<<endl;
    for(auto i:m) {
        cout<<i.first<<"->"<<i.second<<endl;
    }
    cout<<endl;
    m.erase(5);  //erases element specified inside bracket
    cout<<"after erase: "<<endl;
    for(auto i:m) {
        cout<<i.first<<"->"<<i.second<<endl;
    }

    return 0;
}
