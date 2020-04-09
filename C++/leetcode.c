1. 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
https://leetcode-cn.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string str) {
        int i = 0;
        if(str.length() == 0)
            return NULL;
        for(i = 0; i < str.length(); i++)
        {
            if(str[i] >= 65 && str[i] <= 90)
                str[i] = str[i] + 32;
        }
        return str;
    }
};

2. 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
https://leetcode-cn.com/problems/rotate-array/





