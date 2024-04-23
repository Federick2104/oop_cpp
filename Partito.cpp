//
// Created by Federico Schianchi on 23/04/24.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Partito{
protected:
    string nome;
    string sigla;
    string presidente;


public:
    Partito(string nome, string sigla, string presidente){
        this->nome = nome;
        this->sigla = sigla;
        this->presidente = presidente;
    }


    string getSigla() const{
        return this->sigla;
    }


    bool operator==(const Partito& other){
        return this->nome == other.nome && this->sigla == other.sigla;
    }

     const Partito& getPartito() const{
        return partito;
     }


};

class PartitoDiDestra : public Partito{
private:
    double percentuale_voti;

public:
    PartitoDiDestra(string nome, string sigla, string presidente, double percentuale_voti)
        : Partito( nome,  sigla,  presidente){
        this->percentuale_voti = percentuale_voti;
    }
};

class PartitoDiSinistra : public Partito{
private:
    double percentuale_voti;

public:
    PartitoDiSinistra(string nome, string sigla, string presidente, double percentuale_voti)
            : Partito( nome,  sigla,  presidente){
        this->percentuale_voti = percentuale_voti;
    }
};

class PartitoDiCentro : public Partito{
private:
    double percentuale_voti;

public:
    PartitoDiCentro(string nome, string sigla, string presidente, double percentuale_voti)
            : Partito( nome,  sigla,  presidente){
        this->percentuale_voti = percentuale_voti;
    }
};

class Parlamentare {
private:
    string _nome;
    string _cognome;
    Partito _partito;
public:
    Parlamentare(string nome, string cognome, Partito partito) : _nome(nome), _cognome(cognome), _partito(partito) {

    }

    void visualizza (){
        cout << _nome << " " << _cognome << " " << _partito.getSigla() << endl;
    }
};

class Parlamento{

    
private:
    vector<Parlamentare> parlamentari;
public:
    Parlamento(){
        this->parlamentari = parlamentari;
    }
    void addParlamentare(Parlamentare parl){
        for(const auto& p : parlamentari)
            if(p == pari) throw invalid_argument("Parlamentare Presente!");
        parlamentari.push_back(parl);
    }

    void visualizzaParlamento() const {

    }

    void visualizzaParlamentariDI(const Partito&) const{

    }

};

int main(){

}