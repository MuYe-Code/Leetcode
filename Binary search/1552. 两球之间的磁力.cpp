/*
在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有 n 个空的篮子，第 i 个篮子的位置在 position[i] ，Morty 想把 m 个球放到这些篮子里，使得任意两球间 最小磁力 最大。

已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为 |x - y| 。

给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。

例：
输入：position = [1,2,3,4,7], m = 3
输出：3
解释：将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3 
*/

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        //先排序
        sort(position.begin(),position.end());
        //maxMgns是可能的最大磁力，即恰好可以将m个球均匀分布
        int maxMgns=(position.back()-position[0])/(m-1);
        //minMgns是可能的最小磁力，初始化为m个球全部紧邻
        int minMgns=1;
        //要求最大的符合要求的间隔
        int ans=minMgns;
        int len=position.size();
        //二分查找符合要求的最大值
        while(minMgns<=maxMgns){
            int mid=minMgns+((maxMgns-minMgns)>>1);
            //count计数，next是下一个篮子的最小编号，即满足间隔不小于mid的最小编号
            int count=0,next=mid+position[0];
            for(int i=0;i<len;){
                //放一个球到当前篮子
                count++;
                next=mid+position[i];
                //寻找下一个篮子
                while(i<len && position[i]<next) i++;
            }
            //可以放入的球不足m，说明间隔过大
            if(count<m) maxMgns=mid-1;
            else{
                //若放入的球不少于m，说明还可以将间隔增大
                //注意：刚好放入m个球不一定就是最大的符合要求的解，例如[1,4,7]放三个球，1,2,3都是解
                ans=mid>ans?mid:ans;
                minMgns=mid+1;
            }
        }
        return ans; 
    }
};
