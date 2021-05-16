#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#define TAM 5

int main(void)
{

    setbuf(stdout, NULL);

    eEmpleado nomina[TAM];

    char seguir = 's';
    char confirma;

    inicializarEmpleados(nomina, TAM);
    do
    {
        switch (menu())
        {
        case 1:
            if(altaEmpleado (nomina, TAM)==1)
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Hubo un problema en el alta del empleado\n");
            }

            break;
        case 2:
            modificarEmpleado(nomina, TAM);
            break;
        case 3:
            if(bajaEmpleado(nomina, TAM)==1)
            {
                printf("Baja exitosa\n");
            }
            else
            {
                printf("Hubo un problema en la baja del empleado\n");
            }
            break;
        case 4:
          if(ordenarEmpleados(nomina, TAM)==1 &&
            mostrarEmpleados(nomina, TAM)==1 &&
            FSueldos(nomina, TAM)==1){
            printf("Se ordeno por apellido y sector");
            }
            break;
        case 5:
            printf ("Seguro que quiere salir?: ");
            fflush (stdin);
            scanf ("%c", &confirma);
            if (confirma=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf("Opcion invalida\n\n");

        }
        system ("pause");

    }
    while (seguir=='s');

    return 0;
}
