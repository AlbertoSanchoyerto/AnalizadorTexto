# 🧠 AnalizadorTexto

Motor básico de procesamiento de lenguaje natural (NLP) en C++, con tokenización, etiquetado gramatical (PGO), manejo de errores estructurado y sistema de logging thread-safe.

---

## 🚀 Características

- 🔤 Tokenización avanzada (soporte Unicode con ICU opcional)
- 🏷️ Etiquetado gramatical (PGO)  
- 📚 Diccionarios externos configurables
- ⚠️ Sistema de errores tipado (`ErrorNLP`)
- 📝 Logging thread-safe
- ⚙️ Build con CMake
- 🧩 Arquitectura modular y escalable

---

## 📁 Estructura del proyecto

AnalizadorNLP/
├── include/
├── src/
├── data/
├── CMakeLists.txt
└── main.cpp

---

## ⚙️ Requisitos

- C++14 o superior
- CMake ≥ 3.16

---

## 🔧 Instalación

git clone https://github.com/AlbertoSanchoyerto/AnalizadorTexto.git
cd AnalizadorTexto
mkdir build
cd build
cmake ..
make

---

## 🧪 Ejemplo de uso

```cpp
#include "nlp/DocumentoTexto.h"
#include "utils/Logger.h"

int main() {
    Logger::instancia().setArchivo("app.log");

    DocumentoTexto doc;
    doc.cargarDesdeFichero("data/texto.txt");
    doc.imprimir();
}
```

---

## 📄 Licencia

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
