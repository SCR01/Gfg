//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int distinct=0;
        int total=0;
        unordered_map<char,int>mp;
        for(auto it:str){
            if(it>='a' && it<='z'){
                mp[it]++;
            }
        }
        
        for(auto it:mp){
            total+=it.second;
        }
        distinct=mp.size();
        //cout<<total<<" "<<distinct<<endl;
        if(total-distinct>=26-distinct && k+distinct>=26){
            return true;
        }
        else{
            return false;            
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends