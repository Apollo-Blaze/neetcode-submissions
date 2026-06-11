class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int l;
    KthLargest(int k, vector<int>& nums) {
        l=k;
        for(auto x:nums)
            minheap.push(x);
        while(minheap.size()>k)minheap.pop();
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>l)minheap.pop();
        return minheap.top();
    }
};
