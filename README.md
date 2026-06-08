# 🧠 AnalizadorTexto

Motor básico de procesamiento de lenguaje natural (NLP) en C++, con tokenización, etiquetado gramatical (PGO), manejo de errores estructurado y sistema de logging thread-safe.

---

## 🚀 Características

- 🔤 Tokenización avanzada (soporte Unicode con ICU opcional)
- 🏷️ Etiquetado gramatical (EtiquetaPGO)  
- 📚 Diccionarios externos configurables
- ⚠️ Sistema de errores tipado (`Error`)
- 📝 Logging thread-safe
- ⚙️ Build con CMake
- 🧩 Arquitectura modular y escalable

---

## 📁 Estructura del proyecto

AnalizadorTexto/  
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

git clone https://github.com/AlbertoSanchoyerto/AnalizadorTexto.git  
cd AnalizadorTexto  
mkdir build  
cd build  
cmake ..  
make  

---

## 🧪 Ejemplo de uso

```Bash

AnalizadorTexto --archivo data/documento.txt  
AnalizadorTexto --help  
```

Comandos:  
  --archivo [fichero]   Realizar analisis del texto del fichero .txt  
  --log [ficheroLog]    Especifica un fichero .log  
  --help                Mostrar ayuda  

---

## 📄 Licencia

MIT License.

Copyright (c) 2026 Alberto Sanchoyerto

Consulte el archivo [LICENSE](LICENSE) para obtener el texto completo.

\include LICENSE
