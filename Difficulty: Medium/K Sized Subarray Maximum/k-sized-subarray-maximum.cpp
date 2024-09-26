//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // Deque to store indices of array elements
        deque<int> dq;
        // Result vector to store the maximum of each subarray
        vector<int> result;
        
        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            // Remove indices from the front of the deque if they are out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove elements from the back of the deque if they are smaller than or equal to the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            // Add the current element index to the deque
            dq.push_back(i);
            
            // If we have processed at least k elements, the front of the deque is the maximum for the current window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends