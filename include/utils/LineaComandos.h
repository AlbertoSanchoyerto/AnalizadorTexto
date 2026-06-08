/**
* @file LineaComandos.h
* @author Alberto Sanchoyerto
* @date 2026
* @version 1.0
* @copyright (c) 2026 Alberto Sanchoyerto
*
* @brief Define el comportamiento y la ejecución de un programa con ordenes en linea de comandos
*/

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>

/**
* @class LineaComandos
* @brief Gestiona comandos de línea de comandos (CLI).
*
* Esta clase permite registrar comandos con callbacks asociados y ejecutar
* acciones en función de los argumentos recibidos desde la terminal.
*
* - Establece los posibles comandos disponibles
* - Ejecuta los comandos mandados por el usuario
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