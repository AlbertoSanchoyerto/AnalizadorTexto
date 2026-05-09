/**
* @file main.cpp
*/
#include "core/DocumentoTexto.h"
#include "utils/ErrorMacros.h"
#include "utils/lineaComandos.h"

#include <iostream>

int main(int argc, char* argv[]) {

    LineaComando lineaComando(argc, argv);

    lineaComando.ponerComando("--help", [](const std::vector < std::string>&) {
        std::cout << "Comandos:\n";
        std::cout << "  --archivo <ruta>\n";
        std::cout << "  --log <archivo>\n";
        std::cout << "  --help\n";
    });

    lineaComando.ponerComando("--log", [](const std::vector < std::string>& args) {
        if (args.size() < 1) {
            std::cerr << "Falta archivo de log\n";
            return;
        }

        Logger::instancia().setArchivo(args[0]);
        std::cout << "Log configurado en " << args[0] << "\n";
    });

    lineaComando.ponerComando("--archivo", [](const std::vector < std::string>& args) {
        std::string archivoLog =
        if (args.size() < 1) {
            std::cerr << "Falta ruta del archivo\n";
            return;
        }

        Logger::instancia().setArchivo("AnalizadorTexto.log");
        Logger::instancia().setNivel(NivelLog::DEBUG);
        
        LOG_INFO("Inicio del programa");

        DocumentoTexto doc;
        doc.cargarDesdeFichero(args[0]);
        doc.imprimir();
    });

    LineaComando.ejecutar();

    return 0;
};