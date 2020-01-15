class Solution {
public:
int GetNumberOfK(vector<int> data ,int k) {
    int sz = data.size();
    if(sz==0){
        return 0;
    }

    int start = 0, end = sz-1;
    int mid, firstInd, lastInd;

    while(true){
        if(start>end){
            return 0;
        }      

        mid = start+((end-start)>>1);
        if(data[mid]<k){
            start = mid+1;
        }else if(data[mid]>k){
            end = mid-1;
        }else if(data[mid]==k){
            if(mid==0 || (data[mid-1]!=k)){
                firstInd = mid;
                break;
            }else{
                end = mid-1;
            }
        }
    }

    start = firstInd;
    end = sz-1;
    while(true){
        if(start>end){
            return 0;
        }      

        mid = start+((end-start)>>1);
        if(data[mid]<k){
            start = mid+1;
        }else if(data[mid]>k){
            end = mid-1;
        }else if(data[mid]==k){
            if(mid==sz-1 || (data[mid+1]!=k)){
                lastInd = mid;
                break;
            }else{
                start = mid+1;
            }
        }
    }

    return lastInd-firstInd+1;
} 
};