class Solution {
public:
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {  
    int sz = input.size();
    if(sz<k || k<1 || k>sz){
        return vector<int>();
    }

    priority_queue<int> maxHeap;
    int curMax;

    for(int i = 0;i<sz;i++){
        if(maxHeap.size()<k){
            maxHeap.push(input[i]);
        }else{
            if(maxHeap.top()>input[i]){
                maxHeap.pop();
                maxHeap.push(input[i]);
            }
        }
    }
    
    vector<int> res(k);
    while(!maxHeap.empty()){
        res[--k]=maxHeap.top();
        maxHeap.pop();
    }
    return res; 
}
};