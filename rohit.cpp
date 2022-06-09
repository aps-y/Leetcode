#include<bits/stdc++.h>

using namespace std;

int maxPathSum(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n,INT_MIN));

    for(int i=0; i<n; i++){
        dp[0][i] = matrix[0][i];
    }

    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(j!=0) {
                dp[i][j] = dp[i-1][j-1] + matrix[i][j];
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j] + matrix[i][j]);
            if(j<n-1){
                dp[i][j] = max(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[m-1][i]);
    }
    return ans;
}