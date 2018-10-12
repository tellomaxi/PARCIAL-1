#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "parcialfunciones.h"

#define CANTIDAD_JUEGOS 5
#define CANTIDAD_CATEGORIAS 10
#define CANTIDAD_CLIENTES 100

int funcion_opcionesCliente();
int funcion_BuscarLugarVacioCliente(eCliente lista[],int len);
int funcion_AltaCliente(eCliente list[], int tam);
void menu(eCliente list[]);
//void funcion_harcodeoCliente(eCliente list[]);
//void funcion_InicializarCategoria(eCategoria categoria[], int tam);
//void funcion_inicioJuegos(eJuego juegos[], int tam);
//void funcion_harcodeoClientes(eCliente list[]);


int main()
{
    eCliente cliente[CANTIDAD_CLIENTES];

    funcion_InicializarCliente(cliente,CANTIDAD_CLIENTES);
    //funcion_inicioJuegos(juegos,CANTIDAD_JUEGOS);
    //funcion_InicializarCategoria(categorias,CANTIDAD_CATEGORIAS);
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
            break;
        case 5:
            printf("Alta alquileres");
            system("pause");
            system("cls");
            break;

        case 6:
            printf("Listar alquileres");
            system("pause");
            system("cls");
            break;

        default:
            printf("Opcion no valida, ingrese un numero entre el 1-6\n");
            system("pause");
            system("cls");

        }
    }while(seguir=='s');

}
/*
void funcion_harcodeoCliente(eCliente list[])
{
    eCliente newClientes [10] =
    {
        {1, "TOMAS OLIVIERI",'M', 1131420065},
        {2, "JULIETA CARLE",'F', 1131420064},
        {3, "BETINA MEND",'F', 1131420063},
        {4, "NATALIA NATALIA",'F', 1131420062},
        {5, "EL PUMA GIGLIOTI",'M', 1131420061},
        {6, "CELULAR HUAWEI",'M', 1131420060},
        {7, "COMPUTADORA TECLADO",'M', 113142059},
        {8, "TOBIAS PEREZ",'M', 1131420058},
        {9, "ROCIO JIMENEZ",'F', 1131420057},
        {10, "ALGUN NOMBRE",'F', 1131420056},
    };

    for (int i = 0; i < 10; i++)
    {
        list[i] = newClientes[i];
    }
}
*/
