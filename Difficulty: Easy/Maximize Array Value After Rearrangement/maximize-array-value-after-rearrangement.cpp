//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 #define mod 1000000007
  public:
    int Maximize(vector<int> arr) {
        sort(arr.begin(), arr.end());
        long sum =0;
        
        for(int i =0; i<arr.size(); i++){
            sum += (long)arr[i]*i;
        }
        long ans = sum%mod;
        return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends