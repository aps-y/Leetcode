#include<bits/stdc++.h>
using namespace std;

void validIps(int stri, int doti, string ip ,vector<string> &ans, int n){
    if(stri>=n){
        if(doti==3)
        ans.push_back(ip);
        return;
    }
    if(doti == 3){
        if(ip[stri]=='0' && stri!=n-1)
        return;
        if(n-stri<4 && stoi(ip.substr(stri, n-stri))<256){
            ans.push_back(ip);
        }
        return;
    }
    string newIp;
    
    newIp = ip;
    newIp.insert(stri+1, ".");
    validIps(stri+2, doti+1, newIp, ans, n+1);
    
    if(ip[stri] != '0' && n-stri >=2){
        newIp = ip;

        newIp.insert(stri+2, ".");
        validIps(stri+3, doti+1, newIp, ans, n+1);

    }
    if(ip[stri] != '0' && n-stri >=3 && stoi(ip.substr(stri,3))<256){
        newIp = ip;

        newIp.insert(stri+3, ".");
        validIps(stri+4, doti+1, newIp, ans, n+1);
    }
}

int main() {
    string ip;
    cin>>ip;
    vector<string> ans;
    int n = ip.length();
    if(n<13 && n>3)
    validIps(0,0,ip,ans, ip.length());
    for(string s: ans ){
        cout<<s<<" ";
    }
    cout<<endl;
}