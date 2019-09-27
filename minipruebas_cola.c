#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

// Constantes:
    #define PRUEBA_4 "la prueba #4"
    #define PRUEBA_5 "la prueba #5"

    #define FALLO -1
    #define EXITO 0
    #define COLA_VACIA 0
    #define UNICO_NODO 1
    #define MAX_VECTOR 5

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

void si_encolo_y_desencolo_la_misma_cantidad_de_elementos_deberian_salir_en_el_orden_que_fueron_encolados(){
    cola_t* cola = cola_crear();
    if(!cola){
        imprimir_error_de_prueba(PRUEBA_5);
        return;
    }

    int elementos[MAX_VECTOR] = {1, 2, 3, 4, 5};
    int contador_coincidencias = 0;
    int i = 0;

    printf("\nPrueba #5: Si encolo y desencolo la misma cantidad de elementos, estos salen en el orden en que entraron.\n");
    for(int i = 0; i < MAX_VECTOR; i++){
        cola_encolar(cola, &elementos[i]);
    }

    while((!cola_vacia(cola)) && (i < MAX_VECTOR)){
        if(*(int*)cola_primero(cola) == elementos[i]){
            contador_coincidencias++;
        }
        cola_desencolar(cola);
        i++;
    }

    printf("\t%s: al encolar y desencolar la misma cantidad de elementos, estos %s en el orden en que entraron.\n",
        (contador_coincidencias == MAX_VECTOR?"EXITO":"FALLO"),
        (contador_coincidencias == MAX_VECTOR?"salen":"no salen"));

    cola_destruir(cola);
}

int main(){
    system("clear");

    //ejecutar_caso_feliz();

    desencolar_cola_vacia_deberia_devolver_NULL();
    si_la_cola_es_nula_deberia_fallar_encolar_y_desencolar();
    ver_primer_elemento_de_cola_nula_deberia_devolver_NULL();
    si_la_cola_esta_vacia_entonces_cola_cantidad_deberia_devolver_cero();
    si_encolo_y_desencolo_la_misma_cantidad_de_elementos_deberian_salir_en_el_orden_que_fueron_encolados();

    return 0;
}