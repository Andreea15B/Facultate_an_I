#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <class T>
int Partition(vector<T> &arr, int low, int high, function<int(T &e1, T &e2)> &Compare) {
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
void quickSort(vector<T> &arr, int low, int high, function<int(T &e1, T &e2)> &Compare) {
    if(low < high) {
        int pi = Partition(arr, low, high, Compare); // pi = partitioning index
        quickSort(arr, low, pi-1, Compare);
        quickSort(arr, pi+1, high, Compare);
    }
}

//template <class T>
// function<int(T &e1, T &e2)> Compare = [](T &e1, T &e2)->int {return e1<=e2;};

template <class T>
void Sort(vector<T> lista, function<int(T &e1, T &e2)> &Compare) {
    quickSort(lista, 0, lista.size()-1, Compare);
}

int main()
{
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(30);
    vect.push_back(10);
    vect.push_back(2);
    function<int(int &e1, int &e2)> Compare = [](int &e1, int &e2)->int {return e1<=e2;};
    Sort(vect, Compare);
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" ";
    return 0;
}
