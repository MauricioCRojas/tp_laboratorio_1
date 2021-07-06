#include "validaciones.h"



int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno=-1;
    int bufferInt;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getInt(&bufferInt)==0 && bufferInt>=minimo && bufferInt<=maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}




 int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumerico(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atoi(bufferString);
    }
    return retorno;
}




 int myGets(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL && bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
        {
            bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
        }
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}




 int myGetsChar(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        gets(bufferString);
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}




 int esNumerico(char* cadena, int limite)
{
    int retorno=-1;
    int i;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        for(i=0;i<limite && cadena[i]!='\0';i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]>'9' || cadena[i]<'0')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}



int getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getCharacter(&bufferChar)==0 && (bufferChar==opcion1 || bufferChar==opcion2))
			{
				*pResultado=bufferChar;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}




 int getCharacter(char* pResultado)
{
    int retorno = -1;
    char bufferString;

    if(pResultado != NULL && !myGetsChar(&bufferString,sizeof(bufferString)) && esCaracter(&bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado=tolower(bufferString);
    }
    return retorno;
}




 int esCaracter(char* cadena, int limite)
{
    int retorno=-1;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        if((cadena[0]<'A' || cadena[0]>'Z') && (cadena[0]<'a' || cadena[0]>'z') && limite>1)
        {
            retorno=0;
        }
    }
    return retorno;
}



int getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos)
{
    int retorno=-1;
    char bufferNombre[sizeNombre];

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && sizeNombre>0 && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getCadenaChar(bufferNombre)==0)
            {
                strcpy(pResultado,bufferNombre);
				retorno = 0;
				break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}




 int getCadenaChar(char* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNombre(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        strcpy(pResultado,bufferString);
    }
    return retorno;
}



 int esNombre(char* cadena, int limite)
{
    int retorno=-1;
    if (cadena!= NULL && limite>0)
    {
        retorno = 1;
        for(int i=0; i<limite && cadena[i]!='\0'; i++)
        {
            if(i==0 && cadena[i]==' ')
            {
                retorno=0;
                break;
            }
            else if(cadena[i]!=' ' && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}



int getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat)==0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			reintentos--;
            printf("%s",mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}




 int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumeroFlotante(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atof(bufferString);
    }
    return retorno;
}





 int esNumeroFlotante(char* cadena, int limite)
{
    int retorno=-1;
    int flagComa=0;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        for(int i=0;i<limite && cadena[i]!='\0';i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]==',')
            {
                if(flagComa==1 || i==0)
                {
                    retorno=0;
                    break;
                }
                flagComa=1;
            }
            if(cadena[i]>'9' || cadena[i]<'0')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
