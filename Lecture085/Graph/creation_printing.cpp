// https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

# include <bits/stdc++.h>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    
    // store nodes in adjacency list
    vector <int> ans[n];
    for (int i = 0; i < m; i++) {
        
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    // convert list to required formet -> matrix 
    /*[[ ],
       [ ],
       [ ]
      ]
    */
    vector<vector<int>> requiredFormatList(n);
    for (int i = 0; i < n; i++) {

        requiredFormatList[i].push_back(i);

        // neighbours of node i
        for (int j = 0; j < ans[i].size(); j++) {
            requiredFormatList[i].push_back(ans[i][j]);
        }
    }
    return requiredFormatList;
}