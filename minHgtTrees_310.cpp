#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    vector<int> mx = vector(30000, 0);
    vector<int> mx2= vector(30000, 0);
    
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for(int i=0; i<adj[node].size(); i++) {
            if(vis[adj[node][i]])
                continue;
            int v = dfs(adj[node][i], adj, vis);
            if(v >= mx[node]) {
                mx2[node] = mx[node];
                mx[node] = v;
            } else if(v > mx2[node]) {
                mx2[node] = v;
            }
        }
        return mx[node]+1;
    }
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int v) {
        vis[node] = true;
        if(v >= mx[node]) {
            mx2[node] = mx[node];
            mx[node] = v;
        } else if(v > mx2[node]) {
            mx2[node] = v;
        }
        for(int i=0; i<adj[node].size(); i++) {
            if(vis[adj[node][i]])
                continue;
            if(mx[adj[node][i]] +1 == mx[node]) {
                dfs(adj[node][i], adj, vis, mx2[node]+1);
            } else {
                dfs(adj[node][i], adj, vis, mx[node]+1);
            }
        }
    }
    
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n, vector<int>());
        
        for(int i=0; i<n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(0, adj, vis);
        vis = vector<bool>(n, false);
        dfs(0, adj, vis, 0);
        int mmx = 0;
        for(int i=0; i<n; i++) {
            mmx = max(mmx, mx[i]+mx2[i]);
        }
        int mxV = ceil((double)mmx/2);
        int mx2V = mmx/2;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(mx[i]==mxV && mx2[i]==mx2V)
                ans.push_back(i);
        }
        return ans;
    }
};