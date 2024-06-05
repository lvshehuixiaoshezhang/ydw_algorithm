//单调队列比单调栈多了一个弹出队头罢了

#include<bits/stdc++.h>
using namespace std;

vector<int>st;
int main(){
    int n;
    cin>>n;
    int top = -1;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        while(top!=-1&&st[top]>=x)top--;
        st[++top] = x;
    }
}
