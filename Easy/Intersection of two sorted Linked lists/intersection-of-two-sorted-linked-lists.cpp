//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node *newlist=NULL;
        Node *temp=NULL;
        int first=1;
        while(head1&&head2)
        {
            if(head1->data==head2->data)
            {
                if(first==1)
                {   first=0;
                    newlist=new Node(head1->data);temp=newlist;
                    head1=head1->next;head2=head2->next;
                }
                else{
                    temp->next=new Node(head1->data);
                    temp=temp->next;
                    head1=head1->next;head2=head2->next;
                }
                
            }
            else if(head1->data<head2->data)
                head1=head1->next;
             else
                head2=head2->next;
        }
        return newlist;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends