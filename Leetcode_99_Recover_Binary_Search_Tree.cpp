#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode *first; // first incorrect node in the tree
    TreeNode *second; //second incorrect node in the tree
    TreeNode *pre;
     
    //utility function to print tree
    void inOrder(TreeNode *root){
        if (root==NULL){return;} 
        else{
            inOrder(root->left);
            if (pre == NULL){pre = root;}
            else {
                if (pre->val > root->val){
                    if (first==NULL) {first = pre;}
                    second = root;
                }
                pre = root;
            }
            inOrder(root->right);
             
        }
    }
    void recoverTree(TreeNode *root) {
        pre = NULL;
        first = NULL;
        second= NULL;
        inOrder(root);
        int val;
        val = first->val;
        first->val=second->val;
        second->val=val;
        return;
    }
};
int main(){
    TreeNode *root(0);
    TreeNode *left(1);
    root->left = left;
    recoverTree(root);
    return 0;
}
