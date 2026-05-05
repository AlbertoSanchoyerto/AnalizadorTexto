/**
* @file DocumentoTexto.cpp
*/
#include "utils/ErrorMacros.h"
#include "core/DocumentoTexto.h"

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

void DocumentoTexto::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        LANZAR_ERROR(TipoError::ARCHIVO, "No se pudo abrir el fichero " + nombreArchivo);
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