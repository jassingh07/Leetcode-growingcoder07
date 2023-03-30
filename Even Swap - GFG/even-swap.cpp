//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector<int> lexicographicallyLargest(vector<int> &a,int n)
        {
            bool prev = a[0] % 2;
            bool cur = a[0] % 2;
            int start = 0;
            for(int i = 1; i < n; i++){
                cur = a[i] % 2;
                if(cur != prev) {
                    sort(a.begin() + start, a.begin() + i,greater<int>());
                    start = i;
                    prev = cur;
                }
            }
            sort(a.begin() + start, a.end(), greater<int>());
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends