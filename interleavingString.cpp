#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> dp = vector<vector<bool>>(s1.length()+1, vector<bool>(s2.length()+1, false));
        dp[0][0]=1;
        for(int i=1; i<=s1.length(); i++){
            dp[i][0] = s1[i-1]==s3[i-1] ? dp[i-1][0] : false;
        }
        for(int i=1; i<=s2.length(); i++) {
            dp[0][i] = s2[i-1]==s3[i-1] ? dp[0][i-1] : false;
        }

        for(int i=1; i<=s1.length(); i++){
            for(int j=1; j<=s2.length(); j++){
                dp[i][j] = (s1[i-1] == s3[i+j-1] ? dp[i-1][j] : false) || (s2[j-1] == s3[i+j-1] ? dp[i][j-1] : false);
            }
        }

        return dp[s1.length()][s2.length()];
}

int main() {
    string s1,s2,s3;

    cin>>s1>>s2>>s3;
    

    cout<<isInterleave(s1,s2,s3)<<endl;
}