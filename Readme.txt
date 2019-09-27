TDA Cola (Nodos Simplemente Enlazados)

La implementación del TDA Cola incluído en 'TDA Cola (Lucas Leoni).zip' posee los siguientes programas:
    1) 'cola.h' es la biblioteca que incluye las firmas de las funciones primitivas para el funcionamiento de la cola.
    2) 'cola.c' es el programa con la implementación de la cola.
    3) 'minipruebas_cola.c' es el programa que contiene las pruebas que testean el funcionamiento de la cola implementada.
    4) 'makefile' es el programa que facilita el acceso a las líneas de compilación y ejecución de la cola, las pruebas y Valgrind.
    5) 'Consigna' es la consigna del trabajo pŕactico.


Funciones del TDA cola

Aclaración: todas las funciones utilizadas verifican (previo a ser ejecutadas) que no haya ningún error,
            (ver 'Funciones Propias > Verificación de errores generales').

1) Creación de la cola ---> cola_t* cola_crear();
     Crea la estructra 'cola_t cola'.
     Devuelve un puntero a la estructura 'cola_t cola' inicializada y reserva la memoria necesaria para su almacenamiento en el Heap.
     Devuelve NULL en caso de haber habido un error al crear la cola.

2) Encolar elementos ---> int cola_encolar(cola_t* cola, void* elemento);
     Encola el elemento recibido, resevando la memoria necesaria para el nuevo nodo que lo contiene y actualizando los punteros correspondientes.
     Si la cola esta vacía, tanto el 'inicio' como el 'fin' de la cola apuntan al nuevo nodo (el único).
     Disminuye la cantidad de elementos de la cola.
     Devuelve '0' si la operación tuvo éxito y '-1' si falló.

3) Desencolar elementos ---> int cola_desencolar(cola_t* cola);
     Desencola el elemento en la primera posición de la cola (posición inicio), actualizando los puntero correspondientes y liberando
     la memoria ocupada por el nodo desencolado.
     Disminuye la cantidad de elementos de la cola.
     Devuelve '0' si la operación tuvo éxito y '-1' si falló.

4) cola vacía ---> bool cola_vacia(cola_t* cola);
     Determina si la cola está vacía (es decir, si tiene 0 elementos/nodos).
     Devuelve 'true' si la cola está vacía o es nula, y 'false' en cualquier otro caso.

5) Cantidad de elementos ---> int cola_cantidad(cola_t* cola);
     Devuelve la cantidad de elementos/nodos presentes en la cola.
     Devuelve '0' si la cola es nula o está vacía.

6) Primer elemento de la cola ---> void* cola_primero(cola_t* cola);
     Devuelve un puntero al primer elemento de la cola (el elemento situado en la posición 'inicio', sea cual sea su tipo de dato).
     Devuelve NULL si la cola es nula o está vacía.

7) Destrucción de la cola ---> void cola_destruir(cola_t* cola);
     En caso de no estar vacía, desencola todos los elmentos/nodos de la cola hasta que no tenga ninguno.
     Luego, destruye la estructura 'cola_t cola' (liberando la memoria ocupada por ella).


Función Propia (para modularizar la implementacíon de la cola)

1) Verificación de errores generales ---> bool hay_error(cola_t* cola);
     Devuelve 'true' si:
        1.1) La estructura 'cola_t cola' es nula.
        1.2) La cantidad de elementos es menor a 0.
        1.3) El 'nodo_inicio' es nulo y el 'nodo_fin' no lo es, o viceversa.


Pruebas (Testing)

En la carpeta se incluye una serie de pruebas que testean casos bordes, intermedios y normales del funcionamiento de la cola.
Todas las funciones que requieren que la estructura 'cola_t cola' no sea nula, verifican previamente si esta fue creada con éxito y,
de no ser así, imprimen por pantalla que la prueba no pudo ser llevada a cabo.
Si una prueba es ejecutada, destruye la estructura al finalizar, liberando la memoria utilizada para la misma.
Las pruebas (funciones void) implementadas son las siguientes:

