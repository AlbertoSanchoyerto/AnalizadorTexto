/**
* @file EtiquetaPGO.cpp
*/
#include "utils/EtiquetadorPGO.h"

Lexico::Lexico() {
    determinantes.cargarDesdeArchivo("determinantes.txt");
    preposiciones.cargarDesdeArchivo("preposiciones.txt");
    vervos.cargarDesdeArchivo("vervos.txt");
    advervios.cargarDesdeArchivo("advervios.txt");
}

EtiquetaPGO Lexico::obtenerEtiqueta(const std::string& palabra) const {
    if(determinantes.existe(palabra)) {
        return EtiquetaPGO::DETERMINANTE;
    }
    else if(preprosiciones.existe(palabra)) {
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

const EtiquetaPGO EtiquetarPGO::Etiquetar(const std::string& palabra) {
    return lexico.obtenerEtiqueta(palabra);
}
