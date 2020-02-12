#include <iostream>
using namespace std;

template <class T>
class MyVector
{
    T* buffer;
    int size_v;
    int capacity;

public:
    MyVector();
    MyVector(unsigned int _capacity);

// inserare la sfarsit
    void push_back_v(T value);

// inserare pe o anumita pozitie. Se va verifica daca position e valid
    void insert_v(T value, unsigned int position);

// sterge ultimul element si il returneaza
    T pop_back_v();

// returneaza dimensiunea vectorului
    unsigned int length() const;

// verifica daca un element exista in vector
    bool contains(T value) const;

// afiseaza pe ecran continutul vectorului
    void print_vector() const;

// sorteaza crescator continutul vectorului
// creati un template specializat pentru char*
    void sort_v();
};

template <typename T>
MyVector<T>::MyVector() {
    size_v = 0;
    capacity = 0;
    buffer = NULL;
}

template <typename T>
MyVector<T>::MyVector(unsigned int _capacity) {
    size_v = 0;
    capacity = _capacity;
    buffer = new T[_capacity];
}

template <typename T>
void MyVector<T>::push_back_v(T value) {
    T* aux;
    if (size_v >= capacity){
        capacity *= 2;
        aux = new T[capacity];
        for (int i = 0; i < size_v; ++i) aux[i] = buffer[i];
        delete[] buffer;
        buffer = aux;
    }
    buffer[size_v] = value;
    size_v++;
}

template <typename T>
void MyVector<T>::insert_v(T value, unsigned int position) {
    T* aux;
    int i;
    if (position > size_v) cout<<"Pozitie invalida.\n";
    else {
        if (position == size_v) push_back_v(value);
        else {
            for (i = size_v; i >=position; i--) buffer[i] = buffer[i-1];
            buffer[position] = value;
        }
        size_v++;
    }
}

template <typename T>
T MyVector<T>::pop_back_v() {
    size_v--;
    return buffer[size_v];
}

template <typename T>
unsigned int MyVector<T>::length() const {
    return size_v;
}

template <typename T>
bool MyVector<T>::contains(T value) const {
    for (int i = 0; i < size_v; i++)
        if (buffer[i] == value) return true;
    return false;
}

template <typename T>
void MyVector<T>::sort_v() {
    int i, j;
    for (i = 0; i < size_v; ++i) {
        for (j = i+1; j < size_v; ++j) {
            if (buffer[i] > buffer[j]) swap(buffer[i], buffer[j]);
        }
    }
}

template <typename T>
void MyVector<T>::print_vector() const {
    for(int i=0; i<size_v; i++) cout<<buffer[i]<<" ";
    cout<<endl;
}

template<>
void MyVector<char>::sort_v(){
    int i, j;
    for (i = 0; i < size_v; ++i) {
    for (j = i+1; j < size_v; ++j) {
        if (buffer[i] > buffer[j]) swap(buffer[i], buffer[j]);
    }
}
