class Solution {
public:
void FindNumsAppearOnce(vector<int> arr,int* num1,int *num2) {
    int n = arr.size();

    int xxor = 0;
	for (int i = 0; i < n; i++) {
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
        *num1 = a;
        *num2 = b;
	}else{        
        *num1 = b;
        *num2 = a;
	}
}
};