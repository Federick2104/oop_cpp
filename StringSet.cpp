// Esercizio StringSet
//
#include <iostream>
#include <string>

using namespace std;

class StringSet {
private:
 int dim;
 string s[100];

public:
    StringSet() {
        this->dim = 0;
    }

//chiamata al costruttore, delega ad un'altro costruttore priam di partire

    StringSet(string s[], int n) : StringSet(){
        for(int i = 0; i < n; i++){
            add(s[i]);
        }
    }

    void add(string x){
        if(this->contains(x)){
            return;
        }else if (dim == 100){
            cout << "Error full set";
        }else{
            s[dim] = x;
            dim++;
        }
    }

    bool contains(const string x) const{
        for(int i = 0; i < dim; i++){
            if (s[i] == x) return true;
        }
        return false;
    }

    int size() const{
        return this->dim;
    }

    StringSet operator+(const StringSet& other) const{
        StringSet res;
        for(int i = 0; i < this->size(); i++){
            res.add(this->s[i]);
        }

        for(int i = 0; i < other.size(); i++){
            res.add(other.s[i]);
        }
        return res;
    }

    bool operator<=(const StringSet& other) const{
        if(size() > other.size()) return false;  //fail fast (worst case scenario Furbo)
        for (int i = 0; i < size(); i++){
            if(!other.contains(s[i])) return false;
        }
        return true;
    }

    string getElem(int i) const {
        if(i >= 0 && i < size()){
            return s[i];

        }
        else{
            cout << "Index out of bound" << endl;
            return "";
        }
    }

    void print(ostream& dest) const{ //modo con print
        for(int i = 0; i < size(); i++){
            dest << this->s[i] << endl;
        }
    }

    bool operator==(const StringSet& other) const{
        return *this <= other && other <= *this;
    }



};

ostream& operator<< (ostream& dest , const StringSet& s){
    dest << "{ " ;
    for(int i = 0; i < s.size(); i++){
        dest << s.getElem(i);
        if(i < s.size() - 1)
            dest << ", ";
    }
    dest << "}";
    return dest;
}



int main() {
    string frase[] = {"goku", "dragon", "ball", "culo", "suca"};
    StringSet S1(frase, 5);
    cout << "S1:" << S1 << endl;
    cout << S1.size() << endl;

    string frase2[] = {"dio", "cane", "porco", "dio"};
    StringSet S2(frase2, 4);
    cout << S1 + S2 << endl;


    cout << S2.contains("porco") << endl;

    S1.add("c");
    S2.add("halo");
    StringSet s3 = S1 + S2;
    cout << s3 << endl;
    return 0;
}
