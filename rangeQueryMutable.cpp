class NumArray {
    
    vector<int> segmentTree = vector<int>(100000, 0);
    int n;
    
    void buildST(int ind, int l, int r, vector<int>& nums){
        if(l==r){
            segmentTree[ind] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        buildST(2*ind+1, l, mid, nums);
        buildST(2*ind+2, mid+1, r, nums);
        
        segmentTree[ind] = segmentTree[2*ind+1] + segmentTree[2*ind+2];
    }
    
    void updateST(int ind, int val, int l, int r, int place) {
        int c = (l+r)/2;
        
        if(l==r && l==ind) {
            segmentTree[place] = val;
            return;
        }
        
        if(ind <= c){
            updateST(ind, val, l, c, 2*place+1);
        } else {
            updateST(ind, val, c+1, r, 2*place+2);
        }
        segmentTree[place] = segmentTree[2*place+1] + segmentTree[2*place+2];
    }
    
    int sumST(int l, int r, int left, int right, int ind) {
        if(left<=l && right>=r){
            return segmentTree[ind];
        }
        if(left>r || right<l)
            return 0;
        int c = (l+r)/2;
        return sumST(l, c, left, right, 2*ind+1) + sumST(c+1, r, left, right, 2*ind+2);
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        buildST(0, 0, nums.size()-1, nums);
    }
    
    void update(int index, int val) {
        updateST(index, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumST(0, n-1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */