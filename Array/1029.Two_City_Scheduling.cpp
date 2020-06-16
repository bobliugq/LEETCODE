#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
    int res;
    int n = costs.size();
    // sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
    //    return a[0] - a[1] < b[0] - b[1];
    // });
    sort(costs.begin(), costs.end(), [](auto& c1, auto& c2){
        return c1[0] - c1[1] < c2[0] - c2[1];
    });
    for (int i = 0; i < n / 2; ++i) {
        res += costs[i][0] + costs[n - 1 - i][1];
    }
    return res;
}

void printVector(vector<vector<int>>& vect) {
    for (int i = 0; i < vect.size(); ++i) {
        printf("[%d, %d],", vect[i][0], vect[i][1]);
    }
    printf("\n");
}
int main() {
    int n;
    cin >> n;
    srand(time(NULL));
    vector<vector<int>> costs(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        costs[i][0] = rand() % 99;
        costs[i][1] = rand() % 150;
    }
    printVector(costs);
    int res = twoCitySchedCost(costs);
    cout << res << endl;
    return 0;
}
