// Make a tree which has nodes (directories) that has it's sum and also leaves (files) which have a size.

#include <vector>
#include <fstream>


using namespace std;

struct dir {
    vector<int> files;
    dir* parent;
};

int main() {
    ifstream f("input.txt");
    string ln;
    getline(f, ln); // skip "$ cd /"
    dir my_dir;
    my_dir.parent = nullptr;
    dir current_dir = my_dir;

    while(getline(f, ln)) {
        if (ln[0] == '$') {
            // command
            // ignore ls
            if (!ln.compare("$ ls")) {
                continue;
            }
        } else {
            // output
            if (ln[0] <= '9' && ln[0] >= '0') {
                // file
                // split at space. first output is size
                my_dir.files.push_back();
            }
        }
    }

}
