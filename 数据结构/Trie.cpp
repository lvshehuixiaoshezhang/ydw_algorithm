#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
int son[N][26],idx;
char op[2];
char str[N];
int cnt[N];



void insert(char str[]){
    int p = 0;
    for(int i = 0;str[i];i++){
        int u = str[i]-'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;

}

int query(char str[]){
    int p = 0;
    for(int i = 0;str[i];i++){
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
