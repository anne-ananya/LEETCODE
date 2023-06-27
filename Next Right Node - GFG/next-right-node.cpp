//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{

  private:
    void levelOrder(Node* root, vector<vector<Node*>>& ans) {
        if (root == NULL)
            return;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<Node*> level;
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                if (node->left != NULL)
                    q.push(node->left);
                
                if (node->right != NULL)
                    q.push(node->right);
                
                level.push_back(node);
            }
            
            ans.push_back(level);
        }
    }
    
public:
    Node* nextRight(Node* root, int key) {
        Node* z = new Node(-1);
        vector<vector<Node*>> ans;
        
        levelOrder(root, ans);
        
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                Node* node = ans[i][j];
                
                if (node->data == key && j < ans[i].size() - 1) {
                    return ans[i][j + 1];
                }
            }
        }
        
        return z;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int key;
        cin >> key;
        cin.ignore();
        Solution obj;
        Node *res = obj.nextRight(root, key);
        cout << res->data;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends