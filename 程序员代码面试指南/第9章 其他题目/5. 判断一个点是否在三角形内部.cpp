#include <iostream>
using namespace std;

double crossProd(double x1, double y1, double x2, double y2) {
	return x1*y2 - x2*y1;
}

bool isInsideTriangle(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) {
	bool sign; double c1, c2, c3;
	c1 = crossProd(x2 - x1, y2 - y1, x - x1, y - y1);
	c2 = crossProd(x3 - x2, y3 - y2, x - x2, y - y2);
	c3 = crossProd(x1 - x3, y1 - y3, x - x3, y - y3);

	if (c1 > 0 && c2 > 0 && c3 > 0 || c1 < 0 && c2 < 0 && c3 < 0) { // 有可能逆时针，有可能顺时针，只要符号都相同即可
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	double x1, y1, x2, y2, x3, y3, x, y;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
	if (isInsideTriangle(x1, y1, x2, y2, x3, y3, x, y)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}