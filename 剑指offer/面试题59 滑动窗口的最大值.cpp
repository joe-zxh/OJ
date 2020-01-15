class Solution {
public:
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {

	int  sz = num.size();
	vector<int> vret;
	list <int> li;

	for (int  i = 0; i < sz; i++) {

		while (!li.empty() && num[li.back()] <= num[i]) {
			li.pop_back();
		}

		li.push_back(i);

		if (i >= size - 1) {
			while (li.front()+size <= i) {
				li.pop_front();
			}
			vret.push_back(num[li.front()]);
		}
	}

	return vret;
}
};