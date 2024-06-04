/*
知道完全二叉树吗？他可以使用数组存储，dfs序就是将一颗任意树存到数组上而已

参数解析：
In[i]：以节点i为根树的时间戳开头
Out[i]：以节点i为根树的时间戳结尾
Num[time]：时间为time的根节点

所以想要得到节点i的开头和结尾，访问in和out即可
比如节点2,只需要访问in[2]和out[2]即可得到在num上的位置（开头与结尾）

由于其连续区间的性质，所以可以配合很多东西去使用（线段树，树状数组，树链剖分等）
*/
#include<bits/stdc++.h>

using namespace std;
const int N = 1e3+10;
vector<int>num(N);
vector<int> node[N];
int in[N],out[N];
int Time = 0; //时间戳

void dfs(int now,int fa){
     in[now]=++Time;
     num[Time]=now;//生成新的线性结结构
     for(int i=0;i<node[now].size();i++)
          if(node[now][i]!=fa) dfs(node[now][i],now);
     out[now]=Time;
}