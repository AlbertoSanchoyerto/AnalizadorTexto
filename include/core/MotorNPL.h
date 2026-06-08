/**
* @file MotorNPL.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Un analizafor de texto simple, de un texto txt extrae su grupo de palabras
* etiquetadas por lexico utilizando diccionarios de palabras
*/
#pragma once

#include <vector>

#include "core/Tokenizador.h"
#include "core/EtiquetadorPGO.h"
#include "core/Palabra.h"

/**
* @class MotorNLP
* @brief Motor para procesar texto y
* convertirlo en palabras etiquetadas PGO
* 
* - Tokenizador que transforma el texto en palabras
* - EtiquwtadorPGO determina la etiqueta de las palabras
*/
class MotorNLP {
    private:
    Tokenizador tokenizador;
    EtiquetadorPGO etiquetador;

    public:
    /**
     * @brief Transforma un parrafo en una lista de palabras etiquetadas PGO
     * 
     * @param texto del parrafo a procesar
     * @param indiceParrafo que se encuentra
     * @return lista de palabras procesadas
     */
    std::vector < Palabra > procesar(const std::string& texto, int indiceParrafo);
};

