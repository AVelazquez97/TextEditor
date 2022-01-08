#ifndef RETORNOFUNCIONES_H
#define RETORNOFUNCIONES_H
#include "definiciones.h"

///Obligatorias-Amarillas
texto Insertar_Linea(texto text);

texto Borrar_Linea(texto text, Posicion posicionLinea);

void Imprimir_Texto(texto text);

texto Insertar_Palabra_En_Linea(texto text, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);

texto Borrar_Palabra(texto text, Posicion posicionLinea, Posicion posicionPalabra);

void Imprimir_Linea(texto text, Posicion posicionLinea);

///Obligatorias-Naranjas
texto Insertar_Linea_En_Posicion(texto text, Posicion posicionLinea);

texto Borrar_Todo(texto text);

texto Borrar_Ocurrencias_Palabra_En_Texto(texto text, Cadena palabraABorrar);

texto Borrar_Ocurrencias_Palabra_En_Linea(texto text, Posicion posicionLinea, Cadena palabraABorrar);

///Funciones de segunda entrega
dicc Ingresar_Palabra_Diccionario(dicc &diccionario, Cadena palabraAIngresar, dicc padre);

dicc Borrar_Palabra_Diccionario(dicc diccionario, Cadena palabraABorrar);

void Imprimir_Diccionario(dicc diccionario);

void Imprimir_Texto_Incorrecto(texto text, dicc diccionario);

///Opcional primera entrega
texto Comprimir_Texto(texto text); //Sin implementar

///Opcional segunda entrega
void Imprimir_Ultimas_Palabras(UltimasPalabras ultima);

///Auxiliares
//Función que evalúa si un texto está vacío o no. Si lo es retorna true, caso contrario retorna false
bool esVacio(texto text);

//Función que evalúa si una línea está vacía o no. Si lo es retorna true, caso contrario retorna false
bool esVacia(linea lineas);

//Procedimiento que muestra el estado de una función. Si está OK, da ERROR o se encuentra NO_IMPLEMENTADA
void mostrarResultado(int retorno);

//Función que retorna la cantidad de lineas que tiene un texto 
int cantidadLineas(texto text);

//Función que retorna la cantidad de palabras que tiene una línea
int cantidadPalabrasEnLinea(texto text, Posicion lineaDeseada);

//Funcion que borra libera los espacios en memoria reservados para las palabras que tenía una linea determinada
//Retorna la linea apuntando a null
linea borro_palabras(linea l);

//Elimina una palabra especifica de una linea determinada todas las veces que ésta se encuentre
linea borro_ocurrencias_palabra(linea l, Cadena palabra_a_borrar, bool *hayCoinicidencia);

//Inserta una palabra al principio de una línea
linea insertarPalAlPrincipio(linea nodoPalabra, Cadena palabra);

/*Función que desplaza la ultima palabra de una linea (que superó su máximo permitido) a la siguiente linea.
En caso que la siguiente linea está llena, se repite el proceso. En un caso extremo,
se crea una nueva línea en el texto*/
texto desplazamiento_de_Palabras(texto text);

///Auxiliares de segunda entrega
//Devuelve true si existe la palabra en el diccionario, y en caso contrario retorna false
bool existePalabraEnDicc(dicc diccionario, Cadena palabra);

//Retorna la dirección de memoria de la menor palabra dentro del diccionario
dicc Minimo(dicc diccionario);

//Retorna la dirección de memoria de la mayor palabra dentro del diccionario
dicc Maximo(dicc diccionario);

//Devuelve true si la palabra es hoja del arbol diccionario, caso contrario retorna false
bool esHoja(dicc diccionario);

void pausa();

void mostrarAyuda();

dicc esPadre(dicc diccionario);

dicc hijoDer(dicc diccionario);

dicc hijoIzq(dicc diccionario);

Cadena datoWord(dicc diccionario);

dicc buscarEnDicc(dicc diccionario, Cadena palabraABorrar);

void mostrarError();

void mostrarTitulo();

///Auxiliares para opcionales
linea InsertarPalAlFinal(linea palabraAInsertar, Cadena palabra);

cabezal Insertar_Ultimas_Palabras(cabezal ultimas, Cadena palabraAIngresar);

bool Esta_Vacia (cabezal Palabra);

int Cant_Palabras(UltimasPalabras Primera);

#endif
