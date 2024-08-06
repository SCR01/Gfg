//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        int i = 0, j = 0;
        int cnt = 0;
        int result = -1;
        
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                result = arr1[i];
                
                i++;
            } 
            else {
                
                
                result = arr2[j];
                j++;
            }
            cnt++;
            if (cnt == k) return result;
        }
        
        while (i < n) {
            result = arr1[i];
            i++;
            cnt++;
            if (cnt == k) return result;
        }
        
        while (j < m) {
            result = arr2[j];
            j++;
            cnt++;
            if (cnt == k) return result;
        }
        
        return -1; 
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends