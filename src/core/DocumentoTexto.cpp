/**
* @file DocumentoTexto.cpp
*/
#include "utis/ErrorMacros.h"
#include "core/DocumentoTexto.h"

#include <fstream>
#include <stdexcept>

void DocumentoTexto::cargarDesdeFichero(const std::string& nombreFichero) {
    std::ifstream archivo(nombreFichero);

    if (!archivo) {
        LANZAR_ERROR(TipoError::ARCHIVO, "No se pudo abrir el fichero " + nombreFichero);
    }

    std::string linea;
    int indice = 0;

    while (std::getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }
        parrafos.push_back(motor.procesar(linea, indice++));
    }
}

void DocumentoTexto::imprimir() const {
    for (const auto& parrafo: parrafos) {
        for (const auto& palabra: parrafo) {
            palabra.imprimir();
        }
    }
}