//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    // Complete this function
     static  bool compa(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second; 
}

    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
         unordered_map<int, int> freqMap;

    for (int num : arr) {
        freqMap[num]++;
    }

    vector<pair<int, int>> freqVec;
    for (auto& it : freqMap) {
        freqVec.push_back(it);
    }

    sort(freqVec.begin(), freqVec.end(), compa);

    vector<int> result;
    for (auto& it : freqVec) {
        int count = it.second;
        while (count--) {
            result.push_back(it.first);
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends