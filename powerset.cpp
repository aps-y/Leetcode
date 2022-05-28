#include<bits/stdc++.h>

using namespace std;

void powerset(vector<int>& v, int i, vector<int>& arr, vector<vector<int>> &pwrset){
    pwrset.push_back(v);
    set<int> st;
    for(; i<arr.size(); i++){
        if(st.find(arr[i]) == st.end())
        {
            st.insert(arr[i]);
            v.push_back(arr[i]);
            powerset(v, i+1, arr, pwrset);
            v.pop_back();            
        }
    }
}

int main() {
    int n;
    vector<int> v;
    cin>>n;
    int t;
    while(n--){
        cin>>t;
        // cout<<t<<" ";
        v.push_back(t);
    }
    // cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<vector<int>> pwrset;
    vector<int> vv;
    powerset(vv, 0, v, pwrset);
    // cout<<powerset(v)<<endl;;
    for(auto itr = pwrset.begin(); itr!= pwrset.end(); itr++){
        cout<<"[ ";
        for(auto jtr = itr->begin(); jtr != itr->end(); jtr++)
        cout<< *jtr<< " ";
        cout<<" ]"<<endl;
    }
}