//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

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
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    Node* getParentTrack(Node* root, int target, 
            unordered_map<Node*, Node*> &parentTrack){
        
        queue<Node*> q;
        q.push(root);
        Node* startNode;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target){
                startNode = curr;
            }
            
            if(curr->left){
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right){
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        return startNode;
    }
    
    int getMinTime(unordered_map<Node*, Node*> &parentTrack, Node* start){
       unordered_map<Node*, bool> vis;
       queue<Node*> q;
       q.push(start);
       vis[start] = true;
       int minTime = 0;
       
       while(!q.empty()){
           int size = q.size();
           int flag = 0;
           
           for(int i=0; i<size; i++){
               Node *curr = q.front();
               q.pop();
               
               if(curr->left && !vis[curr->left]){
                   flag = 1;
                   q.push(curr->left);
                   vis[curr->left] = true;
               }
               
               if(curr->right && !vis[curr->right]){
                   flag = 1;
                   q.push(curr->right);
                   vis[curr->right] = true;
               }
               
               if(parentTrack[curr] && !vis[parentTrack[curr]]){
                   flag = 1;
                   q.push(parentTrack[curr]);
                   vis[parentTrack[curr]] = true;
               }
           }
           
           if(flag == 1){
               minTime++;
           }
       }
       return minTime;
    }
  
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentTrack;
        Node *startNode = getParentTrack(root, target, parentTrack);
        int minTimeReq = getMinTime(parentTrack, startNode);
        return minTimeReq;
    }
};













//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends