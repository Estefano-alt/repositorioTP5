/*
*    AUTHOR: Catedra de lenguajes de Taller 1 
*    DATE: 04/2025
*    LICENCE: Creative Commons 
*/

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DECLARE SUS FUNCIONES ACA
nodo *listaVacia();
void insertar_inicio(nodo **Start, nodo *Nnodo);
nodo *crearNodo(Producto prod);
void mostrarLista(nodo *Start, const char *titulo);

int main()
{    
    Producto *TodosLosProductos = ProductoElectronicos();
    MostrarProductosDeArreglo(TodosLosProductos, 40, "Productos de Proveedor 1");
    
    nodo *ListaSoftware = listaVacia();
    nodo *ListaHardware = listaVacia();

    for (int i = 0; i < 40; i++)
    {
        nodo *nuevoNodo = crearNodo(TodosLosProductos[i]);

        if (strcmp(TodosLosProductos[i].Categoria, "Software") == 0)
        {
            insertar_inicio(&ListaSoftware, nuevoNodo);
        }
        else if (strcmp(TodosLosProductos[i].Categoria, "Hardware") == 0)
        {
            insertar_inicio(&ListaHardware, nuevoNodo);
        }
    }

    mostrarLista(ListaSoftware, "Software");
    mostrarLista(ListaHardware, "Hardware");

    printf("\nFin programa\n");
    return 0;
}

// IMPLEMENTE SUS FUNCIONES ACA

nodo *listaVacia()
{
    return NULL;
}

void insertar_inicio(nodo **Start, nodo *Nnodo)
{
    Nnodo->Siguiente = *Start;
    *Start = Nnodo;
}

nodo *crearNodo(Producto prod)
{
    nodo *Nnodo = (nodo *)malloc(sizeof(nodo));

    Nnodo->producto.Nombre = (char *)malloc(strlen(prod.Nombre) + 1);
    strcpy(Nnodo->producto.Nombre, prod.Nombre);

    Nnodo->producto.Categoria = (char *)malloc(strlen(prod.Categoria) + 1);
    strcpy(Nnodo->producto.Categoria, prod.Categoria);

    Nnodo->producto.Id = prod.Id;
    Nnodo->producto.Stock = prod.Stock;
    Nnodo->producto.Precio = prod.Precio;
    Nnodo->producto.Activo = 1;

    Nnodo->Siguiente = NULL;

    return Nnodo;
}

void mostrarLista(nodo *Start, const char *titulo)
{
    printf("\n%s\n", titulo);
    MostrarLinea();

    while (Start != NULL)
    {
        MostrarProducto(Start->producto);
        printf("\n");

        Start = Start->Siguiente;
    }

    MostrarLinea();
}