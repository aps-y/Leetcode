#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 vector<TreeNode*> genBst(int root, int left, int right) {
     vector<TreeNode*> lefts;
     vector<TreeNode*> rights;
     if(root == left) {
         lefts.push_back(NULL);
     }
     for(int i=left; i<root; i++){
         vector<TreeNode*> tmp = genBst(i, left, root-1);
         lefts.insert(lefts.end(), tmp.begin(), tmp.end());
     }

     if(root == right) {
         rights.push_back(NULL);
     }
     for(int i=root+1; i<=right; i++){
         vector<TreeNode*> tmp = genBst(i, root+1, right);
         rights.insert(rights.end(), tmp.begin(), tmp.end());
     }

     vector<TreeNode*> bsts;
     for(TreeNode* lft : lefts) {
         for(TreeNode* rgt: rights) {
             TreeNode* tmp = new TreeNode(root, lft, rgt);
             bsts.push_back(tmp);
         }
     }
     return bsts;
 }

 vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        for(int i=1; i<=n; i++){
            vector<TreeNode*> tmp = genBst(i, 1, n);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }

int main(){
    int n;
    cin>>n;

}