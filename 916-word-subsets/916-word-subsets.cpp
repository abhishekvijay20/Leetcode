class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> m, temp;
        for (auto w2: words2) {
            temp.clear();
            for (int i=0; i<w2.size(); i++) {
                temp[w2[i]]++;
                if (m.find(w2[i]) != m.end()) {
                    m[w2[i]] = max(temp[w2[i]], m[w2[i]]);
                } else {
                    m[w2[i]] = temp[w2[i]];
                }
            }
        }
        
        
        for (auto w1: words1) {
            int cnt = 0;
            unordered_map<char, int> m_w1;
            for (int i=0; i<w1.size(); i++) {
                m_w1[w1[i]]++;   
            }
            for (auto i: m) {
                if (m_w1.find(i.first) != m_w1.end()) {
                    if (m_w1[i.first] >= m[i.first]){
                        cnt++;
                    }
                }
            }
            if (cnt == m.size()) ans.push_back(w1);
        }
        return ans;
    }
};