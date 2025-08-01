//  cplx_number.cpp
// ENSF 614 Fall 2022 LAB 3 - EXERCISE B
// implemented by John Zhou

#include "cplx_number.h"
#include <iostream>
using namespace std;

Cplx::Cplx(): realM(0), imagM(0) {
    
}

Cplx::Cplx(double real , double imag ): realM(real),
imagM(imag) {
    // point three - When the program reaches this point for the first time
    cout<< realM<<"aaaaaaaaaa        ";
    cout<< realM<<"   ";
    cout<< imagM<<"   ";
}

double Cplx::getRealPart() const {
    // point two - When the program reaches this point for the first time
    return realM;
}

double Cplx::getImaginaryPart( ) const {
    return imagM;
}

void Cplx::setRealPart(double arg) {
    
    realM = arg;
    cout<< realM<<"aaaaaaaaaa        ";
    cout<< realM<<"   ";
    cout<< imagM<<"   ";
    // Point one
}

void Cplx::setImaginaryPart(double arg) {
    imagM = arg;
}

Cplx Cplx::add(const Cplx& other)const {
    Cplx local;
    
    local.realM = this->getRealPart() + other.realM;
    local.imagM = imagM + other.imagM;
    
    return local;
}

Cplx Cplx::subtract(const Cplx* other)const {
    Cplx local;
    local.realM = realM - other->realM;
    local.imagM = imagM - other->imagM;
    cout << endl << "in subtract";
    global_print (*this);
    global_print(*other);
    return local;
}

