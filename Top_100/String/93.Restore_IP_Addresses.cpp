class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip = "";
        vector<string> res;
        dfs(s, 0, 0, ip, res);
        return res;
    }

    void dfs(string str, int start, int part,string ip,  vector<string>& res) {
        if (start == str.size() && part == 4) {
            ip.erase(ip.end() - 1);
            res.push_back(ip);
        }

        if (str.size() - start > (4 - part) * 3) return;
        if (str.size() - start < (4 - part)) return;
        int n = 0;
        for (int i = start; i < start + 3; ++i) {
            n = n * 10 + str[i] - '0';
            if (n <= 255) {
                ip += str[i];
                dfs(str, i + 1, part + 1, ip, res);
            }
            if (n == 0) break;
        }
    }
};
