#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    int cant;
    char nombre[40];
    char id[40];
    char horasTrabajadas[40];
    char sueldo[40];
    int status=0;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    do
    {
        cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        if(cant<4)
        {
            break;
        }

        auxEmployee=employee_newParametros(incrementarId(pArrayListEmployee), nombre, atoi(horasTrabajadas), atoi(sueldo));
        if(auxEmployee!=NULL)
        {
            ll_add(pArrayListEmployee, auxEmployee);
            status++;
            printf("%d\n", status);
        }
        else
        {
            printf("Error generando nuevo empleado\n");
        }
    }
    while(feof(pFile)==0);
    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    int status=1;
    int len=ll_len(pArrayListEmployee);

    pFile=fopen("data.bin", "rb");
    if(pFile!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            auxEmployee=(Employee*) malloc(sizeof(Employee));
            fread(auxEmployee, sizeof(Employee), 1, pFile);
            ll_add(pArrayListEmployee, auxEmployee);
        }
    }else{
        status=0;
    }

    fclose(pFile);

    return status;
}
