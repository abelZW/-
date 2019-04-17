/*
题目描述：已知某小镇的房子沿直线分布，给定一个有序整数数组arr，里面的每个镇代表小镇每栋房子的一维坐标点。现在需要建N个广告牌，广告牌只能建立在这些坐标点上，使得每个坐标点离广告牌的总距离最短，求这个最短的总距离。

输入描述：输入最后一个为N值，其余的为arr值，需要考生自行处理。

例如：输入1 2 3 4 5 1000 2，输出6。

解答：这是一条经典的动态规划的题目：

设置一个数组dis[i][j]
*/
#include<iostream>
using namespace std;
int main()
{
    int arr[100] = {0};
    int m = 0,n;            //n:小镇的个数  m:广告牌的个数
    int x,dis[100][100] = {0};
    int total[100][100] = {0};

    while(cin >> x)
        arr[m++] = x;
    n = arr[--m];
    for(int i = 0; i < m; i++)
    {
        for(int j = i; j < m; j++)
        {
            for (int k = i; k <= j; k++)
                dis[i][j] += abs(arr[(i + j) / 2]- arr[k]);
        }
    }
    
    for(int i = 0; i < m; i++)
        total[i][1] = dis [i][m-1];

    for (int i = 2; i <= n; i++)
    {
        for ( int j = 0;j < m; j++)
        {
            for ( int k = j;k  <= m-i; k++)
            total[j][i] = dis[j][k] + total[k+1][i-1];
        }
    }
    cout << total[0][n] << endl;
    return 0;
}