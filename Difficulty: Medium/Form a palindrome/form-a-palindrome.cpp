//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
        if(i==0||j==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str1[i-1]==str2[j-1]){
            return dp[i][j]=1 + lcs(str1,str2,i-1,j-1,dp);
        }
        else{
            return dp[i][j]=max(lcs(str1,str2,i,j-1,dp),lcs(str1,str2,i-1,j,dp));
        }
    }
    int countMin(string str){
        string str1 = str;
        int n = str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        reverse(str1.begin(),str1.end());
        return str.size()-lcs(str,str1, n, n,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends