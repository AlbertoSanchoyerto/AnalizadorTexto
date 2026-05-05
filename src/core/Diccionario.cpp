/**
* @file Diccionario.cpp
*/
#include "utils/ErrorMacros.h"
#include "core/Diccionario.h"

#include <fstream>
#include <cctype>
#include <algorithm>

const std::string Diccionario::normalizar(const std::string& palabra) {
    std::string resultado;

    for (char c: palabra) {
        if (std::isalpha(static_cast<unsigned char > (c))) {
            resultado += std::tolower(static_cast<unsigned char > (c));
        }
    }
    return resultado;
}

bool Diccionario::empiezaCon(const std::string & prefijo, const std::string & texto)
{
	if (prefijo.size() > texto.size()) return false;
	return texto.compare(0, prefijo.size(), prefijo) == 0;
}

const int Diccionario::distanciaLevenshtein(const std::string& a, const std::string& b) {
    size_t n = a.size();
    size_t m = b.size();

    std::vector < std::vector < int>> dp(n + 1, std::vector < int > (m + 1));

    for (size_t i = 0; i <= n; i++) dp[i][0] = static_cast<int > (i);
    for (size_t j = 0; j <= m; j++) dp[0][j] = static_cast<int > (j);

    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            int costo = (a[i - 1] == b[j - 1]) ? 0: 1;

            dp[i][j] = (std::min)({
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + costo
            });
        }
    }
    return dp[n][m];
}

bool Diccionario::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        LANZAR_ERROR(TipoError::ARCHIVO, "No se pudo abrir el fichero " + nombreArchivo);
    }

    std::string palabra;
    while (archivo >> palabra) {
        palabras.insert(normalizar(palabra));
    }
    return true;
}

bool Diccionario::existe(const std::string& palabra) {
    return palabras.count(normalizar(palabra)) > 0;
}

bool Diccionario::existeRaiz(const std::string& palabra) {
    for(const auto& raiz: palabras) {
		if (empiezaCon(normalizar(palabra), normalizar(raiz))) {
			return true;
		}
    }
    return false;
}

bool Diccionario::existeSugerencia(const std::string palabra, int distanciaMaxima) {
    std::string p = normalizar(palabra);

    for(const auto& w: palabras) {
		if (std::abs(static_cast<long long>(p.size()) - static_cast<long long>(w.size())) > distanciaMaxima)
		{
			continue;
		}
        if(distanciaLevenshtein(p, w) <= distanciaMaxima) {
            return true;
        }
    }
    return false;
}

const size_t Diccionario::tamano() {
    return palabras.size();
}
