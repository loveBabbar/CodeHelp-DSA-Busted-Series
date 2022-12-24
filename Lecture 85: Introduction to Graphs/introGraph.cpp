#include<iostream>

using namespace std;

template <typename T>
class graph{
    public:

    unorder_map<T,list<T>> adj;


    void addEdge(T u,T v , bool direction){

        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first <<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
}