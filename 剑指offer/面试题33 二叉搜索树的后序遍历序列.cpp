class Solution {
public:
    bool f(vector<int> sequence, int start, int end) {
        if(start>=end){
            return true;
        }

        bool big = false;
        int ind=0;

        for(int i = start;i<end;i++){
            if(sequence[i]>sequence[end] && big==false){
                big = true;
                ind = i-1;
            }else if(sequence[i]<sequence[end] && big==true){
                return false;
            }
        }

        return f(sequence, start, ind) && f(sequence, ind+1, end-1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0){
            return false;
        }
        return f(sequence, 0, sequence.size()-1);
    }
};