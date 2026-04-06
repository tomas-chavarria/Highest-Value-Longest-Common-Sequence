#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int K;
    fin >> K;

    unordered_map<char, int> value;

    for (int i = 0; i < K; i++) {
        char c;
        int val;
        fin >> c >> val;
        value[c] = val;
    }

    string A, B;
    fin >> A >> B;

    int n = A.size();
    int m = B.size();

    // memo table
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + value[A[i - 1]];
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    // Output only the maximum valalue
    fout << memo[n][m] << endl;

    fin.close();
    fout.close();

    return 0;
}