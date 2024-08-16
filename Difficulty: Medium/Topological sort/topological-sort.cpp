//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    void dfs(int node,int V, vector<int> adj[],int visited[],stack<int>& st)
    {
        visited[node]=1;
        
        //visited marked hone ke baad neighbour me jaa
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfs(it,V,adj,visited,st);
            }
        }
        
        //node is visisted and explore thus push into the stack
        st.push(node);
    }
public:
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    
    //visited//
    int visited[V]={0};
    //stack//
    stack<int>st;
    
    //har node me traversal
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            //dfs call kar de as visited nhi hai
            dfs(i,V,adj,visited,st);
        }
    }
    
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
 
};
 

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends