# Practica 4

## PASO I
Crear una clase Pair que admita una clave y un valor. Los tipos de la clave y el valor estarán templatizados.

## PASO II
Crear una clase templatizada Data que contenga un vector de Pair.

## PASO III
Crear una clase templatizada DB que contenga un vector de punteros a Data.

1. Realizar las siguientes funciones miembro de la clase DB
    - find() -> devuelve el puntero al primer Data que contenga el criterio de búsqueda.
    - filter() -> devuelve una variable de tipo DB con los punteros a Data que cumplan el criterior de búsqueda.
    - forEach() -> recorre todos los elementos Data de DB realizando alguna operación sobre ellos.

## PASO IV
Sobrecargar el operador << para Pair, Data y DB, de modo que se puedan mostrar por pantalla usando std::cout << var

## PASO V
Crear un programa main que realice lo siguiente
1. Crea una variable de tipo DB<string, string>
2. La rellena con los siguientes datos

```
  [
    {
      "nombre": "Julian",
      "apellido": "Santurche",
      "telefono": "32323232",
    },
    {
      "nombre": "Alberto",
      "apellido": "Valero",
      "telefono": "12345644",
    },
    {
      "nombre": "Julian",
      "apellido": "Romeva",
      "telefono": "12345644",
      "DNI": "23232334J",
    },
    {
      "nombre": "Lucrecia",
      "apellido": "Aveces",
      "email": "lalucre@gmail.com",
    },
  ]
```

3. Utilizar la función find para encontrar la primera ocurrencia de nombre: Julian
4. Utilizar la función filter para encontrar todas las ocurrencias de nombre: Julian
5. Mostrar los correspondientes resultados por pantalla usando el operador <<