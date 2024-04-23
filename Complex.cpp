//
// Created by Federico Schianchi on 20/03/24.
//

#include <iostream>
using namespace std;

class Complex{
private:
    int r;
    int i;

    Complex somma(const Complex& other) const {
        Complex res(this->r + other.r, this->i + other.i);
        return res;
    }

    Complex differenza(const Complex& other) const {
        Complex res(this->r - other.r, this->i - other.i);
        return res;
    }

public:
    Complex(int r, int i) {
        this->r = r;
        this->i = i;
    }

    Complex(){
        this->i = 0;
        this->r = 0;
    }

    bool operator==(const Complex& c) const {
        if(this->r == c.r && this->i == c.i)
            return true;
        else return false;
    }

    bool operator!=(const Complex& c) const {
        if(this->r != c.r || this->i != c.i)
            return true;
        else return false;
    }

    Complex operator+(const Complex& other) const{
        return this->somma(other);
    }

    Complex operator-(const Complex& other) const{
        return this->differenza(other);
    }


    void print(ostream& dest) const {
        dest << this->r << " + " << this->i << "i" << endl;
    }

    void read(istream& sorg) {
        int in, im;
        char sep;
        cout << "Scrivere nella forma a(intera)+b(immaginaria):" << endl;
        sorg >> in >> sep >> im;
        this->r = in;

        if (im == 0) {
            throw runtime_error("Error: If the imaginary part is 0, the number isn't complex, just Real");

        } else
            this->i = im;

    }



};

ostream& operator<<(ostream& dest, const Complex& r) {
    r.print(dest);
    return dest;
}
istream& operator>>(istream& sorg, Complex& r) {
    r.read(sorg);
    return sorg;
}




int main(){
    Complex s1;
    Complex s2;
    cin >> s1 >> s2;

    return 0;
}