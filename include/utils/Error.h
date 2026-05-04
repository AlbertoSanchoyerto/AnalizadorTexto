/**
* @file Error.h
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

#include <exception>
#include <string>

enum class TipoError {
    LEXICO,
    SINTACTICO,
    SEMANTICO,
    ARCHIVO,
    INTERNO
};

/**
 * @class Error
 * 
 * @brief Clase para el manejo de errores
 * 
 * 
 */
class Error : public std::exception {
private:
    TipoError tipo;
    std::string mensaje;
    std::string archivo;
    int linea;
    std::string funcion;
    std::string mensajeCompleto;

    void construirMensaje();

public:
    Error(TipoError tipo, const std::string& mensaje, const std::string& archivo, int linea, const std::string& funcion);

    const char* what() const noexcept override;

    TipoError getTipo() const;
};