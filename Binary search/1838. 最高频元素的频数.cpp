/*
元素的 频数 是该元素在一个数组中出现的次数。

给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。

执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。

链接：https://leetcode.cn/problems/frequency-of-the-most-frequent-element
*/

//排序+二分+滑动窗口
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        int ans=0;

        while(left<=right){
            //mid代表将前mid+1个数都增加到mid，这样nums[mid]的频数为mid+1
            int mid=left+((right-left)>>1);
            long long count=0, tmp=0;
            //计算将前mid+1个数都增加到mid所需要的操作次数count
            while(tmp<mid){
                count+=(nums[mid]-nums[tmp++]);
            }
            //如果操作次数在k次之内，则增大mid继续寻找
            if(count<=k) {
                left=mid+1;
                ans= mid>ans? mid:ans;
            }
            //若操作次数超过k次，则检查剩余数组是否有满足条件的组合
            else {
                bool flag=false;
                for(int i=mid+1;i<nums.size();i++){
                    int prev=i-1;
                    //移动窗口，去掉最左侧数据
                    count -= (nums[prev]-nums[prev-mid]);
                    //添加最右侧数据
                    count += mid*(nums[i]-nums[prev]);
                    //检查操作次数
                    if(count<=k){ left=mid+1; flag=true; break;}
                }
                if(flag) ans= mid>ans? mid:ans;
                else right=mid-1;
            }   
        }
        return ans+1;
    }
};
