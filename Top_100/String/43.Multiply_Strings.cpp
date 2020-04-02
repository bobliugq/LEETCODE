class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> sum(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; --i) {
            int n1 = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; --j) {
                int n2 = num2[j] - '0';
                int two_sum = sum[i + j + 1] + n1 * n2;
                sum[i + j] += two_sum / 10;
                sum[i + j + 1] = two_sum % 10;  
            }
        }
        
        string str = "";
        for (int i = 0; i < sum.size(); ++i) {
            if (i == 0 && sum[0] == 0) continue;
            str += to_string(sum[i]);
        }
        return str;
    }
};
