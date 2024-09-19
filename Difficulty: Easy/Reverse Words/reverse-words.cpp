//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stringstream strs(str);
        string ans="";
        string token;
        while(getline(strs, token, '.')){
            ans="."+token+ans;
        }
        return ans.substr(1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends