/**
* @file EtiquetaPGO.cpp
*/
#include "core/EtiquetadorPGO.h"

#include <regex>

Lexico::Lexico() {
    determinantes.cargarDesdeArchivo("determinantes.txt");
    preposiciones.cargarDesdeArchivo("preposiciones.txt");
    vervos.cargarDesdeArchivo("vervos.txt");
    advervios.cargarDesdeArchivo("advervios.txt");
}

const EtiquetaPGO Lexico::obtenerEtiqueta(const std::string& palabra) {
    if(determinantes.existe(palabra)) {
        return EtiquetaPGO::DETERMINANTE;
    }
    else if(preposiciones.existe(palabra)) {
        return EtiquetaPGO::PREPOSICION;
    }
    else if(advervios.existe(palabra)) {
        return EtiquetaPGO::ADVERBIO;
    }
    else if(vervos.existeRaiz(palabra)) {
        return EtiquetaPGO::VERBO;
    }
    else {
        if (std::regex_match(palabra, std::regex("^[0-9]+$"))) {
            return EtiquetaPGO::NUMERO;
        }
        else {
            return EtiquetaPGO::DESCONOCIDO;
        }
    }
}

const EtiquetaPGO EtiquetadorPGO::Etiquetar(const std::string& palabra) {
    return lexico.obtenerEtiqueta(palabra);
}
