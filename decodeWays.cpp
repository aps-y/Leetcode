#include<bits/stdc++.h>
using namespace std;

int numDecodings(string s) {
        
        if(s[0]=='0')
            return 0;
        vector<pair<int,int>> dp;
        dp.push_back({1,0});
        int dbl = stoi(s.substr(0,2));
        int fs,sc;
        fs = s[1]=='0' ? 0 : 1;
        sc = dbl > 26 ? 0 : 1;
        // cout<<fs<<" "<<sc<<" "<<dbl<<endl;
        dp.push_back({fs,sc});
        
        for(int i=2; i<s.length(); i++){
            dbl = stoi(s.substr(i-1,2)); 
            fs = s[i]=='0' ? 0 : 1;
            sc = dbl > 26 || dbl<10 ? 0 : 1;
            // cout<<fs<<" "<<sc<<" "<<dbl<<endl;
            if(sc==0 && fs == 0)
                return 0;
            fs = fs ? dp[i-1].first + dp[i-1].second : 0;
            sc = sc ? dp[i-2].first + dp[i-2].second : 0;
            dp.push_back({fs,sc});
            
        }
        return dp.rbegin()->first + dp.rbegin()->second;
        
    }

int main() {
    string s;
    cin>>s;
    cout<<numDecodings(s)<<endl;
}