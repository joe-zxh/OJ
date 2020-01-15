class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(n<=0||m<=0){
            return -1;
        }
        int newNum = 1; // 最后幸存的人的新编号为0
        for (int i = 2; i <= n; i++) { // 还剩2个人的时候
            int B = (m - 1) % i + 1;// 编号为B的人 报了m这个数
            newNum = (newNum <= i - B) ? B + newNum : newNum - i + B; // 计算旧编号
        }
        return newNum-1;
    }
};