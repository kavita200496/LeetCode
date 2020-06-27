/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
    vector<int> res;
    if (!root) return res;
   map<int, int> mp;
   queue<pair<Node*, int>> q;
   
   int hd = 0;
   q.push({root, hd});
   while (!q.empty()) {
       Node* curr = q.front().first;
       hd = q.front().second;
       
       mp[hd] = curr->data;
       if (curr->left) q.push({curr->left, hd-1});
       if (curr->right) q.push({curr->right, hd+1});
       q.pop();
   }
   
   for (auto it : mp) res.push_back(it.second);
   
   return res;
}
