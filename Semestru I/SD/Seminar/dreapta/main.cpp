/* ecuația unei drepte în plan
(y-yA)/(yB-yA)=(x-xA)/(xB-xA)
(y-yA)*(xB-xA)=(x-xA)*(yB-yA)
y*xB - y*xA - yA*xB + yA*xA = x*yB - x*yA - xA*yB + xA*yA
y*(xB-xA) - yA*xB + yA*xA = x*(yB-yA) - xA*yB + xA*yA
y*(xB-xA) - x*(yB-yA) = yA*xB - yA*xA - xA*yB + xA*yA
x*(yA-yB) + y*(xB-xA)  - (yA*xB - yA*xA - xA*yB + xA*yA) = 0
x*(yA-yB) + y*(xB-xA)  - yA*xB + xA*yB = 0
AB: a*x + b*y + c = 0
*/
#include <iostream>

using namespace std;

int main()
{
    int xA,xB,yA,yB,a,b,c;
    cin>>xA>>yA>>xB>>yB;
    b=xB-xA;
    a=yA-yB;
    c=xA*yB-yA*xB;
    cout<<a<<'x';
    if(b<0) cout<<b<<'y';
    else cout<<'+'<<b<<'y';
    if(c<0) cout<<c<<"=0";
    else cout<<'+'<<c<<"=0";
    return 0;
}
