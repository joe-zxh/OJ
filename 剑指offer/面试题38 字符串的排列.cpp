class Solution {
public:
    void f(set<string> &v, string str, int ind){
        int sz = str.size();

        if(ind==sz-1){
            v.insert(str);
            return;
        }

        char t;
        for(int i = ind;i<sz;i++){
            t = str[ind];
            str[ind] = str[i];
            str[i] = t;

            f(v, str, ind+1);

            t = str[ind];
            str[ind] = str[i];
            str[i] = t;
        }	
    }

    vector<string> Permutation(string str) {
        vector<string> v;
        if(str==""){
            return v;
        }

        set<string> s;
        f(s, str, 0);
        v.assign(s.begin(), s.end());
        return v;
    }
};