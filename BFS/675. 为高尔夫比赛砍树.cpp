/*
你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：

0 表示障碍，无法触碰
1 表示地面，可以行走
比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。

你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/cut-off-trees-for-golf-event
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        // 求出横纵坐标大小
        m = forest.size(), n = forest[0].size();
        // 存要砍的树的坐标
        vector<pair<int, int>> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 将树添加到坐标集合中
                if (forest[i][j] > 1) trees.emplace_back(i, j);
            }
        }
        // 用排序将所有坐标从小到大排序，用来确定坐标顺序
        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        // 第一次的出发坐标是[0, 0]
        int x = 0, y = 0, ans = 0;
        // 出发，开始找每一段的最小距离
        for (int i = 0; i < trees.size(); ++i) {
            // 使用bfs算法得出最小步数
            int step = bfs(forest, x, y, trees[i].first, trees[i].second);
            // 如果一段不可达，则不可能砍完所有的树，直接返回-1
            if (step == -1) return -1;
            // 更新下一次的出发坐标，下一次的出发坐标即这一次的目的坐标
            x = trees[i].first;
            y = trees[i].second;
            // 叠加步数
            ans += step;
        }
        return ans;
    }
private:
    int bfs(vector<vector<int>>& forest, int x, int y, int tx, int ty) {
        // 特判一下，出发地和目的地相同的情况
        if (x == tx && y == ty) return 0;
        // bfs标准模版，用一个队列来存坐标
        queue<pair<int, int>> q;
        q.push({x, y});
        // 用一个visit数组来避免一个点被重复走
        vector<vector<bool>> visit(m, vector<bool> (n, false));
        // 记得先把第一个点设置为已访问
        visit[x][y] = true;
        int step = 0;
        while (!q.empty()) {
            // 接下来所有被push进队列的都相当于现在的点走了一步
            ++step;
            // 当前队列中的所有点的step是相同的，它们的下一步点的步数也是相同的，因此一起处理
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    // 边界处理
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n ) continue;
                    // 避免重复走+题目的要求（0是不能走的点）
                    if (visit[nx][ny] || forest[nx][ny] == 0) continue;
                    // 找到了目的坐标，返回步数即可
                    if (nx == tx && ny == ty) return step;
                    // 队列加入下一个点
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        // 所有能访问的点都访问完了都没能到达目的坐标，就返回-1
        return -1;
    }
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    int m, n;
};
