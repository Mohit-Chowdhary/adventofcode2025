#include <bits/stdc++.h>
using namespace std;

int main(){
    int noOfRollsAccesable = 0;
    vector<vector<char>> grid;
    string s;

    while (cin >> s && s != "$") {
        grid.push_back(vector<char>(s.begin(), s.end()));
    }

    int tables = grid.size();
    int entry  = grid[0].size();

    for (int i = 0; i < tables; i++) {
        for (int j = 0; j < entry; j++) {

            if (grid[i][j] != '@') continue;

            int totalsides = 0;

            if (i-1 >= 0 && grid[i-1][j] == '@') totalsides++;

            if (i+1 < tables && grid[i+1][j] == '@') totalsides++;

            if (j-1 >= 0 && grid[i][j-1] == '@') totalsides++;

            if (j+1 < entry && grid[i][j+1] == '@') totalsides++;

            if (i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == '@') totalsides++;

            if (i-1 >= 0 && j+1 < entry && grid[i-1][j+1] == '@') totalsides++;

            if (i+1 < tables && j-1 >= 0 && grid[i+1][j-1] == '@') totalsides++;

            if (i+1 < tables && j+1 < entry && grid[i+1][j+1] == '@') totalsides++;

            if (totalsides < 4) noOfRollsAccesable++;
        }
    }

    cout << "finallly we have " << noOfRollsAccesable << "\n";
}
