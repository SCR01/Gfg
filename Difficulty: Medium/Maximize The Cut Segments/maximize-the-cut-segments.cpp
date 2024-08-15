//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int res = 0;
        vector<int> vecx(n+1,INT_MIN),vecy(n+1,INT_MIN),vecz(n+1,INT_MIN);
        vecx[0] = vecy[0] = vecz[0] = 0;
        for(int i=1;i<=n;i++)
        {
            if((i>=x) && (!(i%x)))
            vecx[i] = i/x;
            
            if(i>=y)
            vecy[i] = max(1+vecy[i-y],vecx[i]);
            else
            vecy[i] = vecx[i];
            
            if(i>=z)
            vecz[i] = max(1+vecz[i-z],vecy[i]);
            else
            vecz[i] = vecy[i];
        }
        return max(vecz[n],0);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends