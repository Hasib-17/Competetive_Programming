
#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long int
#define dec greater<int>()
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
 
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    vector<vector<int>> scc(n);
    vector<int> visited(n), order(n), signal(n), claimed(n);
    int timer = 0;
    vector<int> S;
    vector<int> topo;
    auto tarjan = [&](auto &&self, int x) -> void
    {
        S.push_back(x);
        signal[x] = order[x] = timer++;
        visited[x] = 1;
        for (int y : g[x])
        {
            if (!visited[y])
                self(self, y);
            if (!claimed[y])
                signal[x] = min(signal[x], signal[y]);
        }
        if (signal[x] == order[x])
        {
            while (true)
            {
                int y = S.back();
                S.pop_back();
                scc[x].push_back(y);
                claimed[y] = 1;
                if (x == y)
                    break;
            }
            topo.push_back(x);
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            tarjan(tarjan, i);
        }
    }

    reverse(all(topo));

    cout <<"Number of scc: "<<topo.size() << '\n';
    for (int x : topo)
    {
        //cout << scc[x].size() << ' ';
        cout<<"scc : ";
        for (int y : scc[x])
        {
            cout << y << ' ';
        }
        cout << '\n';
    }
}
 
signed main()
{
    fast;    
    int t=1;
    //cin>>t;
    while(t--)
      solve();
}
