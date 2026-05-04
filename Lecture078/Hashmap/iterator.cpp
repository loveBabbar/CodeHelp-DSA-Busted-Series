#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, int> m;
    
    pair<string, int> p = make_pair("Axit", 19);
    m.insert(p);

    pair<string, int> p2("tiwari", 18);
    m.insert(p2);

    m["moon"] = 13;

    m["moon"] = m["moon"] + 2;

    cout << m["tiwari"] << endl;
    cout << m.at("Axit") << endl;

    cout << m.size() << endl;

    cout << m.count("moon") << endl;

    m.erase("moon");
    cout << "size: " << m.size() << endl;

    // ----------iterator----------
    unordered_map<string, int> :: iterator it = m.begin();
    while (it != m.end()) {
        cout << it->first << ": " << it->second << endl;
        it++;
    }

    return 0;
}