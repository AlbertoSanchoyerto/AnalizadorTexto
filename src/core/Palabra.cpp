/**
* @file Palabra.cpp
*/
#include "core/Palabra.h"

void Palabra::setEtiqueta(EtiquetaPGO e) {
	etiqueta = e;
}

EtiquetaPGO Palabra::getEtiqueta() const
{
	return etiqueta;
}

void Palabra::imprimir() const {
	std::cout << "[" << token.palabra << "] "
		<< "PGO=" << DescripcionPGO(etiqueta).descripcion()
		<< " Numero=" << DescripcionPGO(numero).descripcion()
		<< " Genero=" << DescripcionPGO(genero).descripcion()
		<< " Parrafo=" << indiceParrafo
		<< std::endl;
}