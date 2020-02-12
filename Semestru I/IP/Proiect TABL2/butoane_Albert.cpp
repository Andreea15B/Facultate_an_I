#include <iostream>

using namespace std;

float a;
int main()

{   start:

    cin>>a;
    if(!a){
        cout<<"Da"<<endl;
    }
    else {cout<<"Nu"<<endl;}

    if(a!=90)
    goto start;

    return 0;
}
