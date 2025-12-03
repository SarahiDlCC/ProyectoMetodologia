/* ====================================================================================================================
                                                TIENDA CORTES
=======================================================================================================================*/

#include <iostream>
#include <string>

using namespace std;

int contadordeProductos = 0;
int tamaniodeProducto = 100;

// Definir la estructura para un producto.

struct Producto {
    string nombre;
    float precio;
    int cantidad;
};

Producto productoenLista[100] = {};

/* ====================================================================================================================
                    Paso 1:             Registrar productos del usuario.
=======================================================================================================================*/

void registrarProductos() {
    int cantidaddeProductos = 0;

    cout << "\n¿Cuántos productos desea registrar? ";
    cin >> cantidaddeProductos;

    int totalRegistro = contadordeProductos + cantidaddeProductos;

    if(contadordeProductos < tamaniodeProducto) {
        for(int i = contadordeProductos; i < totalRegistro; i++) {
            if(i >= tamaniodeProducto) {
                cout << "\nLímite de la lista de productos alcanzado. " << endl;
                break;
            }
            cout << "\nProducto " << i + 1 << ": " << endl;

            while(true) {
                cout << "Nombre: ";
                cin >> productoenLista[i].nombre;

                if(productoenLista[i].nombre == "") {
                    cout << "Ingrese un nombre que sea válido." << endl;
                    continue;
                }
                if(productoenLista[i].nombre == "") {
                    cout << "\nEl nombre debe ir de forma continua. Intentelo de nuevo." << endl;
                    continue;
                } else break;
            }

            while(true) {
                cout << "Precio: ";
                cin >> productoenLista[i].precio;

                if(productoenLista[i].precio <= 0) {
                    cout << "\nEl precio debe registrarse con una cantidad mayor a cero." << endl;
                } else break;
            }

            while(true) {
                cout << "Cantidad: ";
                cin >> productoenLista[i].cantidad;

                if(productoenLista[i].cantidad <= 0) {
                    cout << "\nLa cantidad debe registrarse con una cantidad mayor a cero." << endl;
                } else break;
            }
            contadordeProductos++; 
        }
    } 
    else {
        cout << "\nLímite máximo de productos excedido." << endl;
    }
    cout << "\nProductos registrados existosamente." << endl << endl;
}

/* ====================================================================================================================
                    Paso 2:            Mostrar las lista de productos.
=======================================================================================================================*/

void mostrarProductos() {
    cout << "\n============ LISTA DE PRODUCTOS ============" << endl;
    cout << "Nombre \t\t Precio \t Cantidad" << endl;
    cout << "--------------------------------------------" << endl;

    for(int i = 0; i < contadordeProductos; i++) {
        if(productoenLista[i].nombre != "" && productoenLista[i].precio != 0.0) {
            if(productoenLista[i].cantidad != 0) {
                cout << productoenLista[i].nombre << " \t " << productoenLista[i].precio << " \t\t " << productoenLista[i].cantidad << endl;
            }
        }
    }
    cout << endl;
}

/* ====================================================================================================================
            Paso 3:       Ordenarlos por precio (ascedente) utilizando métodos de ordenamiento básicos.
=======================================================================================================================*/

//      Void para imprimir los productos y  no hacerlo en cada uno de los void de métodos

void imprimirProducto() {
    cout << "\n======= LISTA DE PRODUCTOS ORDENADOS =======" << endl;
    
    for(int i = 0; i < contadordeProductos; i++) {
        cout << "\nProducto " << i + 1 << ": " << endl;
        cout << "Nombre: " << productoenLista[i].nombre << endl;
        cout << "Precio: " << productoenLista[i].precio << endl;
        cout << "Cantidad: " << productoenLista[i].cantidad << endl;
    }
}

//      Método de ordenamiento Burbuja.

void ordenarProductosburbuja() {
    int i, j;
    Producto aux;

    for(i = 0; i < contadordeProductos - 1; i++) {
        for(j = 0; j < contadordeProductos - 1 - i; j++) {
            if(productoenLista[j].precio > productoenLista[j+1].precio) {
                aux = productoenLista[j];
                productoenLista[j] = productoenLista[j + 1];
                productoenLista[j + 1] = aux;
            }
          
        }
    }
    imprimirProducto();
}

//      Método de ordenamiento Seleción.

void ordenarProductosSelecion() {
    int i, j, min;
    Producto aux;

    for(i = 0; i < contadordeProductos - 1; i++) {
        min = i;

        for(j = i + 1; j < contadordeProductos; j++) {
            if(productoenLista[j].precio < productoenLista[min].precio) {
                min = j;
            }
        }
        if(min != i) {
            aux = productoenLista[i];
            productoenLista[i] = productoenLista[min];
            productoenLista[min] = aux;
        }
    }
    imprimirProducto();
}

//      Método de ordenamiento Inserción.

void ordenarProductosInsercion() {
    int i, pos;
    Producto aux;

    for(i = 1; i < contadordeProductos; i++) {
        pos = i;
        aux = productoenLista[i];

        while(pos > 0 &&  productoenLista[pos - 1].precio > aux.precio) {
            productoenLista[pos] = productoenLista[pos - 1];
            pos--;
        }
    productoenLista[pos] = aux;
    }
    imprimirProducto();
}

//      Menú de nuestros métodos de ordenamiento

