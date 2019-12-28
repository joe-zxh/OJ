#include <iostream>

using namespace std;

#define PRE(cur, n) (cur + n - 1) % n
#define NEXT(cur, n) (cur + 1) % n

void goodStart(long *oil, long *dist, long n) {
	if (n == 1) {		
		oil[0] - dist[0] >= 0?printf("1\n"):printf("0\n");
		return;
	}

	long* res = new long[n]; // -1表示还未判断，0表示非良好，1表示良好

	for (long i = 0; i < n; i++) {
		oil[i] -= dist[i]; // 转化为纯能
		res[i] = -1;
	}

	long L = 0, R = 1, N, lastSet=-1;
	long rest = oil[0];

	while (L!=R) { // O(N)内找到一个良好出发点
		if (rest >= 0) { // R往右扩			
			rest += oil[R];
			R = NEXT(R, n);				
		}
		else { // L往左扩
			L = PRE(L, n);
			rest += oil[L];
		}
	}

	// 从良好出发点往逆时针遍历，能扩到上一个良好出发点的就是良好出发点，否则不是
	// O(N)
	if (rest >= 0) { // 找到一个良好出发点
		long cur = L;
		rest = oil[cur]; // 上一个节点到 找到的良好出发点rest值
		
		while (res[cur] == -1) { // 还没设定值
			if (rest>=0) {
				res[cur] = 1;
				cur = PRE(cur, n);
				rest = oil[cur]; // 更新上一个良好出发点的位置
			}
			else { // 该节点不是良好出发点，下一个节点的rest要叠加
				res[cur] = 0;
				cur = PRE(cur, n);
				rest += oil[cur];
			}
		}
	}
	else { // 否则 所有点都不是良好出发点
		long cur = L;

		while (res[cur] == -1) { // 还没设定值
			res[cur] = 0;
			cur = PRE(cur, n);
		}
	}	

	for (long i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}

	delete[]res;
}

int main() {
	long n;
	cin >> n;
	long* oil = new long[n];
	long* dist = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> oil[i];
	}

	for (long i = 0; i < n; i++) {
		cin >> dist[i];
	}

	goodStart(oil, dist, n);
	return 0;
}