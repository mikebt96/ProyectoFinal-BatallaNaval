# 🚢 Batalla Naval en C

Un proyecto clásico de "Batalla Naval" (Battleship) escrito en C puro. Este repositorio es una recreación y mejora de mi proyecto final para la materia de **Fundamentos de Programación** en la **UNAM** (original de 2018).

## 📸 Demo de Juego
--- LUEGO AGREAGRÉ ALGO AQUÍ

## ✨ Características

* **Juego Clásico:** El objetivo es hundir la flota enemiga antes de que ellos hundan la tuya.
* **Tablero 5x5:** Un tablero compacto (5x5) con 5 barcos (1x1) que garantiza una partida rápida y llena de acción.
* **Jugador vs. IA:** Juegas contra un oponente de IA "justo" que dispara a coordenadas aleatorias.
* **Colocación Estratégica:** El jugador debe colocar sus 5 barcos al inicio de la partida.
* **Validación de Entradas:** El juego maneja robustamente entradas incorrectas (fuera del tablero, casillas ya ocupadas, etc.).
* **UI Limpia en Terminal:** Utiliza `system("clear")` y pausas (`sleep`) para crear una experiencia de usuario limpia y cinemática en la consola.
* **Multiplataforma:** Escrito en C estándar y usa `#ifdef _WIN32` para ser compatible tanto con `clear` (Linux/WSL/macOS) como con `cls` (Windows).

## 🚀 Cómo Jugar

Este proyecto está escrito en C puro y no requiere dependencias externas, solo un compilador de C.

### Requisitos

* Un compilador de C (ej. **GCC** o **Clang**).
* En Windows, se recomienda usar WSL (Windows Subsystem for Linux) o MinGW.

