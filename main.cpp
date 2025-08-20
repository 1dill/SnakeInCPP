#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
using namespace std;
int w = 20, h = 20, score, x, y, fx, fy;
vector<pair<int, int>> s;
enum Dir { STOP, LEFT, RIGHT, UP, DOWN }d;
void init() {
    srand(time(0));
    d = STOP; x = w / 2; y = h / 2; s.push_back({ x,y });
    fx = rand() % w; fy = rand() % h; score = 0;
}
void draw() {
    system("cls");
    for (int i = 0; i < w + 2; i++)cout << "#"; cout << "\n";
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j == 0)cout << "#";
            bool p = false;
            for (int k = 0; k < s.size(); k++)
                if (s[k].first == j && s[k].second == i) { cout << (k == 0 ? "O" : "o"); p = true; }
            if (!p)cout << (j == fx && i == fy ? "F" : " ");
            if (j == w - 1)cout << "#";
        }
        cout << "\n";
    }
    for (int i = 0; i < w + 2; i++)cout << "#"; cout << "\n\n\n\n\n                           -        CURRENT SCORE :          " << score << "\n";
}
void input() {
    if (_kbhit())switch (_getch()) {
    case 'a': d = LEFT; break;
    case 'd': d = RIGHT; break;
    case 'w': d = UP; break;
    case 's': d = DOWN; break;
    }
}
void logic() {
    pair<int, int> prev = s[0]; pair<int, int> prev2;
    switch (d) { case LEFT: x--; break; case RIGHT: x++; break; case UP: y--; break; case DOWN: y++; break; }
                          if (x < 0 || x >= w || y < 0 || y >= h) { cout << "YOU LOST!\n"; exit(0); }
                          s[0] = { x,y };
                          for (int i = 1; i < s.size(); i++) { prev2 = s[i]; s[i] = prev; prev = prev2; }
                          if (x == fx && y == fy) { score++; s.push_back({ -1,-1 }); fx = rand() % w; fy = rand() % h; }
}
int main() {
    init();
    while (1) { draw(); input(); logic(); Sleep(100); }
}
