/**
* @file Palabra.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Contiene lo que definimos como palabra y su analisis
*/
#pragma once

#include <iostream>

#include "core/Token.h"

/**
* @class Palabra
* @brief Representa la palabra analizada de un texto
* 
* se subdivide en los siguienyes elementos;
* 
* - Token estructura textual de la Palabra
* - Etiqieta PGO ()
*/
class Palabra {
    private:
    Token token;
    EtiquetaPGO etiqueta;
	NumeroPGO numero;
	GeneroPGO genero;
    int indiceParrafo;

    public:
    /**
     * @brief Constructor de la palabra
	 * @param t token de la palabra
	 * @param n numero de la palabra
	 * @param g género de la palabra
	 * @param indice del parrafo de la palabra
     */
	Palabra(const Token &t, NumeroPGO n, GeneroPGO g, int indice) : token(t), numero(n), genero(g), indiceParrafo(indice) {};

	/**
	 * @brief Pone etiqueta PGO a la palabra
	 * @param e etiqueta PGO
	 */
	void setEtiqueta(EtiquetaPGO e);

	/**
	 * @brief Obtiene la etiqueta PGO a la palabra
	 * @return etiqueta PGO
	 */
	EtiquetaPGO getEtiqueta() const;

    /**
     * @brief inprime por consola la informacion de la palabra
     */
    void imprimir() const;
};