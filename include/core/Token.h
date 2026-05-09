/**
 * @file Token.h
 * 
 * @brief Estructura y etiquetados utiles
 */
#pragma once

#include <string>
 
/**
* @enum EtiquetaPGO
* @brief tipos de Partes Gramaticales de la Oracion
*/
enum class EtiquetaPGO {
    SUSTANTIVO,
    VERBO,
    DETERMINANTE,
    PREPOSICION,
    ADVERBIO,
    NUMERO,
    DESCONOCIDO
};

class DescripcionPGO {
private:
	std::string descripcionPGO;

public:
	// Constructor
	DescripcionPGO(EtiquetaPGO e) {

		switch (e) {

		case EtiquetaPGO::SUSTANTIVO: {
			descripcionPGO = "Sustantivo";
			break;
		}
		case EtiquetaPGO::VERBO: {
			descripcionPGO = "Verbo";
			break;
		}
		case EtiquetaPGO::DETERMINANTE: {
			descripcionPGO = "Determinante";
			break;
		}
		case EtiquetaPGO::PREPOSICION: {
			descripcionPGO = "Preposición";
			break;
		}
		case EtiquetaPGO::ADVERBIO: {
			descripcionPGO = "Adverbio";
			break;
		}
		case EtiquetaPGO::NUMERO: {
			descripcionPGO = "Número";
			break;
		}
		default: {
			descripcionPGO = "Desconocido";
			break;
		}
		}
	}

	std::string descripcion() const {
		return descripcionPGO;
	}
};

/**
 * brief Estructura token de una palabra
 * 
 * Estructura de una palabra dividida en;
 * 
 * - prefijo, signos al inicio de la palabra.
 * - palabra, la palabra en si, puede tener guion y/o apostrofe.
 * - sufijo, signos al final de la palabra.
 * - separador, espacio entre palabras.
 */
struct Token {
    std::string prefijo;
    std::string palabra;
    std::string sufijo;
    std::string separador;
};
