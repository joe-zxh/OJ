class Solution {
public:
    bool f(char* matrix, int rows, int cols, char* str, 
        int curi, int curj, int strInd, bool* isSet) {

        if(str[strInd]=='\0') {
            return true;
        }

        if(curi>=0&&curi<rows&&curj>=0&&curj<cols&&
                matrix[curi*cols+curj]==str[strInd]&&
                isSet[curi*cols+curj]==false){

            isSet[curi*cols+curj] = true;
            bool ret = false;

            ret = f(matrix, rows, cols, str, curi-1, curj, strInd+1, isSet) | 
            f(matrix, rows, cols, str, curi+1, curj, strInd+1, isSet) | 
            f(matrix, rows, cols, str, curi, curj-1, strInd+1, isSet) | 
            f(matrix, rows, cols, str, curi, curj+1, strInd+1, isSet);

            isSet[curi*cols+curj] = false;
            return ret;
        }else{
            return false;
        }
    }

    bool hasPath(char* matrix, int rows, int cols, char* str) {
        int sz = rows*cols;
        bool *isSet = new bool[sz];
        for (int i = 0;i<sz;i++) {
            isSet[i] = false;
        }

        for(int i = 0;i<rows;i++) {
            for(int j = 0;j<cols;j++){
                if(f(matrix, rows, cols, str, i, j, 0, isSet)) {
                    delete []isSet;
                    return true;
                }
            }
        }

        delete []isSet;
        return false;
    }
};