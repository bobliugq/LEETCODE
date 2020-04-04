class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string tmp = "";
        vector<string> stk;
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || ".") continue;
            if (tmp == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(tmp);
            }
        }
        string str = "";
        for (int i = 0; i < res.size(); ++i) {
            str += '/';
            str += stk[i];
        }
        return (str ? str : "/");
    }
};
