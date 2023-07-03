//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node *helper(int in[], int instart, int inend, int post[], int poststart, int postend, map<int, queue<int>>& mp){
    if (instart > inend || poststart > postend) return nullptr;

    Node* root = new Node(post[postend]);
    int inroot = mp[root->data].front();
    mp[root->data].pop();
    int numsLeft = inroot - instart;

    root->left = helper(in, instart, inroot - 1, post, poststart, poststart + (inroot - instart) - 1, mp);
    root->right = helper(in, inroot + 1, inend, post, poststart + (inroot - instart), postend - 1, mp);

    return root;
}
Node *buildTree(int in[], int post[], int n) {
    
    map<int, queue<int>> mp;
   for(int i=0; i<n; i++){
       mp[in[i]].push(i);
   }
   Node* root = helper(in, 0, n - 1, post, 0, n - 1, mp);
    return root;
}
