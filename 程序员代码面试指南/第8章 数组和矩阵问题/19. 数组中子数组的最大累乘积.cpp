#include <iostream>
#include <algorithm>
using namespace std;

double maxMulti(double*arr, int n) {
	double res=arr[0];
	double maxMulti = arr[0];
	double minMulti = arr[0];
	double temp;
	for (int i = 1; i < n; i++) {
		temp = max(maxMulti * arr[i], max(minMulti * arr[i], arr[i]));
		minMulti = min(maxMulti * arr[i], min(minMulti * arr[i], arr[i]));
		maxMulti = temp;
		res = max(res, maxMulti);
	}
	return res;
}

int main()
{
	int n, t;
	cin >> n;
	double* arr = new double[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	printf("%.2lf\n", maxMulti(arr, n));

	delete[]arr;	
	return 0;
}