TDA Cola (Nodos Simplemente Enlazados)

La implementación del TDA Cola incluído en 'TDA Cola (Lucas Leoni).zip' posee los siguientes programas:
    1) 'cola.h' es la biblioteca que incluye las firmas de las funciones primitivas para el funcionamiento de la cola.
    2) 'cola.c' es el programa con la implementación de la cola.
    3) 'makefile' es el programa que facilita el acceso a las líneas de compilación y ejecución de la cola, las pruebas y Valgrind.
    4) 'Consigna' es la consigna del trabajo pŕactico.


Funciones del TDA cola

Aclaración: todas las funciones utilizadas verifican (previo a ser ejecutadas) que no haya ningún error,
            (ver 'Funciones Propias > Verificación de errores generales').

1) Creación de la cola ---> pila_t* pila_crear();
     Crea la estructra 'pila_t cola'.
     Devuelve un puntero a la estructura 'pila_t cola' inicializada y reserva la memeoria necesaria para su almacenamiento en el Heap.
     Devuelve NULL en caso de haber habido un error al crear la cola.

2) Apilar elementos ---> int pila_apilar(pila_t* cola, void* elemento);
     Apila el elemento recibido, redimensionando la cola en caso de que esta se encuentre llena antes de apilar
     (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').
     Devuelve '0' si la operación tuvo éxito y '-1' si falló.

3) Desapilar elementos ---> int pila_desapilar(pila_t* cola);
     Desapila el elemento en la última posición de la cola y verifica si es necesario redimensionar
     (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').
     Devuelve '0' si la operación tuvo éxito y '-1' si falló.

4) cola vacía ---> bool pila_vacia(pila_t* cola);
     Determina si la cola está vacía (es decir, si tiene 0 elementos).
     Devuelve 'true' si la cola está vacía o es nula, y 'false' en cualquier otro caso.

5) Cantidad de elementos ---> int pila_cantidad(pila_t* cola);
     Devuelve la cantidad de elementos presentes en la cola.
     Devuelve '0' si la cola es nula o está vacía.

6) Tope de la cola ---> void* pila_tope(pila_t* cola);
     Devuelve el último elemento de la cola (el elemento situado en la posición tope, sea cual sea su tipo de dato).
     Devuelve NULL si la cola es nula o está vacía.

7) Destrucción de la cola ---> void pila_destruir(pila_t* cola);
     Destruye la estructura 'pila_t cola' (liberando toda la memoria previamente ocupada/reservada por/para ella en el Heap).


Funciones Propias (para modularizar la implementacíon de la cola)

1) Verificación de errores generales ---> bool hay_error(pila_t* cola);
     Devuelve 'true' si:
        1.1) La estructura 'pila_t cola' es nula.
        1.2) El vector de elementos es nulo.
        1.3) El tope del vector es menor a 0.
        1.4) El tope del vector es mayor al tamaño de la cola.

2) Verificación de cola llena ---> bool pila_llena(pila_t* cola);
     Determina si la cola está llena.
     Devuelve 'true' si la cola está llena (es decir, si tiene tantos elementos como espacios en ella).
     Si la cola no existe devolverá 'false'.

3) Redimensionamiento de la cola ---> int pila_redimensionar(pila_t* cola, int nuevo_tamanio);
     Redimensiona el tamaño de la cola según el tamaño/proporción recibido.
     Devuelve '0' si pudo redimensionar o '-1' en caso contrario.


Pruebas (Testing)

En la carpeta se incluye una serie de pruebas que testean casos bordes, intermedios y normales del funcionamiento de la cola.
Todas las funciones que requieren que la estructura 'pila_t cola' no sea nula, verifican previamente si esta fue creada con éxito y,
de no ser así, imprimen por pantalla que la prueba no pudo ser llevada a cabo.
Si una prueba es ejecutada, destruye la estructura al finalizar, liberando la memoria utilizada para la misma.
Las pruebas (funciones void) implementadas son las siguientes:

