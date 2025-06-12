# Metody numeryczne – biblioteka obliczeniowa

Projekt biblioteki numerycznej realizowany w ramach zajęć z metod numerycznych. Zawiera implementacje i testy podstawowych metod obliczeniowych wykorzystywanych w analizie numerycznej.

# Struktura projektu

Metody_numeryczne-main/

├── include/               # Pliki nagłówkowe (.h) 

├── src/                   # Implementacje funkcji (.cpp)

├── tests/                 # Testy jednostkowe

├── examples/              # Przykłady użycia funkcji bibliotecznych

├── CMakeLists.txt         # Konfiguracja budowania (CMake)

└── README.md              # Dokumentacja projektu


# Metody numeryczne – projekt biblioteki obliczeniowej

Projekt zrealizowany w ramach zajęć z metod numerycznych. Celem było utworzenie biblioteki implementującej wybrane algorytmy numeryczne wraz z testami jednostkowymi i przykładami użycia.

---

## Zakres funkcjonalny

Biblioteka zawiera zaimplementowane metody numeryczne w następujących obszarach:

### Układy równań liniowych
- Eliminacja Gaussa z częściowym wyborem
- Eliminacja Gaussa bez wyboru

### Interpolacja
- Interpolacja Lagrange’a
- Obliczanie wartości wielomianu interpolacyjnego

### Aproksymacja
- Metoda najmniejszych kwadratów (regresja liniowa)

### Całkowanie numeryczne
- Metoda trapezów
- Metoda Simpsona
- Kwadratura Gaussa-Legendre’a (dla n = 2–5)

### Równania różniczkowe zwyczajne (ODE)
- Metoda Eulera
- Metoda Heuna (Euler poprawiony)
- Metoda punktu środkowego
- Metoda Rungego-Kutty czwartego rzędu (RK4)

### Równania nieliniowe
- Metoda Newtona
- Metoda siecznych

---

## Kompilacja projektu

### Wymagania
- Kompilator zgodny z C++17 (np. g++, clang++, MSVC)
- CMake ≥ 3.10

### Budowanie (Linux/Mac/WSL/MinGW)
- bash
- mkdir build
- cd build
- cmake ..
- make

### Budowanie (Visual Studio)
- Otwórz folder jako projekt CMake

- Wybierz „element startowy” (np. test_approximation.exe)

- Naciśnij ▶ aby uruchomić


## Testowanie

Każda funkcja posiada testy jednostkowe (`tests/`) sprawdzające poprawność działania oraz przypadki brzegowe.


## Autor

Projekt opracowany w ramach ćwiczeń z metod numerycznych przez Joannę Polak i Wiktorię Rychlak.


