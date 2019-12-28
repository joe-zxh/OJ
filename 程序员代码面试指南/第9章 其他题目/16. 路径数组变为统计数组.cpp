#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int capital = -1;
	int dist;
	int pre, cur = 0, next, nn, level;
	while (cur < n) { // 路径数组改距离数组，但 距离是负数。边界很难code
		if (arr[cur] == cur) {
			capital = cur;
		}
		else if (arr[cur] >= 0) {
			next = arr[cur];
			arr[cur] = cur;// 回来的标记
			while (arr[next] != next && arr[next] >= 0) {
				nn = arr[next];
				arr[next] = cur;
				cur = next;
				next = nn;
			}
			capital = arr[next] == next ? next : capital;
			level = arr[next] < 0 ? arr[next] - 1 : -1;

			if (arr[cur] == cur) {
				arr[cur] = level--;
			}
			else {
				while (arr[cur] != cur) {
					next = arr[cur];
					arr[cur] = level--;
					cur = next;
				}
				arr[cur] = level--;
			}
		} // 负数不用管	
		cur++;
	}
	arr[capital] = 0;


	cur = 0;
	int i, t;

	while (cur < n) { // 距离数组改统计数组
		next = arr[cur];
		while (next <= 0) {

			if (-next <= cur) {
				if (arr[-next] < 0) {
					arr[-next] = 1;
				}
				else {
					arr[-next]++;
				}
				break;
			}

			nn = arr[-next];
			if (arr[-next] > 0) {
				arr[-next]++;
				break;
			}
			else {
				arr[-next] = 1;
			}
			next = nn;
		}
		cur++;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			printf("%d ", arr[i]);
		}
		else {
			printf("0 ");
		}
	}
	printf("\n");
	
	delete[]arr;
		
	return 0;
}