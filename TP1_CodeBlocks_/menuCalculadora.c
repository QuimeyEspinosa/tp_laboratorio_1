#include <stdio.h>
#include <stdlib.h>
#include "menuCalculadora.h"
#include "operacionesCalculadora.h"

int menuCalculadora(int x, int y, int flagA, int flagB)
{
    int opcion;

    system("cls");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("<<<<< Bienvenido a la calculadora de Quimey Espinosa >>>>>\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("<<<<<<<<<<<<<<<<<<<<<< Menu opciones >>>>>>>>>>>>>>>>>>>>>\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

    if(flagA)
    {
        printf("1-Primer operando ingresado: A = %d\n", x);
    }
    else
    {
        printf("1-Ingresar primer operando (A=x)\n");
    }

    if(flagB)
    {
        printf("2-Segundo operando ingresado: B = %d\n", y);
    }
    else
    {
        printf("2-Ingresar segundo operando (B=y)\n");
    }
    printf("3-Realizar todas las operaciones:\n");
    printf("  a)Calcular la suma (A+B)\n");
    printf("  b)Calcular la resta (A-B)\n");
    printf("  c)Calcular la division (A/B)\n");
    printf("  d)Calcular la multiplicacion (A*B)\n");
    printf("  e)Calcular el factorial (A! y B!)\n");
    printf("4-Mostrar resultados: \n");
    printf("5-Salir\n\n");

    printf("Indique opcion (1,2,3,4 o 5): ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int ingresarOperando()
{
    int numero;

    scanf("%d", &numero);

    return numero;
}

void calcularOperaciones()
{
    printf("\n>>>>> Operaciones calculadas <<<<<\n\n");
    printf("Regrese al menu y seleccione la opcion 4 para mostrar los resultados\n\n");
}

void informarResultados(int a, int b)
{
    int suma;
    int resta;
    float division;
    int multiplicacion;
    unsigned int factorizarA;
    unsigned int factorizarB;

    printf("Los numeros ingresados son:\n");
    printf("A = %d \n", a);
    printf("B = %d \n\n", b);

    suma = calcularSuma(a, b);
    resta = calcularResta(a, b);
    multiplicacion = calcularMultiplicacion(a, b);
    factorizarA = operacionFactorial(a);
    factorizarB = operacionFactorial(b);

    printf("a)El resultado de la suma es: %d \n", suma);
    printf("b)El resultado de la resta es: %d \n", resta);
    if(b != 0)
    {
        division = calcularDivision(a, b);
        printf("c)El resultado de la division es: %.2f\n", division);
    }
    else
    {
        printf("c)El resultado de la division es: No se puede dividir entre cero\n");
    }
    printf("d)El resultado de la multiplicacion es: %d\n", multiplicacion);
    printf("e)Resultado de las factorizaciones: \n");
    printf("(Factoriza numeros positivos hasta el 33, caso contrario el resultado se mostrara como 0)\n");
    printf("  A = %u\n", factorizarA);
    printf("  B = %u\n", factorizarB);

}
