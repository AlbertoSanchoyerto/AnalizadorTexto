/**
* @file ErrorMacros.h
* @author Alberto Sanchoyerto
* @date 2026
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Grupo de macros para utilizar el sistema de errores
*
* Con estas marcos podemos iniciar un error y escribir en un log
* el tipo de errores que se esten produciendo.
*
* Hay una macro para lanzar el error y cuatro para escribir en el log
* según el nivel de error que se estime del mismo.
*/
#pragma once

#include "utils/Error.h"
#include "utils/Logger.h"

#include <sstream>

/**
 * @brief Lanza una excepcion de error
 * @param tipo de error
 * @param mensaje de error
 * @throw excepcion con el tipo, mensaje, fichero, linea y funcion
 */
#define LANZAR_ERROR(tipo, mensaje) \
    throw Error(tipo, mensaje, __FILE__, __LINE__, __func__)

/**
 * @brief Crea una instancia de error de depuracion
 * @param mensaje del error
 */
#define LOG_DEBUG(mensaje) \
    Logger::instancia().log(NivelLog::DEBUG, mensaje)

/**
 * @brief Crea una instancia de error informativo
 * @param mensaje del error
 */
#define LOG_INFO(mensaje) \
    Logger::instancia().log(NivelLog::INFO, mensaje)

/**
 * @brief Crea una instancia de error de aviso
 * @param mensaje del error
 */
#define LOG_WARNING(mensaje) \
    Logger::instancia().log(NivelLog::WARNING, mensaje)

/**
 * @brief Crea una instancia de error critico
 * @param mensaje del error
 */
#define LOG_ERROR(mensaje) \
    Logger::instancia().log(NivelLog::ERROR, mensaje)
