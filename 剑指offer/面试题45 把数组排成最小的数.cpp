class Solution {
public:
	static bool cmp(string a, string b) {
		return a+b < b+a;
	}

	string PrintMinNumber(vector<int> numbers) {
		int sz = numbers.size();
		if (sz == 0) {
			return "";
		}
		vector<string> v;

		for (int i = 0; i < sz; i++) {
			v.push_back(to_string(numbers[i]));
		}

		sort(v.begin(), v.end(), cmp);

		string res = "";

		for (int i = 0; i < sz; i++) {
			res = res + v[i];
		}
		return res;
	}
};