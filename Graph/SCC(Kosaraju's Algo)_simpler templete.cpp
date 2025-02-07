#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define int long long int
#define dec greater<int>()
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
const int inf = 2e9 + 5;
//pikel_rik code
vector<int> g[100001], grev[100001], scc[100001];
int cost[100001], f[100001];
int cur = 0;

bool visited[100001];
int s = 0;

void dfs(int x)
{
    visited[x] = true;

    for (int &i : grev[x])
    {
        if (!visited[i])
            dfs(i);
    }

    cur += 1;
    f[cur] = x;
}

void dfs2(int x)
{
    visited[x] = true;
    scc[s].push_back(x);

    for (int &i : g[x])
    {
        if (!visited[i])
            dfs2(i);
    }
   // scc[s].push_back(x);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        grev[v].push_back(u);
    }

    fill(visited, visited + n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    fill(visited, visited + n + 1, false);
    int Scc = 0;
    for (int i = n; i >= 1; i--)
    {
        if (!visited[f[i]])
        {
            Scc++;
            s = f[i];
            dfs2(f[i]);
        }
    }

    cout << "number of scc: " << Scc << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (!scc[i].empty())
        {
            cout << "scc : ";
            for (int &x : scc[i])
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}
signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}
