#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

typedef pair<int, int> point;

vector<point> visited (1, point(0,0));
int cnt = 1;


int sgn(double v) {
  return (v > 0) - (v < 0);
}

void eval(point head, point &tail) {
    int dx = head.first - tail.first;
    int dy = head.second - tail.second;

    if (abs(dx) == 2 || abs(dy) == 2) {
        tail.first += sgn(dx);
        tail.second += sgn(dy);
    }
    if (!count(visited.begin(), visited.end(), tail)) {
        cnt++;
        visited.push_back(tail);
    }
}

int main() {
       point head(0,0);
    point tail(0,0);

    ifstream f("input.txt");
    string ln;

    while(getline(f, ln)) {
        char direction = ln[0];
        int move = stoi(ln.substr(2, ln.length()));
        
        // t can only ever move once
        // so in the case T is diagonal to H. T has to move below H if, if and only if head moves up again. In other words it has to perform the same motion
        switch(direction) {
            case 'U': 
                {
                    for (int i = 0; i < move; i++) {
                        head.second++;
                        eval(head, tail);
                        
                    }
                }break;
            case 'D':
                {
                    for (int i = 0; i < move; i++) {
                        head.second--;
                        eval(head, tail);
                    }
                }break;
            case 'R':
                {
                    for (int i = 0; i < move; i++) {
                        head.first++;
                        eval(head, tail);
                    }
                }break;
            case 'L': 
                {
                    for (int i = 0; i < move; i++) {
                        head.first--;
                        eval(head, tail);

                    }
                }break;
        }
    }
    cout << cnt << endl;
}
