#include <stdio.h>
#include <stdlib.h>
#include "rojas.h"

float sumaf (float a, float b)
{
    return a + b;
}





float restaf (float a, float b)
{
    return a - b;
}




float divisionf (float a, float b)
{
    return a / b;
}




float multiplicacionf (float a, float b)
{
    return a * b;
}




float factorialfa (float a){
int factorial = 1;
for (int i=1; i<=a; i++){
    factorial=factorial * i;
}
return factorial;
}





float factorialfb (float b){
int factorial = 1;
for (int i=1; i<=b; i++){
    factorial=factorial * i;
}
return factorial;
}




int menu ()
{
int opcion;

    printf ("       ***** Menu *****\n\n");
    printf ("1) Ingrese primer operando: \n");
    printf("2) Ingrese segundo operando: \n");
    printf("3) Calcular todas las operaciones\n");
    printf("4) Informar resultados\n");
    printf("5) Salir\n\n");
    printf ("Ingrese opcion: \n");
    scanf ("%d", &opcion);
        /*while (!(opcion ==1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5)){
            printf ("Opcion invalida. Ingrese opcion: \n");
            scanf ("%d", &opcion);
        }//funciona solo si se ingresar numeros erroneos, pero si ingresar char se rompe
        */

    return opcion;

}
