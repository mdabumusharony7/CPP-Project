#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<string> polygon;
vector<vector<bool>> visited;

void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || polygon[x][y] == '*')
    {
        return;
    }
    visited[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int countWaysToHit()
{
    int ways = 0;
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j] && polygon[i][j] == '.')
            {
                dfs(i, j);
                ways++;
            }
        }
    }
    return ways;
}

int main()
{
    int k;
    cin >> n >> m >> k;

    polygon.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> polygon[i];
    }

    int result = countWaysToHit();
    cout << result << endl;

    return 0;
}
