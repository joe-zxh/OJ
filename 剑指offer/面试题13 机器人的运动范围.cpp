class Solution {
public:
    int bitSum(int i, int j){
        int sum = 0;
        while(i){
            sum+=i%10;
            i/=10;
        }

        while(j){
            sum+=j%10;
            j/=10;
        }
        //cout<<sum<<endl;
        return sum;
    }

    void movingCountCore(int threshold, int rows, int cols,
                int curi, int curj, int *count, bool *isSet, int *isCheck){

        if(curi>=0&&curi<rows&&curj>=0&&curj<cols
        &&isSet[curi*cols+curj]==false){

            if(isCheck[curi*cols+curj]==-1){
                if(bitSum(curi, curj)<=threshold){
                    isCheck[curi*cols+curj] = 1;
                }else{
                    isCheck[curi*cols+curj] = 0;
                }
            }

            if(isCheck[curi*cols+curj]==1){
                *count=*count+1;
                isSet[curi*cols+curj] = true;
                movingCountCore(threshold, rows, cols, curi+1, curj, count, isSet, isCheck);
                movingCountCore(threshold, rows, cols, curi-1, curj, count, isSet, isCheck);
                movingCountCore(threshold, rows, cols, curi, curj+1, count, isSet, isCheck);
                movingCountCore(threshold, rows, cols, curi, curj-1, count, isSet, isCheck);
            }
        }
    }

    int movingCount(int threshold, int rows, int cols){
        int count = 0;
        int sz = rows*cols;
        bool *isSet = new bool[sz];
        int *isCheck = new int[sz]; // -1: unchecked 1: > threshold 0: <= threshold
        // 可能会出现一些重复 判断的位置，用空间换取一下
        for(int i = 0;i<sz;i++){
            isSet[i] = false;
            isCheck[i] = -1;
        }

        movingCountCore(threshold, rows, cols, 0, 0, &count, isSet, isCheck);
        delete []isSet, isCheck;
        return count;
    }
};