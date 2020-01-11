class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {  
        stack<int>st;
        int pushvsz = pushV.size();
        int popvsz = popV.size();

        int pushInd = 0;
        for(int i = 0;i<popvsz;i++){
            if(st.empty()||st.top()!=popV[i]){
                while(pushInd<pushvsz && pushV[pushInd]!=popV[i]){
                    st.push(pushV[pushInd++]);
                }
                if(pushInd>=pushvsz){
                    return false;
                }else{
                    pushInd++;
                }
            }else{
                st.pop();
            }
        }
        return true;
    }
};