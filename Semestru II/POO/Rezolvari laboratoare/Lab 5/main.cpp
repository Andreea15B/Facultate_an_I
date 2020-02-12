#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
    MyVector<char> a(2);
    a.push_back_v(7);
    a.push_back_v(2);
    a.push_back_v(3);
    a.push_back_v(1);
    a.print_vector();
    a.sort_v();
    a.print_vector();
    return 0;
}
