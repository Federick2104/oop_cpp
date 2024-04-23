#include <iostream>
using namespace std;

template<class KeyType, class ValueType>
class Pair {
private:
    KeyType key;
    ValueType v;
public:

    Pair<KeyType, ValueType>() {
    }

    Pair<KeyType, ValueType>(KeyType key, ValueType v) {
        this->key = key;
        this->v = v;
    }

    KeyType getKey() const {
        return key;
    }

    ValueType getValue() const {
        return v;
    }

    void setKey(KeyType key) {
        this->key = key;
    }

    void setValue(ValueType v) {
        this->v = v;
    }
};

template<class K, class V>
class Map {
private:
    int next;
    int dim; // dimensione dell'array dinamico allocato
    Pair<K, V>* pairs;

    void enlarge() {
        Pair<K, V>* tmp = new Pair<K, V>[dim*2];
        for (int i = 0; i < dim; i++)
            tmp[i] = this->pairs[i];
        this->dim *= 2;
        delete [] this->pairs;
        this->pairs = tmp;
    }

public:

    Map<K, V>() {
        this->pairs = new Pair<K, V>[5];
        this->dim = 5;
        this->next = 0;
    }

    ~Map<K, V>() {
        delete [] pairs;
    }

    void remove(K k) {
        // TODO
    }

    void update(K k, V v) {
        if (!contains(k))
            throw invalid_argument("Key " + k + "does not exist in this map");
        for (int i = 0; i < next; i++)
            if (pairs[i].getKey() == k)
                pairs[i].setValue(v);
    }

    void add(K k, V v) {
        if (contains(k))
            throw invalid_argument("Key already exists in this map");
        if (next == dim)
            enlarge();
        this->pairs[next] = Pair<K, V>(k, v);
        next++;
    }

    bool contains(K k) const {
        for (int i = 0; i < next; i++)
            if (pairs[i].getKey() == k)
                return true;
        return false;
    }

    void print(ostream& dest) const {
        for (int i = 0; i < next; i++)
            dest << "[" << pairs[i].getKey() << ", " << pairs[i].getValue() << "]" << endl;
    }
};

template<class T1, class T2>
ostream& operator<<(ostream& dest, const Map<T1, T2>& map) {
    map.print(dest);
    return dest;
}

int main() {
    Map<string, int> m;
    m.add("hello", 1);
    m.add("world", 2);
    m.add("ciao", 3);

    cout << m << endl;
    m.update("ciao", 5);
    cout << m << endl;
    return 0;
}