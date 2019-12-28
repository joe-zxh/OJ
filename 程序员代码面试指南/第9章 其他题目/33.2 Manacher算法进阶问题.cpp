#include <iostream>
#include <algorithm>
using namespace std;

char* str;

void getManStr(string str1) {
	long sz1 = str1.size();
	str = new char[2*sz1+1];
	str[0] = '#';
	long ind = 1;
	for (long i = 0; i < sz1; i++) {
		str[ind++] = str1[i];
		str[ind++] = '#';
	}
}

long Manacher(string str1) {
	getManStr(str1);
	long sz = str1.length() * 2 + 1;

	long* pArry = new long[sz]; // 回文半径数组
	long maxRad = 1;

	long C = -1, R = -1; // 边界不包括

	bool couldBreak = false;
	long i;

	for (i = 0; i < sz && !couldBreak; i++) {
		pArry[i] = i < R ? min(R-i, pArry[2*C-i]): 1;
		while (i+pArry[i]<sz&&i-pArry[i]>-1) {
			if (str[i+pArry[i]]==str[i-pArry[i]]) {
				pArry[i]++;
				if (i + pArry[i] == sz) {
					couldBreak = true;//找到了包括最后一个字符的最长回文
				}
			}
			else {
				break;
			}
		}
		if (i + pArry[i] > R) {
			R = i + pArry[i];
			C = i;
		}
		maxRad = max(maxRad, pArry[i]);
	}
	i--;
	for (long iter = i - pArry[i]; iter >= 0; iter-=2) {
		printf("%c", str[iter]); // 逆序打印即可
	}

	delete[]pArry;
	delete[] str;
	return maxRad - 1;
}

int main() {
	string str;
	cin >> str;

	Manacher(str);
	return 0;
}