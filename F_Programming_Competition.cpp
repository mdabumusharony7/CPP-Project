#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[200005];
int dp[200005][2];

void dfs(int u)
{
    dp[u][0] = dp[u][1] = 0;

    for (int v : adj[u])
    {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

    for (int v : adj[u])
    {
        dp[u][1] = max(dp[u][1], 1 + dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0]);
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            adj[i].clear();
            dp[i][0] = dp[i][1] = 0;
        }

        for (int i = 2; i <= n; ++i)
        {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }

        dfs(1);

        cout << max(dp[1][0], dp[1][1]) << endl;
    }

    return 0;
}
