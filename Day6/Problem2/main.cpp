#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

bool unique_str(string s) {
    vector<bool> b(26, false);
    for (int i = 0; i < s.length(); i++) {
        if (b[(s[i]-0x61)]) return false;
        else b[(s[i]-0x61)] = true;
    }
    return true;
}

int solve(string s) {
    for(int i = 0; i < s.length()-14; i++) {
        string sub = s.substr(i, 14);
        if (unique_str(sub)) return i+14;
    }

    return -1;
}

int main() {
    string input;
    ifstream f("input.txt");
    getline(f, input);

    cout << solve(input) << endl;
}
