/**
* @file LineaComandos.h
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

#include <iostream>
#include <string>
#include <map>
#include <functional>

/**
* @class LineaComandos
* @brief Clase simple para gestionar comandos de línea de comandos (CLI).
*
* Esta clase permite registrar comandos con callbacks asociados y ejecutar
* acciones en función de los argumentos recibidos desde la terminal.
*
*/
class LineaComandos {
    private:
    std::vector < std::string > args;
    std::map < std::string,
    std::function < void(const std::vector < std::string>&)>> comandos;

    public:
    /**
    * @brief Constructor que analiza los argumentos de línea de comandos.
    * @param argc Número de argumentos.
    * @param argv Array de argumentos.
    */
    LineaComandos(int argc, char* argv[]);
    
    /**
    * @brief Registra un comando CLI.
    *
    * @param nombre Nombre del comando (ej: --help, --archivo).
    * @param func Función a ejecutar cuando se invoque el comando.
    *
    * La función recibe los parámetros adicionales del comando.
    */
    void ponerComando(const std::string& nombre, std::function < void(const std::vector < std::string>&) > func);

    /**
    * @brief Ejecuta el comando introducido por el usuario.
    *
    * Analiza el primer argumento recibido y ejecuta el comando asociado.
    * Si el comando no existe, muestra un mensaje de error.
    */
    void ejecutar();
};