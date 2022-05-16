/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。
*/

class Solution {
public:
    string intToRoman(int num) {
        //ans存放答案，Roman存放所有可能的符号
        string ans,Roman="IVXLCDM";
        //divide存放当前位的权重，cur存放当前位的数值
        int divide=1,cur;
        for(int n=log(num);n>=0;n--){
            divide=pow(10,n);
            cur=num/divide;
            //更新num
            if(cur!=0) num%=divide;
            //cur为9,4时特殊处理，当cur在4到9之间时，提出一个5，再处理剩下的
            //一定要注意cur=4或9时两次加法分开写，与字符串的加法规则有关
            if(cur==9) {ans+=Roman[2*n];ans+=Roman[2*(n+1)];continue;}
            if(cur==4) {ans+=Roman[2*n];ans+=Roman[2*n+1];continue;}
            if(cur<9 && cur>4) {ans+=Roman[2*n+1];cur%=5;}
            for(int i=0;i<cur;i++) ans+=Roman[2*n];
        }
        return ans;
    }
};
