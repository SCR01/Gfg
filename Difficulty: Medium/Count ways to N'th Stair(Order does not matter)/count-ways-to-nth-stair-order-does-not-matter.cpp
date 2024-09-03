//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{      //Watch the Explanation on above mentioned YT Link :)
	public:
	    int solve(int ind,vector<int>& temp,int n,vector<vector<int>>& dp){
	        if(n < 0 || ind >= temp.size()){
	            return 0;
	        }
	        if(n == 0){
	            return 1;
	        }
	        if(dp[ind][n] != -1){
	            return dp[ind][n];
	        }
	        
	        int include = solve(ind,temp,n-temp[ind],dp);
	        int exclude = solve(ind+1,temp,n,dp);
	        
	        return dp[ind][n] = include+exclude;
	    }
		int nthStair(int n){
		    vector<int> temp = {1,2};
		    vector<vector<int>> dp(temp.size(),vector<int>(n+1,-1));
		    return solve(0,temp,n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends