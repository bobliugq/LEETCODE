// Time:        2020.4.8
// Topic:       Array and find
// Todo:        Summary all solution


// mini_heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int n : nums) {
            q.push(n);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};


// max_heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int n : nums) {
            q.push(n);
        }
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};
