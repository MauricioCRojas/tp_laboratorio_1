#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief Pide un numero para comprobarlo
 * \param pResultado int*, aca se guarda el resultado
 * \param mensaje char* Mensaje que pide el dato
 * \param mensajeError char* Mensaje en caso de error
 * \param minimo int numero minimo aceptable
 * \param maximo int numero maximo aceptable
 * \param reintentos int cantidad de intentos
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Pide un numero para comprobarlo
 * \param pResultado int*, aca se guarda el resultado
 * \param mensaje char* Mensaje que pide el dato
 * \param mensajeError char* Mensaje en caso de error
 * \param minimo int numero minimo aceptable
 * \param maximo int numero maximo aceptable
 * \param reintentos int cantidad de intentos
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
int getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


 /** \brief Pide un caracter
 * \param pResultado char*, aca se guarda el resultado
 * \param mensaje char* Mensaje que pide el dato
 * \param mensajeError char* Mensaje en caso de error
  * \param char opcion1, es opcion valida
 * \param char opcion2, es opcion valida
  * \param reintentos int cantidad de intentos
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
int getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos);


 /** \brief Pide una cadena de caracteres
 * \param pResultado char*, aca se guarda el resultado
 * \param mensaje char* Mensaje que pide el dato
 * \param mensajeError char* Mensaje en caso de error
  * \param size maximo
  * \param reintentos int cantidad de intentos
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
int getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);


/** \brief pide un dato y limita su tamanio, pasa cadena a entero
 * \param pResultado int*, aca se guarda el resultado
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int getInt(int* pResultado);


/** \brief cuando encuentra '\n' o copiado en cadena un maximo de caracteres.
 * \param cadena char* donde se guarda el resultado
 * \param longitud int tamanio de la cadena
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int myGets(char* cadena, int longitud);


/** \brief comprueba si la cadena pedida es numerica
 * \param cadena char* cadena de caracteres a ser comprobada
 * \param limite int tamanio de la cadena a comprobar
 * \return retorna -1 si hubo error, 0 si no es numerico, y 1 si es numerico
 */
 int esNumerico(char* cadena, int limite);


 /** \brief Pide un caracter y limita el tamanio, comprueba caracter valido
 * \param pResultado char*, aca se guarda el resultado
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int getCharacter(char* pResultado);


/** \brief cuando encuentra '\n' o copiado en cadena un maximo de caracteres.
 * \param cadena char* se guarda resultado
 * \param longitud int tamanio de la cadena
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int myGetsChar(char* cadena, int longitud);

/** \brief comprueba si la cadena pedida es caracter
 * \param cadena char* cadena de caracteres a ser comprobada
 * \param longitud int tamanio de la cadena
 * \return retorna -1 si hubo error, 0 si no es caracter, y 1 si es caracter
 */
 int esCaracter(char* cadena, int limite);


/** \brief pide un dato y limita su tamanio, pasa cadena a entero
 * \param pResultado int*, aca se guarda el resultado
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int getCadenaChar(char* pResultado);


/** \brief comprueba si la cadena pedida es nombre
 * \param cadena char* cadena a comprobar
 * \param limite int tamanio de la cadena a comprobar
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int esNombre(char* cadena, int limite);


/** \brief pide un dato y limita su tamanio, pasa cadena a entero
 * \param pResultado int*, aca se guarda el resultado
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int getFloat(float* pResultado);


/** \brief comprueba si la cadena pedida es numerica
 * \param cadena char* cadena a comprobar
 * \param limite int tamanio de la cadena a comprobar
 * \return retorna -1 si no se pudo, y 0 si pudo
 */
 int esNumeroFlotante(char* cadena, int limite);

