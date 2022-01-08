#include<iostream>
using namespace std;
#include "retornoCabeceras.h"
#include "funciones.h"

///Obligatorias-Amarillas
TipoRetorno InsertarLinea(texto &text){//HECHA
	text = Insertar_Linea(text);
	return OK;
}

TipoRetorno BorrarLinea(texto &text, Posicion posicionLinea){//HECHA
	Posicion nro_Lineas;
	
	nro_Lineas = cantidadLineas(text); //Se cuentan las lineas del texto
	if(posicionLinea < 1 || posicionLinea > nro_Lineas){ //Una posición de linea mayor a la cantidad de lineas del texto significa un error
		return ERROR;
	}
	else{
		text = Borrar_Linea(text, posicionLinea);
	}
	return OK;
}

TipoRetorno ImprimirTexto(texto text){//HECHA
	Imprimir_Texto(text);
	return OK;
}

TipoRetorno InsertarPalabraEnLinea(texto &text, cabezal &ultimas, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){//HECHA
	Posicion nro_Lineas, nro_Palabras;
	
	nro_Lineas = cantidadLineas(text); //Se cuentan las lineas del texto
	if(posicionLinea < 1 || posicionLinea > nro_Lineas){ //Una posición de línea mayor a la cantidad de lineas del texto o menor a 0 significa un error
		return ERROR;
	}
	
	nro_Palabras = cantidadPalabrasEnLinea(text, posicionLinea);
	//Se cuentan la cantidad de palabras en la linea que se va a editar
	if(posicionPalabra < 1 || posicionPalabra > (nro_Palabras + 1)){//Si la posición de la palabra es inválida retorna error
		return ERROR;
	}

	text = Insertar_Palabra_En_Linea(text, posicionLinea, posicionPalabra, palabraAIngresar);
	ultimas = Insertar_Ultimas_Palabras(ultimas, palabraAIngresar);
	return OK;
}

TipoRetorno BorrarPalabra(texto &text, Posicion posicionLinea, Posicion posicionPalabra){//HECHA
	Posicion nroLineas, nroPalabras;
	nroLineas = cantidadLineas(text);
	if(posicionLinea < 1 || posicionLinea > nroLineas){
		return ERROR;
	}
	nroPalabras = cantidadPalabrasEnLinea(text, posicionLinea);
	if(posicionPalabra < 1 || posicionPalabra > nroPalabras){
		return ERROR;
	}
	text = Borrar_Palabra(text, posicionLinea, posicionPalabra);
	return OK;
}

TipoRetorno ImprimirLinea(texto text, Posicion posicionLinea){//HECHA
	Posicion cantLineas;
	cantLineas = cantidadLineas(text);
	if(posicionLinea < 1 || posicionLinea > cantLineas){
		return ERROR;
	}
	Imprimir_Linea(text, posicionLinea);
	return OK;
}

///Obligatorias-Naranjas
TipoRetorno InsertarLineaEnPosicion(texto &text, Posicion posicionLinea){//HECHA
	Posicion nroLineas;
	nroLineas = cantidadLineas(text);
	if(posicionLinea < 1 || posicionLinea > (nroLineas + 1)){
		return ERROR;
	}
	
	text = Insertar_Linea_En_Posicion(text, posicionLinea);
	return OK;
}

TipoRetorno BorrarTodo(texto &text){ //HECHA
	text = Borrar_Todo(text);
	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(texto &text, Cadena palabraABorrar){//HECHA
	text = Borrar_Ocurrencias_Palabra_En_Texto(text, palabraABorrar);
	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(texto &text, Posicion posicionLinea, Cadena palabraABorrar){//HECHA
	Posicion nroLineas;
	nroLineas = cantidadLineas(text);
	if(posicionLinea < 1 || posicionLinea > nroLineas){
		return ERROR;
	}
	
	text = Borrar_Ocurrencias_Palabra_En_Linea(text, posicionLinea, palabraABorrar);
	return OK;
}

///Funciones de segunda entrega
TipoRetorno IngresarPalabraDiccionario(dicc &diccionario, Cadena palabraAIngresar){//HECHA
	bool existe = false;
	existe = existePalabraEnDicc(diccionario, palabraAIngresar);
	if(existe){
		return ERROR;
	}
	
	diccionario = Ingresar_Palabra_Diccionario(diccionario, palabraAIngresar, NULL);
	return OK;
}

TipoRetorno BorrarPalabraDiccionario(dicc &diccionario, Cadena palabraABorrar){
	bool existe = false;
	existe = existePalabraEnDicc(diccionario, palabraABorrar);
	if(!existe){
		return ERROR;
	}
	diccionario = Borrar_Palabra_Diccionario(diccionario, palabraABorrar);
	return OK;
}

TipoRetorno ImprimirDiccionario(dicc diccionario){//HECHA
	Imprimir_Diccionario(diccionario);
	return OK;
}

TipoRetorno ImprimirTextoIncorrecto(texto text, dicc diccionario){//HECHA
	Imprimir_Texto_Incorrecto(text, diccionario);
	return OK;
}
	
///Opcional de primera entrega
TipoRetorno ComprimirTexto(texto &text){
	//text = Comprimir_Texto(text);
	return NO_IMPLEMENTADO;
}

///Opcional de segunda entrega
TipoRetorno ImprimirUltimasPalabras(cabezal ultimas){
	Imprimir_Ultimas_Palabras(ultimas.Ultima_Palabra);
	return OK;
}
	
