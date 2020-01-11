class Solution {
public:
    double Power(double base, int exponent) {
        if (base==0) {
            return 0;
        }
        if (exponent==0){
            return 1;
        }

        double res = 1;

        if(exponent<0){
            while(exponent++<0){
                res/=base;
            }
        }else{ // 正数exponent用快速求平方。负数怕会溢出，所以 还是一步一步求
            int t = 1;
            while(t){
                if(exponent&t){
                    res*=base;
                }
                t<<=1;
                base=base*base;
            }
        }
        return res;
    }
};