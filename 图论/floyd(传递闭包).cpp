/*

传递闭包的bitset优化
逻辑：d[i][j] |= d[i][k] && d[k][j]
我们压缩掉第二维，即剩余d[i]
直接d[i] |= d[j]即可
    不过需要j在外循环
    因为i要取到所有的情况




*/
#include <bits/stdc++.h>
using namespace std;
int n;
bitset<110> a[110];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            int x;

            cin>>x;
            a[i][j] = x;
        }

    for (int j = 1; j <= n; j++)//注意j循环在i循环外
        for (int i = 1; i <= n; i++)
            if (a[i][j])
                a[i] |= a[j];//bitset也挺好写的
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            putchar(a[i][j] + '0'), putchar(' ');
        putchar('\n');
    }
    return 0;
}