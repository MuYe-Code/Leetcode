/*
有效数字（按顺序）可以分成以下几个部分：

一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]

部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]

给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。
*/

class Solution {
public:
    bool isNumber(string s) {
        int len=s.length();
        //先检查是不是科学计数法
        auto pos=s.find('e');
        if(pos==-1) pos=s.find('E');
        //若e或E出现在首位，则不是有效数字
        if(pos==0) return false;
        //不是科学计数法
        if(pos==-1) {return OnlyNumber(s,0,len);}
        //是科学计数法，检查底数是否为整数或者小数，指数是否为整数
        else return OnlyNumber(s,0,pos)&&(OnlyNumber(s,pos+1,len)==1);
    }
private:
    //目标字符串是整数返回1，小数返回2，否则返回0
    int OnlyNumber(string s, int start, int end){
        //分别记录小数点和数字是否出现
        bool dotcount=false, numbercount=false;
        //若有正负号，则只能出现在首位
        if(s[start]=='+'||s[start]=='-') start++;
        for(;start<end;start++){
            if(s[start]=='.'){
                //小数点只能出现一次
                if(dotcount) return 0;
                else{dotcount=true;continue;}  
            }
            //不是小数点，也不是数字，则字符串不是有效数字
            else if(s[start]>'9'||s[start]<'0') return 0;
            //当前位是数字，标志位置为true
            else numbercount=true;
        }
        //如果没有非法字符，且有数字，那么当有小数点时返回2，没有时返回1
        return numbercount? dotcount+1:0;
    }
};
