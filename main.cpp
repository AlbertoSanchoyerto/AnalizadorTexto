/**
* @file main.cpp
*/
#include "DocumentoTexto.h"
#include "Logger.h"

#include <iostream>

int main() {

    Logger::instancia().setArchivo("AnalizadorTexto.log");
    Logger::instancia().setNivel(NivelLog::DEBUG);

    LOG_INFO("Inicio del programa");

    try {
        DocumentoTexto doc;
        doc.cargarDesdeFichero("texto.txt");
        doc.imprimir();
    }
    catch (const Error& e) {
        LOG_ERROR(e.what());
    }
}