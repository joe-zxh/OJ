class Solution {
public:
    void printLtR(vector<vector<int> > matrix, int x1, int y1, int x2, int y2, vector<int>&v){
        for(int j = y1;j<y2;j++){
            v.push_back(matrix[x1][j]);
        }
    }

    void printUtD(vector<vector<int> > matrix, int x1, int y1, int x2, int y2, vector<int>&v){
        for(int i = x1;i<x2;i++){
            v.push_back(matrix[i][y2]);
        }
    }

    void printRtL(vector<vector<int> > matrix, int x1, int y1, int x2, int y2, vector<int>&v){
        for(int j = y2;j>y1;j--){
            v.push_back(matrix[x2][j]);
        }
    }

    void printDtU(vector<vector<int> > matrix, int x1, int y1, int x2, int y2, vector<int>&v){
        for(int i = x2;i>x1;i--){
            v.push_back(matrix[i][y1]);
        }
    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int rows = matrix.size();
        if(rows==0){
            return res;
        }

        int cols = matrix[0].size();
        int x1=0, y1=0, x2, y2;

        while(x1<=(rows-1)/2&&y1<=(cols-1)/2){
            x2 = rows-x1-1;
            y2 = cols-y1-1;

            // todo: 打印一条线的情况
            if(x1==x2){
                for(int j = y1;j<=y2;j++){
                    res.push_back(matrix[x1][j]);
                }
            } else if(y1==y2){
                for(int i = x1;i<=x2;i++){
                    res.push_back(matrix[i][y1]);
                }
            } else {
                printLtR(matrix, x1, y1, x2, y2, res);
                printUtD(matrix, x1, y1, x2, y2, res);
                printRtL(matrix, x1, y1, x2, y2, res);
                printDtU(matrix, x1, y1, x2, y2, res);             
            }                
            x1++;y1++;
        }
        return res;
    }
};