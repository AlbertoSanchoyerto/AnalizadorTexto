/**
* @file EtiquetaPGO.cpp
*/
#include "core/EtiquetadorPGO.h"

#include <regex>

Lexico::Lexico() {
    determinantes.cargarDesdeArchivo("data/determinantes.txt");
    preposiciones.cargarDesdeArchivo("data/preposiciones.txt");
    vervos.cargarDesdeArchivo("data/vervos.txt");
    advervios.cargarDesdeArchivo("data/advervios.txt");
}

const EtiquetaPGO Lexico::obtenerEtiqueta(const std::string& palabra) {
	if (std::regex_match(palabra, std::regex("^[0-9]+$"))) {
		return EtiquetaPGO::NUMERO;
	}
    else if(determinantes.existe(palabra)) {
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
        return EtiquetaPGO::DESCONOCIDO;
    }
}

const EtiquetaPGO EtiquetadorPGO::Etiquetar(const std::string& palabra) {
    return lexico.obtenerEtiqueta(palabra);
}
