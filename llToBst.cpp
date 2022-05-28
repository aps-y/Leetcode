#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* toBST(int l, int r, vector<int>& ll){
    if(l>r)
    return NULL;

    int m = l + (l-r)/2;
    return new TreeNode(ll[m], toBST(l,m-1, ll), toBST(m+1, r, ll));

}

int main() {
    int n;
    cin>>n;
    vector<int> ll = vector<int>(n,0);
    for(int i=0; i<n; i++)
    cin>>ll[i];
    TreeNode* root = toBST(0, n-1, ll);
}
