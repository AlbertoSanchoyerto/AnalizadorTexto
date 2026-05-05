#makelist AnalizadorTexto

# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(AnalizadorTexto VERSION 1.0 LANGUAGES CXX)

# Estándar de C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ===== FUENTES =====

include_directories(
    include
)

# Archivos fuente
file(GLOB CORE_SOURCES src/core/*.cpp)
file(GLOB UTILS_SOURCES src/utils/*.cpp)
file(GLOB CORE_HEADERS include/core/*.h)
file(GLOB UTILS_HEADERS include/utils/*.h)

# ===== EJECUTABLE =====

add_executable(${PROJECT_NAME}
    main.cpp
    ${CORE_SOURCES}
    ${UTILS_SOURCES}
	${CORE_HEADERS}
    ${UTILS_HEADERS}
)

# ===== PLATAFORMAS =====

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
	target_compile_options(${PROJECT_NAME} PRIVATE /std:c++14)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# (Opcional) Definiciones por plataforma
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_MAC)
elseif(UNIX)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_LINUX)
endif()

# ===== INSTALACIÓN =====

# 1. Ejecutable ? bin/
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin        # Windows (.exe)
    BUNDLE DESTINATION bin         # macOS (.app)
)

# 2. Archivos de configuración
install(DIRECTORY config/
    DESTINATION config
    FILES_MATCHING PATTERN "*.conf"
)

# 3. Datos iniciales
install(DIRECTORY data/
    DESTINATION data
)

# 4. Crear carpeta logs (vacía)
install(DIRECTORY DESTINATION logs)


