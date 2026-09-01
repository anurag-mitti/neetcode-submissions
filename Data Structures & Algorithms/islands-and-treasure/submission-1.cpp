class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int curstep = it.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == INT_MAX) {

                    grid[nr][nc] = curstep + 1;
                    q.push({{nr, nc}, curstep + 1});
                }
            }
        }
    }
};
