//{ Driver Code Starts
//

#include<bits/stdc++.h>
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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* helper(int in[], int instart, int inend, int pre[], int prestart, int preend, map<int, queue<int>>& mp) {
    if (prestart > preend || instart > inend) return nullptr;
    Node* root = new Node(pre[prestart]);
    int inroot = mp[root->data].front();
    mp[root->data].pop();
    int numsLeft = inroot - instart;

    root->left = helper(in, instart, inroot - 1, pre, prestart + 1, prestart + numsLeft, mp);
    root->right = helper(in, inroot + 1, inend, pre, prestart + numsLeft + 1, preend, mp);

    return root;
}

Node* buildTree(int in[], int pre[], int n) {
    map<int, queue<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[in[i]].push(i);
    }
    Node* root = helper(in, 0, n - 1, pre, 0, n - 1, mp);
    return root;
}

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends