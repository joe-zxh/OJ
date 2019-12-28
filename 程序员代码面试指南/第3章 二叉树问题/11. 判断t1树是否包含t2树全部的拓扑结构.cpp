#include <iostream>

using namespace std;

bool check(int* tree1l, int* tree1r, int* tree2l, int* tree2r,
	int head1, int head2) {

	if (head2 == 0) {
		return true;
	}

	if (head1 == 0 || head1!=head2) {
		return false;
	}
	
	return check(tree1l, tree1r, tree2l, tree2r, tree1l[head1], tree2l[head2]) &&
		check(tree1l, tree1r, tree2l, tree2r, tree1r[head1], tree2r[head2]);
}

bool isContain(int *tree1l, int* tree1r, int *tree2l, int*tree2r, 
	int head1, int head2) {

	if (head2 == 0) {
		return true;
	}

	if (head1 == 0) {
		return false;
	}

	return check(tree1l, tree1r, tree2l, tree2r, head1, head2) || 
		isContain(tree1l, tree1r, tree2l, tree2r, tree1l[head1], head2) ||
		isContain(tree1l, tree1r, tree2l, tree2r, tree1r[head1], head2);
}

int main()
{
	int n1, root1, t;
	cin >> n1 >> root1;
	int* tree1l = new int[n1+1];
	int* tree1r = new int[n1+1];

	for (int i = 0; i < n1; i++) {
		cin >> t;
		cin >> tree1l[t] >> tree1r[t];
	}

	int n2, root2;
	cin >> n2 >> root2;
	int* tree2l = new int[n1+1];
	int* tree2r = new int[n1+1];

	for (int i = 0; i < n2; i++) {
		cin >> t;
		cin >> tree2l[t] >> tree2r[t];
	}

	if (n2 > n1) {
		printf("false\n");
	}
	else {
		if (isContain(tree1l, tree1r, tree2l, tree2r, root1, root2)) {
			printf("true\n");
		}
		else {
			printf("false\n");
		}
	}	
	delete[]tree1l, tree1r, tree2l, tree2r;
	return 0;
}