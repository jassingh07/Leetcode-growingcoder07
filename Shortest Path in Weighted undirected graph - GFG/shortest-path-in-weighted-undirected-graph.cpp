//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll           long long int
#define fl(i,m,n,p)  for(int i=m;i<n;i+=p)
#define bl(i,m,n,p)  for(int i=m,i>=n;i-=p)
#define pb(a)        push_back(a)
#define vi           vector<int>
#define all(v)       v.begin(),v.end()
#define vlli         vector<ll>
#define pi           pair<int, int>
#define si           set<int>
#define MOD          (int)(1e9+7)
#define plli         pair<ll,ll>
#define testin       ll t;cin >> t; while (t--)
#define fel(x,v)     for(auto &x:v)
#define print(x,v)   fel(x,v) cout<<x<<' '
#define FIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vvi          vector<vi>
#define vvlli        vector<vlli>
#define vc           vector<char>
#define vvc          vector<vc>
#define vb           vector<bool>
#define MIN_HEAP(T) priority_queue<T, vector<T>, greater<T>>
class Solution {
  public:
    
vi shortestPath(int n, int m, vector<vector<int>>& edges){
    vi res;
    vector<vector<vector<int>>> adj(n + 1);

    vector<pi> dis(n + 1, {1e9, -1});//unreachable from source and distance hence equals infinity
    fel(v, edges){
        adj[v[0]].push_back({v[1], v[2]});
        adj[v[1]].push_back({v[0], v[2]});
        // cout << adj[v[0]][0][0] << adj[v[0]][0][1]<< endl;
    }

    int src = 1;
    dis[src] = {0, src};
    MIN_HEAP(vi) pq;
    pq.push({0, src});

    while(pq.size()){
        int node = pq.top()[1];
        int cur = pq.top()[0];//minimum distance from src to this node
        pq.pop();
        for(auto &neb: adj[node]){
            // cout << cur << " " << neb[1] << " " << dis[neb[0]].first << endl;
            if(cur + neb[1] < dis[neb[0]].first) {
                dis[neb[0]] = {cur + neb[1], node};
                pq.push({dis[neb[0]].first, neb[0]});
            }
            
        }
    }//all distances reduced to minimmums
    

    int des = n;//destination
    if(dis[des].second == -1) //unreachable
        return {-1};
        // cout << " hello";
    while(dis[des].second != src){
        res.pb(des);
        des = dis[des].second;
    }
    res.pb(des);
    res.pb(src);

    reverse(all(res));
    return res;
}
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends