/*
题目描述：找出输入字符串中的重复字符，再根据ASCII码把重复的字符从小到大排序。

例如：输入ABCABCdd，输出ABCd。
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    //getline(cin,s);
    cin >> s;
    int count[200] = {0};
    for (int i = 0;i < s.length();i++)
    {
        count[s.at(i)]++;
    }
    for (int i =0;i < 127; i++)
    {
        if(count[i] > 1)
            cout << (char)i;
    }
    return 0;
}