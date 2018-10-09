#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "parcialfunciones.h"


#define CANTIDAD_CLIENTES 100

int funcion_opcionesCliente();
int funcion_BuscarLugarVacioCliente(eCliente lista[],int len);
int funcion_AltaCliente(eCliente list[], int tam);


int main()
{
    eCliente cliente[CANTIDAD_CLIENTES];
    char seguir='s';
    funcion_InicializarCliente(cliente,CANTIDAD_CLIENTES);

    do
    {
        switch(funcion_opcionesCliente())
        {
        case 1:
            funcion_AltaCliente(cliente,CANTIDAD_CLIENTES);
            system("pause");
            break;
        case 2:
            funcion_modificarCliente(cliente,CANTIDAD_CLIENTES);
            system("pause");
            break;
        case 3:
            funcion_BajaCliente(cliente,CANTIDAD_CLIENTES,0);
            system("pause");
        case 4:
            funcion_ordenarClientesXNombre(cliente,CANTIDAD_CLIENTES);
            funcion_mostrarClientes(cliente,CANTIDAD_CLIENTES);
            system("pause");
        case 5:
            printf("Entraste al case 5");
            system("pause");
            system("cls");
        default:
            printf("Opcion no valida, ingrese un numero entre el 1-5");
            system("pause");
        }
    }while(seguir=='s');

    return 0;
}

