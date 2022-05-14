/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len=candidates.size();
        sort(candidates.begin(),candidates.end());
        int maxcycle=target/candidates[0];
        //dep表示本次查找长度为dep的目标
        for(int dep=1;dep<=maxcycle;dep++){
            vector<int> cur;
            backTracking(candidates,cur,target,0,dep,len);
        }
        return ans;
    }

    //index指向本轮查找开始下标，dep表示还需要多少个元素，len是candidates长度
    void backTracking(vector<int>& candidates, vector<int>& cur, int target, int index, int dep, int len){
        //终止条件
        if(dep==0){
            if(target==0) ans.push_back(cur);
            return;
        }

        //如果当前数超过maxNum，则后续匹配的最小值大于(dep-cur.size())个maxNum，一定超过目标值
        int maxNum=target/dep;
        //每次加入一个数
        int endIndex=len-dep;
        for(int i=index;i<=endIndex;i++){
            if(candidates[i]>maxNum) return;
            cur.push_back(candidates[i]);
            backTracking(candidates,cur,target-candidates[i],i+1,dep-1,len);
            //回溯
            cur.pop_back();
            //跳过重复
            while(i<endIndex && candidates[i]==candidates[i+1]) i++;
        }
    }

private:
    vector<vector<int>> ans;
};
