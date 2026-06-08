/**
* @file EtiquetadorPGO.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Sistema para la etiquetación de palabras
*/
#pragma once

#include <string>

#include "core/Token.h"
#include "core/Diccionario.h"

/**
* @class Lexico
* @brief Determina la tipologia PGO de las palabras.
*
* - Carga los diccionarios
* - Verifica la palabra con los diccionarios
* - Verificavraices de vervos
* - Verifica si el contenido son digitos (numero)
*/
class Lexico {
    private:
		Diccionario adjetivo;
		Diccionario adverbio;
		Diccionario articulo;
		Diccionario vervo;
		Diccionario preposicion;
		Diccionario conjuccion;

    public:
    /**
    * @brief Contructor que carga los diccionarios
    */
    Lexico();

    /**
    * @brief Obtiene la etiqueta Parte Gramatical de la Oracion
    *
    * @param palabra de la que optenemos la etiqueta
    * @return etiqueta de la palabra
    */
    const EtiquetaPGO obtenerEtiqueta(const std::string& palabra);

	/**
	 * @brief Obtener el genero de la palabra.
	 *
	 * se obtiene segun como termine dicha palabra 
	 *
	 * @param palabra de la que optenemos el genero
	 * @return genero de la palabra
	 */
	const GeneroPGO obtenerGenero(const std::string& palabra);

	/**
	 * @brief Obtener el número de la palabra.
	 *
	 * se obtiene según como termine dicha palabra en s o es es plural, y si no singular.
	 *
	 * @param palabra de la que optenemos el número
	 * @return número de la palabra
	 */
	const NumeroPGO obtenerNumero(const std::string& palabra);
};

/**
* @class EtiquetadorPGO
* @brief Asigna etiquetas de Partes Gramaticales de la Oracion.
*/
class EtiquetadorPGO {
    public:
    Lexico lexico;

    /**
     * @brief Obtiene la etiqueta de la palabra
     * @param palabra a Etiquetar
     * @return etiqueta de la palabra
     */
    const EtiquetaPGO Etiquetar(const std::string& palabra);
};
