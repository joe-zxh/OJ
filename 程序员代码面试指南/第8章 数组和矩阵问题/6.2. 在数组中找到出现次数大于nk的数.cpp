#include<iostream>
#include<map>
using namespace std;

void mapMinusOne(map<int, int> &cands) {
	map<int, int>::iterator temp, iter = cands.begin();
	while (iter != cands.end()) {
		if (iter->second == 1) {
			temp = iter;
			iter++;
			cands.erase(temp);
		}
		else {
			iter->second--;
			iter++;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];
	int times = 0;
	map<int, int> cands; // 最多有k-1个candidate key: cand value: cand出现的次数
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (cands.find(arr[i]) != cands.end()) {
			cands[arr[i]]++;
		}else if(cands.size()<k-1){
			cands[arr[i]] = 1;		
		}
		else { // cands.size()==k-1  凑齐k个，可以来删除一下了
			mapMinusOne(cands);
		}
	}

	map<int, int>::iterator iter = cands.begin();
	while (iter != cands.end()) {
		iter->second = 0;
		iter++;
	}

	for (int i = 0; i < n; i++) {
		if (cands.find(arr[i]) != cands.end()) {
			cands[arr[i]]++;
		}
	}

	bool isPrint = false;
	iter = cands.begin();
	while (iter != cands.end()) {
		if (iter->second > n / k) {
			isPrint = true;
			printf("%d ", iter->first);
		}
		iter++;
	}

	!isPrint ? printf("-1\n") : printf("\n");
	return 0;
}