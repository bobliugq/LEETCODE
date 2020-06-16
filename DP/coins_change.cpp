#include <iostream>
#include <vector>
using namespace std;




int coinChangeOne(int amount, vector<int>& coins) {    
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int& coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int coinChangeTwo(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int& coin : coins) {
        for (int i = 1; i <= amount; ++i) {
            if (i >= coin) {
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[amount];
}

int main() {
    // int n, amount;
    // cin >> n >> amount;
    //vector<int> nums(n, 0);
    // for (int i = 0; i < n; ++i) {
    //    nums[i] = rand() % 5;
    //    cout << nums[i] << " ";
    // }
    int amount1 = 11;
    vector<int> nums1({1, 2, 5});
    int amount2 = 5;
    vector<int> nums2({1, 2, 5});
    cout << coinChangeOne(amount1, nums1) << endl;
    cout << coinChangeTwo(amount2, nums2) << endl;
    return 0;
}

