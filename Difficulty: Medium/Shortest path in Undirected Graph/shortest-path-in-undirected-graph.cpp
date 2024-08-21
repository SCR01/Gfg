//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> arr[N];
        vector<int> ans(N, -1);
        // build array of destinations
        for(int i=0; i<M; i++)
        {
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        // start ftom src, go through the elements in the array and set distance
        // if element is -1, or if it bigger than current distance + 1
        // update it to cur + 1
        // if it equals or smaller, end the loop
        ans[src] = 0;
        bool bCont = true;
        while(bCont)
        {
            bCont = 0;
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<arr[i].size(); j++)
                {
                    if((ans[i] == -1 || ans[i] > ans[arr[i][j]] + 1) &&
                        ans[arr[i][j]] != -1)
                    {
                        ans[i] = ans[arr[i][j]] + 1;
                        bCont = true;
                    }
                }
            }
        }
        return ans;
    }
};;


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends