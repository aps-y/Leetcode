#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        
        vector<int> count(10,0);
        
        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i])
                bulls++;
            else
                count[secret[i]-'0']++;
        }
        
        for(int i=0; i<secret.length(); i++){
            if(secret[i]!=guess[i]){
                if(count[guess[i]-'0']>0){
                    count[guess[i]-'0']--;
                    cows++;
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};