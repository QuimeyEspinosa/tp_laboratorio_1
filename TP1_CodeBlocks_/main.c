#include <stdio.h>
#include <stdlib.h>
#include "menuCalculadora.h"
#include "operacionesCalculadora.h"

int main()
{
    char seguir = 's';

    int operandoA;
    int operandoB;

    int flagOperandoA = 0;
    int flagOperandoB = 0;
    int flagOperaciones = 0;

    do
    {
        switch(menuCalculadora(operandoA, operandoB, flagOperandoA, flagOperandoB))
        {
        case 1:
            system("cls");
            printf("Ingrese primer operando: ");
            operandoA = ingresarOperando();
            flagOperandoA = 1;
            system("pause");
            break;

        case 2:
            system("cls");
            if(flagOperandoA)
            {
                printf("Ingrese segundo operando: ");
                operandoB = ingresarOperando();
                flagOperandoB = 1;
            }
            else
            {
                printf("Para poder ingresar el segundo operando, antes debe ingresar el primero\n\n");
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if(flagOperandoB)
            {
                calcularOperaciones();
                flagOperaciones = 1;
            }
            else
            {
                printf("Para poder calcular las operaciones, primero debe ingresar los operandos correspondientes\n\n");
            }
            system("pause");
            break;

        case 4:
            system("cls");
            if(flagOperaciones)
            {
                informarResultados(operandoA, operandoB);
                system("pause");
                printf("\nSi desea realizar otro calculo ingrese 's', de lo contrario, ingrese 'n' para salir del programa: ");
                fflush(stdin);
                scanf("%c", &seguir);
                if(seguir == 's')
                {
                    flagOperandoA = 0;
                    flagOperandoB = 0;
                    flagOperaciones = 0;
                }
                else
                {
                    seguir = 'n';
                }
            }
            else
            {
                printf("Para mostrar los resultados primero debe calcular las operaciones\n\n");
                system("pause");
            }
            break;

        case 5:
            seguir = 'n';
            break;

        default:
            system("cls");
            printf("El caracter ingresado no es una opcion valida\n");
            system("pause");
        }

    }
    while(seguir == 's');

    return 0;
}

