#include <bits/stdc++.h>

using namespace std;

bool checkIfXMAS(const vector<string>& matrix, int r, int c, int dr, int dc, int idx) {
    if (idx == string("XMAS").length())
        return true;
    if (r < 0 or r >= matrix.size() or c < 0 or c >= matrix[0].length())
        return false;
    if (matrix[r][c] != "XMAS"[idx])
        return false;

    return checkIfXMAS(matrix, r + dr, c + dc, dr, dc, idx+1);
}

int part_1(const vector<string>& matrix) {
    int m = matrix.size(), n = matrix[0].length();  
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1} , {-1, 1}, {1, 1}, {-1, -1}};
    
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            for (auto& [dr, dc] : dirs) {
                count += checkIfXMAS(matrix, i, j, dr, dc, 0);
            }

        }
    }

    return count;
}

int part_2(const vector<string>& matrix) {
    int m = matrix.size(), n = matrix[0].length();
    int count = 0;

    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            string a = "", b = "";

            a += matrix[i - 1][j + 1]; a += matrix[i][j];  a += matrix[i + 1][j - 1];
            b += matrix[i - 1][j - 1]; b += matrix[i][j];  b += matrix[i + 1][j + 1];

            if ( (a == "MAS" or a == "SAM") and (b == "MAS" or b == "SAM") ) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    freopen("../input/4.input", "r", stdin);

    vector<string> matrix;
    string s; 

    while (cin >> s) {
        matrix.push_back(s);
    }
    
    cout << part_1(matrix) << "\n";
    cout << part_2(matrix) << "\n";
}

