#include <stdio.h>
#include <stdlib.h>
#include "rojas.h"


int main()
{
    float x;
    float y;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorialA;
    float factorialB;
    int opcion;
    char salir='s';
    char confirma;
    int flag1op=0;
    int flag2op=0;
    int flagcalcular=0;


    do
    {
        system ("cls");
        menu();
        printf("Ingrese opcion: ");
        scanf ("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf ("Ingrese primer operando: ");
            scanf ("%f", &x);
            flag1op=1;
            break;
        case 2:
            if (flag1op==0){
                printf ("Antes de ingresar el segundo operando, ingresar el primero\n");
                            system ("pause");

            }
            else {
            printf ("Ingrese segundo operando: ");
            scanf ("%f", &y);
            flag2op=1;
            }
            break;
        case 3:
            if (flag1op==0){
                printf ("Antes de calcular las operaciones, ingresar ambos operandos\n");
                system ("pause");

            }
            else if (flag1op==1 && flag2op==0){
                printf("Te falto ingresar el segundo operando\n");
                system ("pause");

            }
            else {
            suma= sumaf(x,y);
            resta= restaf(x,y);
            if (y!=0){
            division= divisionf(x,y);
            }
            multiplicacion= multiplicacionf(x,y);
            factorialA= factorialfa (x);
            factorialB= factorialfb (y);
            printf ("Operaciones calculadas correctamente\n");
            system ("pause");
            flagcalcular=1;
            }
            break;
        case 4:
            if (flag1op==0){
                printf("Antes de mostrar resultados, tenes que cargar los operandos y calcular la operacion\n");
                system("pause");
            }
           else if (flag1op==1 && flag2op==0){
                printf("Te falta cargar el segundo operando y calcular la operacion\n");
                system("pause");
            }
            else if (flag2op==1 && flagcalcular==0){
                printf("Te falta calcular la operacion\n");
                system("pause");
            }
            else {
            printf ("A= %.2f", x);
            printf (" B= %.2f\n", y);
            printf("a) El resultado de %.2f+%.2f es: %.2f\n",x,y,suma);
            printf("b) El resultado de %.2f-%.2f es: %.2f\n",x,y,resta);
             if (y==0){
                printf("c) No se puede dividir por 0\n");
            }
            else {
            printf("c) El resultado de %.2f/%.2f es: %.2f\n",x,y,division);
            }
            printf("d) El resultado de %.2f*%.2f es: %.2f\n",x,y,multiplicacion);
            printf("e) El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f\n",x,factorialA,y, factorialB);
            system ("pause");
            flag1op=0;
            flag2op=0;
            flagcalcular=0;
            }
            break;
        case 5:
            printf ("¿Seguro que quiere salir?: ");
            fflush (stdin);
            scanf ("%c", &confirma);
            if (confirma=='s')
            {
                salir='n';
            }
            break;
        }
    }
    while (salir =='s');
    return 0;
}






