#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    vector<vector<vector<bool>>> dp = vector<vector<vector<bool>>>(n,vector<vector<bool>>(n, vector<bool>(n,false)));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j][0]=s1[i]==s2[j];
        }
    }

    for(int len=2; len<=n; len++){
        for(int s1i=0; s1i<=n-len; s1i++){
            for(int s2i=0; s2i<=n-len; s2i++) {
                dp[s1i][s2i][len-1] = s1.substr(s1i, len) == s2.substr(s2i, len);
                for(int i=1; i<len; i++){
                    if(dp[s1i][s2i][len-1])
                    break;
                    dp[s1i][s2i][len-1] = (dp[s1i][s2i][i-1] && dp[s1i+i][s2i+i][len-i-1]) || (dp[s1i+len-i][s2i][i-1] && dp[s1i][s2i+i][len-i-1]);
                }
            }
        }
    }
    cout<<dp[0][0][n-1]<<endl;
   
}