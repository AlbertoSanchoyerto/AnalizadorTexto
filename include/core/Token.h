/**
 * @file Token.h
 * @author Alberto Sanchoyerto
 * @date 2026
 * @version 1.0
 * @copyright (c) 2026 Alberto Sanchoyerto
 *
 * @brief Estructuras y etiquetados utiles
 */
#pragma once

#include <string>
 
/**
* @enum EtiquetaPGO
* @brief tipos de Partes Gramaticales de la Oracion
*/
enum class EtiquetaPGO {
    SUSTANTIVO,
	ADJETIVO,
	ADVERBIO,
	ARTICULO,
	VERBO,
	PREPOSICION,
    CONJUCION,
    NUMERO,
    DESCONOCIDO
};

/**
* @enum NumeroPGO
* @brief tipos numerales de la palabra
*/
enum class NumeroPGO {
	SINGULAR,
	PLURAL
};

/**
* @enum GeneroPGO
* @brief generos de las palabra
*/
enum class GeneroPGO {
	MASCULINO,
	FEMENINO,
	INDEFINIDO
};

/**
 * @class DescripcionPGO
 * @brief Relaciona el código de los tipos con sus descripciones
 */
class DescripcionPGO {
private:
	std::string descripcionPGO;

public:
	/**
	 * @brief Constructor de descripcion con etiquetaPGO
	 * @param e codigo EtiquetaPGO
	 */
	DescripcionPGO(EtiquetaPGO e) {
		switch (e) {
			case EtiquetaPGO::ADJETIVO: {
				descripcionPGO = "Adjetivo";
				break;
			}
			case EtiquetaPGO::ADVERBIO: {
				descripcionPGO = "Adverbio";
				break;
			}
			case EtiquetaPGO::ARTICULO: {
				descripcionPGO = "Articulo";
				break;
			}
			case EtiquetaPGO::VERBO: {
				descripcionPGO = "Verbo";
				break;
			}
			case EtiquetaPGO::PREPOSICION: {
				descripcionPGO = "Preposición";
				break;
			}
			case EtiquetaPGO::CONJUCION: {
				descripcionPGO = "Conjucción";
				break;
			}
			case EtiquetaPGO::SUSTANTIVO: {
				descripcionPGO = "Sustantivo";
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

	/**
	 * @brief Constructor de descripcion con NumeroPGO
	 * @param n codigo NumeroPGO
	 */
	DescripcionPGO(NumeroPGO n) {
		switch (n) {
			case NumeroPGO::SINGULAR: {
				descripcionPGO = "Singular";
				break;
			}
			case NumeroPGO::PLURAL: {
				descripcionPGO = "Plural";
				break;
			}
			default: {
				descripcionPGO = "Desconocido";
				break;
			}
		}
	}

	/**
	 * @brief Constructor de descripcion con GeneroPGO
	 * @param g codigo GeneroPGO
	 */
	DescripcionPGO(GeneroPGO g) {
		switch (g) {
		case GeneroPGO::MASCULINO: {
			descripcionPGO = "Masculino";
			break;
		}
		case GeneroPGO::FEMENINO: {
			descripcionPGO = "Femenino";
			break;
		}
		case GeneroPGO::INDEFINIDO: {
			descripcionPGO = "Indefinido";
			break;
		}
		default: {
			descripcionPGO = "Desconocido";
			break;
		}
		}
	}

	/**
	 * @brief Obtiene la descripcion correpondiente al código
	 * @return devuelve la descripcion correspondiente al codigo
	 */
	std::string descripcion() const {
		return descripcionPGO;
	}
};

/**
 * @brief Estructura token de una palabra
 *
 * Estructura de una palabra dividida en;
 */
struct Token {
    std::string prefijo; /**< prefijo signos al inicio de la palabra */
    std::string palabra; /**< palabra la palabra en si, puede tener guion y/o apostrofe */
    std::string sufijo; /**< sufijo signos al final de la palabra */
    std::string separador; /**< @brief separador entre palabras */
};
