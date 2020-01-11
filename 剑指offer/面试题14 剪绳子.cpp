class Solution {
public:
    int cutRope(int number) {
        if(number<2){
            return 0;
        }
        if(number<=3){
            return number-1;
        }

        int res = 1;
        while(number>4){
            res*=3;
            number-=3;
        }
        return res*number;        
    }
};