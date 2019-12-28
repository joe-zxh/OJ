#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	map<int, int>sumPos;// key: sum, value: sum所在的位置

	long N, k, temp;
	k = 0;
	cin >> N;
		
	long sum=0;
	sumPos[sum] = -1;
	long len = 0;

	for (long i = 0; i < N; i++) {
		cin >> temp;

		if (temp == 1) {
			sum += 1;
		}
		else if (temp == 0) {
			sum += -1;
		}

		if (sumPos.find(sum)==sumPos.end()) {
			sumPos[sum] = i;
		}

		if (sumPos.find(sum - k) != sumPos.end()) {
			len = max(i - sumPos[sum - k], len);
		}
	}

	cout << len << endl;
	return 0;
}