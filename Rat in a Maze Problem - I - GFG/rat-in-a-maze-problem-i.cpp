// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void helper(vector<vector<int>> &m, int n, vector<string>& ans, string s, int r, int c) {
        if (r < 0 || r >= n  || c <0 || c >= n || m[r][c] == 0) {
            return;
        }    
    
        if (m[r][c] == 1 && r == n-1 && c == n-1) {
            ans.push_back(s);
            return;
        }
    
        m[r][c] = 0;
        helper(m, n, ans, s + "D", r+1, c);
        helper(m, n, ans, s + "U", r-1, c);
        helper(m, n, ans, s + "L", r, c-1);
        helper(m, n, ans, s + "R", r, c+1);
        m[r][c] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s = "";
        helper(m, n, ans, s, 0, 0);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends