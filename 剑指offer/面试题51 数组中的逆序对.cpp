class Solution {
public:
    int M = 1000000007;

    void MergeSort(vector<int> &data, int &res) {
        int dsz = data.size();
        if(dsz==1 || dsz==0){
            return;
        }

        int mid = ((dsz-2)>>1);        
        vector<int> left(data.begin(), data.begin()+mid+1);
        vector<int> right(data.begin()+mid+1, data.end());

        MergeSort(left, res);
        MergeSort(right, res);

        // Merge
        int p1=0, p2 = 0, p3 = 0;
        int leftsz = left.size(), rightsz = right.size();

        while(p1<leftsz&&p2<rightsz){
            if(left[p1]<=right[p2]){
                data[p3++] = left[p1++];
            }else{ // 产生逆序对
                res = (res+leftsz-p1)%M;
                data[p3++] = right[p2++];
            }
        }
        
        while(p1<leftsz){
            data[p3++] = left[p1++];
        }
        while(p2<rightsz){
            data[p3++] = right[p2++];
        }
    }

    int InversePairs(vector<int> data) {
        int res = 0;
        MergeSort(data, res);
        return res;
    }
};