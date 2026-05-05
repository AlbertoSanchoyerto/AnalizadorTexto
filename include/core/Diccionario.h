/**
* @file Diccionario.h
* @autor Alberto Sanchoyerto
* @fecha 2026
* @version 1.0
*
* @copyright
* Copyright (c) 2026 Alberto Sanchoyerto
*
* @license MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
*/
#pragma once

#include <unordered_set>
#include <vector>
#include <string>

/**
* @class Diccionario
* @brief Representa un conjunto de palabras
* con funcionalidades de búsqueda y corrección.
*
* Permite:
* - Cargar palabras desde un archivo
* - Verificar existencia de palabras o su comienzo de la palabra
*/
class Diccionario {
    private:
    std::unordered_set < std::string > palabras; /// Conjunto de palabras

    /**
    * @brief Normaliza una palabra eliminando caracteres no alfabéticos y
    * convirtiendo a minúsculas.
    * @param palabra Palabra original
    * @return Palabra normalizada
    */
    const std::string normalizar(const std::string& palabra);

	/**
	 * @brieg Comprueba si una cadena empieza igual a otra menor
	 * @param prefijo posible de la palabra
	 * @param palabra palabra que comprobamos si coincide con el prefijo
	 * return true si empieza,false en caso contrario 
	 */
	bool empiezaCon(const std::string& prefijo, const std::string& texto);

    /**
    * @brief Calcula la distancia de Levenshtein entre dos cadenas.
    * La distancia de Levenshtein mide el número mínimo de operaciones necesarias
    * para transformar una cadena en otra.
    * Las operaciones permitidas son:
    *
    * - Inserción de un carácter
    * - Eliminación de un carácter
    * - Sustitución de un carácter
    *
    * @param s1 Primera cadena de texto.
    * @param s2 Segunda cadena de texto.
    * @return int Número mínimo de operaciones necesarias para convertir s1 en s2.
    *
    * @note
    * Ejemplo:
    * distanciaLevenshtein("gato", "gata") = 1 (solo una sustitución)
    * distanciaLevenshtein("kitten", "sitting") = 3
    *
    * @details
    * Se utiliza programación dinámica para construir una matriz donde:
    * - Las filas representan los caracteres de s1
    * - Las columnas representan los caracteres de s2
    *
    * Cada celda (i, j) representa la distancia entre:
    * - Los primeros i caracteres de s1
    * - Los primeros j caracteres de s2
    *
    *
    * dist[i][j] = min(
    *     dist[i-1][j] + 1,        // eliminación
    *     dist[i][j-1] + 1,        // inserción
    *     dist[i-1][j-1] + coste   // sustitución (0 si iguales, 1 si distintos)
    * )
    */
    const int distanciaLevenshtein(const std::string& a, const std::string& b);

    public:

    /**
    * @brief Carga palabras desde un archivo de texto.
    * @param nombreArchivo Ruta del archivo
    * @return true si se cargó correctamente, false en caso de erro
    */
    bool cargarDesdeArchivo(const std::string& nombreArchivo);

    /**
    * @brief Comprueba si una palabra existe
    *en el diccionario.
    * @param palabra Palabra a buscar
    * @return true si existe, false en caso contrario
    */
    bool existe(const std::string& palabra);

    /**
    * @brief Comprueba si la raiz de la palabra
    * existe en el diccionario.
    * @param palabra Palabra a buscar
    * @return true si existe,false en caso contrario
    */
    bool existeRaiz(const std::string& palabra);

    /**
    * @brief comprueba si la palabra es similar a las del diccionario
    * @param pslabra palabra a comprobar
    * @param distanciaMaxima Distancia máxima permitida (por defecto 2)
    * return true si existe,false en caso contrario
    */
    bool existeSugerencia(const std::string palabra, int distanciaMaxima = 2);

    /**
    * @brief Devuelve el número de palabras en el diccionario.
    * @return Tamaño del diccionario
    */
    const size_t tamano();
};
