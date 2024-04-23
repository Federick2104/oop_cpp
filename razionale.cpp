#include <iostream>
#include <fstream>
using namespace std;

class Razionale {
private:
    int n;
    int d;

    Razionale somma(const Razionale& other) const {
        Razionale risultato(this->n * other.d + this->d * other.n, this->d * other.d);
        return risultato;
    }

public:
    Razionale() {
        this->n = 1;
        this->d = 1;
    }

    Razionale(int n) {
        this->n = n;
        this->d = 1;
    }

    Razionale(int num, int den) {
        this->n = num;
        if (den == 0) {
            cout << "Errore: denominatore uguale a zero" << endl;
            this->d = 1;
        } else
            this->d = den;
    }

    void leggi(istream& sorg) {
        int num, den;
        char sep;
        sorg >> num >> sep >> den;
        this->n = num;

        if (den == 0) {
            cout << "Errore: denominatore uguale a zero" << endl;
            this->d = 1;
        } else
            this->d = den;
        return;
    }

    Razionale operator+(const Razionale& other) const {
        return this->somma(other);
    }
 
    Razionale operator+(int other) const {
        Razionale that(other, 1);
        return *this + that; // (*this).operator+(that)
    }

    bool operator>(const Razionale& other) {
        return this->n * other.d > this->d * other.n;
    }

    int& operator[](int idx) {
        if (idx == 0)
            return this->n;
        else if (idx == 1)
            return this->d;
        else {
            cout << "Errore: indice invalido" << endl;
            return this->n;
        }
    }

    // prefix
    Razionale operator++() {
        *this = *this + 1;
        return *this;
    }

    //post-fix
    Razionale operator++(int) {
        Razionale result = *this;
        *this = *this + 1;
        return result;
    }    

    void stampa(ostream& dest) const {
        dest << this->n << "/" << this->d << endl;
    }
};

ostream& operator<<(ostream& dest, const Razionale& r) {
    r.stampa(dest);
    return dest;
}

istream& operator>>(istream& sorg, Razionale& r) {
    r.leggi(sorg);
    return sorg;
}

Razionale operator+(int i, const Razionale& r) {
    return r + i; // r.operator+(i)
}

int main() {
    Razionale r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    cout << r1 << r2 << r3; 

    Razionale r4 = 1 + r3;
    cout << r4;


    return 0;
}