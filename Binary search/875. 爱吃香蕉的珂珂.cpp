/*
珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。

珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //left是每次能吃的最少香蕉数，right是每次能吃的最大香蕉树
        int left=1, right=piles[0], len=piles.size(), mink=INT_MAX;
        //right取piles的最大值，能保证每一堆香蕉都能一次吃完
        for(int elem:piles){
            if(elem>right) right=elem;
        }

        //left取值使得最大一堆能在h小时吃完（只有1堆的情况时left即为答案，也可以直接设为1）
        //可以保证left足够大又不会超过最终的k值
        left=(right-1)/h + 1;
        //二分查找k值，寻找最小的满足能在h小时吃完的k值
        while(left<=right){
            int mid=left+((right-left)>>1);
            //tmph表示k=mid时吃完所有香蕉要花的时间
            int tmph=0;
            //k为mid，则吃完piles[i]需要(piles[i]-1)/mid+1小时
            for(int i=0;i<len;i++){
                tmph += ((piles[i]-1)/mid+1);
            }
            //时间超过h，则增大k
            if(tmph>h) left=mid+1;
            //否则，减少k
            else {
                //注意：tmph==h时不一定是最小k，可能有多个值满足刚好在h小时吃完
                mink= mid<mink? mid:mink;
                right=mid-1;
            }
        }

        return mink;
    }
};
