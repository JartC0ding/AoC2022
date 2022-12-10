#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int solve(string s) {
    for(int i = 0; i < s.length()-4; i++) {
        if(s[i] != s[i+1] && s[i] != s[i+2] && s[i] != s[i+3]) {
            if (s[i+1] != s[i+2] && s[i+1] != s[i+3]) {
                if(s[i+2] != s[i+3]) {
                    return i+4;
                }
            }
        }
    }

    return -1;
}

int main() {
    string input;
    ifstream f("input.txt");
    getline(f, input);

    cout << solve(input) << endl;
}
