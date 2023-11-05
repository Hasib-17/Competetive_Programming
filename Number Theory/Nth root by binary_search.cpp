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
double multiply(double mid, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
        ans *= mid;
    return ans;
}
void solve()
{
    double x, eps = 1e-7; // x er nth root find
    int n;
    cin >> x >> n;
    double l = 1, r = x, mid;
    while (r - l > eps)
    {
        mid = (r + l) / 2;
        if (multiply(mid, n) < x)
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(10) << l << '\n';
}

int main()
{
    fast;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
