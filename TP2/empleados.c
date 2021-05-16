#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "validaciones.h"




//ID autoincremental
static int idIncremental = 0;

int incrementarId(void) {

	return idIncremental+=1;
}

int FSueldos (eEmpleado lista[], int tam){
    int todoOk=0;
    float acumSueldos=0;
    int contSueldos=0;
    float promSueldos=0;
    int contSueldoMasQueProm=0;


    for (int i=0; i<tam; i++){
        if (lista[i].isEmpty==0){
        acumSueldos+= lista[i].sueldo;
        contSueldos++;
        }
        todoOk=1;
    }
    if (contSueldos>0){
    printf("El total de sueldos es %.2f\n", acumSueldos);
    promSueldos=acumSueldos/contSueldos;
    printf("El promedio de sueldos es %.2f\n", promSueldos);
    for (int i=0; i<tam; i++){

        if(lista[i].sueldo>promSueldos && lista[i].isEmpty==0){
            contSueldoMasQueProm++;
        }
    }
    printf("La cantidad de sueldos que superan el promedio es de %d\n", contSueldoMasQueProm);
    }
    else{
        printf("No se ingresaron empleados\n");
    }

    return todoOk;
}


//Mostrar empleado (uno)
void mostrarEmpleado (eEmpleado unEmpleado)
{
    printf("%d    %10s        %10s         %.2f        %d\n",
           unEmpleado.id,
           unEmpleado.nombre,
           unEmpleado.apellido,
           unEmpleado.sueldo,
           unEmpleado.sector);
}


//Mostrar empleados (todos)
int mostrarEmpleados(eEmpleado lista[], int tam)
{
    int todoOk=0;
    int flagSeIngEmpleados=0;
    if(lista!=NULL && tam>0)
    {
        todoOk=1;
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                flagSeIngEmpleados=1;
                break;
            }
        }
        if(flagSeIngEmpleados)
        {
            printf("      LISTA DE EMPLEADOS\n");
            printf("Legajo      Nombre           Apellido      Sueldo        Sector\n");
        }
        else
        {
            printf("NO HAY EMPLEADOS CARGADOS POR EL MOMENTO...\n");
        }
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                mostrarEmpleado(lista[i]);
            }
        }
    }
    return todoOk;
}


//Ordenamiento empleados
int ordenarEmpleados (eEmpleado lista[], int tam)
{
    int todoOk=0;
    eEmpleado auxStruct;
    for (int i=0; i < tam-1 ; i++)
    {
        for (int j=i+1 ; j < tam; j++)
        {
            if (strcmp(lista[i].apellido, lista[j].apellido)>0 ||
                (strcmp(lista[i].apellido, lista[j].apellido)>0 && lista[i].sector > lista[j].sector))

            {
                auxStruct=lista[i];
                lista[i]=lista[j];
                lista[j]=auxStruct;
                todoOk=1;
            }
        }
    }
        return todoOk;
}



//Menu ABM
int menu (void)
{
    int opcion;
    system("cls");
    printf ("Gestion de empleados\n\n");
    printf ("1- Alta empleado\n");
    printf ("2- Modificar empleado\n");
    printf ("3- Baja empleado\n");
    printf ("4- Informar\n");
    printf ("5- Salir\n");
    printf ("Ingrese opcion: ");
    scanf ("%d", &opcion);

    return opcion;
}


//Menu modificaciones
int menuModificaciones (void)
{
    int opcion;
    system("cls");
    printf ("Modificacion de empleados\n\n");
    printf ("1- Modificar nombre\n");
    printf ("2- Modificar apellido\n");
    printf ("3- Modificar sueldo\n");
    printf ("4- Modificar id de sector\n");
    printf ("5- Salir/Guardar/Cancelar\n");
    printf ("Ingrese opcion: ");
    scanf ("%d", &opcion);

    return opcion;
}

//Inializo isEmpty en 1
void inicializarEmpleados (eEmpleado lista[], int tam)
{
    for (int i=0; i<tam; i++)
    {
        lista[i].isEmpty=1;
    }
}


