//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long int
class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> A, vector<int> B) {
        ll res = 0, twop = 0, val = 1e9;
        for(int i = 0; i < A.size(); i++) {
            res += A[i] * (B[i] - B[i] % 2);
            if(B[i] / 2) val = min(val, (ll)A[i]);
            twop += B[i] / 2;
        }
        
        return res - (twop % 2 ? 2 * val : 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends