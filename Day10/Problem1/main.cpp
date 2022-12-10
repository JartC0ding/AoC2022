#include <iostream>
#include <fstream>

using namespace std;

// supports 2 instructions:
// addx V (where v is a signed integer)
// noop does nothing

// signal strength is cycle_number * x value
// return the sum of signals for the 20th, 60th, 100th, 140th, 180th cycle
// if (cycle-20) % 40 compute and add

int x = 1;
bool valid(int i) {
    if ((i-20)%40 == 0) {
        cout << i << " " << x << " = " << x*i << endl;
        return true;
    }
    return false;
}

int main() {
    int sol = 0;
    ifstream f("input.txt");
    string ln;

    int cycles = 1;
    while (getline(f, ln)) {
        if (ln[0] == 'a') {
            // addx
            // everything after "addx " is a number
            string s = ln.substr(5);
            int i = stoi(s);

            if (valid(cycles+1)) {
                // if we have to check for an uneven clock cycle
                sol += (x*(cycles+1));
            }
            x += i;
            cycles+=2;
        } else {
            // nop
            cycles++;
        }

        if (valid(cycles)) {
            sol += (x*cycles);
        }
        if (cycles >= 220) break;
    }
    cout << sol << endl;
}
