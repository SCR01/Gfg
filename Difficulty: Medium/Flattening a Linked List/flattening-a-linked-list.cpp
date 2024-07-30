//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
 
   Node *flatten(Node *root) {
    // declaring pointers array which points to the minimum elements right now
    vector<Node*> ptrs;
    Node* temp = root;
    while (temp) {
        ptrs.push_back(temp);
        temp = temp -> next;
    }
    
    int n = ptrs.size();
    
    Node* head = nullptr;
    Node* curr = nullptr;
    
    while (true) {
        int mini = INT_MAX;
        int index = -1;
        for (int i=0; i<n; ++i) {
            if (ptrs[i]) {
                if (ptrs[i] -> data < mini) {
                    mini = ptrs[i] -> data;
                    index = i;
                }
            }
        }
        if (index == -1) break;
        if (!head) {
            head = ptrs[index];
            curr = head;
        } else {
            curr -> bottom = ptrs[index];
            curr = curr -> bottom;
        }
        ptrs[index] = ptrs[index] -> bottom;
        curr -> bottom = nullptr;
    }
    
    return head;
}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends