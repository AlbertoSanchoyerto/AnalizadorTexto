/**
* @file Palabra.h
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

#include <iostream>

#include "core/Token.h"

/**
* @class Palabra
* @brief Representa la palabra analizada de un texto
* 
* se subdivide en los siguienyes elementos;
* 
* - Token estructura textual de la Palabra
* - Etiqieta PGO ()
*/
class Palabra {
    private:
    Token token;
    EtiquetaPGO etiqueta;
    int indiceParrafo;

    public:
    /**
     * @brief Constructor de la palabra
     */
    Palabra(const Token &t, EtiquetaPGO e, int indice);

    /**
     * @brief inprime por consola la informacion de la palabra
     */
    void imprimir() const;
};