#include "Dreptunghi.h"
Dreptunghi::Dreptunghi(int lungime, int latime) {
    Latime = latime;
    Lungime = lungime;
}

double Dreptunghi::ComputeArea() {
    return Latime*Lungime;
}

const char * Dreptunghi::GetName() {
    return "Dreptunghi";
}
