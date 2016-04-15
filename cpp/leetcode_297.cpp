#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Codec {
private:
    /* data */
public:
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);
};

string Codec::serialize(TreeNode* root)
{
    string str;
    queue<TreeNode*> q;
    q.push(root)
    while(!q.empty()){
        if(q.front() == NULL){
            str = str + "#,";
        } else {
            q.push(q.front()->left);
            q.push(q.front()->right);
            str = str + to_string(q.front()->val) + ",";
        }
        q.pop();
    }
    return str;
}

TreeNode* Codec::deserialize(string data){
    TreeNode* root = NULL;
    queue<TreeNode**>q;
    q.push(&root);
    auto first = data.begin();
    while(first != data.end()){
        TreeNode** pp = q.front();
        if(*first == '#'){
            advance(first,2);
        } else {
            auto last = find(first,data.end(),',');
            int val = stoi(string(first, last));
            *pp = new TreeNode(val);
            q.push(&((*pp)->left));
            q.push(&((*pp)->right));
            first = next(last);
        }
        q.pop();
    }
    return root;
}

int main()
{
    
    return 0;
}