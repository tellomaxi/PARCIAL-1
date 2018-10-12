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
