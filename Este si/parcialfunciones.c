#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "parcialfunciones.h"



void funcion_InicializarCliente(eCliente list[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        list[i].isEmpty = 1;

    }

}

int funcion_opcionesCliente()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf("\n\n\n");
    printf("----CLIENTES----\n");
    printf(" 1- ALTA CLIENTE\n");
    printf(" 2- MODIFICAR CLIENTE\n");
    printf(" 3- BAJA CLIENTE\n");
    printf(" 4- LISTAR CLIENTES\n");
    printf("\n");
    printf("----ALQUILERES----\n");
    printf(" 5- ALTA ALQUILER\n");
    printf(" 6- LISTAR ALQUILERES\n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-6 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 6\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
}

int funcion_AltaCliente(eCliente list[], int tam)
{
    eCliente nuevoCliente ;
    int returns;
    int index ;
    //int auxId;
    char auxNombre[51];
    char auxSexo[10];
    char auxTelefono[21];



    if(list != NULL && tam > 0)
    {
        system("cls");
        fflush(stdin);
        index = funcion_BuscarLugarVacioCliente(list,tam);
        printf("\n**** Nuevo Cliente ****\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            returns = -1 ;
            system("pause");

        }
        else
        {


            printf("\n Nuevo Cliente, ID numero %d \n",index) ;
            nuevoCliente.idCliente = index ;
            if(!funcion_getStringLetras("Ingrese nombre: ",auxNombre))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!funcion_getStringLetras("Ingrese el sexo: ",auxSexo))
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!funcion_getStringTelefono("Ingrese el telefono: ",auxTelefono))
            {
                printf("** Error, el telefono solo puede contener numeros y ir sin guiones**\n\n");
                system("pause");
                system("cls");

            }
            else
            {
                strcpy(nuevoCliente.nombre,auxNombre);
                strcpy(nuevoCliente.sexo,auxSexo) ;
                nuevoCliente.telefono=atoi(auxTelefono);
                nuevoCliente.isEmpty = 0;
                list[index] = nuevoCliente;
                system("pause");
                system("cls");
                printf("\n\nNUEVO CLIENTE INGRESADO:\n\n");
                funcion_mostrarCliente(list[index]);
                printf("\n\n\n");
                system("pause");
                returns = 0 ;
            }
        }

    }
    else
    {
        returns = -1 ;
    }
    return returns;
}

int funcion_BuscarLugarVacioCliente(eCliente lista[],int tam)
{
    int index = -1;
    for(int i=0; i< tam ; i++)
    {
        if( lista[i].isEmpty == 1)
        {
            index = i + 1;
            break;
        }
    }
    return index ;
}

void funcion_mostrarCliente(eCliente list)
{

    printf("\nID:%d - NOMBRE:%s - SEXO:%s - TELEFONO:%d\n\n", list.idCliente, list.nombre, list.sexo, list.telefono);
}

void funcion_modificarCliente(eCliente list[], int tam)
{
    int id;
    int index;
    int opcion;
    char auxOpcion[3];
    char auxId[11];
    char nuevoNombre[31] ;
    char nuevoSexo[31];
    char nuevoTelefono[11];


    system("cls");
    printf("  *** Modificar  cliente ***\n\n");


    if(!funcion_getStringNumeros("Ingrese id: ",auxId))
    {
        printf("*** ERROR *** El id debe contener solo numeros.") ;
    }

    id = atoi(auxId) ;
    index = funcion_BuscarClienteXID(list, tam, id);


    if( index == -1)
    {
        printf("No hay ningun cliente con ese id %d.\n\n", id);
        system("pause");
    }
    else
    {
    char seguirModificando ='s';
    do{
       system("cls");
        funcion_mostrarCliente(list[index]) ;


    if(!funcion_getStringNumeros("\n\nQue desea modificar?\n\n1 - Nombre\n2 - Sexo\n3 - Telefono\n",auxOpcion))
    {
        printf("ERROR- INGRESE UN NUMERO");
    }

    opcion = atoi(auxOpcion);

    switch(opcion)
    {


       case 1:
        funcion_mostrarCliente(list[index]) ;
        printf("\n\n");
       //modificar nombre
        if(!funcion_getStringLetras("Ingrese nuevo nombre: ",nuevoNombre))
            {
                printf("*** Error *** El nombre debe tener solo letras.");
            }else
            {
            strcpy(list[index].nombre,nuevoNombre);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_mostrarCliente(list[index]);
            system("pause");
            break ;
       }
    case 2:
// Modifica sexo
        funcion_mostrarCliente(list[index]) ;
        printf("\n\n");
        if(!funcion_getStringLetras("Ingrese nuevo sexo: ",nuevoSexo))
            {
                printf("*** ERROR *** El sexo debe tener solo letras.\n\n");
            }else{

            strcpy(list[index].sexo,nuevoSexo);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_mostrarCliente(list[index]);
            system("pause");
            }
        break ;
    case 3:
        // modifica telefono
        funcion_mostrarCliente(list[index]) ;
        printf("\n\n");
        if(!funcion_getStringNumeros("Ingrese nuevo telefono: ",nuevoTelefono))
            {
                printf("*** ERROR *** El telefono debe contener solo numeros.") ;
            }else{

            list[index].telefono = atoi(nuevoTelefono);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_mostrarCliente(list[index]);
            system("pause");
            }
            break ;
    case 4:
        printf("*** ERROR *** Debe ingresar un numero del 1 al 4.\n");
        system("pause");
        break;

        }
} while (seguirModificando =='s');
        }
}

int funcion_BuscarClienteXID(eCliente list[], int tam, int id)
{

    for(int i=0; i < tam ; i++)
    {

        if( list[i].idCliente == id && list[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;

}

int funcion_BajaCliente(eCliente list[], int tam, int id)
{

    int index;
    int returns ;
    char auxID[10] ;
    char seguir;
    int flag = 0;

    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("  *** BAJA CLIENTE ***\n\n");


        if(!funcion_getStringNumeros("Ingrese id: ",auxID))
        {
            printf("*** ERROR *** El ID debe contener solo numeros.\n\n");
            system("pause") ;
            system("cls");
        }
        else
        {
            id = atoi(auxID) ;

            index = funcion_BuscarClienteXID(list,tam,id) ;


            if(index == -1)
            {
                printf("No hay ningun empleado con el id %d\n",id) ;
                system("pause") ;
            }
            else
            {
                returns = 0;
                funcion_mostrarCliente(list[index]) ;
                printf("¿Seguro que quiere borrar empleado? S o N");
                scanf("%c",&seguir);
                if(seguir == 'n')
                {
                    printf("Baja cancelada\n\n");
                }
                else
                {

                    list[index].isEmpty = 1;
                    printf("Borrado exitoso\n\n");
                }
                system("pause");
            }
        }
    }
    return returns ;
}

int funcion_ordenarClientesPorNombre(eCliente list[], int tam, int order)
{
    eCliente auxCliente;
    char auxOrder[1] ;
    if(!funcion_getStringNumeros("\n Ingrese 1 para ordenar de manera ascendente o ingrese 2 para ordenar de manera descendente: ",auxOrder))
    {
        printf("*** ERROR DEBE INGRESAR UN NUMERO ***");

    }

    order = atoi(auxOrder);
    switch(order)
    {
    case 1:
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(strcmp(list[j].nombre, list[i].nombre) < 0  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente;
                }
                else if(strcmp(list[j].nombre, list[i].nombre) == 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente;
                }
            }
        }
        printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");
        system("pause") ;
        system("cls") ;
        break;
    case 2:
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i+1; j <tam; j++)
            {
                if(strcmp(list[j].nombre, list[i].nombre) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente;
                }
                else if(strcmp(list[j].nombre, list[i].nombre) == 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente;
                }
            }
        }

        system("pause") ;
        system("cls") ;
        break;
    default:
        printf("No ingreso 1 o 2");
    }
    return 0;
}


void funcion_mostrarClientes(eCliente list[], int tam)
{

    system("cls");
    printf("\n ID NOMBRE SEXO TELEFONO\n\n");

    for(int i=0; i < tam; i++)
    {

        if( list[i].isEmpty == 0)
        {
            funcion_mostrarCliente(list[i]);
        }
    }
    system("pause");
}

void funcion_InicializarCategoria(eCategoria list[], int tam)
{
    eCategoria nuevaCategoria [5] =
    {
        {1, "MESA"},
        {2, "AZAR"},
        {3, "ESTRATEGIA"},
        {4, "SALON"},
        {5, "MAGIA"},
    };
    for (int i = 0; i < tam; i++)
    {
        list[i] = nuevaCategoria[i];
    }
}

void funcion_inicioJuegos(eJuego list[], int tam)
{
    eJuego nuevoJuego[10] =
    {
        {1, "POLL", 1000, 1},
        {2, "LA GUERRA", 100, 3},
        {3, "MAGIC KIDS", 300, 5},
        {4, "PIN-PONG", 1500, 1},
        {5, "BATALLA NAVAL", 500, 3},
        {6, "TETRIS", 350, 2},
        {7, "PELOTERO", 1000, 4},
        {8, "INFLABLE", 1500, 4},
        {9, "MAGICO-MAGICO", 1000, 5},
        {10,"TETRIS SUPER", 650, 2},
    };
    for (int i = 0; i < tam; i++)
    {
        list[i] = nuevoJuego[i];
    }
}

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
