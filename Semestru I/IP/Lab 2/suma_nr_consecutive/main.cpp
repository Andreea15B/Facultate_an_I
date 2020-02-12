/* Să se afișeze toate variantele de a scrie un număr natural n ca sumă de numere consecutive.
n=k*i+(k-1)*k/2=k*i+(k^2-k)/2
2*n=2*k*i+k^2-k;

k^2 + k(2*i-1) - 2n = 0;

delta = (2i-1)^2 + 8n

k1,2 = (-(2*i-1) +- sqrt (delta) )/ 2

k nr întreg */
#include <iostream>
#include <cmath>

using namespace std;

void afiseaza (int, int);

int main()
{
    int n,i,k;

    double delta;
    double k1, k2;
    cin>>n;
    for(i=1;i<=n/2;i++) {
        delta = (2*i-1)*(2*i-1) + 8*n;
        k1 = (-(2*i-1) + sqrt(delta))/2;
        k2 = (-(2*i-1) - sqrt(delta))/2;

        if (k1 - (int)k1 == 0 && k1>0)
            afiseaza (i, k1);

        if (k2 - (int)k2 == 0 && k2>0)
            afiseaza (i, k2);
    }
    return 0;
}


void afiseaza(int i, int k){
    for (int j = i; j < i+k-1; ++j)
        cout<<j<<"+";
    cout<<i+k-1;
    cout<<'\n';
}
