#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solve() {
    int sol = 0;

    ifstream my_file("input.txt");
    if(my_file.is_open()) {
        string rucksack;
        while(getline(my_file, rucksack)) {
            // create a vector that holds the converted rucksack values
            vector<int> v;
            for (char i : rucksack) {
                if (i <= 'z' && i >= 'a') v.push_back(i-0x60);
                else v.push_back((i-64)+26);
            }
            
            int right_idx = v.size()/2;

            for (int left_idx = 0; left_idx <= right_idx; left_idx++) {
                for (int i = right_idx; i < v.size(); i++) {
                    if (v[left_idx] == v[i]) {
                        sol += v[i];
                        left_idx = right_idx +1;
                        break;
                    }
                }
            }
        }
    }

    return sol;
}

int main(void) {
    cout << solve() << endl;
}
