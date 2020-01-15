class Solution {
public:
	typedef int(*fun)(int);

	static int f0(int n) {
		return 0;
	}
	
	static int Sum_Solution(int n) {
		static fun func[2] = {f0, Sum_Solution};
		return n+func[!!n](n-1);
	}
};