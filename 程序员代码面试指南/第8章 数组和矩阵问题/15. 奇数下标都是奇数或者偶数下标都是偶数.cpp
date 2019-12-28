#include <iostream>
using namespace std;

int main()
{
	int n, t;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int evenInd = 0, emax = n % 2 ? n - 1 : n - 2;
	int oddInd = 1, omax = n % 2 ? n - 2 : n - 1;

	while (evenInd <= emax && oddInd <= omax) { // 下标循环怼即可
		if (arr[evenInd] % 2) {
			while (oddInd <= omax && arr[oddInd] % 2) {
				oddInd += 2;
			}
			if (oddInd <= omax) {
				t = arr[evenInd];
				arr[evenInd] = arr[oddInd];
				arr[oddInd] = t;
				evenInd += 2;
			}
		}
		else {
			evenInd += 2;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	delete[]arr;	
	return 0;
}