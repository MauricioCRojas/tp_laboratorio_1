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




void menu ()
{

    printf ("***** Menu *****\n\n");
    printf ("1) Ingrese primer operando: \n");
    printf("2) Ingrese segundo operando: \n");
    printf("3) Calcular todas las operaciones\n");
    printf("4) Informar resultados\n");
    printf("5) Salir\n\n");

}
