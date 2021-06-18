class NumArray {
public:
    int n;
    vector<int> tree;
    vector<int> input;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        input = nums;
        tree.resize(4 * n, 0);
        buildSegmentTree(nums, 0, n - 1, 0);
    }
    
    int buildSegmentTree(vector<int>& nums, int l, int r, int i) {
        if (l == r) {
            tree[i] = nums[l];
            return nums[l];
        }
        
        int mid = (l + r) / 2;
        tree[i] = buildSegmentTree(nums, l, mid, (2 * i) + 1) + 
                    buildSegmentTree(nums, mid + 1, r, (2 * i) + 2);
        
        return tree[i];
    };
    
    void update(int index, int val) {
        int x = input[index];
        input[index] = val;
        updateIndex(0, n - 1, index, 0, val - x);
    }
    
    void updateIndex(int start, int end, int index, int i, int diff) {
        // completely outside the range
        if (index < start || index > end) {
            return;
        }
        
        tree[i] += diff;
        if (start < end) {
            int mid = (start + end) / 2;
            updateIndex(start, mid, index, (2*i) + 1, diff);
            updateIndex(mid + 1, end, index, (2*i) + 2, diff);
        }
    }

    int getSum(int left, int right, int node, int start, int end){
        // completely inside the range / overlap
        if(right >= end and left <= start){
            return tree[node];
        }

        // completely outside the range
        if(left > end || right < start){
            return 0;
        }

        //partial overlap
        int mid = (start + end)/2;
        return getSum(left, right, 2 * node + 1, start, mid) +
                getSum(left, right, 2 * node + 2, mid + 1, end);
    }
    
    int sumRange(int left, int right) {
        return getSum(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
