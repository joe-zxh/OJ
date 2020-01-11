class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int n = array.size(); // 行数
		int m = array[0].size(); // 列数

		int i = 0, j = m - 1;

		while (i < n&&j >= 0) {
			if (array[i][j] == target) {
				return true;
			}
			else if (array[i][j] < target) {
				i++;
			}
			else {
				j--;
			}
		}
		return false;
	}
};