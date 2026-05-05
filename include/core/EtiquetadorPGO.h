/**
* @file EtiquetadorPGO.h
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

#include <string>

#include "core/Token.h"
#include "core/Diccionario.h"

/**
* @class Lexico
* @brief clase que determina la tipologia PGO de las palabras.
*
* - Carga los diccionarios
* - Verifica la palabra con los diccionarios
* - Verificavraices de vervos
* - Verifica si el contenido son digitos (numero)
*/
class Lexico {
    private:
    Diccionario determinantes;
    Diccionario preposiciones;
    Diccionario vervos;
    Diccionario advervios;

    public:
    /**
    * @brief Contructor que carga los diccionarios
    */
    Lexico();

    /**
    * brief Obtiene la etiqueta Parte Gramatical
    * de la Oracion
    *
    * @param string palabra
    * @return EtiquetaPGO etiqueta.
    */
    const EtiquetaPGO obtenerEtiqueta(const std::string& palabra);
};

/**
* @class EtiquetadorPGO
* @brief Asigna etiquetas de Partes Gramaticales de la Oracion.
*/
class EtiquetadorPGO {
    private:
    Lexico lexico;

    public:
    /**
     * @brief Obtiene la etiqueta de la palabra
     * @param palabra, palabra a Etiquetar
     * @return etiquetaPGO, etiqueta de la palabra
     */
    const EtiquetaPGO Etiquetar(const std::string& palabra);
};
