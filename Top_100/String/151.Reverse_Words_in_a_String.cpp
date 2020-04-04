class Solution {
public:
    void reverse(string s, int start, int end) {
        while (start < end) {
            char tmp = s[start];
            s[start++] = s[end];
            s[end--] = tmp;
        }
    }
    
    string reverseWords(string s) {
        int i = 0, j = 0;
        int l = 0;
        int wordCount = 0;
        while (true) {
            while (i < s.size() && s[i] == ' ') ++i;
            if (i == s.size()) break;
            if (wordCount) s[j++] = ' ';
            l = j;
            while(i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse(s, l, j - 1);
            ++wordCount;
        }
        s.resize(j);
        reverse(s, 0, j - 1);
        return s;
    }
};
