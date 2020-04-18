#include <stdio.h>
#include <stdlib.h>
#include "menuCalculadora.h"
#include "operacionesCalculadora.h"

int calcularSuma(int a, int b)
{
    int resultSuma;

    resultSuma = a + b;

    return resultSuma;
}

int calcularResta(int a, int b)
{
    int resultResta;

    resultResta = a - b;

    return resultResta;
}

float calcularDivision(int a, int b)
{
    float resultDivision;

    resultDivision = (float) a / b;

    return resultDivision;
}

int calcularMultiplicacion(int a, int b)
{
    int resulMultiplicacion;

    resulMultiplicacion = a * b;

    return resulMultiplicacion;
}

unsigned int operacionFactorial(int a)
{
    int resultadoFact;

    if(a >= 0)
    {

        if (a == 1 || a == 0)
        {
            resultadoFact = 1;
        }
        else
        {
            resultadoFact = a * operacionFactorial(a -1);
        }
    }
    else
    {
        resultadoFact = 0;
    }

    return resultadoFact;
}



