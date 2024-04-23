#include <iostream>
#include <string>
using namespace std;


template<class T>
class vect {
private:
    T* container;
    int dim;
public:
    //destructor
    ~vect<T>() {
        if (!isEmpty())
            delete [] this->container;
    }
    //constructor
    vect<T>() {
        this->dim = 0;
        this->container = nullptr;
    }

    vect(const vect<T>& other) {
        this->dim = other.dim;
        this->container = new T[dim];
        for (int i = 0; i < dim; i++)
            this->container[i] = other.container[i];
    }

    // Inizializza un vector di dimensione n, dove
    // ogni element è inizializzato con elem
    vect<T>(int n, T elem) {
        this->dim = n;
        this->container = new T[n];
        for (int i = 0; i < n; i++)
            this->container[i] = elem;
    }
    //overloading operator=
    const vect<T>& operator=(const vect<T>& other) {
        if (this != &other) {
            this->~vect<T>();
            this->dim = other.dim;
            this->container = new T[dim];
            for (int i = 0; i < dim; i++)
                this->container[i] = other.container[i];
        }
        return *this;
    }

    //isEmpty method
    bool isEmpty() {
        return this->dim == 0;
    }
    //overloading operator==
    bool operator==(const vect<T>& other) const {
        if (this->dim != other.dim)
            return false;
        for (int i = 0; i < dim; i++)
            if (this->container[i] != other.container[i])
                return false;
        return true;
    }
    //add element to the vector
    void push_back(const T& elem) {
        T* new_container = new T[dim+1];
        for(int i = 0; i < dim ; i++)
            new_container[i] = container[i];
        new_container[dim++] = elem;
        this->~vect<T>();
        container = new_container;
    }

    void push_front(const T& elem) {
        T* new_container = new T[dim+1];
        new_container[0] = elem;
        for(int i = 0; i < dim; i++)
            new_container[i+1] = container[i];
        this->~vect<T>();
        container = new_container;
        dim++;
    }

    void push_at(int i, const T& elem) {
        T* new_container = new T[dim+1];
        new_container[i] = elem;
        for(int k = 0; k < dim; k++){
            if(k == i){
                k++;
            }
            new_container[k] = container[k];
        }
        this->~vect<T>();
        container = new_container;

    }
    //overloading operator[]
    T& operator[](int idx) const {
        if (idx < 0 || idx >= dim)
            throw out_of_range("Out of range");
        return this->container[idx];
    }
    //size method
    int size() const {
        return this->dim;
    }
    //print method
    void print(ostream& dest) const {
        for (int i = 0; i < dim; i++)
            dest << container[i] << " ";
        dest << endl;
    }
    //read method
    void read(istream& source) {
        for (int i = 0; i < dim; i++)
            source >> container[i];
    }


};

template<class T>
ostream& operator<<(ostream& dest, const vect<T>& other) {
    other.print(dest);
    return dest;
}

template<class T>
istream& operator>>(istream& source, vect<T>& other) {
    other.read(source);
    return source;
}

int main() {
    string a = "19";
    vect<string> v(10, a);
    cout << v << endl;

    v.push_back("b");
    cout << v.size() << endl;
    cout << v << endl;

    v.push_front("c");
    cout << v.size() << endl;
    cout << v << endl;

    v.push_at(2, "d");
    cout << v.size() << endl;
    cout << v << endl;

    return 0;
}
