#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class outline {
public:
	bool up;
	long pos;
	long height;
	outline() {}
	outline(bool u, long p, long h) :up(u), pos(p), height(h) {}
};

bool cmp(outline a, outline b) {
	return a.pos < b.pos;// 按照位置排序即可
}

void getOutlines(vector<outline> &outlines) {
	long sz = outlines.size();

	map<long, long>help;// key: 高度  value: 当前对应高度的有多少个楼
	map<long, long>curHeight;// key: 位置  value: 高度

	sort(outlines.begin(), outlines.end(), cmp);

	bool up; long pos, height;
	for (long i = 0; i < sz; i++) { // 获得curHeight
		up = outlines[i].up;
		pos = outlines[i].pos;
		height = outlines[i].height;
		
		if (up == true) {
			if (help.find(height) == help.end()) {
				help[height] = 1;
			}
			else {
				help[height] += 1;
			}
		}
		else {
			help[height] -= 1;
			if (help[height] < 0) {
				printf("Fuck %d, %d\n", height, help[height]);
			}

			if (help[height] == 0) {
				help.erase(help.find(height));
			}
		}
		map<long, long>::iterator temp = help.end();
		if (temp == help.begin()) {
			curHeight[pos] = 0; // 最后一个元素需要设置一下为0
		}
		else {
			curHeight[pos] = (--temp)->first; // 因为map是按照key排序的，最后一个key就是当前的高度
		}		
	}

	// 从curHeight中构建返回值
	map<long, long>::iterator iter=curHeight.begin();

	long s = 0, e = 0;
	long h = 0;

	while (iter != curHeight.end()) {
		if (iter->second!=h) { // 高度发生变化
			e = iter->first;
			if (h != 0) {
				printf("%d %d %d\n", s, e, h);
			}
			s = e;
			h = iter->second;
		}
		iter++;
	}
}

int main() {
	long n;
	cin >> n;
	vector<outline> outlines;
	long a, b, c;

	for (long i = 0; i < n; i++) {
		cin >> a >> b >> c;
		outlines.push_back(outline(true, a, c));
		outlines.push_back(outline(false, b, c));
	}

	getOutlines(outlines);
	return 0;
}