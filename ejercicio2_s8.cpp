#include <iostream>
using namespace std;
void ingreso_Datos(float lista[], int extension);
void encontrarMayorMenor(float precios[], int extension, float &mayor, float &menor);
void mostrarDatosProgramador();
void calcular_descuento();

int main(){
	float precios[8];
	int extension = 8;
	float mayor,menor;

	ingreso_Datos(precios,extension);

	mayor = precios[0];
	menor = precios[0];
	cout << endl;
	encontrarMayorMenor(precios, extension, mayor, menor);
	cout << endl;
	mostrarDatosProgramador();
	cout << endl;
	calcular_descuento();
	
	return 0;
}

void ingreso_Datos(float lista[], int extension){
	float precio;
	for (int i = 0; i< extension; i++){
		cout << "Ingrese el precio: ";
		cin >> precio;
		lista[i] = precio;
	}
	
}
void encontrarMayorMenor(float precios[], int extension, float &mayor, float &menor){
	for (int i = 1; i < extension; i++){
		if (precios[i] > mayor){
			
			mayor = precios[i];
		}

		if (menor > precios[i]){
			
			menor = precios[i];
		}
	}
	cout << "EL numero mayor es : " << mayor << endl;
	cout << "EL numero menor es : "<< menor << endl;
}

void mostrarDatosProgramador(){
	cout << "Nombre:Alexis Chasi"<< endl;
	cout << "Edad: 18 años" << endl;
	cout << "Celular: 0994402375" << endl;
}

void calcular_descuento(){
	string producto;
	float precio,precio_final;
	float descuento = 0.10;
	cout << "Nombre del producto: ";
	cin >> producto;
	cout << "Precio: " << endl;
	cin >>  precio;
	if (precio > 1000){
		precio_final = precio - (precio* descuento);
		cout << "Posee un descuento del 10% "<< endl;
		cout << "Precio final: " << precio_final << endl;
	}else if (precio>0 && precio < 1000){
		cout <<"Precio final: " << precio;
	}else{
		cout << "Valor no valido";
	}
	
}
