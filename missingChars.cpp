#include<bits/stdc++.h>

using namespace std;

int main() {
    int k;
    string input_string;
    cin>>input_string;
    cin>>k;
    int n=0;
    for(int i=0;i<input_string.length(); i++)
    {
        if(input_string[i]=='#')
        n++;
    }
    k--;
    stack<char> s;
    while(k!=0){
        s.push('a'+(k%26));
        k/=26;
        n--;
    }
    while(n--){
        s.push('a');
    }
    for(int i=0;i<input_string.length(); i++)
    {
        if(input_string[i]=='#')
        {
            input_string[i] = s.top();
            s.pop();
        }
    }
    // cout<<s.empty()<<endl;
    cout<<input_string<<endl;
}