class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    void Insert(int temp)
    {
        if (minHeap.empty()) {
            minHeap.push(temp);
        }
        else if (!maxHeap.empty() && maxHeap.top()>temp) {
            maxHeap.push(temp);
            if (minHeap.size() < maxHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else {
            minHeap.push(temp);
            if (minHeap.size() - 1 > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }        
    }

    double GetMedian()
    {
        if (minHeap.empty() && maxHeap.empty()) {
            return -1;
        }
        else if (minHeap.size() == maxHeap.size()) {
            return double (minHeap.top() + maxHeap.top()) / double(2);
        }
        else {
            return (double)minHeap.top();
        }    
    }
};