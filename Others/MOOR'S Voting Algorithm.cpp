#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long int
#define ul unsigned long long
#define dec greater<int>()
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
// find the mejority elements into the array O(n) times and O(1)space. ele>n/2 times
// [1,2,2,3,2,1,2,2] ...output:2
void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &i : v)cin>>i;

    int cnt=0,val=0;

    for(auto &i : v)
    {
        if(cnt==0)
            val = i;
        cnt+=(val==i)?1:-1;
    }
    cnt=0;
    for(auto ii : v)cnt+=(ii==val);

    if(cnt>n/2)
        cout<<val<<'\n';
    else cout<<-1<<'\n';
}
 
signed main()
{
    fast;    
    int t=1;
    //cin>>t;
    while(t--)
      solve();
}
 
 
/*You need to learn from the problem you solved.*/
/*If you got it slow, why? If you got WA, why?*/
/*What can you do to prevent it in the future?*/
/*Did you miss a critical observation?*/
/*What path of thinking would've led you there? */
