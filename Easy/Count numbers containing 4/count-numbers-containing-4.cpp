//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        if (n < 4)
            return 0;
        int d = log10(n);
        int *a = new int[d+1];
        a[0] = 0;
        a[1] = 1;
        for (int i=2; i<=d; i++)
            a[i] = a[i-1]*9 + ceil(pow(10,i-1));
        int p = ceil(pow(10, d));
        int msd = n/p;
        if (msd == 4)
            return (msd)*a[d] + (n%p) + 1;
        if (msd > 4)
            return (msd-1)*a[d] + p + countNumberswith4(n%p);
        return (msd)*a[d] + countNumberswith4(n%p);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends