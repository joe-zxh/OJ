class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) { 
        int sz = numbers.size();
        if(sz==0){
            return 0;
        }
        int cur, count = 0;
        for(int i = 0;i<sz;i++){
            if(count==0){
                cur = numbers[i];
                count = 1;
            }else if(numbers[i]==cur){
                count++;
            }else{
                count--;
            }
        }    
        if(count==0){
            return 0;
        }
        count = 0;
        for(int i = 0;i<sz;i++){
            if(numbers[i]==cur){
                count++;
            }
        }
        return count>sz/2?cur:0;
    }
};