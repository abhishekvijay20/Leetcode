class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map, t_map;
        for (auto i: s) s_map[i]++;
        for (auto i: t) t_map[i]++;
        
        for (auto i: t_map) {
            if(s_map[i.first] == i.second) s_map.erase(i.first);
        }
        if (s_map.size() == 0) return true;
        return false;
    }
};