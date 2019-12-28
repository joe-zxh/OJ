#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, range;
	scanf("%d %d", &n, &range);
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int curRange = 0, need = 0;

	int i = 0;
	while(curRange < range) {
		if (i<n && v[i] <= curRange + 1) {
			curRange += v[i++];
		}
		else {
			curRange += (curRange + 1);
			need++;
		}
	}
	printf("%d\n", need);	
	return 0;
}