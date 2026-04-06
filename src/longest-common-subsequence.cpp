#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// argc is the number of arguments, argv is an array of strings
int main(int argc, char* argv[]) {
    // Default filename if no argument is provided
    string inputFileName = "../run-io/input.txt";

    // Check if a filename was passed as an argument
    if (argc > 1) {
        if (string(argv[1]).substr(0, 10) != "../run-io/") {
            cout << "Please place file [" << string(argv[1]) << "] in the run-io folder and re-run." << endl;
            return 1;
        } else {
            inputFileName = "../run-io/" + string(argv[1]);
        }
        
        cout << "Using input file: " << inputFileName << endl;
    } else {
        cout << "No file specified. Defaulting to input.txt" << endl;
    }

    ifstream fin(inputFileName);
    if (!fin.is_open()) {
        cerr << "Error: Could not open file " << inputFileName << endl;
        return 1;
    }

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
    
    cout << "String A: " << A << ", String B: " << B << endl;

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

    fout << memo[n][m] << endl;
    cout << "Highest Value: " << memo[n][m] << endl;

    fin.close();
    fout.close();

    return 0;
}