1) ejecutar_caso_feliz();
     Es la prueba provista por la cátedra, cuyo funcionamiento es encolar 4 elementos, imprimiendo luego por pantalla la cantidad de nodos
     que la cola posee (para verificar si efectivamente fueron todos encolados). Después, desencola uno de ellos y vuelve a imprimir
     la cantidad (para testear la funcion que desencola). Verifica si la cola está vacía (la respuesta debería de 'NO', dado que ahora posee 3 nodos).
     Finalmente, imprime el elemento en la posición 'inicio', para terminar destruyendo la estructura y liberar la memoria utilizada.

     Esta prueba testea:
        1.1) La creación de la estructura 'cola_t cola'.
        1.2) El encolamiento/desencolamiento de varios elementos.
        1.3) Si las funciones 'cola_cantidad', 'cola_vacia' y 'cola_primero' funcionan correctamente.
        1.4) La destrucción de la estructura 'cola_t cola' (verificada al correr el comando 'make valgrind').
    
2) desencolar_cola_vacia_deberia_devolver_NULL();
     Intenta desencolar un elemento de la cola vacía e imprime por pantalla si efectivamente la función 'cola_desencolar' devuelve NULL.

3) si_la_cola_es_nula_deberia_fallar_encolar_y_desencolar();
     Se inicializa un puntero 'cola_t* cola' en NULL (un cola nula) y se verifica si las funciones encolar y desencolar devuelven ambos
     el código error establecido (-1), imprimiendo el resultado de la prueba por pantalla.

4) ver_primer_elemento_de_cola_nula_deberia_devolver_NULL();
     Se inicializa un puntero 'cola_t* cola' en NULL (un cola nula) y se verifica si ver el primer elemento/nodo de la cola devuelve NULL,
     imprimiendo el resultado de la prueba por pantalla.

5) si_la_cola_esta_vacia_entonces_cola_cantidad_deberia_devolver_cero();
     Se crea una estructura 'cola_t* cola' a la que no se le encola ningún elemento/nodo, para verificar (imprimiendo por pantalla el resultado
     de la prueba) si la función 'cola_cantidad' devuelve '0'.

6) si_encolo_y_desencolo_la_misma_cantidad_de_elementos_deberian_salir_en_el_orden_que_fueron_encolados();
     Se crea una estructura 'cola_t* cola', un 'int vector[]' de 5 elementos y un 'int contador_coincidencias'. Se encolan todos los elementos del vector
     Luego, se crea una estructura de control iterativa que compara el elemento devuelvo por la función 'cola_primero' con el primer elemento
     del vector; si estos son iguales, el contador aumenta en una unidad. Después, este elemento se desencola y vuelve a comenzar el ciclo hasta
     que la cola esté vacía.
     Finalmente, se imprime por pantalla el resultado de la prueba (si el contador de coincidencias es igual a la cantidad de elementos
     encolados/desencolados, la prueba fue superada con éxito).


Compilación y Convenciones

1) Tamaño de la cola
     Inicialmente, la cola se creará totalmente vacía (0 elementos/nodos).

2) Makefile
   La carpeta cuenta con un programa 'makefile' que posee los siguientes comandos:
     3.1) 'make compile' compilará el programa 'cola.c' junto con las pruebas que testean su funcionamiento, ejecutando la línea de compilación:
              gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 cola.c minipruebas_cola.c -o cola_ne -g

     3.2) 'make cola' compilará el programa con la línea mencionada en el punto (3.1) y luego ejecutará las pruebas (incluídas en la carpeta) con la línea:
              ./cola_ne

     3.2) 'make valgrind' ejecutrá Valgrind (mostrando los resultados de las pruebas por pantalla) con la línea:
              valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./cola_ne