void ordenarProductos() {
    int opcion;

    do {
        cout << "\nSeleccione método de ordenamiento: " << endl;
        cout << "1. Burbuja." << endl;
        cout << "2. Selección." << endl;
        cout << "3. Inserción. " << endl;
        cout << "4. Volver al menú principal." << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ordenarProductosburbuja();
            break;

            case 2:
                ordenarProductosSelecion();
            break;

            case 3:
                ordenarProductosInsercion();
            break;
            
            case 4:
                cout << "\nRegresando al menú principal" << endl;
            break;

            default:
                cout << "\nOpción no valida. Intentelo de nuevo." << endl;
        }
    } while (opcion != 4);
    cout << endl;
}

/* ====================================================================================================================
                    Paso 4:                  Buscar un producto por nombre.
=======================================================================================================================*/

void buscarProducto() {
    string busqueda;

    cout << "\nIngrese el nombre a buscar: ";
    cin >> busqueda;
    cout << "\nProducto encontrado: " << endl;

    for(int i = 0; i < contadordeProductos; i++) {
        if(productoenLista[i].nombre == busqueda) {
            cout << "Nombre: " << productoenLista[i].nombre << endl;
            cout << "Precio: " << productoenLista[i].precio << endl;
            cout << "Cantidad: " << productoenLista[i].cantidad << endl;
            break;
        }
    }
    cout << endl;
}

/* ====================================================================================================================
                    Paso 5:           Actualizar información de un producto seleccionado.
=======================================================================================================================*/

void actualizarProducto() {
    int i = 0;
    int opcion = 0;

    while(true) {
        cout << "\nIngrese el índice del producto a actualizar (0 - " << contadordeProductos - 1 << "): ";
        cin >> i;

        if(i >= contadordeProductos) {
            cout << "\nLa posición indicada no fue encontrada. Intentelo de nuevo.";
        }
        else {
            break;
        }
    }
    cout << "¿Qué desea actualizar?" << endl;
    cout << "1. Precio." << endl;
    cout << "2. Cantidad." << endl;
    cout << "Opción : ";
    cin >> opcion;

    switch(opcion) {
        case 1:
        while(true) {
            cout << "Nuevo precio: ";
            cin >> productoenLista[i].precio;

            if(productoenLista[i].precio <= 0) {
                cout << "\nEl precio debe registrarse con una cantidad mayor a cero. Intentelo de nuevo." << endl;
            }
            else {
                break;
            }
        }
        break;

        case 2:
        while(true) {
            cout << "Nueva cantidad: ";
            cin >> productoenLista[i].cantidad;

            if(productoenLista[i].cantidad <= 0) {
                cout << "\nLa cantidad debe registrarse con una cantidad mayor a cero. Intentelo de nuevo." << endl;
            }
            else {
                break;
            }
        }
        break;

        default:    break;
    }
    cout << "Producto actualizado" << endl << endl;
}

/* ====================================================================================================================
                    Paso 6:            Generar un pequeño reporte final.
=======================================================================================================================*/

void generarReporteFinal() {
    int totaldeProductos = 0;
    double totaldePrecios = 0.0;
    string productoMayor = "";
    int mayorCantidad = 0;

    for(int i = 0; i < contadordeProductos; i++) {
        if(productoenLista[i].nombre != "" && productoenLista[i].precio != 0.0)
        if(productoenLista[i].cantidad != 0) {
            totaldeProductos++;
            totaldePrecios += productoenLista[i].precio;            
        }
        productoMayor = productoenLista[0].nombre;
        mayorCantidad = productoenLista[0].cantidad;
        
        for(int i = 1; i < contadordeProductos; i++) {
        if(productoenLista[i].nombre != "" && productoenLista[i].precio != 0.0)
        if(productoenLista[i].cantidad != 0) {
            if(productoenLista[i].cantidad > mayorCantidad) {   
                productoMayor = productoenLista[i].nombre;
                mayorCantidad = productoenLista[i].cantidad;
            }
        }
        }
        }
    cout << "\n========= REPORTE FINAL =========" << endl;
    cout << "Total de productos registrados: " << totaldeProductos << endl;
    cout << "Valor total en inventario: $ " << totaldePrecios << endl;
    cout << "Producto con mayor cantidad: " << productoMayor << "(" << mayorCantidad << ")" << endl;
}

/* ====================================================================================================================
                                                    Menú general.
=======================================================================================================================*/

int main() {
    int opcion;

    do {
        cout << "======= SISTEMA BÁSICO DE GESTIÓN DE PRODUCTOS =======" << endl << endl;
        cout << "1. Registrar productos." << endl;
        cout << "2. Mostrar productos." << endl;
        cout << "3. Ordenar productos." << endl;
        cout << "4. Buscar producto." << endl;
        cout << "5. Actualizar producto." << endl;
        cout << "6. Generar reporte final." << endl;
        cout << "7. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarProductos();
            break;

            case 2:
                mostrarProductos();
            break;

            case 3:
                ordenarProductos();
            break;

            case 4:
                buscarProducto();
            break;

            case 5:
                actualizarProducto();
            break;

            case 6:
                generarReporteFinal();
            break;
            
            case 7:
                cout << "\n¡Muchas gracias!" << endl;
            break;
            
            default:
                cout << "\nError: esa opción no existe, ingresa la opción de nuevo" << endl;
        }
    } while (opcion != 7);

    return 0;
}