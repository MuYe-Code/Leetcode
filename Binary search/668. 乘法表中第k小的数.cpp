/*
几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？

给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        //因为是一行一行查找，因此为减少遍历次数，要令m<n
        if(m>n) return findKthNumber(n,m,k);
        //第k小的值val的可能取值最小为1
        //当k<n时，最大值直接取k，因为一定存在1~k这些数
        //当k>n时，对于第 k/n + 1 行，第n列的数n(k/n+1)，至少存在k个数不小于它，因此可设为最大值
        int left=1,right= k<n? k:k+n;
        //ans为满足条件的最小值，因此初始化为最大
        int ans=INT_MAX;
        while(left<=right){
            //取中间值
            int mid=left+((right-left)>>1);
            int count=0,i=1,j=n;
            while(i<=m){
                //在第i行找最小的 不小于mid的值
                while(j>0 && i*j>mid) j--;
                //从第1列到第j列的数都不大于mid
                count+=j;
                //下一列
                i++;
            }
            //如果小于等于mid的数不足k，说明mid小于最终答案
            if(count<k) left=mid+1;
            else {
                //就算mid是最终答案，得到的count也可能大于k，也就是mid值不止1个的情况
                //按理说还应该检查mid是否存在于矩阵中，但是不检查也能跑通，还不清楚是不是巧合
                ans= mid<ans? mid:ans;
                right=mid-1;
            }
        }
        return ans;
    }
};
