#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


typedef struct
{
    int id;
    char nombre[40];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo);
int employee_delete(Employee* eEmployee);

int employee_setId(Employee* eEmployee,int id);
int employee_getId(Employee* eEmployee,int* id);

int employee_setNombre(Employee* eEmployee,char* nombre);
int employee_getNombre(Employee* eEmployee,char* nombre);

int employee_setHorasTrabajadas(Employee* eEmployee,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* eEmployee,int* horasTrabajadas);

int employee_setSueldo(Employee* eEmployee,int sueldo);
int employee_getSueldo(Employee* eEmployee,int* sueldo);

#endif // employee_H_INCLUDED

//Menu ABM
int menu ();

int menuModificaciones ();


//Buscar Libre Empleado
int buscarLibreEmpleado(Employee** eEmployee, int sizeEmp, int* pIndice);


void mostrarEmployee(LinkedList* pArrayListEmployee, int index);

int comparaEmployees(void* pEmployeeA,void* pEmployeeB);



