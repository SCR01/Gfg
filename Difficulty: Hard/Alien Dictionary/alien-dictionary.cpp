//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        //in this alien dictionary question once you are able to crack
        //that how to make a link between the alphabet as per the 
        //customised dictionary then after that you can easily able use 
        //topo sort here
        
        
        //int this we can clearly see that if a word is occuring first then
        //the first letter that differ between those word will have an edge
        //as the word 1st having the differ letter has the high priority
        //than the word 2nd at which we got differ element
        
        //here we made the adjacency matrix with help of map
        //as mp[i] have all its child(neighbour) where i is 
        //the node(parent node)
        map<int,vector<int>>mp;
        for(int i = 0; i < N-1; i++){
            for(int j = 0; j < min(dict[i].size(),dict[i+1].size()); j++){
                if(dict[i][j] != dict[i+1][j]){
                    mp[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        queue<int>q;
        vector<int>in(K,0);
        // we just kept the indgree of each node in in[] vector
        for(int i = 0; i < K; i++){
            for(int j = 0; j < mp[i].size(); j++){
                in[mp[i][j]]++;
            }
        }
        //now we push all the element which has 0 indegree to our queue i.e. q
        for(int i = 0; i < K; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        //we keep vector v such as to find the topo sort and if
        //the size of v is eual to the number of node the this 
        //bunch of number are in correct order
        vector<int>v;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            v.push_back(x);
            for(int i = 0; i < mp[x].size(); i++){
                in[mp[x][i]]--;
                if(in[mp[x][i]] == 0){
                    q.push(mp[x][i]);
                }
            }
        }
        //as per question we just need to put all elementf of topo 
        //sort path in string and we just need to return that only
        //so we just iterate on v and add the element in string ans
        string ans = "";
        for(auto i : v){
            ans+=char(i+'a');
        }
        //finally we return the string ans as required by the question
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends