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
ll big_mod(ll a, ll b) // a^b=3^17
{
    if (b == 0)
        return 1;
    if (b % 2)
        return (a % mod * big_mod(a, b - 1) % mod) % mod; // 3^1 * 3^16=3^17
    else
        return (big_mod(a, b / 2) % mod * big_mod(a, b / 2) % mod) % mod; // 3^8 * 3^8
}

//.....<------>....using this
ll binary_exponential(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a * 1LL) % mod;
        a = (a * a * 1LL) % mod;
        b = (b >> 1);
    }
    return res;
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll ans = big_mod(a, b);
    ll ans2 = binary_exponential(a, b);
}

int main()
{
    fast;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
