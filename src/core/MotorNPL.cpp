/**
* @file MotorNPL.cpp
*/
#include "core/MotorNPL.h"

std::vector < Palabra > MotorNPL::procesar(const std::string& texto, int indiceParrafo) {
    std::vector < Palabra > palabras;

    auto tokens = tokenizador.tokenizar(texto);

    for (const auto& token: tokens) {
        EtiquetaPOS etiqueta = etiquetador.etiquetar(t.texto);
        palabras.emplace_back(token, etiqueta, indiceParrafo);
    }

    return palabras;
}