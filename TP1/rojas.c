#include <stdio.h>
#include <stdlib.h>
#include "rojas.h"

int sumaf (int a, int b)
{

    return a + b;
}





int restaf (int a, int b)
{
    return a - b;
}




float divisionf (int a, int b)
{
    return (float) a / b;
}




int multiplicacionf (int a, int b)
{
    return a * b;
}




int factorialfa (int a){

int factorial = 1;
for (int i=1; i<=a; i++){
    factorial=factorial * i;
}

return factorial;
}





int factorialfb (int b){
int factorial = 1;
for (int i=1; i<=b; i++){
    factorial=factorial * i;
}
return factorial;
}




int menu (int a, int b)
{
int opcion;
    printf (" -----------------------------------------\n");
    printf (" ||||||***** MENU DE OPCIONES *****|||||| \n");
    printf (" -----------------------------------------\n\n");
    printf ("1) Ingrese primer operando: (A = %d)\n",a);
    printf("2) Ingrese segundo operando: (B = %d)\n",b);
    printf("3) Calcular todas las operaciones\n");
    printf("    a) Calcular la suma %d + %d\n",a,b);
    printf("    b) Calcular la resta %d - %d\n",a,b);
    printf("    c) Calcular la division %d / %d\n",a,b);
    printf("    d) Calcular la multiplicacion %d * %d\n",a,b);
    printf("    e) Calcular el factorial de %d y de %d\n",a,b);
    printf("4) Informar resultados\n");
    printf("5) Salir\n\n");
    printf ("Ingrese opcion: \n");
    scanf ("%d", &opcion);

    return opcion;

}
