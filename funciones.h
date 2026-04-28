#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Producto {
    int Id;
    char *Nombre;
    char *Categoria;
    int Stock;
    float Precio;
    int Activo;
}Producto;

typedef struct nodo
{
   Producto producto;
   struct nodo * Siguiente;
}nodo;

char Sucursal[3][15] = 
{
    "Tucuman", "Salta", "Deposito"
};

Producto * ProductoElectronicos();
void MostrarProductosDeArreglo(Producto * producto, int cantidad, const char * Titulo);
Producto CrearProducto(const char *nombre, const char *categoria, int id, int stock, float precio);
void MostrarProducto(Producto prod);


Producto * ProductoElectronicos() {
    Producto *Productos = malloc(sizeof(Producto) * 40);

    Productos[0] = CrearProducto("Placa madre GigaBlast", "Hardware", 1, 15, 1200);
    Productos[1] = CrearProducto("Simulador de clics infinito", "Software", 2, 5, 500);
    Productos[2] = CrearProducto("Memoria RAM HiperXtreme 16GB", "Hardware", 3, 10, 900);
    Productos[3] = CrearProducto("Compilador de pensamientos", "Software", 4, 3, 1800);
    Productos[4] = CrearProducto("Placa de video Dragón RTX9090", "Hardware", 5, 4, 3000);
    Productos[5] = CrearProducto("Sistema Operativo GatOS", "Software", 6, 12, 1000);
    Productos[6] = CrearProducto("Disco sólido 2TB TruenoSSD", "Hardware", 7, 7, 950);
    Productos[7] = CrearProducto("Suite Ofimática OjoSoft", "Software", 8, 15, 800);
    Productos[8] = CrearProducto("Fuente de poder Nuclear 800W", "Hardware", 9, 6, 1200);
    Productos[9] = CrearProducto("Editor de memes profesional", "Software", 10, 2, 600);
    Productos[10] = CrearProducto("Gabinete con luces de feria", "Hardware", 11, 5, 1100);
    Productos[11] = CrearProducto("Antivirus contra spoilers", "Software", 12, 10, 700);
    Productos[12] = CrearProducto("Kit de ventiladores RGB", "Hardware", 13, 9, 400);
    Productos[13] = CrearProducto("Juego 'Cosecha de Bits'", "Software", 14, 8, 1300);
    Productos[14] = CrearProducto("Adaptador universal para todo", "Hardware", 15, 3, 600);
    Productos[15] = CrearProducto("Calculadora cuántica v2.1", "Software", 16, 6, 1500);
    Productos[16] = CrearProducto("Teclado mecánico DragonFlame", "Hardware", 17, 7, 850);
    Productos[17] = CrearProducto("Traductor de emojis a texto", "Software", 18, 1, 450);
    Productos[18] = CrearProducto("Mouse gamer con cohete", "Hardware", 19, 4, 950);
    Productos[19] = CrearProducto("Simulador de programación", "Software", 20, 2, 1000);
    Productos[20] = CrearProducto("Router WiFi con sonido envolvente", "Hardware", 21, 3, 1400);
    Productos[21] = CrearProducto("ChatBot emocional v3.0", "Software", 22, 1, 1700);
    Productos[22] = CrearProducto("Monitor UltraWide SuperCurvo", "Hardware", 23, 2, 2500);
    Productos[23] = CrearProducto("Editor de memes de gatos AI", "Software", 24, 5, 900);
    Productos[24] = CrearProducto("Procesador OctaCore Lagfree", "Hardware", 25, 6, 3200);
    Productos[25] = CrearProducto("Sistema de gestión de tiempo perdido", "Software", 26, 3, 1500);
    Productos[26] = CrearProducto("Impresora 3D para stickers", "Hardware", 27, 4, 2800);
    Productos[27] = CrearProducto("Aplicación de alarmas personalizadas con voz de gato", "Software", 28, 2, 700);
    Productos[28] = CrearProducto("Auriculares envolventes 9.1", "Hardware", 29, 8, 1600);
    Productos[29] = CrearProducto("Simulador de vacaciones", "Software", 30, 6, 2000);
    Productos[30] = CrearProducto("Cámara web con filtro fantasía", "Hardware", 31, 1, 1300);
    Productos[31] = CrearProducto("Editor de fotos vintage automático", "Software", 32, 4, 1200);
    Productos[32] = CrearProducto("Refrigeración líquida IceBlast", "Hardware", 33, 2, 2200);
    Productos[33] = CrearProducto("Antiestrés digital con IA", "Software", 34, 9, 1100);
    Productos[34] = CrearProducto("Controlador universal para todo lo que se enchufa", "Hardware", 35, 7, 1700);
    Productos[35] = CrearProducto("Sistema de backup por telepatía", "Software", 36, 1, 1900);
    Productos[36] = CrearProducto("Mini dron USB espía (legal)", "Hardware", 37, 5, 2500);
    Productos[37] = CrearProducto("Calculadora de memes", "Software", 38, 2, 800);
    Productos[38] = CrearProducto("Pantalla portátil enrollable", "Hardware", 39, 4, 2100);
    Productos[39] = CrearProducto("Generador de excusas para entregar trabajos tarde", "Software", 40, 3, 600);

    return Productos;
}




Producto CrearProducto(const char *nombre, const char *categoria, int id, int stock, float precio) {
    Producto nuevo;

    nuevo.Id = id;
    nuevo.Nombre = (char *)malloc(strlen(nombre) + 1);
    strcpy(nuevo.Nombre, nombre);

    nuevo.Categoria = (char *)malloc(strlen(categoria) + 1);
    strcpy(nuevo.Categoria, categoria);

    nuevo.Stock = stock;
    nuevo.Precio = precio;
    nuevo.Activo = 1;  // Por defecto activo

    return nuevo;
}
        



void MostrarLinea()
{   
    printf("\n---------------------------\n");
}



void MostrarTextoYValor(const char *tituloLista, int cantidad)
{
    printf("\n"); 
    printf("%s - %d \n", tituloLista, cantidad);
}

void MostrarProductosDeArreglo(Producto * producto, int cantidad, const char * Titulo)
{
    printf("%s \n\r" ,Titulo);
    MostrarLinea();
    for (int i = 0; i < cantidad; i++)
    {
        MostrarProducto(producto[i]);
        printf("\n");
    }
    MostrarLinea();
}

void MostrarProducto(Producto producto)
{
    printf("%2d - %-10s | %-40s | $%7.2f | Stock: %2d | Activo: %d",
           producto.Id,
           producto.Categoria,
           producto.Nombre,
           producto.Precio,
           producto.Stock,
           producto.Activo);
}