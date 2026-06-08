/**
* @file Diccionario.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Conjunto de palabras para utilizar en busquedas en textos
*/
#pragma once

#include <unordered_set>
#include <vector>
#include <string>

/**
* @class Diccionario
* @brief Representa un conjunto de palabras con funcionalidades de búsqueda.
*
* Permite:
* - Cargar las palabras del diccionario desde un archivo
* - Verifica la existencia de la palabra con alguna de las palabras del diccionario
* - Verifica por igualdad exacta
* - Verifica por similitud (según distancia Levenshtein)
* - Verifica si empieza igual (patrón: asterisco al final de la palabra)
* - Verifica si termina igual (patrón: asterisco al inicio de la palabra)
* - Verifica si esta contenido en otra (patrón: asterisco al inicio y al final de la palabra)
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
    * @brief Calcula la distancia de Levenshtein entre dos cadenas.
    * La distancia de Levenshtein mide el número mínimo de operaciones necesarias
    * para transformar una cadena en otra.
    * Las operaciones permitidas son:
    *
    * - Inserción de un carácter
    * - Eliminación de un carácter
    * - Sustitución de un carácter
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
	*
	* @param s1 Primera cadena de texto.
    * @param s2 Segunda cadena de texto.
    * @return int Número mínimo de operaciones necesarias para convertir s1 en s2.
	*
    */
    const int distanciaLevenshtein(const std::string& s1, const std::string& s2);

	/**
	 * @brief Comprueba si dos palabras son iguales
	 * @param a palabra a comparar
	 * @param b palabra con la que comparar
	 * @return true si es asi, si no false
	 */
	bool esIgual(const std::string& a, const std::string& b);

	/**
	 * @brief Comprueba si una palabra empieza con el prefijo
	 * @param palabra a comparar
	 * @param prefijo con el que puede empezar
	 * @return true si es asi, si no false
	 */
	bool empiezaPor(const std::string& palabra, const std::string& prefijo);

	/**
	 * @brief Comprueba si una palabra termina con el sufijo
	 * @param palabra a comparar
	 * @param sufijo con el que puede terminar
	 * @return true si es asi, si no false
	*/
	bool terminaPor(const std::string& palabra, const std::string& sufijo);

	/**
	 * @brief Comprueba si una palabra contiene una subcadena
	 * @param palabra a comparar
	 * @param subcadena que puede contener
	 * @return true si es asi, si no false
	 */
	bool contiene(const std::string& palabra, const std::string& subcadena);

    public:

    /**
    * @brief Carga palabras desde un archivo de texto.
    * @param nombreArchivo ruta completa del archivo
    * @return true si se cargó correctamente, false en caso de error
    */
    bool cargarDesdeArchivo(const std::string& nombreArchivo);

    /**
    * @brief Comprueba si una palabra existe en el diccionario.
    * @param palabra a buscar
    * @return true si existe, false en caso contrario
    */
    bool existe(const std::string& palabra);

    /**
    * @brief comprueba si la palabra es similar a las del diccionario
    * @param palabra a comprobar
    * @param distanciaMaxima distancia máxima permitida (por defecto 2)
    * @return true si es asi, si no false
    */
    bool existeSugerencia(const std::string palabra, int distanciaMaxima = 2);

    /**
    * @brief Devuelve el número de palabras en el diccionario.
    * @return Tamaño del diccionario en numero de palabras
    */
    const size_t tamano();
};
