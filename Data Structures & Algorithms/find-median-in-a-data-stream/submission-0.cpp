class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>> r;
    int total=0;
    double currMedian;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        cout<<"here\n";
        total+=1;
        if(l.empty() && r.empty()){
            r.push(num);
            currMedian=num;
            return;
        }
        if(num>r.top()){
            r.push(num);
        }
        else{
            l.push(num);
        }
        while(r.size() + 1 < l.size()){
            r.push(l.top());
            l.pop();
        }
        while(l.size() + 1 < r.size()){
            l.push(r.top());
            r.pop();
        }
        
    }
    double findMedian() {
        if((l.size() + r.size()) % 2 == 0) return (l.top()+r.top())/2.0;
        else return l.size() > r.size() ? l.top() : r.top();
    }
};
