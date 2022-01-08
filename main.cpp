#include<iostream>
#include<string.h>
using namespace std;
#include "definiciones.h"
#include "retornoCabeceras.h"
#include "retornoImplementaciones.cpp"
#include "funciones.h"
#include "funcionesImplementaciones.cpp"

int main (int argc, char *argv[]){
	texto text = NULL;
	dicc diccionario = NULL;
	cabezal ultimas;
	ultimas.Primera_Palabra = NULL;
	ultimas.Ultima_Palabra = NULL;
	
	Cadena comando, orden, parametroCadena, nroLinea, nroPalabra;
	int Linea, Palabra;
		
	while(true){
		mostrarTitulo();
		comando = new char[LARGOCOMANDO];
		
		orden = new char[LARGOCOMANDO];
		
		cin.getline(comando, LARGOCOMANDO);
		orden = strtok(comando, "("); 
		if(strcmp(orden, "InsertarLinea") == 0){
			mostrarResultado(InsertarLinea(text));			
			pausa();
		}
		else if(strcmp(orden, "BorrarLinea") == 0){
			nroLinea = new char;
			nroLinea = strtok(NULL, ")");
			
			if(nroLinea != NULL){
				Linea = atoi(nroLinea);
				mostrarResultado(BorrarLinea(text, Linea));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "ImprimirTexto") == 0){
			mostrarResultado(ImprimirTexto(text));
			pausa();
		}
		else if(strcmp(orden, "InsertarPalabraEnLinea") == 0){
			nroLinea = new char;
			nroPalabra = new char;
			parametroCadena = new char[LARGOCOMANDO];	
			nroLinea = strtok(NULL, ",");
			nroPalabra = strtok(NULL, ",");
			parametroCadena = strtok(NULL, ")");
			
			if((nroLinea != NULL) && (nroPalabra != NULL) && (parametroCadena != NULL)){
				Linea = atoi(nroLinea);
				Palabra = atoi(nroPalabra);
				mostrarResultado(InsertarPalabraEnLinea(text, ultimas, Linea, Palabra, parametroCadena));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "BorrarPalabra") == 0){
			nroLinea = new char;
			nroPalabra = new char;
			nroLinea = strtok(NULL, ",");
			nroPalabra = strtok(NULL, ")");
			
			if((nroLinea != NULL) && (nroPalabra != NULL)){
				Linea = atoi(nroLinea);
				Palabra = atoi(nroPalabra); 
				mostrarResultado(BorrarPalabra(text, Linea, Palabra));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "ImprimirLinea") == 0){
			nroLinea = new char;
			nroLinea = strtok(NULL, ")");
			
			if(nroLinea != NULL){
				Linea = atoi(nroLinea);
				mostrarResultado(ImprimirLinea(text, Linea));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "InsertarLineaEnPosicion") == 0){
			nroLinea = new char;
			nroLinea = strtok(NULL, ")");
			
			if(nroLinea != NULL){
				Linea = atoi(nroLinea);
				mostrarResultado(InsertarLineaEnPosicion(text, Linea));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "BorrarTodo") == 0){
			mostrarResultado(BorrarTodo(text));
			pausa();
		}
		else if(strcmp(orden, "BorrarOcurrenciasPalabraEnTexto") == 0){
			parametroCadena = new char[LARGOCOMANDO];
			parametroCadena = strtok(NULL, ")");
			
			if(parametroCadena != NULL){
				mostrarResultado(BorrarOcurrenciasPalabraEnTexto(text, parametroCadena));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "BorrarOcurrenciasPalabraEnLinea") == 0){
			nroLinea = new char;
			parametroCadena = new char[LARGOCOMANDO];
			nroLinea = strtok(NULL, ",");
			parametroCadena = strtok(NULL, ")");
			
			if((nroLinea != NULL) && (parametroCadena != NULL)){
				Linea = atoi(nroLinea);
				mostrarResultado(BorrarOcurrenciasPalabraEnLinea(text, Linea, parametroCadena));
			}
			else{
				mostrarError();
			}
			pausa();			
		}
		///Obligatorias segunda entrega
		else if(strcmp(orden, "IngresarPalabraDiccionario") == 0){
			parametroCadena = new char[LARGOCOMANDO];
			parametroCadena = strtok(NULL, ")");
			
			if(parametroCadena != NULL){
				mostrarResultado(IngresarPalabraDiccionario(diccionario, parametroCadena));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "BorrarPalabraDiccionario") == 0){
			parametroCadena = new char[LARGOCOMANDO];
			parametroCadena = strtok(NULL, ")");
			
			if(parametroCadena != NULL){
				mostrarResultado(BorrarPalabraDiccionario(diccionario, parametroCadena));
			}
			else{
				mostrarError();
			}
			pausa();
		}
		else if(strcmp(orden, "ImprimirDiccionario") == 0){
			mostrarResultado(ImprimirDiccionario(diccionario));
			pausa();
		}
		else if(strcmp(orden, "ImprimirTextoIncorrecto") == 0){
			mostrarResultado(ImprimirTextoIncorrecto(text, diccionario));
			pausa();
		}
		///Opcional primer entrega
		else if(strcmp(orden, "ComprimirTexto") == 0){
			mostrarResultado(ComprimirTexto(text));
			pausa();
		}
		///Opcional segunda entrega
		else if(strcmp(orden, "ImprimirUltimasPalabras") == 0){
			mostrarResultado(ImprimirUltimasPalabras(ultimas));
			pausa();
		}
		else if(strcmp(orden, "Ayuda") == 0){
			mostrarAyuda();
			pausa();
		}
		else if(strcmp(orden, "Salir") == 0 || strcmp(orden, "Exit") == 0){
			cout << "Fin del programa." << endl;
			return 0;
		}
		else{
			cout << "El comando ingresado no existe." << endl;
			pausa();
		}
		system("clear"); //En linux
		//system("cls"); //En windows
	}
	return 0;
}
