class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
        if (board == target)
            return 0;

        set<vector<vector<int>>> vis;

        int n = 2, m = 3;

        int zeroRow = 0, zeroCol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    zeroRow = i;
                    zeroCol = j;
                    break;
                }
            }
        }

        queue<pair<vector<vector<int>>, pair<int, int>>> q;
        q.push({board, {zeroRow, zeroCol}});
        vis.insert(board);

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int steps = 0;

        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<vector<int>> currentBoard = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                        vector<vector<int>> nextBoard = currentBoard;
                        swap(nextBoard[x][y], nextBoard[nx][ny]);
                        if (vis.count(nextBoard))
                            continue;
                        if (nextBoard == target)
                            return steps + 1;
                        vis.insert(nextBoard);
                        q.push({nextBoard, {nx, ny}});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
