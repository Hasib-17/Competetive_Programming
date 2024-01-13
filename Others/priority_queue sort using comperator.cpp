#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ul unsigned long long
#define dec greater<int>()
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first==b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int vis[10];
class cmp
{
public:
    int operator () (const pair<int,int> &a, const pair<int,int>&b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return vis[a.first] < vis[b.first];
    }
    
};

/*maximum times occurs number/pair  are priority first.
    input->
    2 5
    3 5
    2 10
    3 1
    3 5
    2 3
    1 2
    2 10
    output-> 2 four times-3 three times- 1 two times
    2 10
    2 10
    2 5
    2 3
    3 5
    3 5
    3 1
    1 2
    1 1
*/
void solve()
{
    int n;
    cin>>n;
    //vector<pair<int,int>>vp;
    //set<pair<int,int>,cmp>st;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        vis[x]++;
        //vp.push_back({x,y});
        //st.insert({x,y});
        pq.push({x,y});
    }
    //sort(all(vp),sortbysec);

    //for(auto ii : st)cout<<ii.first<<' '<<ii.second<<'\n';

    while(!pq.empty())
    {
        cout<<pq.top().first<<' '<<pq.top().second<<'\n';
        pq.pop();
    }
}
 
int main()
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
