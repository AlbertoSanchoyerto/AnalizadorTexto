/**
* @file Error.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Contiene el error producido para su consulta
*/
#pragma once

#include <exception>
#include <string>

/**
 * @enum TipoError
 * @brief Tipos de error básicos
 */
enum class TipoError {
    LEXICO,
    SINTACTICO,
    SEMANTICO,
    ARCHIVO,
    INTERNO
};

/**
 * @class Error
 * @brief Manejo de errores
 * 
 * - Establece el error actual
 * - Obtiene el ultimo error producido
 */
class Error : public std::exception {
private:
    TipoError tipo;
    std::string mensaje;
    std::string archivo;
    int linea;
    std::string funcion;
    std::string mensajeCompleto;

    void construirMensaje();

public:
	/**
	 * @brief Constructor de Error
	 * @param tipo de error producido
	 * @param mensaje descripción del error producido
	 * @param archivo donde ocurre el error
	 * @param linea donde ocurre el error
	 * @param funcion donde ocurre el error
	 */
    Error(TipoError tipo, const std::string& mensaje, const std::string& archivo, int linea, const std::string& funcion);

	/**
	 * @brief obtiene una descripcion del error produccido
	 */
    const char* what() const noexcept override;

	/**
	 * @brief obtiene el tipo de error producido
	 */
    TipoError getTipo() const;
};