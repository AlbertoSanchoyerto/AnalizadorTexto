/**
* @file Palabra.cpp
*/
#include "core/Palabra.h"

Palabra::Palabra(const Token &t, EtiquetaPGO e, int indice) {
    token = t;
    etiqueta = e;
    indiceParrafo = indice;
}

void Palabra::imprimir() const {
    std::cout << "[" << token.palabra << "] "
    << "POS=" << static_cast<int > (etiqueta)
    << " Parrafo=" << indiceParrafo
    << std::endl;
}