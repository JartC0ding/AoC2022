#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solve() {
    int sol = 0;

    ifstream my_file("input.txt");
    if(my_file.is_open()) {
        string rucksack;
        vector<bool> dp(52, false);
        int cnt = 0;
        while(getline(my_file, rucksack)) {
                // int the first round. set every element to true which exists in the rucksack. in the next round set all elements to false that are already true but aren't contained in the second rucksack. same thing for round 3. If round 3 is complete. reset
            int v;
            vector<bool> dp2 (52, false);
            for (char i : rucksack) {
                if (i <= 'z' && i >= 'a') v = (i-0x60);
                else v = ((i-64)+26);
                if (cnt == 0) dp[v-1] = true;
                if (dp[v-1]) dp2[v-1] = true;
            }
            for(int i = 0; i < dp.size(); i++) {
                dp[i] = dp2[i];
            }
            cnt++;

            cout << cnt << endl;
            if(cnt % 3 == 0) {
                if (cnt == 0) continue;
                for (int i = 0; i < dp.size(); i++) {
                    if (dp[i]) sol += i+1;
                    dp[i] = false;
                    cnt = 0;
                }
            }
        }
    }
    return sol;
}

int main(void) {
    cout << solve() << endl;
}

