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
    std::vector<int>::iterator fst;
    int first;
    std::vector<int>::iterator snd; 
    int second;
    std::vector<int>::iterator thd;
    int third;
    
    fst = max_element(i.begin(), i.end());
    first = *fst;
    i.erase(i.begin() + distance(i.begin(), fst));

    snd = max_element(i.begin(), i.end());
    second = *snd;
    i.erase(i.begin() + distance(i.begin(), snd));

    thd = max_element(i.begin(), i.end());
    third = *thd;
    i.erase(i.begin() + distance(i.begin(), thd));

    cout << first + second + third << endl;
}

int main(void) {
    solution();
}
