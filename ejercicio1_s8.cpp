#include <iostream>
using namespace std;

int main() {
    int arreglo[5];
    bool arregloLleno = false;
    int opcion;
    
    do {
        cout << "\n=== SISTEMA DE GESTION DE ARREGLO ===" << endl;
        cout << "1. Llenar el arreglo" << endl;
        cout << "2. Sumar los elementos del arreglo" << endl;
        cout << "3. Modificar una posicion" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                cout << "\n--- LLENAR ARREGLO ---" << endl;
                for(int i = 0; i < 5; i++) {
                    cout << "Ingrese el valor para la posicion " << i << ": ";
                    cin >> arreglo[i];
                }
                arregloLleno = true;
                cout << "Arreglo llenado correctamente!" << endl;
                break;
            }
            
            case 2: {
                if(!arregloLleno) {
                    cout << "Error: El arreglo no esta inicializado. Use la opcion 1 primero." << endl;
                } else {
                    cout << "\n--- SUMAR ELEMENTOS ---" << endl;
                    int suma = 0;
                    for(int i = 0; i < 5; i++) {
                        suma += arreglo[i];
                    }
                    cout << "La suma de todos los elementos es: " << suma << endl;
                }
                break;
            }
            
            case 3: {
                if(!arregloLleno) {
                    cout << "Error: El arreglo no esta inicializado. Use la opcion 1 primero." << endl;
                } else {
                    cout << "\n--- MODIFICAR POSICION ---" << endl;
                    int posicion;
                    cout << "Ingrese la posicion a modificar (0-4): ";
                    cin >> posicion;
                    
                    if(posicion >= 0 && posicion < 5) {
                        cout << "Valor actual en posicion " << posicion << ": " << arreglo[posicion] << endl;
                        cout << "Ingrese el nuevo valor: ";
                        cin >> arreglo[posicion];
                        cout << "Valor modificado correctamente!" << endl;
                    } else {
                        cout << "Error: Posicion invalida. Debe estar entre 0 y 4." << endl;
                    }
                }
                break;
            }
            
            case 4: {
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            }
            
            default: {
                cout << "Error: Opcion invalida. Intente nuevamente." << endl;
                break;
            }
        }
        
    } while(opcion != 4);
    
    return 0;
}