1) ejecutar_caso_feliz();
     Es la prueba provista por la cátedra, cuyo funcionamiento es apilar 6 elementos y, por cada vez que apila, imprimir por pantalla
     la cantidad de elementos que la cola posee (para verificar si efectivamente fueron todos apilados). Luego, imprime el elemento
     en la posición tope y lo despila, mostrando el nuevo tamaño de la cola (siguiendo este algoritmo hasta que el tamaño sea 0),
     para finalmente destruir la estructura y liberar la memoria utilizada.

     Esta prueba testea:
        1.1) La creación de la estructura 'pila_t cola'.
        1.2) El apilamiento/desapilamiento de varios elementos.
        1.3) Si las funciones 'pila_cantidad' y 'pila_tope' funcionan correctamente.
        1.4) La destrucción de la estructura 'pila_t cola' (verificada al correr el comando 'make valgrind').
    
2) desapilar_pila_vacia_deberia_devolver_NULL();
     Intenta desapilar un elemento de la cola vacía e imprime por pantalla si efectivamente la función 'pila_desapilar' devuelve NULL.

3) llenar_pila_y_volver_a_apilar_deberia_redimensionar();
     Llena la cola hasta que tenga tantos elementos como espacios disponibles (es decir, hasta que el tope sea igual al tamaño).
     Luego, apila un elemento más y verifica (imprimiendo por pantalla) si la cola fue redimensionada según la convención establecida
     (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').

4) desapilar_hasta_la_mitad_de_su_tamanio_deberia_redimensionar();
     Apila 11 elementos (uno más que la capacidad inicial) para redimensionar la cola. Luego, desapila el último (tal que la cantidad
     de elementos sea igual a la mitad de su tamaño), teniendo que redimensionar y verifica (imprimiendo por pantalla) si la
     redimensión se corresponde con la convención establecida (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').

5) si_la_pila_es_nula_deberia_fallar_apilar_y_desapilar();
     Se inicializa un puntero 'pila_t* cola' en NULL (un cola nula) y se verifica si apilar y desapilar devuelven ambos
     el código error establecido (-1), imprimiendo el resultado de la prueba por pantalla.

6) ver_tope_de_pila_nula_deberia_devolver_NULL();
     Se inicializa un puntero 'pila_t* cola' en NULL (un cola nula) y se verifica si ver el tope de la cola devuelve NULL,
     imprimiendo el resultado de la prueba por pantalla.

7) si_la_pila_esta_vacia_entonces_pila_cantidad_deberia_devolver_cero();
     Se crea una estructura 'pila_t* cola' a la que no se le apila ningún elemento, para verificar (imprimiendo por pantalla el resultado
     de la prueba) si la función 'pila_cantidad' devuelve '0'.

8) si_lleno_y_vacio_la_pila_el_tamanio_no_deberia_ser_inferior_al_inicial();
     Se crea una estructura 'pila_t* cola', que es llenada y luego vaciada, para verificar (imprimiendo por pantalla el resultado de la prueba)
     si su tamaño es igual al tamaño inicial.


Compilación y Convenciones

1) Tamaño de la cola
     Inicialmente, la cola se creará con un tamaño mínimo de 10 espacios libres y totalmente vacía.
     El mismo nunca será inferior al inicial (incluso si se la vacía por completo).

2) Criterio de Redimensionamiento
     2.1) Si la cola está llena y se intenta apilar un elemento más, se duplicará su tamaño y luego se apilará el elemento.
     2.2) Si se desapilan elementos hasta llegar a la mitad de su tamaño, el mismo se reducirá a la cantidad de elementos presentes en la cola.
          Caso borde: Al redimensionar, la cola nunca quedará con un tamaño inferior al inicial.

3) Makefile
   La carpeta cuenta con un programa 'makefile' que posee los siguientes comandos:
     3.1) 'make compile' compilará el programa 'cola.c' junto con las pruebas que testean su funcionamiento, ejecutando la línea de compilación:
              gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 cola.c minipruebas_pila_vd.c -o pila_vd -g

     3.2) 'make cola' compilará el programa con la línea mencionada en el punto (3.1) y luego ejecutará las pruebas (incluídas en la carpeta) con la línea:
              ./pila_vd

     3.2) 'make valgrind' ejecutrá Valgrind (mostrando los resultados de las pruebas por pantalla) con la línea:
              valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pila_vd
