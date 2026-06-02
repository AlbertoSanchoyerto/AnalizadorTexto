# 🧠 AnalizadorTexto

Motor básico de procesamiento de lenguaje natural (NLP) en C++, con tokenización, etiquetado gramatical (PGO), manejo de errores estructurado y sistema de logging thread-safe.

---

## 🚀 Características

- 🔤 Tokenización avanzada (soporte Unicode con ICU opcional)
- 🏷️ Etiquetado gramatical (PGO)  
- 📚 Diccionarios externos configurables
- ⚠️ Sistema de errores tipado (`Error`)
- 📝 Logging thread-safe
- ⚙️ Build con CMake
- 🧩 Arquitectura modular y escalable

---

## 📁 Estructura del proyecto

AnalizadorTexto/.  
├── include/.  
├── src/.  
├── data/.  
├── CMakeLists.txt.  
└── main.cpp.  

---

## ⚙️ Requisitos

- C++14 o superior.  
- CMake ≥ 3.10.  

---

## 🔧 Instalación de fuentes

```bash
git clone.    https://github.com/AlbertoSanchoyerto/AnalizadorTexto.git.   
cd AnalizadorTexto.   
mkdir build.   
cd build.   
cmake ..    
```

---

## 🧪 Ejemplo de uso

```bash
> AnalizadorTexto --help
> AnalizadorTexto --log ficheroLog
> AnalizadorTexto --archivo documento.txt
```

---

## 📄 Licencia

MIT License
