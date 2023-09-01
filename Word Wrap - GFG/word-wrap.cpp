//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int memo(vector<int>& words, int w, int i, int left, vector<vector<int>>& dp){
    int n = words.size();
    if(i == n) return 0;
    if(words[i] > w) return 1e9;
    int& res = dp[i][left + 1];
    if(res != -1) return res;
    res = 0;
    int keep = 1e9;
    if(left >= words[i])
        keep = memo(words, w, i + 1, left - words[i]- 1, dp);
    int endLine = 1e9;
    if(left != w)
        endLine =  (left + 1) * (left + 1) + memo(words, w, i, w, dp);
    
    return res = min(keep, endLine);
}


    int solveWordWrap(vector<int>nums, int w) 
    { 
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(w + 2, -1));
        int res = memo(nums, w, 0, w, dp);
        return (res == 1e9 ? -1 : res);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends