//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
       head = reverseList(head);
        Node* current = head;
        int carry = 1; 

        while (current != nullptr) {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10; 
            if (carry == 0) {
                break;
            }
            current = current->next;
        }

        head = reverseList(head);

        if (carry != 0) {
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends