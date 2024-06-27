//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


bool isToeplitz(vector<vector<int>>& v) {
    int i=0;
    int n=v.size(), m = v[0].size();
    unordered_map<int, int> mp;
    while(i<n) {
        int j=0;
        while(j<m){
            if (mp.find(j-i)!=mp.end()) {
                if (mp[j-i]!=v[i][j]) return false;
            }
            else mp[j-i]=v[i][j];
            j++;
        }
        i++;
    }
    return true;
}