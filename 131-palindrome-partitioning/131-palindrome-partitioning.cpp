class Solution {
private:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string s, vector<vector<string>>& ans, vector<string>& v) {
        if (s.size() == 0) {
            ans.push_back(v);
            return;
        }
        for (int i=0; i<s.size(); i++) {
            if (isPalindrome(s.substr(0, i+1))) {
                v.push_back(s.substr(0, i+1));
                helper(s.substr(i+1), ans, v);
                v.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        helper(s, ans, v);
        return ans;
    }
};