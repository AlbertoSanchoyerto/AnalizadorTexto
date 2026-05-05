/**
 * @file Logger.cpp
 */
 
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "utils/Logger.h"

Logger::Logger() : nivelActual(NivelLog::DEBUG) {}

Logger& Logger::instancia() {
    static Logger instancia;
    return instancia;
}

void Logger::setNivel(NivelLog nivel) {
    nivelActual = nivel;
}

void Logger::setArchivo(const std::string& nombreArchivo) {
    std::lock_guard<std::mutex> lock(mutexLog);
    archivo.open(nombreArchivo, std::ios::app);
}

std::string Logger::nivelToString(NivelLog nivel) {
    switch (nivel) {
        case NivelLog::DEBUG: return "DEBUG";
        case NivelLog::INFO: return "INFO";
        case NivelLog::WARNING: return "WARNING";
        case NivelLog::ERROR: return "ERROR";
    }
    return "UNKNOWN";
}

std::string Logger::timestamp() {
    auto ahora = std::chrono::system_clock::now();
    auto tiempo = std::chrono::system_clock::to_time_t(ahora);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&tiempo), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Logger::log(NivelLog nivel, const std::string& mensaje) {
    if (nivel < nivelActual) return;

    std::lock_guard<std::mutex> lock(mutexLog);

    std::string salida = "[" + timestamp() + "] [" + nivelToString(nivel) + "] " + mensaje;

    // consola
    std::cout << salida << std::endl;

    // fichero (si está activo)
    if (archivo.is_open()) {
        archivo << salida << std::endl;
    }
}
