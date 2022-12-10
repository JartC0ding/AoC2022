#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int> calories_by_elv() {
    vector<int> ret(1,0);
    string filename("input.txt");
    ifstream input_file(filename);
    if (input_file.is_open()) {
        string tp;
        while(std::getline(input_file, tp)) {
            // newline found
            if (tp.compare("") == 0) {
                ret.push_back(0);
                continue;
            }
            ret[ret.size()-1] += stoi(tp);
        }
        input_file.close();
    }
    return ret;
}

void solution() {
    vector<int> i = calories_by_elv();
    cout << *max_element(i.begin(), i.end());
}

int main(void) {
    solution();
}
