#include <iostream>
#include <fstream>

using namespace std;

// supports 2 instructions:
// addx V (where v is a signed integer)
// noop does nothing

// signal strength is cycle_number * x value
// return the sum of signals for the 20th, 60th, 100th, 140th, 180th cycle
// if (cycle) % 40 compute and add
// a single pixel is drawn each cycle
// position is = (cycles-1)-(lines*40)

int x = 1;
int cycles = 1;
int lines = 0;

void draw() {
    int pos = (cycles-(lines*40))-1;
    if (pos == x || pos == x-1 || pos == x+1) {
        cout << "#";
    } else {
        cout << ".";
    }
    if (cycles%40 == 0) {
        cout << endl;
        lines++;
    }
}

int main() {
    cout << "#";
    ifstream f("input.txt");
    string ln;

    while (getline(f, ln)) {
        if (ln[0] == 'a') {
            // addx
            // everything after "addx " is a number
            string s = ln.substr(5);
            int i = stoi(s);
            cycles++;
            draw();
            x += i;
            cycles++;
            draw();
        } else {
            // nop
            cycles++;
            draw();
        }

        if (cycles >= 240) break;
    }
}
