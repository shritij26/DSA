#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node* root)
{
    cout << "Enter data for node: "<< endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1)
        return NULL;
    cout << "Enter data for left child of " << data << ": " << endl;
    root->left = buildtree(root->left); //recursive call to build left subtree
    cout << "Enter data for right child of " << data << ": " << endl;
    root->right = buildtree(root->right); //recursive call to build right subtree
    return root; 
}

/*********************************************************************/

bool isBalanced(node* root)
{
    return dfsHeight(root) != -1;
}
int dfsHeight(node* root)
{
    if(root == NULL)
        return 0;
    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1)
        return -1;
    int rightHeight = dfsHeight(root->right);
    if(rightHeight == -1)
        return -1;
    if(abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}
/*********************************************************************/

int diameter(node* root)
{
    int diameter = 0;
    heightDiameter(root, diameter);
    return diameter;
}
int heightDiameter(node* root, int &diameter)
{   
    if(root == NULL)
        return 0;
    int leftHeight = heightDiameter(root->left, diameter);
    int rightHeight = heightDiameter(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}

/*********************************************************************/

vector<vector<int>> verticalTraversal(node* root) {
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mp;
        queue<pair<node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            node* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            mp[x][y].push(node->data);
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;

        for (auto& i : mp) {
            vector<int> curr;
            for (auto& j : i.second) {
                auto pq = j.second;
                while (!pq.empty()) {
                    curr.push_back(pq.top());
                    pq.pop();
                }
            }
            ans.push_back(curr);
        }
        return ans;
}

/*********************************************************************/

vector<int> topView(node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            node* node = it.first;
            int x = it.second;
            if (mp.find(x) == mp.end()) // Only if it is first time then only we will update the dataue for the current vertical line
                mp[x] = node->data;
            if (node->left)
                q.push({node->left, x - 1});
            if (node->right)
                q.push({node->right, x + 1});
        }
        for (auto& i : mp) {
            ans.push_back(i.second);
        }
        return ans;
}


vector<int> bottomView(node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            node* node = it.first;
            int x = it.second;
            mp[x] = node->data;  // Update the dataue for the current vertical line
            if (node->left)
                q.push({node->left, x - 1});
            if (node->right)
                q.push({node->right, x + 1});
        }
        for (auto& i : mp) {
            ans.push_back(i.second);
        }
        return ans;
}

void rightView(node* root, vector<int>& ans, int level )
{
    if(root == NULL)
        return;
    
    if(ans.size() == level)
        ans.push_back(root->data);
    
    rightView(root->right, ans, level + 1); // first right then left
    rightView(root->left, ans, level + 1);
}

void leftView(node* root, vector<int>& ans, int level )
{
    if(root == NULL)
        return;
    
    if(ans.size() == level)
        ans.push_back(root->data);
    
    leftView(root->left, ans, level + 1); // first left then right
    leftView(root->right, ans, level + 1);
}

/*********************************************************************/

bool getPath(node* root, vector<int>& arr, int x)
{
    if(root == NULL)
        return false;
    if(root->data == x)
    {
        arr.push_back(root->data);
        return true;
    }   
    arr.push_back(root->data);
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;
}

/*********************************************************************/

/******************************************************************************************************************************************/

//BST

node* inorderSuccessor(node* root, node* x)
{
    node* successor = NULL;
    while(root != NULL)
    {
        if(x->data >= root->data)
            root = root->right;
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

node* inorderPredecessor(node* root, node* x)
{
    node* predecessor = NULL;
    while(root != NULL)
    {
        if(x->data <= root->data)
            root = root->left;
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}