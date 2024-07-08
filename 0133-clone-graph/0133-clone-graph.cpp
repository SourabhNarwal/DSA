/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
       if(!node)
           return NULL;
        if(node->neighbors.size()==0)
        {   Node * clone=new Node(1);
            return clone;
        }
         map<Node*,Node*> m;
    queue<Node*> q;
 
    // Enqueue src node
    q.push(node);
    Node *newnode;
 
    // Make a clone Node
    newnode = new Node();
    newnode->val = node->val;
 
    // Put the clone node into the Map
    m[node] = newnode;
    while (!q.empty())
    {
        //Get the front node from the queue
        //and then visit all its neighbours
        Node *u = q.front();
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            // Check if this node has already been created
            if (m[v[i]] == NULL)
            {
                // If not then create a new Node and
                // put into the HashMap
                newnode = new Node();
                newnode->val = v[i]->val;
                m[v[i]] = newnode;
                q.push(v[i]);
            }
 
            // add these neighbours to the cloned graph node
            m[u]->neighbors.push_back(m[v[i]]);
        }
    }
 
    // Return the address of cloned src Node
    return m[node];
                  
}};