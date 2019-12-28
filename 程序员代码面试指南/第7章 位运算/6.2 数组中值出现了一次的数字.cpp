#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int xxor = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		xxor ^= arr[i];
	}
	int RMOInd = 0;
	int a = xxor;
	while ((a & 1) != 1) {
		RMOInd++;
		a >>= 1;
	}
	a = 0;
	for (int i = 0; i < n; i++) {
		if (((arr[i] >> RMOInd)&1) == 1) {
			a ^= arr[i];
		}		
	}
	int b = xxor ^ a;

	if (a < b) {
		printf("%d %d\n", a, b);
	}else{
		printf("%d %d\n", b, a);
	}

	delete[]arr;
	return 0;
}