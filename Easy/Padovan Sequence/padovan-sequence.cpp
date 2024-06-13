//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        int a[n+1];
        int  m=1e9+7;
        a[0]=a[1]=a[2]=1;
        for(int i=3;i<=n;i++)
        {
            a[i]=(a[i-2]+a[i-3])%m;
        }
        return a[n]%m;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends