#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


class Kratka {
    public:
    int x;
    int y;
    float f;
    Kratka* rodzic{}; //Klamerki są dlatego że inaczej nie działa

    Kratka(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    Kratka(const int x, const int y, Kratka* rodzic) {
        this->x = x;
        this->y = y;
        this->rodzic = rodzic;
    }

    friend bool operator==(const Kratka &lhs, const Kratka &rhs) {
        return lhs.x == rhs.x
               && lhs.y == rhs.y;
    }

    friend bool operator!=(const Kratka &lhs, const Kratka &rhs) {
        return !(lhs == rhs);
    }
};


int arr[10][10] = {
    {0, 0, 0, 0, 0, 0},
    {0, 5, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 0},
    {0, 0, 0, 5, 0, 0},
    {0, 0, 0, 0, 5, 0},
    {0, 0, 0, 0, 0, 0}
};
Kratka start(2, 1);
Kratka cel(1, 5);
vector<Kratka> otwarta;
vector<Kratka> zamknieta = {start};


float wylicz_f(int x, int y) {
    float h = sqrt(pow(x - cel.x, 2) + pow(y - cel.y, 2));
    return 1 + h;
}


bool sprawdz_sasiada(int x, int y) {
    if (arr[x][y] == 5) {
        return false;
    }

    for (int i = 0; i < otwarta.size(); i++) {
        if (otwarta[i].x == x && otwarta[i].y == y) {
            return false;
        }
    }

    for (int i = 0; i < zamknieta.size(); i++) {
        if (zamknieta[i].x == x && zamknieta[i].y == y) {
            return false;
        }
    }

    return true;
}


int main() {
    int x = start.x;
    int y = start.y;
    Kratka aktualna_kratka = start;
    while (zamknieta.back() != cel) {
        if (sprawdz_sasiada(x - 1, y)) {
            otwarta.emplace_back(x - 1, y, &aktualna_kratka);
        }
        if (sprawdz_sasiada(x + 1, y)) {
            otwarta.emplace_back(x - 1, y, &aktualna_kratka);
        }
        if (sprawdz_sasiada(x, y - 1)) {
            otwarta.emplace_back(x - 1, y, &aktualna_kratka);
        }
        if (sprawdz_sasiada(x, y + 1)) {
            otwarta.emplace_back(x - 1, y, &aktualna_kratka);
        }
    }

    return 0;
}
