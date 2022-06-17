#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26.0);
        
        vector<bool> present(26, false);
        
        for(int i=0; i<s.length(); i++) {
            freq[s[i]-'a']++;
        }
        
        stack<char> st;
        
        for(int i=0; i<s.length(); i++) {
            
            freq[s[i]-'a']--;
            
            if(present[s[i]-'a'])
                continue;
            
            while(!st.empty() && s[i]<st.top() && freq[st.top()-'a'] > 0) {
                present[st.top()-'a'] = false;
                st.pop();
            }
            
            st.push(s[i]);
            present[s[i]-'a'] = true;
        }
        
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};