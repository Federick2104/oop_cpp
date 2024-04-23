#include <iostream>
using namespace std;

template<class T>
class Stack {
private:
    T* container;
    int dim; // dimensione array dinamico
    int top; // top dello stack;

    void enlarge() {
        T* tmp = new T[dim*2];
        for (int i = 0; i < dim; i++)
            tmp[i] = this->container[i];
        this->dim *= 2;
        delete [] this->container;
        this->container = tmp;
    }
public:

    ~Stack<T>() {
        delete [] container;
    }

    const Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            this->~Stack<T>();
            this->dim = other.dim;
            this->top = other.top;

            this->container = new T[dim];
            for (int i = 0; i < top; i++)
                this->container[i] = other.container[i];
        }

        return *this;
    }

    Stack<T>(const Stack<T>& other) {
        this->dim = other.dim;
        this->top = other.top;
        this->container = new T[other.dim];
        for (int i = 0; i < other.top; i++)
            this->container[i] = other.container[i];
    }

    Stack<T>() {
        this->container = new T[5];
        this->dim = 5;
        this->top = 0;
    }

    bool isEmpty() const {
        return top == 0;
    }

    void push(T x) {
        if (top == dim) {
            enlarge();
            cout << "Enlarge! " << this->dim << endl;
        }

        container[top] = x;
        top++;
    }

    T pop() {
        if (isEmpty())
            throw string("Empty stack");
        top--;
        return this->container[top];
    }

    int size() const {
        return top;
    }

    void print(ostream& dest) const {
        dest << "[";
        for (int i = 0; i < top; i++) {
            dest << container[i];
            if (i != top -1) {
                dest << ", ";
            }
        }

        dest << "]";
        return;
    }
};

template<class Type>
ostream& operator<<(ostream& dest, const Stack<Type>& s) {
    s.print(dest);
    return dest;
}


template<class T>
void scambia(T& x, T& y) {
    cout << "Templatic function" << endl;
    T tmp = x;
    x = y;
    y = tmp;
}

template<class T>
T my_max(T x, T y) {
    return x > y ? x : y;
}

template<typename Type>
Type max_array(Type a[], int len) {
    Type max = a[0];
    for (int i = 0; i < len; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

int main() {
    Stack<int> st;
    try {
        st.pop();
    } catch (const string& e) {
        cout << e << endl;
    }

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st << endl; // [1, 2, 3, 4, 5];

    st.pop();
    st.pop();
    cout << st << endl; // [1, 2, 3];

    Stack<int> other_st;
    other_st = st;

    other_st.push(7);
    other_st.push(8);

    // Stack<float>, Stack<Razionale>, ...
    return 0;
}
