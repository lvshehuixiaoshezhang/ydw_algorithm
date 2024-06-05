/*
多串匹配前后缀，大概率就要用Trie
N的大小为数组中字符长度之和（可能也是二进制位数之和）


*/

#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
int son[N][26],idx;
char op[2];
char str[N];
int cnt[N];
void insert(string str){
    int p = 0;
    for(int i = 0;i<str.size();i++){
        int u = str[i]-'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;//非核心代码

}

int query(string str){
    int p = 0;
    for(int i = 0; i<str.size();i++){
        int u = str[i]-'a';
        if(!son[p][u])return 0;//如果该trie连str子串都没有，就退出
        p = son[p][u];
    }
    return cnt[p];

}
int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%s",op);
        scanf("%s",str);
        if(!strcmp(op,"I")){
            insert(str);
        }
        else{
            cout<<query(str)<<endl;
        }
    }
}
