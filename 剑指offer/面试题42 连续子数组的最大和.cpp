class Solution {
public:
int FindGreatestSumOfSubArray(vector<int> array) {
    int sz = array.size();
    if(sz==0){
        return 0;
    }

    int pre=array[0];
    int retsum=pre;

    for(int i = 1;i<sz;i++){
        pre = pre+array[i]>array[i]?pre+array[i]:array[i];
        retsum = pre>retsum?pre:retsum;
    }
    return retsum;
}
};