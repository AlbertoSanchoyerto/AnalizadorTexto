/**
* @file main.cpp
*/
#include "core/DocumentoTexto.h"
#include "utils/ErrorMacros.h"
#include "utils/LineaComandos.h"

#include <iostream>
#include <string>
#include <direct.h>

#if defined(_WIN32)

//#include <windows.h>
//#include <direct.h>

#elif defined(__linux__)

#include <unistd.h>
#include <limits.h>

#elif defined(__APPLE__)

#include <mach-o/dyld.h>
#include <unistd.h>
#include <limits.h>

#endif

/**
 * @brief Obtenemos el directorio del ejecutable (multiplataforma)
 */
std::string directorioEjecutable()
{
#if defined(_WIN32)

	char buffer[260];

	_getcwd(buffer, 260);
	std::string path(buffer);

	size_t pos = path.find_last_of("\\/");

#elif defined(__linux__)

	char buffer[1024];

	ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);

	if (len <= 0)
		return "";
	
	getcwd(buffer, sizeof(buffer));
	std::string path(buffer);

	size_t pos = path.find_last_of('/');

#elif defined(__APPLE__)

	char buffer[1024];

	getcwd(buffer, sizeof(buffer));
	std::string path(buffer);

	size_t pos = path.find_last_of('/');

#endif

	if (pos == std::string::npos)
		return "";

	return path.substr(0, pos);
}

/**
 * @brief Nos situamos en el directorio ejecutable (multiplataforma)
 * asi nos posibilita utilizar directorios relativos al ejecutable
 */
void situarseDirectorioEjecutable()
{
	std::string directorio = directorioEjecutable();

#if defined(_WIN32)

	_chdir(directorio.c_str());

#else

	chdir(directorio.c_str());

#endif
}

int main(int argc, char* argv[]) {

	/**
	 @note. Nos situamos en el directorio de la aplicación para que todas las rutas sean relativas al mismo.
	 */
	//situarseDirectorioEjecutable();

	LineaComandos lineaComandos(argc, argv);

	lineaComandos.ponerComando("--help", [](const std::vector < std::string>&) {
		std::cout << "Comandos:\n";
		std::cout << "  --archivo <ruta>\n";
		std::cout << "  --log <archivo>\n";
		std::cout << "  --help\n";
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