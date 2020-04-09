/*
统计回文
https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
*/
#include<iostream>
#include<string>
using namespace std;

bool IsReserve(const string& str)
{
    int begin = 0;
    int end = str.size() - 1;
    while (begin < end)
    {
        if (str[begin] == str[end])
        {
            begin++;
            end--;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int count = 0;
    for (int i = 0; i <= str1.size(); ++i)
    {
        string str = str1;
        str.insert(i, str2);
        if (IsReserve(str))
            ++count;
    }
    cout << count << endl;
    return 0;
}