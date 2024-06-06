/*
从小到大遍历，遍历到根号n即可
O(sqrt(n))
*/

#include<iostream>
#include<algorithm>
#include<vector>
 using namespace std;
 vector<int> get_divisors(int x){
    vector<int> res;
    for(int i=1;i<=x/i;i++){
        if(x%i==0){
            res.push_back(i);
            if(i!=x/i) res.push_back(x/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
 }
 int main(){
    int  n,x;
    cin>>n;
    while(n--){
        cin>>x;
        vector<int> ans=get_divisors(x);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
 }