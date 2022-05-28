#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3};
    v.insert(v.begin(), 23);
    for(int i=0; i<v.size(); i++)
    cout<<v[i]<<endl;
}