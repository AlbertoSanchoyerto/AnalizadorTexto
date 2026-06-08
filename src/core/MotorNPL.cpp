/**
* @file MotorNPL.cpp
*/
#include "core/MotorNPL.h"

std::vector < Palabra > MotorNLP::procesar(const std::string& texto, int indiceParrafo) {
    std::vector < Palabra > palabras;

    auto tokens = tokenizador.tokenizar(texto);

    for (const auto& token: tokens) {
		
		GeneroPGO genero = etiquetador.lexico.obtenerGenero(token.palabra);
		NumeroPGO numero = etiquetador.lexico.obtenerNumero(token.palabra);
        palabras.emplace_back(token, numero, genero, indiceParrafo);

		EtiquetaPGO etiqueta = etiquetador.Etiquetar(token.palabra);
		palabras.at(palabras.size() - 1).setEtiqueta(etiqueta);
    }

    return palabras;
}