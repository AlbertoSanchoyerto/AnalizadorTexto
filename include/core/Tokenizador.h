/**
* @file Tokenizador.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Transformación de un texto plano en agrupaciones de palabras
*/
#pragma once

#include <string>
#include <vector>
#include <regex>

#include "core/Token.h"

/**
* @class Tokenizador
* @brief divide el texto en tokens (palabra).
* Realiza la division del texto en base de 4 grupos de expresiones.
*
* - Grupo 1, prefijo de la palabra (([\(\[\{\"'¿¡]*)  
*
* - Grupo 2, parte principal de la palabra con posibilidad de que en medio exista  
*   guion y/o apostrofe (español y portuges)  
*   ([A-Za-z0-9áéíóúüñÁÉÍÓÚÜÑãõâêôçÃÕÂÊÔÇ]+  
*   (?:[-'][A-Za-z0-9áéíóúüñÁÉÍÓÚÜÑãõâêôçÃÕÂÊÔÇ]+)*)  
*
* - Grupo 3, sufijo de la palabra ([.,!?…:;]*)  
*
* - Grupo 4, separador de la palabra (\s*)  
*/
class Tokenizador {
	private:
    const std::string APERTURA   = R"([\(\[\{\"'¿¡]*)";
    const std::string LETRAS     = R"([A-Za-z0-9áéíóúüñÁÉÍÓÚÜÑãõâêôçÃÕÂÊÔÇ]+)";
    const std::string COMPUESTO  = R"((?:[-'])" + LETRAS + R"()*)";
    const std::string PALABRA    = LETRAS + COMPUESTO;
    const std::string PUNTUACION = R"([.,!?…:;]*)";
    const std::string ESPACIOS   = R"(\s*)";
    const std::string PATRON =
        "(" + APERTURA + ")" +
        "(" + PALABRA + ")" +
        "(" + PUNTUACION + ")" +
        "(" + ESPACIOS + ")";
    
    public:
    /**
     * @brief Transforma un texto en tokens (texto palabra)
	 * @param texto a transformar en tokens
	 * @return lista de tokens resultantes
     */
    std::vector < Token > tokenizar(const std::string& texto);
};
