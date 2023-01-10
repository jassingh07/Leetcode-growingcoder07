#define ll long long int
#define fl(i, m, n, p) for (ll i = m; i < n; i += p)
#define bl(i, m, n, p) for (ll i = m, i >= n; i -= p)
#define pb(a) push_back(a)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define vlli vector<ll>
#define vd vector<double>
#define si set<int>
#define MOD (ll)(1e9 + 7)
#define MOD2 (ll)(998244353)
#define plli pair<ll, ll>
#define testin ll t;  cin >> t; while (t--)
#define fel(x, v) for (auto x : v)
#define print(x, v) fel(x, v) cout << x << ' '
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vvi vector<vi>
#define vpi vector<pair<int, int>>
#define vplli vector<pair<ll, ll>>
#define pi pair<int, int>
#define vvlli vector<vlli>
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define endl "\n"
#define MIN_HEAP(T) priority_queue<T, vector<T>, greater<T>>
class Solution {
    ll fun(vector<vector<vector<ll>>> &adj, vlli& dis,ll node, vlli& dp){
        if(node == 0) return 1;

        if(dp[node] != -1) return dp[node];

        ll res = 0;
        for(auto &neb: adj[node]){
            if(dis[node] - neb[1] == dis[neb[0]]) 
                res = (res + fun(adj, dis, neb[0], dp)) % MOD;
        }

        return dp[node] = res;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<ll>>> adj(n);
        for(auto &e: roads)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        MIN_HEAP(vlli) pq;

        ll src = 0;
        ll des = n - 1;
        
        vlli dis(n, 1e18);
        dis[src] = 0;

        pq.push({0, src});
        while(pq.size()){
            ll curMin = pq.top()[0];
            ll node = pq.top()[1];
            pq.pop();
            for(auto &neb: adj[node]){
                if(curMin + neb[1]/*edge*/ < dis[neb[0]]){
                    dis[neb[0]] = curMin + neb[1];
                    pq.push({dis[neb[0]], neb[0]});//new path found
                }
            }
        }//end  while
        // cout << dis[des];
        vlli dp(n, -1);
        // return 1;
        return fun(adj, dis, des, dp);
    }
};