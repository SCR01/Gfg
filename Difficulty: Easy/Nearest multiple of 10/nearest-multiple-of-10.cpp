//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n=str.length();
        if(str[n-1]>53)
        {
            str[n-1]=48;
            for(int i=n-2;i>-1;i--)
            {
                if(str[i]==57)
                {
                    str[i]=48;
                    if(i==0)
                    {
                        str.insert(str.begin(), 49);
                        return str;
                    }
                }
                else
                {
                    str[i]++;
                    return str;
                }
            }
        }
        str[n-1]=48;
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends