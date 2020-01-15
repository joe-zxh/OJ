class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int p1 = 0, p2 = array.size()-1, s;
        vector<int> ret;
        while(p1<p2){
            s = array[p1]+array[p2];
            if(s==sum){
                ret.push_back(array[p1]);
                ret.push_back(array[p2]);
                break;
            }else if(s>sum){
                p2--;
            }else{
                p1++;
            }
        }
        return ret;
    }
};