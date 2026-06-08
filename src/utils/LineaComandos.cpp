/**
* @file LineaComandos.cpp
*/
#include "utils/LineaComandos.h"

LineaComandos::LineaComandos(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }
}

void LineaComandos::ponerComando(const std::string& nombre,
    std::function < void(const std::vector < std::string>&) > func) {
    comandos[nombre] = func;
}

void LineaComandos::ejecutar() {
    if (args.empty()) {
        std::cout << "Sin comandos. Usa --help\n";
        return;
    }

    std::string cmd = args[0];

    if (comandos.find(cmd) != comandos.end()) {
        std::vector < std::string > parametros(args.begin() + 1, args.end());
        comandos[cmd](parametros);
    } else {
        std::cout << "Comando desconocido: " << cmd << "\n";
    }
}

