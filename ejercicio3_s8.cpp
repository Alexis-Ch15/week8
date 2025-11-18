#include <iostream>
using namespace std;
double calcularDescuento(float precio, float descuento);
double calcularTotalPagar(float precio, float descuento1,float descuento2);

int main(){
	float precio, descuento_cliente,descuento_promocion;
	
	cout << "//////Descuento Servicio de Internet///////" << endl;
	cout << "Precio de su plan mensual: ";
	cin >> precio;
	cout << "Descuento por cliente: ";
	cin >> descuento_cliente;
	cout << "Descuento por promocion: ";
	cin >> descuento_promocion;
	double Precio_final = calcularTotalPagar(precio, descuento_cliente, descuento_promocion);
	cout << "Monto final a pagar: " << Precio_final;
}

double calcularDescuento(float precio, float descuento){
	double cant_descuento = precio * (descuento/100);
	
	return cant_descuento;
	
}

double calcularTotalPagar(float precio, float descuento1,float descuento2){
	double Total_a_pagar;
	double fidelidad = calcularDescuento(precio,descuento1);
	double promocion = calcularDescuento(precio,descuento2);
	
	Total_a_pagar = precio - (fidelidad+promocion);
	
	return Total_a_pagar;
}
