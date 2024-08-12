//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node* constTree(int n , int pre[], char preLN[], int &index){
    if(index >= n)return NULL;
    Node* root = new Node(pre[index]);
    index++;
    if(preLN[index -1] == 'N'){
        root->left = constTree(n,  pre, preLN, index);
        root->right = constTree(n, pre, preLN, index);
    }
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    if(n==0) return NULL;
    int index = 0;
    return constTree(n, pre, preLN, index);
}

// Code here
