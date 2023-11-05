// بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long int
#define ul unsigned long long
#define dec greater<int>()
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
//-3 1 3 2 -1 5 4 -4 6 7[k size sub-array er max element].
// using multiset / dequeue
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> v(n), ans;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // multiset<int, greater<int>> s;//O(nlogn)
    // for (int i = 0; i < k; i++)
    //     s.insert(v[i]);
    // ans.push_back(*s.begin());
    // // cout << *s.begin() << '\n';
    // for (int i = k; i < n; i++)
    // {
    //     s.erase(v[i - k]);
    //     s.insert(v[i]);
    //     ans.push_back(*s.begin());
    // }
    deque<int> dq;//O(n)
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] > v[dq.front()])
            dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(v[dq.front()]);
    // cout << v[dq.front()] << '\n';
    for (int i = k; i < n; i++)
    {
        if (i - k == dq.front())
            dq.pop_front();
        while (!dq.empty() && v[i] > v[dq.front()])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(v[dq.front()]);
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
