#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    // Default filename if no argument is provided
    string inputFileName = "../run-io/input.txt";

    // Handle command line arguments for the input file
    if (argc > 1) {
        string arg = argv[1];
        // If the user didn't provide the path, prepend it
        if (arg.find("../run-io/") == string::npos && arg.find("../") != string::npos) {
            cout << "File must be in the ../run-io/ directory." << endl;
            return 1;
        } else if (arg.find("../run-io/") == string::npos) {
            inputFileName = "../run-io/" + arg;
        } else {
            inputFileName = arg;
        }
        cout << "Using input file: " << inputFileName << endl;
    } else {
        cout << "Please provide an input file." << endl;
        return 1;
    }

    ifstream fin(inputFileName);
    if (!fin.is_open()) {
        cerr << "Error: Could not open file " << inputFileName << endl;
        return 1;
    }

    // Prepare output file name based on input name
    string outputFileName = inputFileName.substr(0, inputFileName.find_last_of('.')) + "_output.txt";
    ofstream fout(outputFileName);

    int K;
    if (!(fin >> K)) return 0;

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
    
    cout << "String A: " << A << endl;
    cout << "String B: " << B << endl;

    // 1. Build the DP Table
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

    // 2. Backtracking to find the optimal subsequence
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        // If characters match, they are part of the optimal sequence
        if (A[i - 1] == B[j - 1]) {
            lcs += A[i - 1];
            i--;
            j--;
        } 
        // Otherwise, move in the direction of the higher value
        else if (memo[i - 1][j] > memo[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    // The string was built backwards, so reverse it
    reverse(lcs.begin(), lcs.end());

    // 3. Output Results
    fout << memo[n][m] << endl;
    fout << lcs << endl;

    cout << "Highest Value: " << memo[n][m] << endl;
    cout << "Optimal Subsequence: " << lcs << endl;
    cout << "Results saved to: " << outputFileName << endl;

    fin.close();
    fout.close();

    return 0;
}