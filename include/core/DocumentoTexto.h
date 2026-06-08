/**
* @file DocumentoTexto.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Manejo de documentos de texto para su analisis
*/
#pragma once

#include <vector>
#include <string>

#include "core/MotorNPL.h"

/**
* @class DocumentoTexto
* @brief Maneja documentos de texto completos
*
* - Carga del fichero de texto.
* - Analisis del texto, tranformandolo en palabras etiquetadas PGO.
*/
class DocumentoTexto {
    
private:
	std::vector < std::vector < Palabra>> parrafos;
	MotorNLP motor;

    public:
    /**
    * @brief Carga del Documento de texto.
    * @param nombreArchivo ruta completa del archivo
	* @throw lanza un error si no se puede abrir el archivo
    */
    void cargarDesdeArchivo(const std::string& nombreArchivo);

    /**
    * @brief Imprime palanras etiquetadas del documento
    */
    void imprimir() const;
};
