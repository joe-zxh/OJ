class Solution {
public:
    vector<int> help;
    int p2, p3, p5;

    Solution(){
        help.push_back(1);
        p2 = p3 = p5 = 0;
    }

    int GetUglyNumber_Solution(int index) {
        int sz = help.size();
        int minval, t2, t3, t5;
        if(sz>=index){
            return help[index-1];
        }else{            
            for(int i = sz;i<index;i++){
                t2 = 2*help[p2];
                t3 = 3*help[p3];
                t5 = 5*help[p5];
                
                minval = t2<t3?t2:t3;
                minval = minval<t5?minval:t5;

                help.push_back(minval);
                if(minval==t2){
                    p2++;
                }
                if(minval==t3){
                    p3++;
                }
                if(minval==t5){
                    p5++;
                }                            
            }
            return minval;
        }    
    }
};