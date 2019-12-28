#include <iostream>
#include <string>
using namespace std;

// 非递归版本
int findstr2(string* strs, int left, int right, string aim) { // 二分来查找字符串aim
	
	if (aim == "0") {
		return -1;
	}
	int mid;

	while (left<=right) {
		if (left == right) {
			return strs[left] == aim ? left : -1;
		}
		mid = left + ((right - left) >> 1);

		if (strs[mid] != "0") {
			if (strs[mid] >= aim) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		else {//strs[mid] == "0"
			int ind = mid - 1;
			while (ind >= left) { // 注意：这里是>=left
				if (strs[ind] != "0") {
					if (strs[ind] >= aim) {
						right = ind;
						break;
					}
					else {
						left = mid + 1;
						break;
					}
				}
				ind--;
			}
			left = ind == left -1 ? mid + 1 : left; // 左边没有找到非空的字符串，那么搜索右边
		}
	}
	return -1;
}

int main()
{
	int n; string aim;
	cin >> n;
	cin >> aim;
	string* strs = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
	}
	cout << findstr2(strs, 0, n - 1, aim) << endl;
	delete[]strs;
	return 0;
}