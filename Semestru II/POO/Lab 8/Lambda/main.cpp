#include <iostream>
#include <vector>
using namespace std;

template<class T>
int Compare(T &e1, T &e2) {
    return e1<=e2;
}

/* void BubbleSort(vector<int> &lista, bool (*Compare)(int e1, int e2)) {
    int i, sortat = 1;
    while(sortat) {
        sortat = 0;
        for(i = 0; i < lista.size()-1; i++) {
            if(Compare(lista[i], lista[i+1])) {
                sortat = 1;
                swap(lista[i], lista[i+1]);
            }
        }
    }
}*/

template <class T>
int Partition(vector<T> &arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1; // index of smaller element
    for(int j = low; j < high; j++) {
        if(Compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

template <class T>
void quickSort(vector<T> &arr, int low, int high) {
    if(low < high) {
        int pi = Partition(arr, low, high); // pi = partitioning index
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

template <class T>
void Sort(vector<T> &lista, int (*Compare)(T &e1, T &e2)) {
    quickSort(lista, 0, lista.size()-1);
}

int main()
{
    /*auto lambda = [](int a, int b){return a+b;};
    auto q = lambda(7,9);
    cout<<q;*/

    vector<int> vect;
    vect.push_back(1);
    vect.push_back(30);
    vect.push_back(10);
    // BubbleSort(vect, Compare);
    Sort(vect, Compare);
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" ";
    return 0;
}
