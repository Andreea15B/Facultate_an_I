#include <iostream>

using namespace std;
struct data {
    unsigned int zi, luna, an;
};
int main()
{
    data x,urm;
    cin>>x.zi>>x.luna>>x.an;
    if(x.zi==31 && (x.luna==1 || x.luna==3 || x.luna==5 || x.luna==7 || x.luna==8 || x.luna==10)) {
        urm.zi=1; urm.luna=x.luna+1; urm.an=x.an;
    }
    else {
        if(x.zi==31 && x.luna==12) {
            urm.zi=1; urm.luna=1; urm.an=x.an+1;
        }
        else {
            if(x.zi==30 && (x.luna==4 || x.luna==6 || x.luna==9 || x.luna==11)) {
                urm.zi=1; urm.luna=x.luna+1; urm.an=x.an;
            }
            else if((x.zi==28 || x.zi==29) && x.luna==2) {
                urm.zi=1; urm.luna=x.luna+1; urm.an=x.an;
            }
            else {urm.zi=x.zi+1; urm.luna=x.luna; urm.an=x.an;}
        }
    }
    cout<<urm.zi<<"."<<urm.luna<<"."<<urm.an<<'\n';
    return 0;
}
