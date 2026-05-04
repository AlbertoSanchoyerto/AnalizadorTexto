/**
* @file Tokenizador.cpp
*/
#include "core/Tokenrizador.h"

std::vector < Token > Tokenizador::tokenizar(const std::string& texto) {
    std::vector < Token > tokens;

    std::regex expresion(PATRON);

    auto inicio = std::sregex_iterator(texto.begin(), texto.end(), expresion);
    auto fin = std::sregex_iterator();

    for (auto it = inicio; it != fin; ++it) {
        std::smatch m = *it;

        tokens.push_back({
            m[1].str(),
            m[2].str(),
            m[3].str(),
            " "
        });
    }
    return tokens;
}
