//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int q, vector<int> &A, vector<vector<int>> &Q) {
        vector<int> f(1e5 + 1, 0), suff(n, 0), res;
        for(int i = n - 1; i >= 0; i--){
            f[A[i]]++;
            suff[i] = f[A[i]];
        }
        for(auto v: Q){
            int cnt = 0;
            for(int i = v[0]; i <= v[1]; i++) cnt += suff[i] == v[2];
            res.push_back(cnt);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends