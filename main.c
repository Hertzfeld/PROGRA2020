#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int opcion=999999, num=0, res=0, m, n;
    printf("\tMENU:\n"
           "\n1-FACTORIAL\n"
           "2-COMBINATORIA\n"
           "3-e^x\n"
           "4-RAIZ CUADRADA DE n+\n"
           "5-PERTENECE A FIBONACCI\n"
           "6-sen(x)\n"
           "7-NUMERO NATURAL ES: PERFECTO, DEFICIENTE O ABUNDANTE\n"

           "\n0-SALIR"
           "\nINGRESE NUMERO:\t"
           );
    scanf("%d",&opcion);
    do{
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("INGRESE NUMERO AL QUE DESEA CALCULAR SU FACTORIAL\t");
            scanf("%d", &num);
            if (num == 0)
            {
                printf("\nSU FACTORIAL ES 1");
                getch();
            }
            else
            {
                res=factorial(num);
                printf("\n\nEL FACTORIAL DE %d ES %d",num, res);
                getch();
            }
            break;

        case 2:
            system("cls");
            printf("COMBINATORIA\tm:");scanf("%d",&m);
            printf("\t\tn:");scanf("%d",&n);
            res=combinatoria(m,n);
            printf("\nSU RESULTADO ES:  %d", res);
            getch();
            break;

        case 5:
            system("cls");
            printf("INGRESE NUMERO QUE DESEA SABER SI PERTENECE A LA SERIE DE FIBONACCI:\t");
            scanf("%d", &num);
            perteneceFibonacci(num);
            /*if(res==1)
                printf("\nSI PERTENECE");
            else
                printf("\nNO PERTENECE");
            //printf((res==1)?"\nSI PERTENECE":"\nNO PERTENECE");*/
            getch();
            break;

        case 7:
            system("cls");
            printf("INGRESE NUMERO NATURAL:\t");
            scanf("%d", &num);
            esNatural(num);
            getch();
        }
    }while(opcion!=0);
    return 0;
}
