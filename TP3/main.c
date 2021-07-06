#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

//opcion 9 no disponible sin antes la 1o2
//no se puede la 2, sin antes la 1
//opcion 4,5,6,7 sin antes la 1,2o3
//opcion 8y9 solamente disp si ll_len es mayor a 0

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
    int flagBin=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("Archivo de texto cargado exitosamente\n");
            }
            else
            {
                printf("Fallo al cargar archivo de texto\n");
            }
            break;

        case 2:
            if(flagBin==1)
            {
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Archivo binario cargado exitosamente\n");
                }
                else
                {
                    printf("Fallo al cargar archivo binario\n");
                }
            }
            else
            {
                printf("Aun no se ha creado el binario\n");
            }
            break;
        case 3:
            if(controller_addEmployee(listaEmpleados))
            {
                printf("Empleado dado de alta con exito\n");
            }
            else
            {
                printf("Fallo el alta de empleado\n");
            }
            break;
        case 4:
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("Empleado editado correctamente\n");
                }
                else
                {
                    printf("Error al intentar editar empleado\n");
                }
            }
            else
            {
                printf("No hay empleados cargados al momento\n");
            }
            break;
        case 5:
            if(ll_len(listaEmpleados)>0)
            {

                if(controller_removeEmployee(listaEmpleados))
                {
                    printf("Empleado eliminado correctamente\n");
                }
                else
                {
                    printf("Error al intentar eliminar empleado\n");
                }
            }
            else
            {
                printf("No hay empleados cargados al momento\n");

            }

            break;
        case 6:
            if(ll_len(listaEmpleados)>0)
            {

                if(controller_ListEmployee(listaEmpleados))
                {
                    printf("Empleados mostrados con exito\n");
                }
                else
                {
                    printf("Error al mostrar empleados\n");
                }
            }
            else
            {
                printf("No hay empleados cargados al momento\n");

            }
            break;
        case 7:
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("Empleados ordenados con exito\n");
                }
                else
                {
                    printf("Error al ordenar empleados\n");
                }
            }
            else
            {
                printf("No hay empleados cargados al momento\n");

            }
            break;
        case 8:
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("Archivo de texto guardado con exito\n");

                }
                else
                {
                    printf("Error al intentar guardar archivo de texto\n");

                }
            }
            else
            {
                printf("No hay empleados cargados por el momento\n");
            }
            break;
        case 9:
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("Se guardo el archivo binario con exito\n");
                    flagBin=1;
                }
                else
                {
                    printf("Error al intentar guardar archivo binario\n");

                }
            }
            else
            {
                printf("No hay empleados cargados por el momento\n");

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

