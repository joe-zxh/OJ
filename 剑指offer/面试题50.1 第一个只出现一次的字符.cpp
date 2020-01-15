class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int times[256]={0};
        int ind[256]={0};// 第一次出现时的位置。

        int sz = str.size();

        for(int i = 0;i<sz;i++) {
            if(times[str[i]]==0){
                ind[str[i]] = i;
            }
            times[str[i]]++;
        }

        for(int i = 0;i<sz;i++) {
            if(times[str[i]]==1){            
                return ind[str[i]];
            }
        }
        return -1;
    }
};