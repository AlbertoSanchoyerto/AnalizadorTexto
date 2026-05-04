/**
* @file Diccionario.h
* @autor Alberto Sanchoyerto
* @fecha 2026
* @version 1.0
*
* @copyright
* Copyright (c) 2026 Alberto Sanchoyerto
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

#ifndef DOCUMENTO_TEXTO_H
#define DOCUMENTO_TEXTO_H

#include <vector>
#include <string>

#include "MotorNLP.h"

/**
* @class Clase DocumentoTexto
* @brief Maneja documentos de texto completos
*
* - Carga del fichero de texto.
* - Analisis del texto, tranformandolo en palabras etiquetadas PGO.
*/
class DocumentoTexto {
    
private:
    std::vector < std::vector < Palabra>> parrafos:
    MotorNLP motor;

    public:
    /**
    * @brief Carga del Documento de texto.
    * @param nombreFichero, nombre del fichero de texto
    */
    void cargarDesdeFichero(const std::string& nombreFichero);

    /**
    * brief Imprime palanras etiquetadas del documento
    */
    const void imprimir();
}

#endif // DOCUMENTO_TEXTO_H