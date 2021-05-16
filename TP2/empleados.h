#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct {
int isEmpty;
int id;
char nombre [51];
char apellido [51];
float sueldo;
int sector;
}eEmpleado;


#endif // EMPLEADOS_H_INCLUDED

/** \brief Funcion que incrementa ID cada vez que se llama
 * \return retorna Id incrementado
 *
 */
int incrementarId(void);


/** \brief Informa lo requerido de los sueldos
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
* \return retorno 1todoOk/0noOk
 *
 */
int FSueldos (eEmpleado lista[], int tam);


/** \brief Muestra los empleados
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
\return retorno 1todoOk/0noOk
 *
 */
int mostrarEmpleados(eEmpleado lista[], int tam);


/** \brief Muestra un empleados
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
\return retorno 1todoOk/0noOk
 *
 */
void mostrarEmpleado (eEmpleado unEmpleado);


/** \brief Ordeno todos los empleados activos
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
 * \return
 *
 */
int ordenarEmpleados (eEmpleado lista[], int tam);


/** \brief Menu de opciones ABM
 * \return retorno opcion ingresada
 */
int menu ();


/** \brief Menu de opciones de la opciones Modificar empleado
 * \return retorno opcion ingresada
 */
int menuModificaciones (void);


/** \brief Inicializo cada posicion del vector con isEmpty=1 (vacio)
 *  \brief usarla si no hay hardcodeo
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
 * \return
 */
void inicializarEmpleados (eEmpleado lista[], int tam);


/** \brief Busco posicion vacia para cargar empleado, si es que la hay
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
 * \return retorno indice de primer posicion vacia
 */
int buscarLibre (eEmpleado lista[], int tam);


/** \brief Busca un empleado activo por su id
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
 * \param id, desde ahi lo busco
 * \return retorno indice del empleado con ese id
 *
 */
int buscarEmpleado (eEmpleado lista[], int tam, int id);


/** \brief Da de alta un nuevo empleado si hay lugar, pide datos
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
 * \param *pId, paso puntero de pId
 * \return retorno 1todoOk/0noOk
 */
int altaEmpleado (eEmpleado lista[], int tam);


/** \brief Modifica el o los datos que uno quiera, de el o los empleados, si es que hay
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
 * \return retorno 1todoOk/0noOk
 */
int modificarEmpleado(eEmpleado lista[], int tam);


/** \brief Da de baja a un empleado, si es que hay
 * \param Vector de eEmpleado lista[]
 * \param tam, tamaño del vector
 * \return retorno 1todoOk/0noOk
 */
int bajaEmpleado (eEmpleado lista[], int tam);

