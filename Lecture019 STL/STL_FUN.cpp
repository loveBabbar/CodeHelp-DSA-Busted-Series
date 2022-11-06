#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    // Array -->
    cout << endl;
    cout << "<-------------------------------------Array------------------------------------------>";
    cout << endl;

    int basic[5] = {1, 4, 8, 12, 6}; // basic representation of array

    array<int, 5> a = {2, 8, 4, 6, 8};
    int a_size = a.size();
    for (int i = 0; i < a_size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "element at second index --> " << a.at(2) << endl;
    cout << "empty or not --> " << a.empty() << endl;
    cout << "first element --> " << a.front() << endl;
    cout << "last element --> " << a.back() << endl;

    // Vector -->

    cout << endl;
    cout << "<-------------------------------------Vector------------------------------------------>";
    cout << endl;

    vector<int> v;
    vector<int> b(3, 1);
    vector<int> last(b);
    cout << " print last" << endl;
    for (int i : last)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "capacity --> " << v.capacity() << endl;
    v.push_back(1);
    cout << "capacity --> " << v.capacity() << endl;
    v.push_back(2);
    cout << "capacity --> " << v.capacity() << endl;
    v.push_back(3);
    cout << "capacity --> " << v.capacity() << endl;
    cout << "size --> " << v.size() << endl;

    cout << "element at second index --> " << v.at(2) << endl;
    cout << "empty or not --> " << v.empty() << endl;
    cout << "first element --> " << v.front() << endl;
    cout << "last element --> " << v.back() << endl;

    cout << "before pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back();
    cout << "after pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "before clear --> " << v.size();
    v.clear();
    cout << "after clear --> " << v.size();

    // deque -->

    cout << endl;
    cout << "<-------------------------------------deque------------------------------------------>";
    cout << endl;

    deque<int> d;
    d.push_back(1);
    d.push_front(2);

    // d.pop_back(); // pop method
    cout << endl;
    cout << "element at second index --> " << d.at(1) << endl;
    cout << "empty or not --> " << d.empty() << endl;
    cout << "first element --> " << d.front() << endl;
    cout << "last element --> " << d.back() << endl;
    cout << "before erase --> " << d.size();
    d.erase(d.begin(), d.begin() + 1);
    cout << "after erase --> " << d.size();

    // List -->

    cout << endl;
    cout << "<-------------------------------------List------------------------------------------>";
    cout << endl;

    list<int> l;
    list<int> n(5, 10);
    cout << "printing n " << endl;
    for (int i : n)
    {
        cout << i << " ";
    }
    cout << endl;
    l.push_back(1);
    l.push_front(2);
    cout << "before erase --> ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    l.erase(l.begin());
    cout << "after erase";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "size --> " << l.size() << endl;

    // Stack -->

    cout << endl;
    cout << "<-------------------------------------Stack------------------------------------------>";
    cout << endl;

    stack<string> s;
    s.push("love");
    s.push("babbar");
    s.push("kumar");
    cout << "top element --> " << s.top() << endl;
    s.pop();
    cout << "after pop top element --> " << s.top() << endl;
    cout << "Size --> " << s.size() << endl;
    cout << "empty or not --> " << s.empty() << endl;

    // Queue -->

    cout << endl;
    cout << "<-------------------------------------Queue------------------------------------------>";
    cout << endl;

    queue<string> q;
    q.push("love");
    q.push("babbar");
    q.push("kumar");
    cout << "Size --> " << q.size() << endl;
    cout << "first element --> " << q.front() << endl;
    q.pop();
    cout << "after pop first element --> " << q.front() << endl;
    cout << "Size after pop --> " << q.size() << endl;

    // Priority_Queue -->

    cout << endl;
    cout << "<--------------------------------Priotity_Queue------------------------------------->";
    cout << endl;

    // max heap
    priority_queue<int> maxi;
    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    int maxi_s = maxi.size();
    for (int i = 0; i < maxi_s; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);
    int mini_s = mini.size();
    for (int i = 0; i < mini_s; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "maxi khali hai kaya bhai..? --> " << maxi.empty() << endl;
    cout << "mini khali hai kaya bhai..? --> " << mini.empty() << endl;

    // Set -->

    cout << endl;
    cout << "<-------------------------------------Set------------------------------------------>";
    cout << endl;

    set<int> se;

    se.insert(5);
    se.insert(5);
    se.insert(5);
    se.insert(1);
    se.insert(6);
    se.insert(6);
    se.insert(0);
    se.insert(0);
    se.insert(0);
    cout << "set -->" << endl;
    for (auto i : se)
    {
        cout << i << " ";
    }
    cout << endl;
    set<int>::iterator it = se.begin();
    it++;
    se.erase(it);
    cout << "set after erase -->" << endl;
    for (auto i : se)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "-9 present or not --> " << se.count(-9)<<endl;
    set<int>::iterator itr = se.find(5);
    for (auto it = itr; it != se.end(); it++)
    {
        cout << *it << " ";
    }

    // Map -->

    cout << endl;
    cout << "<-------------------------------------Map------------------------------------------>";
    cout << endl;

    map<int, string> m;

    m[1] = "babbar";
    m[13] = "kumar";
    m[2] = "love";
    m.insert({5, "bheem"});

    cout << "before erase" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    m.erase(13);
    cout << "after erase" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "finding -13 --> " << m.count(-13) << endl;
    // it return iterator of particular element
    auto itu = m.find(2);
    for (auto i = itu; i != m.end(); i++)
    {
        cout << (*i).first << endl;
    }

    // Algorithm -->

    cout << endl;
    cout << "<-------------------------------------Algorithm------------------------------------------>";
    cout << endl;

    vector<int> algo;
    algo.push_back(1);
    algo.push_back(3);
    algo.push_back(6);
    algo.push_back(7);

    cout << "Finding 6 --> " << binary_search(algo.begin(), algo.end(), 6) << endl;

    cout << "lower bound --> " << lower_bound(algo.begin(), algo.end(), 6) - algo.begin() << endl;
    cout << "upper bound --> " << upper_bound(algo.begin(), algo.end(), 4) - algo.begin() << endl;

    int x = 3;
    int y = 5;

    cout << "max(x,y) --> " << max(x, y) << endl;
    cout << "min(x,y) --> " << min(x, y) << endl;

    swap(x,y);
    cout<<"after x & y swap --> "<<x<<" "<<y<<endl;
    string abcd="abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"reversed string --> "<<abcd<<endl;

    rotate(algo.begin(),algo.begin()+1,algo.end());
    cout<<"after rotate"<<endl;
    for(int i:algo){
        cout<<i<<" ";

    }
}
