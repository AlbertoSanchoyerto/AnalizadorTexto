/**
* @file Palabra.h
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

#include <string>
#include <fstream>
#include <mutex>

enum class NivelLog {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

/**
 * @class Logger
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
    static Logger& instancia();

    /**
     * @brief Establece el nivel de log de Errores
     * @param NivelLog nivel establecido del log
     */
    void setNivel(NivelLog nivel);
    
    /**
     * @nrief Establece el fichero donde escribir el log
     * @param nombreArchivo nombre del archivo log
     */
    void setArchivo(const std::string& nombreArchivo);

    void log(NivelLog nivel, const std::string& mensaje);

    // eliminar copias
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};