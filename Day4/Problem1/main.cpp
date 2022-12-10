#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<pair<pair<int, int>, pair<int, int> > > elf_pairs;

elf_pairs parse_text(string fname) {
    elf_pairs sol;
    ifstream my_file(fname);
    string ln;
    if (my_file.is_open()) {
        // split each line at comma
        // split each of the 2 produced outputs at a - and convert into pairs
        while(getline(my_file, ln)) {
            stringstream sstr(ln);
            string pair1;
            string pair2;
            getline(sstr, pair1, ',');
            getline(sstr, pair2);

            string pair11;
            string pair12;
            string pair21;
            string pair22;
            stringstream sp1(pair1);
            stringstream sp2(pair2);

            getline(sp1, pair11, '-');
            getline(sp1, pair12);

            getline(sp2, pair21, '-');
            getline(sp2, pair22);

            pair<pair<int, int>, pair<int, int> > outer;
            outer.first.first = stoi(pair11);
            outer.first.second = stoi(pair12);
            outer.second.first = stoi(pair21);
            outer.second.second = stoi(pair22);
            sol.push_back(outer);
        }
    }
    return sol;
}

int main() {
    // q: in how many sets does one set fully contain the other
    // 1. parse sets to be represented as a pair of pairs. -> ((1,6),(3,5)) ((3,5),(1,6))
    // 2. if the lower bound is >= than the other lower bound and the upper bound is <= to the other upper bound, there is full overlapp
    // solution
    int sum = 0;

    elf_pairs parsed_input = parse_text("input.txt");
    for (auto i : parsed_input) {
        if (i.first.first <= i.second.first && i.first.second >= i.second.second) sum++; // b is contained in a
        else if (i.first.first >= i.second.first && i.first.second <= i.second.second) sum++;
    }
    cout << sum << "\n";
}
