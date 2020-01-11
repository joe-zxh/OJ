class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int left = -1, sz = array.size(), ind;
        vector<int> even;
        ind = 0;
        while(ind<sz){
            if((array[ind]&1)==1){ // 奇数数
                array[++left] = array[ind];
            }else{
                even.push_back(array[ind]);
            }
            ind++;
        }

        ind = left+1;
        while(ind<sz){
            array[ind] = even[ind-left-1];
            ind++;
        }
    }
};