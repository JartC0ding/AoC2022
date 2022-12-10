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
            char turn2 = tp[2]-0x40;
            turn2 -= (0x58-0x41); // normalize

            // a&x = rock
            // b&y = paper
            // c&z = scissors
            if (turn1 == turn2) sum += turn2 + 3; // draw
            else if (turn1+1 == turn2 || (turn1 == 3 && turn2 == 1)) sum += turn2 + 6; // won
            else sum += turn2;
        }
    }

    cout << sum << endl;
}

int main(void) {
    solution();
}
