#include "Cerc.h"

Cerc::Cerc(int raza) {
    Raza = raza;
}

double Cerc::ComputeArea() {
    return 3.14*Raza*Raza;
}

const char * Cerc::GetName() {
    return "Cerc";
}
