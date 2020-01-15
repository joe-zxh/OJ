class Solution {
public:
    int Add(int a, int b)
    {
        int res = a ^ b;
        int jin = (a & b) << 1;
        a = res;
        b = jin;
        while (b != 0) {
            res = a^b;
            jin = b = ((a & b) << 1);
            a = res;
        }
        return res;
    }
};