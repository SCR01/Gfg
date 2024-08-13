//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>InDeg(V,0);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            InDeg[adj[i][j]]++;
        }
        int count=0;
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(!InDeg[i])
            q.push(i);
        }
        while(!q.empty())
        {
            int Node = q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[Node].size();i++)
            {
                InDeg[adj[Node][i]]--;
                if(!InDeg[adj[Node][i]])
                {
                    q.push(adj[Node][i]);
                }
            }
        }
        return count!=V;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends