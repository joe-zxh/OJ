#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
 
bool comp(const string &a, const string &b)
{
    return (a+b).compare(b+a)<0;
}
 
int main()
{
    long n;
    cin >> n;
    vector<string> strs;
    string temp;
 
    for (long i = 0; i < n; i++) {
        cin >> temp;
        strs.push_back(temp);
    }
    sort(strs.begin(),strs.end(), comp);
     
    for (long i = 0; i < n; i++) {
        cout << strs[i];
    }
    cout << endl;
 
    return 0;
}