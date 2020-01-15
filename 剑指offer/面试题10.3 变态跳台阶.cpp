class Solution {
public:
int jumpFloorII(int number) {
    number--;
    if(number==0){
        return 1;
    }
    int pow = 2;
    int res = 1;
    while(number){
        if((number&1)==1){
            res *= pow;
        }
        number>>=1;
        pow = pow*pow;
    }
    return res;
}
};