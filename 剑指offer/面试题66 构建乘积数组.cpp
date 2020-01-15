class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int sz = A.size();

        vector<int> ret(sz);

        if(sz==0){
            return ret;
        }

        vector<int> B(sz);
        vector<int> C(sz);

        B[0] = 1; C[sz-1] = 1;

        int curMult = 1;
        for(int i = 1;i<sz;i++){
            curMult *= A[i-1];
            B[i] = curMult;
        }

        curMult = 1;
        for(int i = sz-2;i>=0;i--){
            curMult *= A[i+1];
            C[i] = curMult;
        }

        for(int i = 0;i<sz;i++){
            ret[i] = B[i]*C[i];
        }

        return ret;
    }
};