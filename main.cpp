/**
* @file main.cpp
*/
#include "core/DocumentoTexto.h"
#include "utils/ErrorMacros.h"
#include "utils/LineaComandos.h"

#include <iostream>
#include <string>
#include <direct.h>

/**
 * @brief Principal de la aplicación
 *
 * - Inicia los comandos de linea
 * - Interpreta los comandos introducidos por el usuario
 *
 * @details
 * Los comando incluidos son
 * - **help**, la ayuda, siempre tiene que existir
 * - **log**, para definir el fichero log que queremos, si no, nos crea uno por defecto
 * - **archivo**, para introducir el fichero, ruta completa para procesar el analisis de texto
 *
 * @note Por cada nuevo comando, ir incluyendolo en este fuente con el código correspondiente
 */
int main(int argc, char* argv[]) {

	LineaComandos lineaComandos(argc, argv);

	lineaComandos.ponerComando("--help", [](const std::vector < std::string>&) {
		std::cout << "Comandos:\n";
		std::cout << "  --archivo ruta\tRealizar analisis del texto del fichero .txt\n";
		std::cout << "  --log archivo \tEspecifica un fichero .log\n";
		std::cout << "  --help        \tMostrar ayuda\n";
	});

	lineaComandos.ponerComando("--log", [](const std::vector < std::string>& args) {
		if (args.size() < 1) {
			std::cerr << "Falta archivo de log\n";
			return;
		}

		Logger::instancia().setArchivo(args[0]);
		std::cout << "Log configurado en " << args[0] << "\n";
	});

	lineaComandos.ponerComando("--archivo", [](const std::vector < std::string>& args) {
		if (args.size() < 1) {
			std::cerr << "Falta ruta del archivo\n";
			return;
		}

		Logger::instancia().setArchivo("AnalizadorTexto.log");
		Logger::instancia().setNivel(NivelLog::DEBUG);

		LOG_INFO("Inicio del programa");

		try {
			DocumentoTexto doc;
			doc.cargarDesdeArchivo(args[0]);
			doc.imprimir();
		}
		catch (const Error& e) {
			LOG_ERROR(e.what());
		}
	});

	lineaComandos.ejecutar();

	return 0;
};