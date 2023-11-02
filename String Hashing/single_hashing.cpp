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

const ll N = 20; // modify this(max string length);
const ll p = 31;
vector<ll> powers(N), hsh(N);

void precal()
{
    powers[0] = 1;
    for (int i = 1; i < N; i++)
        powers[i] = (powers[i - 1] * p) % mod;
}
//compute the string hashing
void compute_hash(string const &s)
{
    // abcdefbcdeh
    for (int i = 0; i < s.size(); i++)
        hsh[i + 1] = (hsh[i] + (s[i] - 'a' + 1) * powers[i]) % mod;
    ll x = (hsh[5] - hsh[2] + mod) % mod; // first "cde"
    x = (x * powers[11 - 2]) % mod;
    ll y = (hsh[10] - hsh[7] + mod) % mod; // lst "cde"
    y = (y * powers[11 - 7]) % mod;
    cout << x << ' ' << y << '\n';
    if (x == y)
        cout << "Yes\n";
    else
        cout << "No\n";
    //needed main code wrote here---

  
}

// count the unique substring
int count_unique_substrings(string const &s)
{
    int n = s.size();
    int cnt = 0;
    for (int l = 1; l <= n; l++)
    {
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++)
        {
            long long cur_h = (hsh[i + l] + mod - hsh[i]) % mod;
            cur_h = (cur_h * powers[n - i - 1]) % mod;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
void solve()
{
    string s;
    cin >> s;
    precal(); // power calculating
    compute_hash(s);
}

int main()
{
    fast;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}
