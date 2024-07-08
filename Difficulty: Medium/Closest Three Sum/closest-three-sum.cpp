//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
       
       sort(arr.begin(),arr.end());
       int num=0;
       for(int i=0;i<arr.size();i++){
           
           int ele=arr[i];
           int  low=i+1;
           int high=arr.size()-1;
           
           while(low<high){
               int sum=ele+arr[low]+arr[high];
               if(sum>target){
                   
                   if(num==0)
                   num=sum-target;
                   else if(sum-target<=abs(num))
                       num=sum-target;
                  
                   high--;
                   
               }
               else if(sum==target)
               return sum;
               else{
                   if(num==0)
                   num=sum-target;
                  else if(abs(sum-target)<abs(num))
                     num=sum-target;
                    
                   low++;
               }
               
           }
           
           
       }
       return num+target;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends