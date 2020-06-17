#include <iostream>
#include <vector>
using namespace std;


int maxScoreSightseeingPair(vector<int>& A) {
    int maxLeft = A[0] + 0;
    int res = 0;
    for (int i = 1; i < A.size(); ++i) {
        res = max(res, A[i] - i + maxLeft);
        maxLeft = max(maxLeft, A[i] + i);
    }
    return res;
}


int main() {
    vector<int> A({8,1,5,2,6});
    cout << maxScoreSightseeingPair(A) << endl;
    return 0;
}
