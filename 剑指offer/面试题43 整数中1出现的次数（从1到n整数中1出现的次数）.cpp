class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n < 1) {
            return 0;
        }
        if (n < 10) {
            return 1;
        }
        int mod = 10;
        int ans = 0;

        int k = 2; // 位数
        while (n / mod >= 10) {
            mod *= 10;
            k++;
        }
        ans += n / mod == 1 ? n%mod + 1 : mod; // 区分最高位是否为1
        ans += (k - 1)*(n / mod)*(mod / 10);
        return ans + NumberOf1Between1AndN_Solution(n%mod);
    }
};