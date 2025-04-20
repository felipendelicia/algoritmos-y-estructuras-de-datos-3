#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grid[i][j];
 
        if ((n + m - 1) % 2 != 0) {
            cout << "NO\n";
            continue;
        }
 
        // dp_min[i][j]: mínima suma posible hasta (i,j)
        // dp_max[i][j]: máxima suma posible hasta (i,j)
        vector<vector<int>> dp_min(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dp_max(n, vector<int>(m, INT_MIN));
 
        dp_min[0][0] = dp_max[0][0] = grid[0][0];
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) {
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i - 1][j] + grid[i][j]);
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i - 1][j] + grid[i][j]);
                }
                if (j > 0) {
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i][j - 1] + grid[i][j]);
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i][j - 1] + grid[i][j]);
                }
            }
        }
 
        // ¿El rango de suma final incluye al 0?
        if (dp_min[n - 1][m - 1] <= 0 && dp_max[n - 1][m - 1] >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}