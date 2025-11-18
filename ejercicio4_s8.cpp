#include <iostream>
using namespace std;

float TELEFONIA_BASE = 7.99;
float TV_BASE = 28.50;
float INTERNET_BASE = 18.00;float IVA = 0.15;
float ICE = 0.15;
float INSTALACION_BASE = 120.00;


void mostrarMenu();
float calcularPrecioMensual(int servicio, int edad, float &descuentoEdad, float &precioBase, float &montoIVA, float &montoICE);
float calcularInstalacion(int metodoPago);
void mostrarResumen(int servicio, float precioBase, float montoIVA, float montoICE, float descuentoEdad, float precioMensual, float costoInstalacion);

int main() {
    int opcion, edad, metodoPago;
    
    while(true) {
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        
        if(opcion == 4) {
            cout << "Gracias por preferirnos!" << endl;
            break;
        }
        
        if(opcion < 1 || opcion > 4) {
            cout << "Opcion invalida!" << endl;
            continue;
        }
        
        // Validar edad
        cout << "Ingrese su edad: ";
        cin >> edad;
        if(edad < 0 || edad > 120) {
            cout << "Edad invalida!" << endl;
            continue;
        }
        
        // Calcular precio mensual
        float descuentoEdad, precioBase, montoIVA, montoICE;
        float precioMensual = calcularPrecioMensual(opcion, edad, descuentoEdad, precioBase, montoIVA, montoICE);
        
        // Método de pago instalación
        cout << "\n--- METODO DE PAGO INSTALACION ---" << endl;
        cout << "1. Tarjeta de credito (50% descuento)" << endl;
        cout << "2. Efectivo (10% descuento)" << endl;
        cout << "3. Otro metodo (sin descuento)" << endl;
        cout << "Seleccione metodo de pago: ";
        cin >> metodoPago;
        
        if(metodoPago < 1 || metodoPago > 3) {
            cout << "Metodo de pago invalido!" << endl;
            continue;
        }
        
        float costoInstalacion = calcularInstalacion(metodoPago);
        
        // Mostrar resumen
        mostrarResumen(opcion, precioBase, montoIVA, montoICE, descuentoEdad, precioMensual, costoInstalacion);
    }
    
    return 0;
}

void mostrarMenu() {
    cout << "\n///// SERVICIOS CLARO EP /////" << endl;
    cout << "1. Telefonia Fija: $" << TELEFONIA_BASE << " mensuales" << endl;
    cout << "2. TV Satelital: $" << TV_BASE << " mensuales" << endl;
    cout << "3. Internet Hogar: $" << INTERNET_BASE << " mensuales" << endl;
    cout << "4. Salir" << endl;
}

float calcularPrecioMensual(int servicio, int edad, float &descuentoEdad, float &precioBase, float &montoIVA, float &montoICE) {
    // Establecer precio base según servicio
    switch(servicio) {
        case 1: precioBase = TELEFONIA_BASE; break;
        case 2: precioBase = TV_BASE; break;
        case 3: precioBase = INTERNET_BASE; break;
    }
    
    // Aplicar descuento por tercera edad (solo sobre la base)
    descuentoEdad = 0;
    if(edad > 65) {
        descuentoEdad = precioBase * 0.50;
        precioBase -= descuentoEdad;
    }
    
    // Calcular impuestos
    montoIVA = precioBase * IVA;
    montoICE = 0;
    
    // ICE solo aplica a TV Satelital
    if(servicio == 2) {
        montoICE = precioBase * ICE;
    }
    
    // Precio final mensual
    return precioBase + montoIVA + montoICE;
}

float calcularInstalacion(int metodoPago) {
    float instalacion = INSTALACION_BASE;
    
    switch(metodoPago) {
        case 1: // Tarjeta de crédito - 50% descuento
            instalacion *= 0.50;
            break;
        case 2: // Efectivo - 10% descuento
            instalacion *= 0.90;
            break;
        case 3: // Otro método - sin descuento
            break;
    }
    
    return instalacion;
}

void mostrarResumen(int servicio, float precioBase, float montoIVA, float montoICE, float descuentoEdad, float precioMensual, float costoInstalacion) {
    string nombreServicio;
    switch(servicio) {
        case 1: nombreServicio = "Telefonia Fija"; break;
        case 2: nombreServicio = "TV Satelital"; break;
        case 3: nombreServicio = "Internet Hogar"; break;
    }
    
    cout << "\n/// RESUMEN DE CONTRATACION ///" << endl;
    cout << "Servicio: " << nombreServicio << endl;
    cout << "Precio base: $";
    switch(servicio) {
    case 1: cout << TELEFONIA_BASE; break;
    case 2: cout << TV_BASE; break;
    case 3: cout << INTERNET_BASE; break;
	}
cout << endl;
    
    if(descuentoEdad > 0) {
        cout << "Descuento tercera edad (50%): -$" << descuentoEdad << endl;
    }
    
    cout << "Base despues de descuentos: $" << precioBase << endl;
    cout << "IVA (15%): +$" << montoIVA << endl;
    
    if(montoICE > 0) {
        cout << "ICE (15%): +$" << montoICE << endl;
    }
    
    cout << "---" << endl;
    cout << "PRECIO MENSUAL A PAGAR: $" << precioMensual << endl;
    cout << "COSTO DE INSTALACION: $" << costoInstalacion << endl;
    cout << "//////////////////////////////" << endl;
}

