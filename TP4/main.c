#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


//Genero una estructura eMascota
typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char sexo;
} eMascota;


//Prototipos funciones
void mostrarMascota(eMascota* mascota);
void mostrarMascotas(LinkedList* lista);
int esMacho(void* m);
int esHembra(void* m);
int mayor5(void* m);
int esMilo(void* m);
int comparaMascotas(void* pMascotaA,void* pMascotaB);


int main()
{

    //Genero un nuevo LL
    LinkedList* lista = ll_newLinkedList(); //uso funcion ll_newLinkedList

    int resultModif;
    int resultRemov;
    int resultClear;
    int resultIndex;
    int resultIsEmpty;
    int order;
    int tam;
    eMascota* resultPop;

    //Harcodeo mascotas
    eMascota m1= {0, "Milo",2, 'm'};
    eMascota m2= {1, "Alma",4, 'h'};
    eMascota m3= {2, "Leia",9, 'h'};
    eMascota m4= {3, "Odin",1, 'm'};
    eMascota m5= {4, "Paul",7, 'm'};
    eMascota m6= {5, "Hanna",5, 'h'};
    eMascota auxMascota= {6, "Lila",3, 'h'};


    //Asigno a a traves de ll_add, los datos
    ll_add(lista, &m1);
    ll_add(lista, &m2);
    ll_add(lista, &m3);
    ll_add(lista, &m4);
    ll_add(lista, &m5);
    ll_add(lista, &m6);


    //Muestro tamanio de la lista inicial
    printf("Tamanio de la lista inicial: %d\n\n", ll_len(lista)); //uso funcion ll_len

    //Muestro lista incial completa
    printf("Lista inicial de mascotas:\n");
    mostrarMascotas(lista);
    printf("\n");


    resultModif = ll_set(lista,5,&auxMascota);//uso funcion ll_set
    if(resultModif!=-1)
    {
        printf("Uso de la funcion ll_set y ll_get para traer a Lila (auxMascota):\n");
        mostrarMascota((eMascota*) ll_get(lista, 5));
        printf("\n\n");
    }


    resultRemov = ll_remove(lista,1);//uso funcion ll_remove
    if(resultRemov!=-1)
    {
        printf("Uso de la funcion ll_remove para el id 1 (Alma):\n");
        mostrarMascotas(lista);
        printf("\n");
    }


    printf("Uso de la funcion ll_push para llevar id 0 (Milo) al final de la lista:\n");
    tam=ll_len(lista);
    ll_push(lista, tam, &m1);
    mostrarMascotas(lista);
    printf("\n");


    printf("Uso de la funcion ll_pop en vector[5] (Milo):\n");
    resultPop = (eMascota*)ll_pop(lista,5);
    mostrarMascotas(lista);
    printf("Printf donde pop guardo esa posicion del vector:\n");
    mostrarMascota(resultPop);
    printf("\n\n");


    resultIndex=ll_indexOf(lista, &m5);//uso funcion ll_indexOf
    printf("El indice buscando con ll_indexOf es %d\n\n\n", resultIndex);


    if(ll_contains(lista,&m1))//uso funcion ll_contains
    {
        printf ("Uso funcion ll_contains con exito\n\n\n");
    }
    else
    {
        printf("Fallo funcion contains\n\n\n");
    }


    LinkedList* listaClone=NULL;
    listaClone=ll_clone(lista);//uso funcion ll_clone

    printf("Uso de ll_clone y ll_containsAll\n\n");

    if(ll_containsAll(lista, listaClone))//uso funcion ll_containsAll
    {
        printf("Lista y listaClone son iguales\n\n\n");
    }
    else
    {
        printf("Las listas son diferentes\n\n\n");
    }

    printf("Uso de ll_sort para ordenar por edad ascendente (criterio 1):\n");
    order=ll_sort(lista,comparaMascotas,1);//uso de la funcion ll_sort
    mostrarMascotas(lista);
    printf("\n");


    //Filtro
    LinkedList* machos=ll_filter(lista, esMacho); //uso funcion ll_filter
    printf("Uso de funcion ll_filter para filtrar y mostrar machos:\n");

    //Muestro lista filtrada
    mostrarMascotas(machos);


    //Dejo sin elementos al Linked List
    resultClear = ll_clear(lista);//uso funcion ll_clear
    if(resultClear!=-1)
    {
        printf("Uso de la funcion ll_clear\n");
        printf("Tamanio de la lista luego del ll_clear es: %d\n\n", ll_len(lista));
    }


    //Utilizacion de ll_isEmpty
    resultIsEmpty=ll_isEmpty(lista);//guardo 1 si esta vacia, 0 si no
    if(resultIsEmpty)
    {
        printf("La lista se encuentra vacia (usando ll_isEmpty)\n");
    }
    else
    {
        printf("La lista se encuentra cargada. Se utilizo funcion ll_isEmpty\n");
    }


    //Eliminamos la lista de la memoria
    ll_deleteLinkedList(lista);//Uso de la funcion ll_deteleLinkedList
    printf("Eliminamos la LinkedList con ll_deteleLinkedList\n");

    return 0;
}

void mostrarMascota(eMascota* mascota)
{
    printf("%d %10s        %d         %c\n", mascota->id, mascota->nombre, mascota->edad, mascota->sexo);
}


void mostrarMascotas(LinkedList* lista)
{
    printf("Id      Nombre      Edad      Sexo\n");
    for(int i=0; i < ll_len(lista); i++)
    {
        mostrarMascota((eMascota*) ll_get(lista, i));
    }
    printf("\n");
}


int esMacho(void* m)
{
    int ok=0;
    eMascota* unaMascota = NULL;
    if (m!=NULL)
    {
        unaMascota=(eMascota*) m;
        if(unaMascota->sexo == 'm')
        {
            ok=1;
        }
    }
    return ok;
}



int esHembra(void* m)
{
    int ok=0;
    eMascota* unaMascota = NULL;
    if (m!=NULL)
    {
        unaMascota=(eMascota*) m;
        if(unaMascota->sexo != 'm')
        {
            ok=1;
        }
    }
    return ok;
}


int mayor5(void* m)
{
    int ok=0;
    eMascota* unaMascota = NULL;
    if (m!=NULL)
    {
        unaMascota=(eMascota*) m;
        if(unaMascota->edad > 5)
        {
            ok=1;
        }
    }
    return ok;
}



int esMilo(void* m)
{
    int ok=0;
    eMascota* unaMascota = NULL;
    if (m!=NULL)
    {
        unaMascota=(eMascota*) m;
        if(!strcmp(unaMascota->nombre, "Milo"))
        {
            ok=1;
        }
    }
    return ok;
}


int comparaMascotas(void* pMascotaA,void* pMascotaB)
{
    if(((eMascota*)pMascotaA)->edad > ((eMascota*)pMascotaB)->edad)
    {
        return 1;
    }
    if(((eMascota*)pMascotaA)->edad <
            ((eMascota*)pMascotaB)->edad)
    {
        return -1;
    }
    return 0;
}
