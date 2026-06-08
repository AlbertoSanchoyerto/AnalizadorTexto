/**
* @file EtiquetadorPGO.cpp
*/
#include "core/EtiquetadorPGO.h"

#include <regex>

Lexico::Lexico() {
	adjetivo.cargarDesdeArchivo("data/adjetivos.txt");
	adverbio.cargarDesdeArchivo("data/advervios.txt");
	articulo.cargarDesdeArchivo("data/articulos.txt");
	vervo.cargarDesdeArchivo("data/vervos.txt");
	preposicion.cargarDesdeArchivo("data/preposiciones.txt");
	conjuccion.cargarDesdeArchivo("data/conjucciones.txt");
}

const EtiquetaPGO Lexico::obtenerEtiqueta(const std::string& palabra) {
	if (std::regex_match(palabra, std::regex("^[0-9]+$"))) {
		return EtiquetaPGO::NUMERO;
	}
	else if (adjetivo.existe(palabra)) {
		return EtiquetaPGO::ADJETIVO;
	}
	else if (adverbio.existe(palabra)) {
		return EtiquetaPGO::ADVERBIO;
	}
	else if (articulo.existe(palabra)) {
		return EtiquetaPGO::ARTICULO;
	}
	else if (vervo.existe(palabra)) {
		return EtiquetaPGO::VERBO;
	}
	else if (preposicion.existe(palabra)) {
		return EtiquetaPGO::PREPOSICION;
	}
	else if (conjuccion.existe(palabra)) {
		return EtiquetaPGO::CONJUCION;
	}
    else {
        return EtiquetaPGO::DESCONOCIDO;
    }
}

const GeneroPGO Lexico::obtenerGenero(const std::string & palabra)
{
	if (palabra.size() >= 1) {
		if (palabra.back() == 'a') {
			return GeneroPGO::FEMENINO;
		}
		else if (palabra.back() == 'o') {
			return GeneroPGO::MASCULINO;
		}
	}
	return GeneroPGO::INDEFINIDO;
}

const NumeroPGO Lexico::obtenerNumero(const std::string & palabra)
{
	if (palabra.size() < 2) {
		return NumeroPGO::SINGULAR;
	}

	if (palabra.compare(palabra.size() - 1, 1, "s") == 0 ||
		palabra.compare(palabra.size() - 2, 2, "es") == 0) {
		return NumeroPGO::PLURAL;
	}
	return NumeroPGO::SINGULAR;
}

const EtiquetaPGO EtiquetadorPGO::Etiquetar(const std::string& palabra) {
    return lexico.obtenerEtiqueta(palabra);
}
