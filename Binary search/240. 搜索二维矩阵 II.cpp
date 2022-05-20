/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
https://leetcode.cn/problems/search-a-2d-matrix-ii/
*/

//从右上角或者左下角看，该矩阵为一棵二叉搜索树
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int row = 0, col = matrix[0].size()-1;
        while(row<m && col>=0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};
