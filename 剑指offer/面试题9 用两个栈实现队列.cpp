class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int t;

        if(!stack2.empty()) {
        	t = stack2.top();
        	stack2.pop();
        	return t;
        }else{
        	if(stack1.empty()){
        		cout<<"queue is empty"<<endl;
        	}

        	while(!stack1.empty()){
        		t = stack1.top();
        		stack1.pop();
        		stack2.push(t);
        	}
        	t = stack2.top();
        	stack2.pop();
        	return t;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};