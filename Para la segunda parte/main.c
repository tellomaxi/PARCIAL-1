#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "parcialfunciones.h"


#define CANTIDAD_CLIENTES 100

int funcion_opcionesCliente();
int funcion_BuscarLugarVacioCliente(eCliente lista[],int len);
int funcion_AltaCliente(eCliente list[], int tam);
void menu(eCliente list[]);

int main()
{
    eCliente cliente[CANTIDAD_CLIENTES];

    funcion_InicializarCliente(cliente,CANTIDAD_CLIENTES);
    menu(cliente);

    return 0;
}




void menu(eCliente cliente[])
{
    char seguir='s';
    int flag=0;
    int flag2=0;

    do
    {
        switch(funcion_opcionesCliente())
        {
        case 1:
            flag = 1;
            funcion_AltaCliente(cliente,CANTIDAD_CLIENTES);
            system("pause");
            break;
        case 2:
            if(flag==0)
            {
                printf("Error, debe cargar un cliente primero!\n");
            }
            else
            {
                funcion_modificarCliente(cliente,CANTIDAD_CLIENTES);
            }
            system("pause");
            break;
        case 3:
            if(flag==0)
            {
                printf("Error, debe cargar un cliente primero!\n");
            }
            else
            {
                funcion_BajaCliente(cliente,CANTIDAD_CLIENTES,0);
            }
            system("pause");
            break;
        case 4:
            if(flag==0)
            {
                printf("Error, debe cargar un cliente primero!\n");
            }
            else
            {
                funcion_ordenarEmpleadosXApellido(cliente,CANTIDAD_CLIENTES);
                funcion_mostrarClientes(cliente,CANTIDAD_CLIENTES);
            }
            system("pause");
        case 5:
            printf("Alta cliente");
            system("pause");
            system("cls");
        default:
            printf("Opcion no valida, ingrese un numero entre el 1-5\n");
            system("pause");
        }
    }while(seguir=='s');

}
