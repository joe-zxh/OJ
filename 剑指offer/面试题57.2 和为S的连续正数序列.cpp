class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int start = 1, end = 2;
        int s;

        vector<vector<int> > vret;
        while((start<<1)+1<=sum){
            s = (start+end)*(end-start+1)/2;

            if(s==sum){
                vector<int> v;
                for(int i = start;i<=end;i++){
                    v.push_back(i);
                }
                vret.push_back(v);
                end++;
            }else if(s<sum){
                end++;
            }else{
                start++;
            }
        }
        return vret;
    }
};