#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    // creation
    unordered_map<string, int> m;

    // insertion
    // M1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // M2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    //M3
    m["mera"] = 1;

    // what will happen now
    m["mera"] = 2;

    // search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;;


    cout << m["unknownKey"] << endl;;
    cout << m.at("unknownKey") << endl;;

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("love") << endl;; 

    // erase
    m.erase("love");
    cout << m.size() << endl;


    // Print
    // M1
    // for(auto i:m) {

    //     cout << i.first << " " << i.second << endl;
    // }

    //M2 - iterator
    unordered_map <string, int> :: iterator it = m.begin();
    while (it != m.end())
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    

    return 0;
}
