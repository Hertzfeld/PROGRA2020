#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define SI 1
#define NO 0


///FUNCION SIN RECURSIVIDAD
int factorial(int num1)
{
	int i, aux=1;
	for(i=1;i<=num1;i++)
    {
        aux=aux*i;//AUX INICIA EN 1 SIGUIENTE ITERACCION ARRASTRA EL 1 Y LO MULTIPLICA POR 2,
                //VUELVE A REPETIR HASTA QUE I SEA MENOR IGUAL AL NUM QUE SE DESEA CALCULAR SU FACTORIAL
    }
	return(aux);
}

int combinatoria(int a, int b)
{
    int aux[3];
    aux[0]=factorial(a);
    aux[1]=factorial(b);
    aux[2]=factorial(a-b);
    aux[3]=aux[0]/(aux[1]*aux[2]);
    return(aux[3]);
}

void perteneceFibonacci(int a)
{
    int aux[3]={1,1,2};
    printf("%d %d %d\n",aux[0], aux[1], aux[2]);
    if(a==0 || a==1 || a==2)
    {
        printf("SI PERTENECE");
        return;
    }
    while(a>aux[2])
    {
        if(a==aux[2])
        {
            printf("SI PERTENECE");
            return;//si coincide con la ult pos, pertenece
        }
        else
        {
            aux[1]=aux[2];//muevo el ultimo numero a la pos del medio
            aux[2]=aux[0]+aux[1];//siempre mantengo la ult pos del vec actualizada
            aux[0]=aux[1];//muevo el numero del medio a la posicion inicial para luego sumar
            printf("\n%d %d %d\n",aux[0], aux[1], aux[2]);
             if(a==aux[2])
            {
                printf("SI PERTENECE");
                return;//si coincide con la ult pos, pertenece
            }
        }
    }
    printf("NO PERTENECE");
    return;
}

void esNatural(int a)
{
    int resto=0, divisor=0, suma=1;//suma inicializado en 1 porque 1 es divisor siempre
    divisor=a;
    divisor--;
    while(divisor!=1)
    {
        resto=a%divisor;
        if(resto==0)
        {
            suma+=divisor;
        }
        divisor--;
    }
    if(suma==a)
        printf("\nES UN NUMERO NATURAL PERFECTO, LA SUMA DE LOS DIVISORES ES: %d", suma);
    if(suma<a)
        printf("\nES UN NUMERO NATURAL DEFICIENTE, LA SUMA DE LOS DIVISORES ES: %d", suma);
    if(suma>a)
        printf("\nES UN NUMERO NATURAL ABUNDANTE, LA SUMA DE LOS DIVISORES ES: %d", suma);
    return;
}
