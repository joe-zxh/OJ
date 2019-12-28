#include<iostream>
#include<string>
#include<map>
using namespace std;

int shortestContain(string str1, string str2) {
	int sz1 = str1.size(), sz2 = str2.size();
	if (str1 == "" || str2 == "" || sz1 < sz2) {
		return 0;
	}
	int res = ~(1<<31);

	map<char, int> m;// 欠债表，key: 字符 value：str1中还差几个
	map<char, int>::iterator iter;
	for (int i = 0; i < sz2; i++) {
		if (m.find(str2[i]) != m.end()) {
			m[str2[i]]++;
		}
		else {
			m[str2[i]] = 1;
		}
	}
	int L=0, R=0, t;
	int left = sz2; // 还剩多少个没有匹配
	
	while (L < sz1) {  // 从L开始的子串
		while (R < sz1) {
			iter = m.find(str1[R]);
			if (iter != m.end()) {
				if (iter->second > 0) {
					left--;
				}
				iter->second--;
			}
			if (left == 0) { // 扩到R不再欠债
				break;
			}
			R++;
		}

		if (R >= sz1) { // R扩完了，还在欠债
			break;
		}

		// L往右缩
		while (L<=R) {
			iter = m.find(str1[L++]);
			if (iter != m.end()) {
				iter->second++;
				if (iter->second == 1) {
					left++;
					break;
				}
			}
		}
		t = R - (L - 1) + 1;
		R++;
		res = t < res ? t : res;
	}

	return res==~(1 << 31)?0:res;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	cout << shortestContain(str1, str2) << endl;
	
	return 0;
}