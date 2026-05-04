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

#include <string>
#include <vector>
#include <regex>

#define TOKENIZADOR_H
#define TOKENIZADOR_H

#include <vector>
#include <string>

#include "Token.h"

/**
* class Tokenizador
* brief divide el texto en tokens (palabra).
* Realiza la division del texto en base de 4 grupos de expresiones.
*
* - Grupo 1, prefijo de la palabra (([\(\[\{\"'¿¡]*)
*
* - Grupo 2, parte principal de la palabra con posibilidad de que en medio exista
*   guion y/o apostrofe (español y portuges)
*   ([A-Za-z0-9áéíóúüñÁÉÍÓÚÜÑãõâêôçÃÕÂÊÔÇ]+
*   (?:[-'][A-Za-z0-9áéíóúüñÁÉÍÓÚÜÑãõâêôçÃÕÂÊÔÇ]+)*)
*
* - Grupo 3, sufijo de la palabra ([.,!?…:;]*)
*
* - Grupo 4, separador de la palabra (\s*))
*/
class Tokenizador {
    const std::string APERTURA   = R"([\(\[\{\"'¿¡]*)";
    const std::string LETRAS     = R"([A-Za-z0-9áéíóúüñÁÉÍÓÚÜÑãõâêôçÃÕÂÊÔÇ]+)";
    const std::string COMPUESTO  = R"((?:[-'])" + LETRAS + R"()*)";
    const std::string PALABRA    = LETRAS + COMPUESTO;
    const std::string PUNTUACION = R"([.,!?…:;]*)";
    const std::string ESPACIOS   = R"(\s*)";
    const std::string PATRON =
        "(" + APERTURA + ")" +
        "(" + PALABRA + ")" +
        "(" + PUNTUACION + ")" +
        "(" + ESPACIOS + ")";
    
    public:
    /**
     * @brief Transforma un texto en tokens (texto palabra)
     */
    std::vector < Token > tokenizar(const std::string& texto);
}

#endif // TOKENIZADOR_H