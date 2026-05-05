# 🧠 AnalizadorNLP

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
- CMake ≥ 3.10

---

## 🔧 Instalación

git clone https://github.com/tuusuario/AnalizadorNLP.git
cd AnalizadorNLP
mkdir build
cd build
cmake ..
make

---

## 🧪 Ejemplo de uso

```cpp
#include "core/DocumentoTexto.h"
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
