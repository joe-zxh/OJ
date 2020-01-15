class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
         
        int sz = numbers.size();
 
        if(sz==0){
            return false;
        }
 
        sort(numbers.begin(), numbers.end());
 
        if(numbers[sz-1]==0){
            return true;
        }
 
        int firstNZeroind = -1;
        int zeros = 0;
        int cur = 0;
 
        while(cur<sz){
            if(cur>0&&numbers[cur]==numbers[cur-1]&&numbers[cur]!=0){ // 出现对
                return false;
            }
            if(firstNZeroind==-1&&numbers[cur]!=0){
                firstNZeroind = cur;
            }
            zeros = numbers[cur]==0?zeros+1:zeros;
            cur++;
        }
 
        if(numbers[sz-1]-numbers[firstNZeroind]+1<=(sz-1-firstNZeroind+1)+zeros){
            return true;
        }else{
            return false;
        }
    }
};