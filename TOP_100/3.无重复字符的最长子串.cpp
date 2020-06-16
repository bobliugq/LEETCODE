class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int maxLen = 1;
        int start = 0, end = 0;
        unordered_map<char, int> mp; 
        while (end < s.size()) {
            ++mp[s[end]];
            while (mp[s[end]] > 1) {
                --mp[s[start]];
                ++start;
            }
            maxLen = max(maxLen, end - start + 1);
            ++end;
        }
        return maxLen;
    }
};
