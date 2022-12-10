#include <iostream>
#include <fstream>

using namespace std;

void solution() {
    // simulare responses
    int sum = 0;
    string filename("input.txt");
    ifstream input_file(filename);
    if (input_file.is_open()) {
        string tp;
        while(std::getline(input_file, tp)) {
            // eval
            char turn1 = tp[0]-0x40;
            cout << (int)turn1 << endl;
            char outcome = tp[2];
            // a&x = rock
            // b&y = paper
            // c&z = scissors
            if (outcome == 'Y') sum += turn1 + 3; // draw
            else if (outcome == 'Z') {
                if(turn1 == 3) sum += 7;
                else sum += turn1 + 1 + 6; // won
            } else {
                if(turn1 == 1) sum += 3;
                else sum += turn1-1;
            }
        }
    }

    cout << sum << endl;
}

int main(void) {
    solution();
}
