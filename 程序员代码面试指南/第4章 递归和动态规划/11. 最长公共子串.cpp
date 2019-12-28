#include <iostream>
#include <string>
 
using namespace std;
 
void longestCommonStr(string str1, string str2) {
 
    int sz1 = str1.size();
    int sz2 = str2.size();
    int longest, longI;
    int last, cur;
     
    longest = 0;
 
    for (int j = sz2 - 1; j >= 0; j--) { // 右上半区：从右往左，从左上往右下
        last = str1[0] == str2[j] ? 1 : 0;
        if (last > longest) {
            longest = last;
            longI = 0;
        }
        for (int i = 1; j + i < sz2&&i<sz1; i++) {
            cur = str1[i] == str2[j+i] ? last + 1 : 0;
            last = cur;
            if (cur > longest) {
                longest = cur;
                longI = i;
            }
        }
    }
 
    // 左下半区：从上往下，从左上往右下
    for (int i = 1; i < sz1; i++) {
        last = str1[i] == str2[0] ? 1 : 0;
        if (last > longest) {
            longest = last;
            longI = i;
        }
        for (int j = 1; i + j < sz1&&j<sz2; j++) {
            cur = str1[i + j] == str2[j] ? last + 1 : 0;
            last = cur;
            if (cur > longest) {
                longest = cur;
                longI = i+j;
            }
        }
    }
     
    if (longest == 0) { // 记得公共子串为空的时候，输出-1
        printf("-1");
    }
    else {
        for (int i = longI - longest + 1; i <= longI; i++) {
            printf("%c", str1[i]);
        }
    }  
    printf("\n");
}
 
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    longestCommonStr(str1, str2);
    return 0;
}
