/**
* @file MotorNPL
* @brief Un analizafor de texto simple,
* de un texto txt extrae su grupo de palabras
* etiquetadas por lexico utilizando
* diccionarios de palabras
*
* @autor Alberto Sanchoyerto
* @fecha 2026
* @version 1.0
*
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @license MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
*/
#pragma once

#include <vector>

#include "core/Tokenizador.h"
#include "core/EtiquetadorPGO.h"
#include "core/Palabra.h"

/**
* @class MotorNLP
* @brief motor para procesar texto y
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
     * @param texto, parrafo de texto
     * @param int indice parrafo
     * @return lista de palabras etiquetadas
     */
    std::vector < Palabra > procesar(const std::string& texto, int indiceParrafo);
};