//Alta empleado
int altaEmpleado (eEmpleado lista[], int tam)
{

    system("cls");
    printf("       Alta empleado\n\n");

    int todoOk=0;
    int indice;
    eEmpleado nuevoEmpleado;

    indice = buscarLibre(lista, tam);

    if (lista != NULL && tam > 0)
    {
        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            incrementarId();
            printf("Id: %d\n", idIncremental);
            nuevoEmpleado.id=idIncremental;
            dam_getNombre(nuevoEmpleado.nombre, "Ingrese nombre: ", "Error\n", 51, 2);
            dam_getNombre(nuevoEmpleado.apellido, "Ingrese apellido: ", "Error\n", 51, 2);
            dam_getNumeroFlotante(&nuevoEmpleado.sueldo, "Ingrese sueldo: ", "Error\n", 0, 9999, 2);
            dam_getNumero(&nuevoEmpleado.sector, "Ingrese sector de 100 a 105: ", "Error\n", 100, 105, 2);
            nuevoEmpleado.isEmpty=0;
            lista[indice]=nuevoEmpleado;
            todoOk=1;
        }
    }

    return todoOk;
}

//Buscar libre
int buscarLibre (eEmpleado lista[], int tam)
{
    int indice = -1;

    if (lista != NULL && tam > 0)
    {

        for (int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;

}

//Buscar empleado
int buscarEmpleado (eEmpleado lista[], int tam, int id)
{
    int indice = -1;

    if (lista != NULL && tam > 0)
    {

        for (int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0 && lista[i].id==id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;

}


//Baja empleado
int bajaEmpleado (eEmpleado lista[], int tam)
{
    int todoOk=0;
    int indice=-1;
    int id;
    char confirma;

    system("cls");

    printf("    Baja empleado\n\n");
    mostrarEmpleados(lista, tam);
    printf("Ingrese id:");
    scanf("%d", &id);

    indice= buscarEmpleado(lista, tam, id);
    if (indice==-1)
    {
        printf("No existe un empleado con el id %d\n", id);
    }
    else
    {
        mostrarEmpleado(lista[indice]);
        printf("Confirma baja?:");
        fflush(stdin);
        scanf("%c", &confirma);

        if (confirma=='s')
        {
            lista[indice].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }

    return todoOk;
}




//Modificar empleado
int modificarEmpleado(eEmpleado lista[], int tam)
{

    int todoOk=0;
    int indice=-1;
    int id;
    char confirma;
    char confirma2='s';
    eEmpleado auxEmpleado;
    int flagNombre=0;
    int flagApellido=0;
    int flagSueldo=0;
    int flagIdSec=0;

    system("cls");

    printf("    Modificar empleado\n\n");
    mostrarEmpleados(lista, tam);
    printf("Ingrese id:");
    scanf("%d", &id);

    indice= buscarEmpleado(lista, tam, id);

    if (indice==-1)
    {
        printf("No existe un empleado con el id %d\n", id);
    }
    else
    {
        mostrarEmpleado(lista[indice]);

        do
        {
            switch(menuModificaciones())
            {
            case 1:
                mostrarEmpleado(lista[indice]);
                dam_getNombre(auxEmpleado.nombre, "Ingrese nuevo nombre: ", "Error\n", 51, 2);

                flagNombre=1;
                break;
            case 2:
                mostrarEmpleado(lista[indice]);
            dam_getNombre(auxEmpleado.apellido, "Ingrese nuevo apellido: ", "Error\n", 51, 2);

                flagApellido=1;
                break;
            case 3:
                mostrarEmpleado(lista[indice]);
            dam_getNumeroFlotante(&auxEmpleado.sueldo, "Ingrese nuevo sueldo: ", "Error\n", 0, 9999, 2);

                flagSueldo=1;
                break;
            case 4:
                mostrarEmpleado(lista[indice]);
            dam_getNumero(&auxEmpleado.sector, "Ingrese nuevo sector de 100 a 105: ", "Error\n", 100, 105, 2);

                flagIdSec=1;
                break;
            case 5:
                confirma2='n';
                break;
            default:
                printf("Opcion invalida\n");

            }
        }
        while(confirma2== 's');

        printf("Confirma modificacion s/n?:");
        fflush(stdin);
        scanf("%c", &confirma);

        if (confirma=='s')
        {
            if(flagNombre==1)
            {
                strcpy(lista[indice].nombre, auxEmpleado.nombre);
                flagNombre=0;
            }
            if(flagApellido==1)
            {
                strcpy(lista[indice].apellido, auxEmpleado.apellido);
                flagApellido=1;
            }
            if (flagSueldo==1)
            {
                lista[indice].sueldo = auxEmpleado.sueldo;
                flagSueldo=0;
            }
            if(flagIdSec==1)
            {
                lista[indice].sector =   auxEmpleado.sector;
                flagIdSec=0;
            }
            todoOk=1;
            printf("Modificacion exitosa\n");
        }
        else
        {
            printf("Modificacion cancelada por el usuario\n");
        }
    }

    return todoOk;
}

