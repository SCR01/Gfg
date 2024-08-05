//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
  
      bool check(int n){
          if(n >= 0 && n <= 255 ){
              return true;
          }
          return false;
      }
  
    int isValid(string str) {
        vector<string> vect;
        string s;
        str.push_back('.');
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] != '.')
                s += str[i];
            else{
                if(s!= "")
                    vect.push_back(s);
                s = "";
            }
        }
        
        int cnt = 0 ;
        
        for(int i = 0 ; i < vect.size() ; i++){
            int n = stoi(vect[i]);
            if(check(n)) cnt++;
        }
        
        return cnt == 4;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends