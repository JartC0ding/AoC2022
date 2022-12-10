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
    // Q: general overlapp.
    // solution
    int sum = 0;

    elf_pairs parsed_input = parse_text("input.txt");
    for (auto i : parsed_input) {
        // 5,7 - 7,9
        // 7,9 - 5,7
        // any point has to be between a.x and a.y
        if (i.first.first <= i.second.first && i.first.second >= i.second.first) sum++; // b.x is contained in a
        else if (i.first.first <= i.second.second && i.first.second >= i.second.first) sum++; // b.y is contained in a
        else if (i.second.first <= i.first.first && i.second.second >= i.first.second) sum++;
        else if (i.second.first <= i.first.second && i.second.second >= i.first.first) sum++;
    }
    cout << sum << "\n";
}
