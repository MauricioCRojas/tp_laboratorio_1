#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int status=-1;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            printf("Archivo de texto cargado exitosamente\n");
            break;

        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            printf("Archivo binario cargado exitosamente\n");
            break;

        case 3:
            status=controller_addEmployee(listaEmpleados);
            if(status!=-1)
            {
                printf("Empleado dado de alta con exito\n");
            }
            else
            {
                printf("Fallo el alta de empleado\n");
            }
            break;
        case 4:
            controller_editEmployee(listaEmpleados);

            break;
        case 5:
            controller_removeEmployee(listaEmpleados);

            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);

            break;
        case 8:
            controller_saveAsText("data.csv",listaEmpleados);

            break;
        case 9:
            if(controller_saveAsBinary("data.bin",listaEmpleados))
            {
                printf("Se guardo el archivo binario con exito\n");
            }

            break;
        case 10:
            option=10;
            printf("Salida exitosa\n");
            break;
        }
        system("pause");
    }
    while(option != 10);
    return 0;
}

