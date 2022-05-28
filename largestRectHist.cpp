#include<bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights) {

        int mx = 0;
        int n= heights.size();
        cout<<"height: "<<n<<endl;
        stack<pair<int,int>> stk;
        stk.push({heights[0],0});
        for(int i=1; i<n; i++) {
            if(heights[i]> stk.top().first) {
                stk.push({heights[i], i});
            }
            else{
                while(!stk.empty() && stk.top().first >= heights[i]){
                    int val = stk.top().first;
                    stk.pop();
                    if(stk.empty()){
                        mx = max(mx,  val*i);
                    }
                    else{
                        mx = max(mx,  val*(i - 1 - stk.top().second));
                    }
                }
                stk.push({heights[i],i});
            }
        }

        while(!stk.empty()){
            int val = stk.top().first;
            stk.pop();
            if(stk.empty())
            {
                mx = max(mx,  val*n);
            }
            else{
                mx = max(mx, (n -1- stk.top().second)*  val);
            }
        }
        return mx;
    }

int main() {
    int n;
    cin>> n;
    vector<int> heights;
    int hgt;
    while(n--){
        cin>>hgt;
        heights.push_back(hgt);
    }
    cout<<largestRectangleArea(heights)<<endl;
}