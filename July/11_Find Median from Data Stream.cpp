class MedianFinder {
private:
    priority_queue<int> maxHeap;                                      // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // min_heap for the second half

public:    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        
        // Rebalance 
        if ((maxHeap.size() > minHeap.size() + 1) || (minHeap.size() > maxHeap.size() + 1)) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty()) 
                return 0;
            else 
                return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            if (maxHeap.size() > minHeap.size()) 
                return maxHeap.top();
            else 
                return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
