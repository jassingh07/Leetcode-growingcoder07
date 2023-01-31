//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int longestCommonSubstr (string nums1, string nums2, int n, int m)
    {
        int ans = 0;
        vector<int> dp(m + 1, 0);
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j < m; j++){
                if(nums1[i] == nums2[j]) dp[j] = 1 + dp[j + 1];
                else dp[j] = 0;
                ans = max(ans, dp[j]);
            }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends