# Practica 1

Se quiere realizar un censo de personas que tengan los siguientes datos:

  - Nombre
  - Año de nacimiento
  - DNI
  - Teléfono

Para ello se pide implementar un clase que incluya dichos atributos.

Además la clase debe tener los siguientes métodos (aparte de los métodos getter y setter para dar valor y leer los atributos)
  - print que muestra por pantalla los datos de la persona.
  - age que recibe como parámetro un año (int) y devuelve la edad que tenía en dicho año.
  - isAdult que recibe como parámetro el un año (int) y devuelve si en dicho año la persona era mayor de edad o no.

Se pide:

  1. Implementar dicha clase en los archivos persona.h y persona.cpp
  2. Realizar un programa que pida al usuario los datos de 5 Personas
  3. Almacenar estas personas en variables puntero a Persona
  4. Crear un vector de punteros a Persona con estas Personas
  5. Utilizando programación funcional (composición de funciones) realizar un función find a través de la cual puedas buscar una persona por un criterio de búsqueda (función lambda), debe devolver el puntero a la persona encontrada
