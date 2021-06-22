#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

//Menu ABM
int menu ()
{
    int opcion;
    system("cls");
    printf ("Gestion de empleados\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf ("Ingrese opcion: ");

    scanf ("%d", &opcion);
    return opcion;
}


//Constructores
Employee* employee_new()
{

    Employee* newEmployee =(Employee*) malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        newEmployee->horasTrabajadas=0;
        newEmployee->id=0;
        strcpy(newEmployee->nombre,"");
        newEmployee->sueldo=0;
    }
    return newEmployee;
}


Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo)
{
    Employee* auxEmployee=employee_new();

    if(auxEmployee!=NULL)
    {

        if(employee_setId(auxEmployee,id) &&
                employee_setSueldo(auxEmployee, sueldo) &&
                employee_setNombre(auxEmployee,nombre) &&
                employee_setHorasTrabajadas(auxEmployee,horasTrabajadas))
        {

            printf("Carga exitosa\n");
        }
        else
        {
            free(auxEmployee);
            auxEmployee = NULL;
        }
    }

    return auxEmployee;
}

//Destructor
int employee_delete(Employee* eEmployee)
{
    int todoOk=0;
    if(eEmployee !=NULL)
    {
        free (eEmployee);
        todoOk=1;
    }
    return todoOk;
}


//Setters
int employee_setId(Employee* eEmployee,int id)
{
    int todoOk=0;
    if(eEmployee != NULL && id > 0)
    {
        eEmployee->id=id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setNombre(Employee* eEmployee, char* nombre)
{
    int todoOk=0;
    if (eEmployee!=NULL && nombre!=NULL && strlen(nombre)>=3 && strlen(nombre)<20)
    {
        strcpy(eEmployee->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* eEmployee,int horasTrabajadas)
{
    int todoOk=0;
    if(eEmployee != NULL && horasTrabajadas >= 0)
    {
        eEmployee->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* eEmployee,int sueldo)
{
    int todoOk=0;
    if(eEmployee != NULL && sueldo > 0)
    {
        eEmployee->sueldo=sueldo;
        todoOk=1;
    }
    return todoOk;
}


//Getters
int employee_getId(Employee* eEmployee,int* pId)
{
    int todoOk=0;
    if(eEmployee != NULL && pId != NULL)
    {
        *pId=eEmployee->id;
        todoOk=1;
    }
    return todoOk;
}

int employee_getNombre(Employee* eEmployee, char* pNombre)
{
    int todoOk=0;
    if (eEmployee!=NULL && pNombre!=NULL)
    {
        strcpy(pNombre, eEmployee->nombre);
        todoOk=1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* eEmployee,int* pHorasTrabajadas)
{
    int todoOk=0;
    if(eEmployee != NULL && pHorasTrabajadas != NULL)
    {
        *pHorasTrabajadas=eEmployee->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* eEmployee,int* pSueldo)
{
    int todoOk=0;
    if(eEmployee != NULL && pSueldo != NULL)
    {
        *pSueldo=eEmployee->sueldo;
        todoOk=1;
    }
    return todoOk;
}

/*
//Buscar empleado
int buscarEmpleado (Employee* eEmployee, int id)
{
    int indice = -1;
    int tam;

    if (eEmployee != NULL && tam > 0)
    {

        for (int i=0; i<tam; i++)
        {
            if(eEmployee[i].codigo==id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;

}*/

//Buscar Libre empleado
int buscarLibreEmpleado(Employee** eEmployee, int sizeEmp, int* pIndice)
{
    int retorno=0;
    *pIndice = -1;
    if(eEmployee!=NULL && sizeEmp>0 && pIndice!=NULL)
    {
        for(int i=0; i<sizeEmp; i++)
        {
            if(*(eEmployee+i)==NULL)
            {
                *pIndice=i;
                break;
            }
        }
        retorno=1;
    }
    return retorno;
}


//Menu modificaciones
int menuModificaciones ()
{
    int opcion;
    system("cls");
    printf ("Modificacion de empleados\n\n");
    printf ("1- Modificar nombre\n");
    printf ("2- Modificar horas trabajadas\n");
    printf ("3- Modificar sueldo\n");
    printf ("4- Salir y guardar/cancelar\n");
    printf ("Ingrese opcion: ");
    scanf ("%d", &opcion);

    return opcion;
}

//Mostrar empleado (uno)
void mostrarEmployee(LinkedList* pArrayListEmployee, int index)
{

    Employee* auxEmployee;
    auxEmployee = (Employee*)ll_get(pArrayListEmployee,index);

    printf("%d   %10s              %5d             %5d\n",
           auxEmployee->id,
           auxEmployee->nombre,
           auxEmployee->horasTrabajadas,
           auxEmployee->sueldo);

}


int comparaEmployees(void* pEmployeeA,void* pEmployeeB)
{
    if(((Employee*)pEmployeeA)->sueldo > ((Employee*)pEmployeeB)->sueldo)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->sueldo <
            ((Employee*)pEmployeeB)->sueldo)
    {
        return -1;
    }
    return 0;
}
