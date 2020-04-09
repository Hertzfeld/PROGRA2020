#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define SI 1
#define NO 0


/**CALCULA EL FACTORIAL DE UN NUMERO, LLEGA HASTA 12 LUEGO SE EXCEDE DE RANGO.
MULTIPLICA DE FORMA CICLICA AUX(INICIALIZADO EN 1 POR DEF DE !) CON SI MISMO Y "i" HASTA QUE SEA MENOR IGUAL
AL NUMERO QUE SE DESEA SABER SU FACTORIAL

FUNCION SIN RECURSIVIDAD
**/
unsigned long long int factorial(int num1)
{
	int i;
	unsigned long long int aux=1;
	for(i=1;i<=num1;i++)
    {
        aux*=i;//AUX INICIA EN 1 SIGUIENTE ITERACCION ARRASTRA EL 1 Y LO MULTIPLICA POR 2,
                //VUELVE A REPETIR HASTA QUE I SEA MENOR IGUAL AL NUM QUE SE DESEA CALCULAR SU FACTORIAL
    }
	return(aux);
}

/**CALCULA LA COMBINATORIA DE M TOMADOS DE N**/
int combinatoria(int a, int b)
{
    int aux[3];
    aux[0]=factorial(a);
    aux[1]=factorial(b);
    aux[2]=factorial(a-b);
    aux[3]=aux[0]/(aux[1]*aux[2]);
    return(aux[3]);
}

/**DADO X DICE SI PERTENECE O NO A LA SERIE, SI ESTA INCLUIDO, MUESTRA LOS NUM HASTA SU OCURRENCIA
RESOLUCION:
USO UN VEC DE 3 POS, INICIALIZADO CON 1 1 2, AUTOMATICAMENTE SI EL X RECIBIDO ES 0,1 O 2 "PERTENECE"
SI NO, ENTRA A UN CICLO DE WHILE HASTA QUE X SEA MAYOR QUE LA ULT POS DEL VEC Y PREGUNTA SI
EL NUMERO RECIBIDO ES IGUAL A LA ULT POS DEL VEC, CASO CONTRARIO INVIERTE POS 2 CON POS 1, ACTUALIZA POS2 Y VUELVE
INVERTIR POS 1 CON POS 0 PARA SIEMPRE MANTENER ACTUALIZADA LA ULT POS DEL VECTOR CON EL ULT NUMERO DE LA SERIE DE FIBONACCI
VUELVE A PREGUNTAR SI POS 2 ES IGUAL X
SI SALE DEL WHILE, NO PERTENECE A LA SERIE
**/
void perteneceFibonacci(int a)
{
    int aux[3]={1,1,2};
    //printf("%d %d %d\n",aux[0], aux[1], aux[2]);
    if(a==0 || a==1 || a==2)
    {
        fibonacci(a);
        printf("\nSI PERTENECE");
        return;
    }
    while(a>aux[2])
    {
        if(a==aux[2])
        {
            fibonacci(a);
            printf("\nSI PERTENECE");
            return;//si coincide con la ult pos, pertenece
        }
        else
        {
            aux[1]=aux[2];//muevo el ultimo numero a la pos del medio
            aux[2]=aux[0]+aux[1];//siempre mantengo la ult pos del vec actualizada
            aux[0]=aux[1];//muevo el numero del medio a la posicion inicial para luego sumar
            //printf("\n%d %d %d\n",aux[0], aux[1], aux[2]);//muestra las 3 pos del vector
             if(a==aux[2])
            {
                fibonacci(a);
                printf("\nSI PERTENECE");
                return;//si coincide con la ult pos, pertenece
            }
        }
    }
    printf("NO PERTENECE");
    return;
}

/**DADO X GENERA LA SERIE DE FIBONACCI HASTA X Y LA MUESTRA POR PANTALLA**/
void fibonacci(int f)
{
   int s[100], i;
   for(i=0;i<100;i++)
   {
       s[i]=0;
   }
   s[1]=1;
   for(i=0;i<f;i++)
   {
       s[i+2]=s[i]+s[i+1];
   }
   printf("\nLA SERIE DE FIBONACCI ES:\n");
   i=0;
   printf("%d ", s[0]);//PARCHE AL PROBLEMA DE ABAJO
   while(s[i]!=f)//SALE AL ENCONTRAR UN NUM DENTRO DEL ARRAY QUE SEA IGUAL AL RECIBIDO, NO LO MUESTRA. POR ESO EL PRINTF ES DE i+1
   {
       printf("%d ", s[i+1]);
       i++;
   }

}

/**NUMERO NATURAL PERFECTO CUANDO LA SUMA DE SUS DIVISORES ES IGUAL AL NUMERO
DEFICIENTE CUANDO LA SUMA DE SUS DIVS ES MENOR QUE EL NUMERO DADO
ABUNDANTE CUANDO LA SUMA DE SUS DIVS ES MAYOR QUE X
RESOLUCION:
RECIBO POR PARAMETRO EL NUMERO, LO ASIGNO A DIVISOR Y LO DECREMENTO PARA DESCARTAR A SI MISMO COMO DIVISOR.
SI EL RESTO DE LA DIVISION DE X Y EL DIVISOR OBTENIDO ES 0, SUMO DICHO NUMERO Y LO ACUMULO EN CADA ITERACCIÓN
(SUMA INICIALIZADO CON 1 PORQUE SIEMPRE ES DIVISOR) SALE DEL CICLO WHILE CUANDO DIVISOR LLEGA A 1

**/
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
