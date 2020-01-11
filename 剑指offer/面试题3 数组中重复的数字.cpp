class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		int t1, t2, i = 0;
		while (i < length) {
			if (numbers[i] != i) {
				if (numbers[numbers[i]] == numbers[i]) {
					*duplication = numbers[i];
					return true;
				}
				else {
					t1 = t2 = numbers[i];
					numbers[i] = numbers[t2];
					numbers[t2] = t1;
				}
			}
			else {
				i++;
			}
		}
		return false;
	}
};