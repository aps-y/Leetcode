#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> vals(words.size(), 0);
        
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].length(); j++) {
                vals[i] = vals[i] | (1<<(words[i][j]-'a'));
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                if((vals[i] & vals[j]) == 0) {
                    ans = max(ans, (int)words[i].length() * (int)words[j].length());
                }
            }
        }
        
        return ans;
    }
};