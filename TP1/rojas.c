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




int menu (float a, float b)
{
int opcion;
    printf (" -----------------------------------------\n");
    printf (" ||||||***** MENU DE OPCIONES *****|||||| \n");
    printf (" -----------------------------------------\n\n");
    printf ("1) Ingrese primer operando: (A = %.2f)\n",a);
    printf("2) Ingrese segundo operando: (B = %.2f)\n",b);
    printf("3) Calcular todas las operaciones\n");
    printf("    a) Calcular la suma %.2f + %.2f\n",a,b);
    printf("    b) Calcular la resta %.2f - %.2f\n",a,b);
    printf("    c) Calcular la division %.2f / %.2f\n",a,b);
    printf("    d) Calcular la multiplicacion %.2f * %.2f\n",a,b);
    printf("    e) Calcular el factorial de %.2f y de %.2f\n",a,b);
    printf("4) Informar resultados\n");
    printf("5) Salir\n\n");
    printf ("Ingrese opcion: \n");
    scanf ("%d", &opcion);

    return opcion;

}
