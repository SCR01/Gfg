//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
 
int src_x=KnightPos[0];
int src_y=N+1-KnightPos[1];
  int target_x=TargetPos[0];
  int target_y=N+1-TargetPos[1];
  vector<vector<int>>vis(N+1,vector<int>(N+1,0));
  queue<pair<pair<int,int>,int>>q;
  q.push({{src_x,src_y},0});
  vis[src_x][src_y]=1;
  int dc[]={-2,-1,1,2,2,1,-1,-2};
  int dr[]={-1,-2,-2,-1,1,2,2,1};
  while(!q.empty()){
      int col=q.front().first.first;
      int row=q.front().first.second;
      int cnt=q.front().second;
      if(col==target_x && row==target_y){
          return cnt;
      }
      q.pop();
      for(int i=0;i<8;i++){
          int ncol=col+dc[i];
          int nrow=row+dr[i];
          if(nrow>0 && nrow<=N && ncol>0 && ncol<=N && vis[ncol][nrow]==0){
              q.push({{ncol,nrow},cnt+1});
              vis[ncol][nrow]=1;
          }
      }
      
  }
  return -1;
  
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends