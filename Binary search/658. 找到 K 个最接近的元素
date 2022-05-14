/*
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len=arr.size();
        //数量不足
        if(len<=k) return arr; 
        int index = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        //区间起始及区间终点
        int left,right;
        //全都比x小
        if(index==len){
            return vector<int>(arr.end()-k,arr.end());
        }
        else{
            //初始区间为紧邻x的左侧k个值
            left= index<k? 0:index-k;
            right=left+k;
            //缓慢向右滑动窗口
            while(right<len && x-arr[left] > arr[right]-x){
                left++;right++;
            }
            return vector<int>(arr.begin()+left,arr.begin()+right);
        }
    }
};
