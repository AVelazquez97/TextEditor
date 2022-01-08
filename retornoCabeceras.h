#ifndef RETORNOCABECERAS_H
#define RETORNOCABECERAS_H
#include "definiciones.h"

///Obligatorias-Amarillas
TipoRetorno InsertarLinea(texto &text); //Alexis

TipoRetorno BorrarLinea(texto &text, Posicion posicionLinea); //Lucas

TipoRetorno ImprimirTexto(texto text); //Nico

TipoRetorno InsertarPalabraEnLinea(texto &text, cabezal &ultimas, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar); //Alexis

TipoRetorno BorrarPalabra(texto &text, Posicion posicionLinea, Posicion posicionPalabra); //Lucas

TipoRetorno ImprimirLinea(texto text, Posicion posicionLinea); //Nico

///Obligatorias-Naranjas
TipoRetorno InsertarLineaEnPosicion(texto &text, Posicion posicionLinea); //Alexis

TipoRetorno BorrarTodo(texto &text); //Lucas

TipoRetorno BorrarOcurrenciasPalabraEnTexto(texto &text, Cadena palabraABorrar); //Nico

TipoRetorno BorrarOcurrenciasPalabraEnLinea(texto &text, Posicion posicionLinea, Cadena palabraABorrar); //Team

///Funciones de segunda entrega
TipoRetorno IngresarPalabraDiccionario(dicc &diccionario, Cadena palabraAIngresar);

TipoRetorno BorrarPalabraDiccionario(dicc &diccionario, Cadena palabraABorrar);

TipoRetorno ImprimirDiccionario(dicc diccionario);

TipoRetorno ImprimirTextoIncorrecto(texto text, dicc diccionario);

///Opcional de primera entrega
TipoRetorno ComprimirTexto(texto &text);

///Opcional de segunda entrega
TipoRetorno ImprimirUltimasPalabras(cabezal ultimas);
#endif
