//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    bool dfs(int u, int parent, vector<int> adj[], vector<bool> &vis, vector<bool> &stk){
        vis[u] = true;
        stk[u] = true;
        
        for(int v : adj[u]){
            if(!vis[v]){
                if(dfs(v,u, adj, vis, stk)) return true;
            }
            else if(stk[v] && parent != v) return true;
        }
        stk[u] = false;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> stk(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]) {
                if(dfs(i,-1, adj, vis, stk))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends