/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*修改了数组内容
        //数字在[1,n]之间，数组长度为n+1，因此必然可以将数字i放到nums[i]
        //若nums[i]放的数字本就等于i，也就是产生了两个数对应一个位置，也就是重复数
        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
        */

        //n+1个数，取值范围[1,n]，只有一个重复，则必然是1到n各一个加上1个重复
        //假设重复数是k，则当1<m<k时，不大于m的数的数量是m;
        //则当k<=m<=n时，不大于m的数的数量是m+1;
        int left=1,right=nums.size()-1;
        while(left<right){
            int k=left+((right-left)>>1),count=0;
            for(int it: nums){
                if(it<=k) count++;
            }
            //count>k，说明重复数小于等于k，因此不能right=k+1
            if(count>k) right=k;
            //count=k，说明重复数大于k
            else left=k+1;
        }
        return left;
    }
};

//快慢指针 链接
https://leetcode.cn/problems/find-the-duplicate-number/solution/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d/
