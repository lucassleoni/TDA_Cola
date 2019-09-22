#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

#define PRUEBA_4 "la prueba #4"

// Pre C.: ---
// Post C.: Muestra por pantalla el error al intentar crear la estructura cola_t cola.
void imprimir_error_de_prueba(char* prueba){
    printf("\nOcurrió un error al crear la cola, %s no pudo ser ejecutada.\n", prueba);
}

// Pre C.: ---
// Post C.: Ejecuta las pruebas provistas por la cátedra.
void ejecutar_caso_feliz(){
    cola_t* cola = cola_crear();

    int a = 1, b = 2, c = 3, d = 4;

    printf("Prueba: 'Ejecutar Caso Feliz'\n\n");

    printf("    Encolo el elemento: %i\n", a);
    cola_encolar(cola, (void*)&a);

    printf("    Encolo el elemento: %i\n", b);
    cola_encolar(cola, (void*)&b);

    printf("    Encolo el elemento: %i\n", c);
    cola_encolar(cola, (void*)&c);

    printf("    Encolo el elemento: %i\n", d);
    cola_encolar(cola, (void*)&d);

    printf("\n    La cola tiene: %i elementos\n", cola_cantidad(cola));
        
    printf("    Desencolo un elemento...\n");
    cola_desencolar(cola);

    printf("    La cola tiene: %i elementos\n", cola_cantidad(cola));

    printf("\n    ¿La cola está vacía? %s\n", cola_vacia(cola)?"SI":"NO");

    printf("\n    El primer elemento de la cola es: %i\n", *(int*)cola_primero(cola));

    cola_destruir(cola);
}

// Pre C.: ---
// Post C.: Crea una cola vacía e imprime por pantalla el resultado de la prueba al intentar desencolar un elemento.
void desencolar_cola_vacia_deberia_devolver_NULL(){
    cola_t* cola = cola_crear();

    printf("\nPrueba #1: Verificar si desencolar un elemento de la cola vacía devuelve ERROR.\n");
    printf("\t%s: Al intentar desencolar un elemento de la cola vacía, la funcion cola_desencolar %s error. \n",
        (cola_desencolar(cola) == FALLO)?"EXITO":"FALLO",
        (cola_desencolar(cola) == FALLO)?"devuelve":"no devuelve");

    cola_destruir(cola);
}

// Pre C.: ---
// Post C.: Imprime por pantalla si el resultado de la prueba al encolar/desencolar en una cola nula obtuvo la respuesta esperada.
void si_la_cola_es_nula_deberia_fallar_encolar_y_desencolar(){
    cola_t* cola = NULL;

    printf("\nPrueba #2: Verificar si hay error al intentar encolar o desencolar en una cola nula.\n");
    
    int elemento = 14;
    printf("\t%s: encolar y desencolar sobre una cola nula %s el código de error establecido (-1).\n",
        ((cola_encolar(cola, &elemento) == FALLO) && (cola_desencolar(cola) == FALLO))?"EXITO":"FALLO",
        ((cola_encolar(cola, &elemento) == FALLO) && (cola_desencolar(cola) == FALLO))?"devuelve":"no devuelve");
}

// Pre C.: ---
// Post C.: Imprime por pantalla el resultado de intentar ver el primer elemento de una cola nula (que debería ser NULL).
void ver_primer_elemento_de_cola_nula_deberia_devolver_NULL(){
    cola_t* cola = NULL;

    printf("\nPrueba #3: Verificar si ver el primer elemento de una cola nula devuelve NULL.\n");
    printf("\t%s: ver primer elemento de cola nula %s NULL.\n",
        (cola_primero(cola) == NULL?"EXITO":"FALLO"),
        (cola_primero(cola) == NULL?"devuelve":"no devuelve"));
}

// Pre C.: ---
// Post C.: Crea una cola vacía e imprime el resultado de ejecutar la función cola_cantidad por pantalla.
void si_la_cola_esta_vacia_entonces_cola_cantidad_deberia_devolver_cero(){
    cola_t* cola = cola_crear();
    if(!cola){
        imprimir_error_de_prueba(PRUEBA_4);
        return;
    }

    printf("\nPrueba #4: Si la cola esta vacía, la función cola_cantidad devuelve 0.\n");
    printf("\t%s: al estar vacía la cola, la función cola_cantidad %s 0.\n",
        ((cola_cantidad(cola) == COLA_VACIA)?"EXITO":"FALLO"),
        ((cola_cantidad(cola) == COLA_VACIA)?"devuelve":"no devuelve"));

    cola_destruir(cola);
}

int main(){
    system("clear");

    ejecutar_caso_feliz();

    desencolar_cola_vacia_deberia_devolver_NULL();
    si_la_cola_es_nula_deberia_fallar_encolar_y_desencolar();
    ver_primer_elemento_de_cola_nula_deberia_devolver_NULL();
    si_la_cola_esta_vacia_entonces_cola_cantidad_deberia_devolver_cero();

    return 0;
}