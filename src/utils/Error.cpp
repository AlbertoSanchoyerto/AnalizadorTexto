/**
 * @file Error.cpp
 */
 
#include "utils/Error.h"

#include <sstream>

Error::Error(TipoError tipo, const std::string& mensaje, const std::string& archivo, int linea, const std::string& funcion)
    : tipo(tipo), mensaje(mensaje), archivo(archivo), linea(linea), funcion(funcion)
{
    construirMensaje();
}

void Error::construirMensaje() {
    std::ostringstream oss;

    oss << "[ERROR ";

    switch (tipo) {
        case TipoError::LEXICO: oss << "LEXICO"; break;
        case TipoError::SINTACTICO: oss << "SINTACTICO"; break;
        case TipoError::SEMANTICO: oss << "SEMANTICO"; break;
        case TipoError::ARCHIVO: oss << "ARCHIVO"; break;
        case TipoError::INTERNO: oss << "INTERNO"; break;
    }

    oss << "] " << mensaje
        << " (" << archivo << ":" << linea
        << ", " << funcion << ")";

    mensajeCompleto = oss.str();
}

const char* Error::what() const noexcept {
    return mensajeCompleto.c_str();
}

TipoError Error::getTipo() const {
    return tipo;
}
