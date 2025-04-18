#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    int diag = 0;
    int anti_diag = 0;
    int cnt=0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            row[i] += grid[i][j];
            col[j] += grid[i][j];
            if(i == j) {
                diag += grid[i][j];
            }
            if(i + j == n - 1) {
                anti_diag += grid[i][j];
            }
        }

if(row[i]&&col[i]&&diag&&anti_diag){
    cnt++;


    }
    
    
}

return cnt;
}


int main(){


vector<vector<int>> grid= [[4,3,8,4],[9,5,1,9],[2,7,6,2]];

int ans =solve(grid);

cout << ans << endl;








    return 0;
}
