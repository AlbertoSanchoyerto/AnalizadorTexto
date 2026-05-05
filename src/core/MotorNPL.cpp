/**
* @file MotorNPL.cpp
*/
#include "core/MotorNPL.h"

std::vector < Palabra > MotorNLP::procesar(const std::string& texto, int indiceParrafo) {
    std::vector < Palabra > palabras;

    auto tokens = tokenizador.tokenizar(texto);

    for (const auto& token: tokens) {
		EtiquetaPGO etiqueta = etiquetador.Etiquetar(token.palabra);
        palabras.emplace_back(token, etiqueta, indiceParrafo);
    }

    return palabras;
}