class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        st.insert(n);
        while (1) {
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n = n / 10;
            }
            if (sum == 1) }
                return true;
            } else {
                n = sum;
            }
            if (st.find(n) != st.end()) {
                return false;
            } else {
                st.insert(n);
            }
        }
    }
};
