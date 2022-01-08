#ifndef DEFINICIONES_H
#define DEFINICIONES_H

//Definición de constantes 
#define MAX_CANT_PALABRAS_X_LINEA 3
#define MAX_CANT_ULTIMAS_PALABRAS 3
#define LARGOCOMANDO 80

//Definición de tipos de datos y estructuras
typedef char* Cadena;

typedef unsigned int Posicion;

typedef enum _tipoRetorno{
	OK,
	ERROR,
	NO_IMPLEMENTADO
}TipoRetorno;

///Estructura de tipo lista simple que almacena palabras en una linea
typedef struct _linea{
	Cadena palabras;
	_linea *ptrSig;
}*linea;

///Estructura de tipo lista simple que almacena lineas en un texto
typedef struct _texto{
	linea lineas; 
	bool estaLlena;
	_texto *ptrSig;
}*texto;

///Estructura de tipo ABB que almacena las palabras en un diccionario.
typedef struct _palabra{
	_palabra *wordPadre;
	_palabra *wordIzq;
	Cadena word;
	_palabra *wordDer;
}*dicc;

///Estructura de tipo lista doblemente encadenada que se encarga de almacenar las �ltimas palabras ingresadas al texto
///La cantidad de palabras es determinada por una constante llamada MAX_CANT_ULTIMAS_PALABRAS
typedef struct _UltimasPalabras{
	Cadena pal;
	_UltimasPalabras *palSig;
	_UltimasPalabras *palAnt;
}*UltimasPalabras;

///Cabezal que apunta a la primera palabra de la pila de ultimas palabras
typedef struct _cabezal{
	UltimasPalabras Primera_Palabra;
	UltimasPalabras Ultima_Palabra;
}cabezal;
#endif



