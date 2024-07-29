//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    
      public:
    vector<string>result;
    
    bool safe(int i,int j,int n){
        
        return i>=0 && j>=0 && i<n && j<n;
    }
    
    void solve(int i,int j,vector<vector<int>> &mat,int n,string &path){
        
       
       if(!safe(i,j,n)|| mat[i][j]==0){
           return;
       } 
       
       if(i==n-1 && j==n-1){
           
           
           
           result.push_back(path);
           
           return;
       }
       
       
       mat[i][j]=0;
       
      path.push_back('L');
      
      solve(i,j-1,mat,n,path);
      
      path.pop_back();
      
        path.push_back('R');
      
      solve(i,j+1,mat,n,path);
      
      path.pop_back();
      
        path.push_back('U');
      
      solve(i-1,j,mat,n,path);
      
      path.pop_back();
      
        path.push_back('D');
      
      solve(i+1,j,mat,n,path);
      
      path.pop_back();
      
      mat[i][j]=1;
      
        
        
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        
        
        int n=mat.size();
    
    
    string path;
      
     
      solve(0,0,mat,n,path);
      return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends