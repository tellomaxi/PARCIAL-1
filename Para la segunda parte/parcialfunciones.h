typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idCategoria;
    char descripcion[51];
    int isEmpty;
}eCategoria;

typedef struct
{
    int idJuego;
    char descripcion[50];
    float importe;
    eCategoria idCategoria;
    int isEmpty;

}eJuego;

typedef struct
{
    int idCliente;
    char nombre[20];
    char sexo[20];
    int telefono;
    int isEmpty;

}eCliente;

typedef struct
{
    int idAlquiler;
    eJuego codigoDelJuego;
    eCliente codigoDeCliente;
    eFecha diaDeHoy;
    int isEmpty;
}eAlquileres;


void funcion_InicializarCliente(eCliente list[], int tam);
int funcion_opcionesCliente();
int funcion_AltaCliente(eCliente lista[], int tam);
int funcion_BuscarLugarVacioCliente(eCliente lista[],int tam);
void funcion_mostrarCliente(eCliente list);
void funcion_modificarCliente(eCliente list[], int tam);
int funcion_BuscarClienteXID(eCliente list[], int tam, int id);
int funcion_BajaCliente(eCliente list[], int tam, int id);
void funcion_mostrarClientes(eCliente list[], int tam);
int funcion_ordenarClientesPorNombre(eCliente list[], int tam, int order);
