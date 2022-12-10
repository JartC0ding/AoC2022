#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void solve(vector<vector<int> > trees) {
    int highest = 0;
    int sol = 0;
    // loop over each element. For each element that is not an edge explore each direction until you reach an edge. If until then all edges are smaller than the original then this tree is visible
    for (int row = 0; row < trees.size()-1; row++) {
        for (int col = 0; col < trees[0].size(); col++) {
            if (row == 0 || row == (trees.size()-2) || col == 0 || col == (trees[0].size()-1)) {
                // edge
                sol++;
            } else {
                bool flg1 = true;
                bool flg2 = true;
                bool flg3 = true;
                bool flg4 = true;
                int v1 = 0;
                int v2 = 0;
                int v3 = 0;
                int v4 = 0;

                // from bottom down
                for (int row2 = row-1; row2 >= 0; row2--) {
                    v1++;
                    if (trees[row2][col] >= trees[row][col]) {
                        flg1 = false;
                        break;
                    }
                }

                for (int row2 = row+1; row2 < trees.size()-1; row2++) {
                    v2++;
                    if (trees[row2][col] >= trees[row][col]) {
                        flg2 = false;
                        break;
                    }
                }

                for (int col2 = col-1; col2 >= 0; col2--) {
                    v3++;
                    if (trees[row][col2] >= trees[row][col]) {
                        flg3 = false;
                        break;
                    }
                }

                for (int col2 = col+1; col2 < trees[0].size(); col2++) {
                    v4++;
                    if (trees[row][col2] >= trees[row][col]) {
                        flg4 = false;
                        break;
                    }
                }

                int vd = v1*v2*v3*v4;
                if (vd > highest) highest = vd;
                if (flg1 || flg2 || flg3 || flg4) {
                    sol++;
                }
            }
        }
    }

    cout << highest << endl;
    cout << sol << endl;
}

int main() {
    // all edges must be visible.
    // 1. Parse the text as a 2d vector of integers
    // 2. For each that is no edge. check the neighbours if any neighbour is lower that tree is visible
    ifstream f("input.txt");
    string ln;
    
    vector<vector<int> > trees(1);
    int sol = 0;

    int cnt = 0;
    while(getline(f, ln)) {
        for(auto i : ln) {
            trees[cnt].push_back(i-'0');
        }
        trees.push_back(vector<int>());
        cnt++;
    }
    solve(trees);
}
