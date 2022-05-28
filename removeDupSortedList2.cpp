#include<bits/stdc++.h>
using namespace std;

int srch(int a, int b, int target, vector<int>& nums){

    if(a>b)
    return -1;

    int c = (a+b)/2;
    if(nums[c]==target)
    return c;

    if(nums[c] == nums[a] && nums[a] == nums[b])
    {
        int ans = srch(a, c-1, target, nums);
        if(ans==-1)
        ans = srch(c+1, b, target, nums);
        return ans;
    }
    else if(nums[a]==target)
    return a;
    else if(nums[c] > target) {
        if(target < nums[a] && nums[c] >= nums[a])
        return srch(c+1,b,target,nums);
        return srch(a, c-1, target, nums);
    }
    else{
        if(nums[c] < target) {
            if(target > nums[a] && nums[c] <= nums[a]) 
            return srch(a, c-1, target, nums);
            return srch(c+1, b, target, nums);
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    int x;
    while(n--){
        cin>>x;
        arr.push_back(x);
    }
    cin>>x;

    cout<<srch(0, arr.size()-1, x, arr)<<endl;
}