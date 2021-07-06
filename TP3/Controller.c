#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "validaciones.h"



//ID autoincremental
//static int idIncremental = 1000;

int incrementarId(LinkedList* this)
{
    int tam=ll_len(this);
    return tam+=1;
}

int decrementarId(LinkedList* this)
{
    int tam=ll_len(this);
    return tam-=1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 todoOk / 0 error)
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f = fopen(path,"r");

    if(f!=NULL && path!= NULL && pArrayListEmployee!= NULL)
    {
        todoOk=1;
        parser_EmployeeFromText(f, pArrayListEmployee);
    }
    else
    {
        printf("No se pudo abrir el archivo texto.\n");
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int flag=0;
    int todoOk=0;
    FILE* f = fopen(path,"rb");

    if(f==NULL )
    {
        f= fopen(path, "wb");
        flag=1;
    }
    if(path== NULL || pArrayListEmployee== NULL)
    {
        printf("No se pudo abrir el archivo binario.\n");
        exit(1);
    }

    if(flag==0)
    {
        parser_EmployeeFromBinary(f, pArrayListEmployee);
        todoOk=1;
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    if (pArrayListEmployee!=NULL)
    {

        char nombre[40];
        int horasTrabajadas;
        int sueldo;
        Employee* auxEmployee=NULL;

        if(!getNombre(nombre,"Ingrese nombre: ","Error\n",128,3) &&
                !getNumero(&horasTrabajadas,"Ingrese cantidad de horas trabajadas: ", "Error\n",0,99999,3) &&
                !getNumero(&sueldo,"Ingrese sueldo: ", "Error\n",1,999999,3))
        {
            auxEmployee = employee_newParametros(incrementarId(pArrayListEmployee), nombre, horasTrabajadas, sueldo);

            if(auxEmployee!=NULL)
            {
                todoOk=1;
                ll_add(pArrayListEmployee, auxEmployee);
            }
        }
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    //Mostramos todos los empleados activos
    //Preguntamos el id del empleado a modificar
    //Muestro empleado seleccionado (Guardamos el empleado encontrado en auxEmployee)
    //Muestro submenu de opciones a modificar
    int todoOk=0;

    if (pArrayListEmployee!=NULL)
    {

        int id;
        char confirma;
        char confirma2='s';
        Employee* auxEmployee;
        Employee* auxEmployee2;

        Employee* arrayEmployee;

        char nombre[50];
        int horasTrabajadas;
        int sueldo;

        int indexJ=-1;


        int flagNombre=0;
        int flagHorasTrabajadas=0;
        int flagSueldo=0;

        int cant;

        cant=ll_len(pArrayListEmployee);


        if (pArrayListEmployee!= NULL)
        {
            system("cls");

            printf("    Modificar Empleado\n\n");
            controller_ListEmployee(pArrayListEmployee);
            printf("Ingrese id: ");
            scanf("%d", &id);


            arrayEmployee = (Employee *)malloc(sizeof(Employee) * cant);

            int idAModificar;

            if (arrayEmployee != NULL)
            {
                for (int i = 0; i < cant; i++)
                {
                    auxEmployee2=(Employee*) ll_get(pArrayListEmployee, i);

                    (arrayEmployee + i)->id = auxEmployee2->id;
                    strcpy((arrayEmployee + i)->nombre, auxEmployee2->nombre);
                    (arrayEmployee + i)->horasTrabajadas = auxEmployee2->horasTrabajadas;
                    (arrayEmployee + i)->sueldo = auxEmployee2->sueldo;
                    auxEmployee2=NULL;

                }
            }

// Con arrayEmploye lleno empezamos a hacer la busqueda

            for (int j = 0; j < cant; j++)
            {
                if ((arrayEmployee + j)->id == id)
                {
                    idAModificar = (arrayEmployee + j)->id;
                    indexJ=j;
                }

            }
            auxEmployee= (Employee*) ll_get(pArrayListEmployee, indexJ);


            if (indexJ==-1)
            {
                //printf("No existe un empleado con el id %d\n", idAModificar);
                printf("No existe un empleado con dicho ID\n");
            }
            else
            {
                do
                {
                    switch(menuModificaciones())
                    {
                    case 1:
                        printf("  Id         Nombre         HorasTrabajadas      Sueldo\n");
                        mostrarEmployee(pArrayListEmployee, indexJ);

                        if(!getNombre(nombre,"Ingrese nombre: ","Error\n",128,3))
                        {
                            flagNombre=1;
                            printf("Nombre modificado, para guardar cambios, presione salir y confirme.\n");
                        }
                        else
                        {
                            printf("Cantidad maxima de reintentos. Vuelva a intentar.\n");
                        }
                        system("pause");
                        break;



                    case 2:
                        printf("  Id         Nombre         HorasTrabajadas      Sueldo\n");
                        mostrarEmployee(pArrayListEmployee, indexJ);

                        if(!getNumero(&horasTrabajadas,"Ingrese cantidad de horas trabajadas: ", "Error\n",0,99999,3))
                        {
                            flagHorasTrabajadas=1;
                            printf("Horas trabajadas modificadas, para guardar cambios, presione salir y confirme\n");
                        }
                        else
                        {
                            printf("Cantidad maxima de reintentos. Vuelva a intentar.\n");
                        }
                        system("pause");
                        break;
                    case 3:
                        printf("  Id         Nombre         HorasTrabajadas      Sueldo\n");
                        mostrarEmployee(pArrayListEmployee, indexJ);

                        if(!getNumero(&sueldo,"Ingrese sueldo: ", "Error\n",1,999999,3))
                        {
                            flagSueldo=1;
                            printf("Sueldo modificado, para guardar cambios, presione salir y confirme\n");
                        }
                        else
                        {
                            printf("Cantidad maxima de reintentos. Vuelva a intentar.\n");
                        }
                        system("pause");
                        break;
                    case 4:
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
                        strcpy(auxEmployee->nombre, nombre);

                        flagNombre=0;
                    }
                    if (flagHorasTrabajadas==1)
                    {
                        auxEmployee->horasTrabajadas= horasTrabajadas;
                        flagHorasTrabajadas=0;

                    }
                    if (flagSueldo==1)
                    {
                        auxEmployee->sueldo = sueldo;
                        flagSueldo=0;
                    }

                    todoOk=1;
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("Modificacion cancelada por el usuario\n");
                }
            }
        }
        free(arrayEmployee);
    }
    return todoOk;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {
        Employee* arrayAuxEmployee;
        Employee* auxEmployee;
        int cant;
        int idIngresado;
        int index;

        cant=ll_len(pArrayListEmployee);


        arrayAuxEmployee=(Employee*) malloc(sizeof(Employee)*cant);
        fflush(stdin);
        controller_ListEmployee(pArrayListEmployee);


        printf("Ingrese Id empleado a eliminar: ");
        scanf("%d", &idIngresado);


        for(int i=0; i<cant; i++)
        {
            auxEmployee=(Employee*) ll_get(pArrayListEmployee, i);

            (arrayAuxEmployee + i)->id = auxEmployee->id;
            strcpy((arrayAuxEmployee + i)->nombre, auxEmployee->nombre);
            (arrayAuxEmployee + i)->horasTrabajadas = auxEmployee->horasTrabajadas;
            (arrayAuxEmployee + i)->sueldo = auxEmployee->sueldo;
            auxEmployee=NULL;
        }

        for(int j=0; j<cant; j++)
        {
            if(idIngresado==(arrayAuxEmployee+j)->id)
            {
                index=j;
                todoOk=1;
            }
        }

        ll_remove(pArrayListEmployee, index);

        free(arrayAuxEmployee);
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {

        int flagEmpleados=0;
        int tam = ll_len(pArrayListEmployee);
        if(tam>0)
        {
            printf("      LISTA DE EMPLEADOS\n");
            printf("  Id         Nombre         HorasTrabajadas      Sueldo\n");

            for(int i=0; i<tam; i++)
            {
                mostrarEmployee(pArrayListEmployee, i);
                flagEmpleados=1;
                todoOk=1;
            }
            if(flagEmpleados==0)
            {
                printf("No hay empleados cargados por el momento\n");
            }
            printf("\n");
        }
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {
        int order=ll_sort(pArrayListEmployee,comparaEmployees,0);
        if(order==0 || order==1)
        {
            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    FILE* f = fopen(path,"w");

    if(f==NULL || path== NULL || pArrayListEmployee== NULL)
    {
        printf("No se pudo guardar el archivo texto.\n");
    }else{

    Employee* auxEmployee;
    int cant;
    fprintf(f,"Id   Nombre      HorasTrabajadas    Sueldo\n");
    cant=ll_len(pArrayListEmployee);
    for(int i=0; i<cant; i++)
    {
        auxEmployee=(Employee*) ll_get(pArrayListEmployee, i);

        fprintf(f,"%d,%10s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);

    }
    todoOk=1;

    }
    fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* f;
    int todoOk=0;
    int tam = ll_len(pArrayListEmployee);

    f=fopen(path, "r+b");

    if(f==NULL)
    {
        f=fopen(path, "w+b");
        if(f==NULL)
        {
            todoOk=1;
        }
    }
    for(int i=0; i<tam; i++)
    {
        Employee* auxEmployee=(Employee*) ll_get(pArrayListEmployee, i);

        fwrite(auxEmployee,sizeof(Employee),1,f);
    }
    fclose(f);


    return todoOk;
}


