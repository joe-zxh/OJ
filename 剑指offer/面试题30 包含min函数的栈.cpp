class Solution {
public:
	stack<int> st, minst;

    void push(int value) {
		st.push(value);
        if(minst.empty()){
			minst.push(value);
		}else{
			int curmin = minst.top();
			if(value<curmin){
				minst.push(value);
			}else{
				minst.push(curmin);
			}
		}
    }
    void pop() {
        if(st.empty()){
			cout<<"stack is empty!"<<endl;
		}else{
			st.pop();
			minst.pop();
		}
    }
    int top() {
        return st.top();
    }
    int min() {
        return minst.top();
    }
};