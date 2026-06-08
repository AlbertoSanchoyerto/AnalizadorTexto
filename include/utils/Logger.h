/**
* @file Logger.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Maneja la escritura de un fichero log
*/
#pragma once

#include <string>
#include <fstream>
#include <mutex>

/**
 * @enum NivelLog
 * @brief Niveles o tipos de log
 */
enum class NivelLog {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

/**
 * @class Logger
 * @brief Maneja los ficheros log de una aplicación
 *
 * - Establece el fichero donde escribir el log
 * - Escribe una linea log con nivel o tipo apunte
 */
class Logger {
private:
    std::ofstream archivo;
    std::mutex mutexLog;
    NivelLog nivelActual;

    Logger(); // constructor privado

    std::string nivelToString(NivelLog nivel);
    std::string timestamp();

public:
    /**
     * @brief Instancia de logs de errores
	 * @return retorna su misma instacia de log
     */
    static Logger& instancia();

    /**
     * @brief Establece el nivel de log de Errores
     * @param nivel establecido del log
     */
    void setNivel(NivelLog nivel);
    
    /**
     * @brief Establece el fichero donde escribir el log
     * @param nombreArchivo del archivo log
     */
    void setArchivo(const std::string& nombreArchivo);

    /**
     * @brief Crea un mensaje log
     * @param nivel del error
	 * @param mensaje del error
     */
    void log(NivelLog nivel, const std::string& mensaje);

    // eliminar copias
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};