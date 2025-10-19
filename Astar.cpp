#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
using namespace std;


class Kratka {
    public:
    int x;
    int y;
    float g;    // Koszt dotarcia do kratki
    float f;    // Funkcja f = g + h
    int rodzic_x;
    int rodzic_y;

    Kratka(const int x, const int y) {  // Konstruktor bez rodzica na potrzeby kratki start
        this->x = x;
        this->y = y;
    }

    Kratka(const int x, const int y, int rodzic_x, int rodzic_y, float g, float f) {  // Każda kratka dodawana do listy otwartej potrzebuje rodzica
        this->x = x;
        this->y = y;
        this->rodzic_x = rodzic_x;
        this->rodzic_y = rodzic_y;
        this->g = g;
        this->f = f;
    }
};



const int h = 6;
const int w = 6;
int arr[h][w] = {
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
vector<Kratka> zamknieta;


float wylicz_f(float g, float h) {
    return g + h;
}


float wylicz_h(int x, int y) {
    return sqrt(pow(x - cel.x, 2) + pow(y - cel.y, 2));
}


// Sprawdza czy można dodać kratkę do listy otwartej, zwraca:
// -1 jeżeli nie można dodać,
// 1 jeżeli można
// i jeżeli kratka znajduję się na liście otwartej
int sprawdz_sasiada(int x, int y) {
    if (arr[x][y] == 5) {
        return -1;
    }

    for (int i = 0; i < zamknieta.size(); i++) {
        if (zamknieta[i].x == x && zamknieta[i].y == y) {
            return -1;
        }
    }

    for (int i = 0; i < otwarta.size(); i++) {
        if (otwarta[i].x == x && otwarta[i].y == y) {
            return i;
        }
    }

    return 1;
}


void dodaj_sasiada(int x, int y, Kratka& aktualna_kratka) {  // Jeżeli możliwe dodaje do listy otwartej
    float g = aktualna_kratka.g + 1;
    float h = wylicz_h(x, y);
    float f = wylicz_f(g, h);
    int mozna_dodac = sprawdz_sasiada(x, y);

    if (mozna_dodac == 1) {
        otwarta.push_back(Kratka(x, y, aktualna_kratka.x, aktualna_kratka.y, g, f));
    }
    else if (mozna_dodac != -1 && f < otwarta[mozna_dodac].f) {   // Jeżeli f mniejsze to nowy rodzic i f
        otwarta[mozna_dodac].f = f;
        otwarta[mozna_dodac].g = g;
        otwarta[mozna_dodac].rodzic_x = aktualna_kratka.x;
        otwarta[mozna_dodac].rodzic_y = aktualna_kratka.y;
    }
}


int znajdz_kratka_z_min_f() {
    float f = otwarta[0].f;
    for (int i = 1; i < otwarta.size(); i++) {
        if (otwarta[i].f < f) {
            f = otwarta[i].f;
        }
    }

    for (int i = otwarta.size() - 1; i >= 0; i--) {
        if (otwarta[i].f == f) {
            return i;
        }
    }
    printf("Nie można znaleźć kratki z najmniejszym f");
    return -1;
}


Kratka znajdz_kratka(int x, int y) {
    for (int i = 0; i < zamknieta.size(); i++) {
        if (zamknieta[i].x == x && zamknieta[i].y == y) {
            return zamknieta[i];
        }
    }
    cout << "nie znaleziono kratki" << endl;
    return zamknieta[0];
}


int main() {
    zamknieta.push_back(start);
    if (arr[start.x][start.y] == 5) {
        printf("start jest na niedozwolonym polu (5)");
        return 0;
    }
    if (start.x == cel.x && start.y == cel.y) {
        printf("Start jest w tym samym miejscu co cel");
        return 0;
    }


    start.g = 0;
    start.f = 0;
    int x = start.x;
    int y = start.y;
    float f;
    int numer;
    Kratka aktualna_kratka = start;

    // szukanie najkrótszej drogi
    bool czy_cel_osiagniety = false;
    bool czy_pusta = false;
    while (!czy_cel_osiagniety && !czy_pusta) {

        // dodawanie do listy otwartej kratki rozważane jako pola do ekspansji góra, dół, lewo, prawo
        if (x - 1 >= 0) {
            dodaj_sasiada(x - 1, y, aktualna_kratka);
        }
        if (x + 1 < w) {
            dodaj_sasiada(x + 1, y, aktualna_kratka);
        }
        if (y - 1 >= 0) {
            dodaj_sasiada(x, y - 1, aktualna_kratka);
        }
        if (y + 1 < h) {
            dodaj_sasiada(x, y + 1, aktualna_kratka);
        }

        // Dodaj kratke z najmniejszą wartością f do zamkniętej i usuń z otwartej
        // Zaktualizuj aktualną kratkę
        numer = znajdz_kratka_z_min_f();
        aktualna_kratka = otwarta[numer];
        x = aktualna_kratka.x;
        y = aktualna_kratka.y;
        zamknieta.push_back(aktualna_kratka);
        otwarta.erase(otwarta.begin() + numer);

        czy_cel_osiagniety = zamknieta.back().x == cel.x && zamknieta.back().y == cel.y;
        czy_pusta = otwarta.empty();
    }

    if (czy_pusta) {
        printf("Nie istnieje droga do celu");
        return 0;
    }

    vector<Kratka> droga;
    while (aktualna_kratka.x != start.x || aktualna_kratka.y != start.y) {
        droga.push_back(aktualna_kratka);
        aktualna_kratka = znajdz_kratka(aktualna_kratka.rodzic_x, aktualna_kratka.rodzic_y);
    }
    droga.push_back(aktualna_kratka);

    for (int i = droga.size() - 1; i > 0; i--) {
        printf("(%d, %d) -> ", droga[i].x, droga[i].y);
    }
    printf("(%d, %d)", droga[0].x, droga[0].y);
    return 0;
}