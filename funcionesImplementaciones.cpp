#include <iostream>
#include <string.h>
using namespace std;
#include "funciones.h"

///Obligatorias-Amarillas
texto Insertar_Linea(texto text){ //HECHA
	texto nuevaLinea;
	nuevaLinea = new struct _texto;	
	nuevaLinea->lineas = NULL; //Crea la lista que almacenará las palabras 
	nuevaLinea->estaLlena = false;
	nuevaLinea->ptrSig = NULL; //Hace que la nueva linea apunte a NULL.
	
	/*Tanto si el texto es vacío como si no lo es, la nueva linea va a apuntar
	a NULL, ya que en todos los casos va a ser la última línea*/
	
	if(esVacio(text)){ //Esto es lo que ocurriría si el texto nos viene vacío.
		text = nuevaLinea;// El texto se engancha a la nueva línea.
	}
	else{//Si el texto ya tiene líneas, se guarda su posición inicial en un nodo auxiliar.
		texto nodoAux;
		nodoAux = text;
		
		while(!esVacio(text->ptrSig)){ //Mientras el puntero de la linea siguiente no apunte a null se sigue recorriendo el texto
			text = text->ptrSig;
		}
		text->ptrSig = nuevaLinea; //Hace que la última línea de la lista se enganche a la nueva línea.
		text = nodoAux; //Lleva al cabezal a su espacio inicial.
	}
	return text;
}
texto Borrar_Linea(texto text, Posicion posicionLinea){//HECHA
	Posicion cant_lineas = 1;
	texto lineaABorrar;
	texto lineaAnterior;
	lineaAnterior = NULL;
	lineaABorrar = text;
	
	while(!esVacio(lineaABorrar)){
		//cant_lineas++; //cant_lineas = 1
		if(cant_lineas == posicionLinea){
			if(esVacio(lineaAnterior)){ //En caso de que la línea a borrar sea la primera
				text = lineaABorrar->ptrSig;
				lineaABorrar->lineas = borro_palabras(lineaABorrar->lineas); //libera los espacios de memoria de las palabras en la linea deseada.
				delete lineaABorrar;
				lineaABorrar = NULL;
			}
			else if(esVacio(lineaABorrar->ptrSig)){//En caso de que la linea a borrar sea la ultima
				lineaAnterior->ptrSig = lineaABorrar->ptrSig;
				lineaABorrar->lineas = borro_palabras(lineaABorrar->lineas);
				delete lineaABorrar;
				lineaABorrar = NULL;
				lineaAnterior = text;
			}
			else{ //Cualquier linea menos la última ni la primera
				lineaAnterior->ptrSig = lineaABorrar->ptrSig;
				lineaABorrar->lineas = borro_palabras(lineaABorrar->lineas);
				delete lineaABorrar;
				lineaABorrar = NULL;
			}
		}
		else{ //Hasta que no se encuentre la linea a borrar, se sigue recorriendo el texto, y se cuentan las lineas
			lineaAnterior = lineaABorrar;
			lineaABorrar = lineaABorrar->ptrSig;
			cant_lineas++;	
		}
	}
	return text;
}

void Imprimir_Texto(texto text){ //HECHA
	int nroLinea = 1; //se definen contadores para las lineas del texto
	texto auxText;
	auxText = text;//se crea una lista auxiliar para conservar la posicion inicial del texto
	linea auxLinea;
	
	if(esVacio(text)){ //En caso de que el texto no tenga lineas
		cout << "Texto vacío" << endl;
	}
	else{
		while(!esVacio(text)){
			cout << nroLinea << ":";
			auxLinea = text->lineas; //se crea una lista auxiliar para conservar la posicion inicial de la palabra
			while(!esVacia(text->lineas)){
				cout << " " << text->lineas->palabras;
				text->lineas = text->lineas->ptrSig;
			}
			text->lineas = auxLinea;
			cout << endl;
			text = text->ptrSig;
			nroLinea++;
		}
	}
	text = auxText;
}


texto Insertar_Palabra_En_Linea(texto text, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){//CASI HECHA
	Posicion nroLinea = 0, nroPalabra;
	int cantPalabras;
	texto textAux;
	linea palabraAnterior;
	linea palabraActual;
	
	linea nuevaPalabra = new struct _linea;
	nuevaPalabra->palabras = palabraAIngresar;
	
	/*Se cuentan las palabras de la linea a modificar y se le suma una unidad, asumiendo que llegado a este punto
	la palabra si o si se va a insertar	*/
	cantPalabras = cantidadPalabrasEnLinea(text, posicionLinea) + 1;
	
	textAux = text;
	while(!esVacio(text)){
		nroLinea++;
		///BÚSQUEDA DE LA LÍNEA A MODIFICAR
		if(nroLinea == posicionLinea){
			nroPalabra = 1;   //Cuenta las palabras de la lista
			palabraActual = text->lineas;      //Se copia la posicion inicial del cabezal en palabraActual ;
			if(!esVacia(text->lineas)){
				///BÚSQUEDA DE LA POSICIÓN DE PALABRA DESEADA
				while(!esVacia(palabraActual->ptrSig) && nroPalabra != posicionPalabra){
					palabraAnterior = palabraActual;
					palabraActual = palabraActual->ptrSig;
					nroPalabra++;
				}
				///INSERCIÓN DE LA PALABRA
				if(posicionPalabra==1){
					//Insertar palabra al inicio
					nuevaPalabra->ptrSig = text->lineas;
					text->lineas = nuevaPalabra;
				}
				else if(palabraActual->ptrSig == NULL && posicionPalabra == nroPalabra+1){
					// Insertar palabra al final
					palabraActual->ptrSig = nuevaPalabra;
					nuevaPalabra->ptrSig = NULL;
				}
				else{
					//Insertar palabra en posicion
					palabraAnterior->ptrSig = nuevaPalabra;
					nuevaPalabra->ptrSig = palabraActual;
				}
			}
			else{
				text->lineas = nuevaPalabra;
				nuevaPalabra->ptrSig = NULL;
			}
			if(cantPalabras == MAX_CANT_PALABRAS_X_LINEA){//Cuando una linea tiene su maxima cantidad de palabras, queda llena.
				text->estaLlena = true;
			}
		}
		text = text->ptrSig; //Avanza a la siguiente linea del texto
	}
	text = textAux;
	
	///DESPLAZAMIENTO DE PALABRAS
	text = desplazamiento_de_Palabras(text);
	return text;
}
	
texto Borrar_Palabra(texto text, Posicion posicionLinea, Posicion posicionPalabra){ //HECHA
	Posicion cant_lineas = 0, cant_palabras;
	
	texto textAux;
	
	linea palabra_anterior;
	linea palabraAborrar;
	
	textAux = text;
	while(!esVacio(text)){ //mientras que el texto no este vacio, hay lineas
		cant_lineas++;
		if(cant_lineas == posicionLinea){ //Encuentro la linea buscada, se prosigue a recorrerla
			cant_palabras = 1;
			palabra_anterior = NULL;
			palabraAborrar = text->lineas;
			while(!esVacia(palabraAborrar)){ 
				if(cant_palabras == posicionPalabra){
					if(posicionPalabra == 1){ //En caso de que la palabra a borrar sea la primera
						text->lineas = palabraAborrar->ptrSig;
						delete palabraAborrar;
						palabraAborrar = NULL;
					}
					else if(esVacia(palabraAborrar->ptrSig)){//En caso de que la palabra a borrar sea la ultima
						palabra_anterior->ptrSig = palabraAborrar->ptrSig;
						delete palabraAborrar;
						palabraAborrar = NULL;
						palabra_anterior = text->lineas;
					}
					else{ //Cualquier linea menos la última ni la primera
						palabra_anterior->ptrSig = palabraAborrar->ptrSig;				
						delete palabraAborrar;
						palabraAborrar = NULL;
					}
				}
				else {
					palabra_anterior = palabraAborrar;
					palabraAborrar = palabraAborrar->ptrSig;
					cant_palabras++;
				}
			}
			text->estaLlena = false;
		}
		//si no encuentro la linea, recorro el texto hasta encontrarla y cuento lineas
		text = text->ptrSig;
	}
	text = textAux;
	return text;
}

void Imprimir_Linea(texto text, Posicion posicionLinea){ //HECHA
	Posicion cant_lineas = 1;
	texto textoAux;
	textoAux = text;
	linea lineaAux;
	
	while(!esVacio(text)){
		//cant_lineas++; //cant_lineas = 1
		if(cant_lineas == posicionLinea){
			cout << cant_lineas << ":";
			lineaAux = text->lineas;
			while(!esVacia(text->lineas)){
				cout << " " << text->lineas->palabras;
				text->lineas = text->lineas->ptrSig;
			}
			text->lineas = lineaAux;
			cout << endl;
		}
		cant_lineas++;
		text = text->ptrSig;
	}
	text = textoAux;
}

///Obligatorias-Naranjas
texto Insertar_Linea_En_Posicion(texto text, Posicion posicionLinea){//HECHA
	Posicion nroLinea = 1;
	texto lineaAnterior;
	texto lineaActual;
	
	texto nuevaLinea = new struct _texto;
	nuevaLinea->lineas = NULL;
	nuevaLinea->estaLlena = false;
	
	lineaActual = text;      // Se copia la posicion inicial del cabezal en lineaActual
	if(!esVacio(text)){
		while(!esVacio(lineaActual->ptrSig) && nroLinea != posicionLinea){
			lineaAnterior = lineaActual;
			lineaActual = lineaActual->ptrSig;
			nroLinea++;
		}
		if(posicionLinea == 1){
			//Insertar palabra al inicio
			nuevaLinea->ptrSig = text;
			text = nuevaLinea;
		}
		else if(lineaActual->ptrSig == NULL && posicionLinea == nroLinea+1){
			//Insertar palabra al final
			lineaActual->ptrSig = nuevaLinea;
			nuevaLinea->ptrSig = NULL;
		}
		else{
			//Insertar palabra en posicion
			lineaAnterior->ptrSig = nuevaLinea;
			nuevaLinea->ptrSig = lineaActual;
		}
	}
	else{
		text = nuevaLinea;
		nuevaLinea->ptrSig = NULL;
	}
	return text;
}

texto Borrar_Todo(texto text){
	Posicion num_linea = 1;
	
	while(!esVacio(text)){
		text = Borrar_Linea(text, num_linea);
	}
	return text;
}

texto Borrar_Ocurrencias_Palabra_En_Texto(texto text, Cadena palabraABorrar){//HECHA
	texto LineaAux;
	LineaAux = text;
	bool hayCoincidencia = false;
	/*variable que determinará si se encontró la palabra en la linea que se posiciona el cabezal,
	al menos una vez*/
	
	while(!esVacio(text)){ //mientras que el texto no este vacio, hay lineas
		text->lineas = borro_ocurrencias_palabra(text->lineas, palabraABorrar, &hayCoincidencia);
		if(hayCoincidencia){
			text->estaLlena = false;
		}
		text = text->ptrSig;
	}
	
	text = LineaAux;
	return text;
}
	
texto Borrar_Ocurrencias_Palabra_En_Linea(texto text, Posicion posicionLinea, Cadena palabraABorrar){//HECHA
	Posicion cant_lineas = 0;
	texto LineaConPalabra;
	bool hayCoincidencia = false;
	
	LineaConPalabra = text;
	
	while(!esVacio(text)){ //mientras que el texto no este vacio, hay lineas
		cant_lineas++;
		if(cant_lineas == posicionLinea){ //Encuentro la linea buscada, se prosigue a recorrerla
			text->lineas = borro_ocurrencias_palabra(text->lineas, palabraABorrar, &hayCoincidencia);
			if(hayCoincidencia){
				text->estaLlena = false;
			}
		}
		//si no encuentro la linea, recorro el texto hasta encontrarla y cuento lineas
		text = text->ptrSig;
	}
	text = LineaConPalabra;
	return text;
}

///Funciones de segunda entrega
dicc Ingresar_Palabra_Diccionario(dicc &diccionario, Cadena palabraAIngresar, dicc padre){
	//caso base
	if(diccionario == NULL){
		diccionario = new struct _palabra;
		diccionario->word = new char;
		strcpy(diccionario->word, palabraAIngresar);
		diccionario->wordPadre = padre;
		diccionario->wordIzq = NULL;
		diccionario->wordDer = NULL;
	}
	else{
		if(strcmp(diccionario->word, palabraAIngresar) == 0){
			return diccionario;
		}
		else{
			if(strcmp(diccionario->word, palabraAIngresar) < 0){
				Ingresar_Palabra_Diccionario(diccionario->wordDer, palabraAIngresar, diccionario);
			}
			else if(strcmp(diccionario->word, palabraAIngresar) > 0){
				Ingresar_Palabra_Diccionario(diccionario->wordIzq, palabraAIngresar, diccionario);
			}
		}
	}
	return diccionario;
}

dicc Borrar_Palabra_Diccionario(dicc diccionario, Cadena palabraABorrar){
	dicc nodoABorrar = NULL;
	dicc nodoPadre = NULL;
	dicc minimo = NULL;
	
	if(diccionario == NULL){  //Si el diccionario está vacío no realiza ninguna acción
		return diccionario;
	}
	else{ 
		//si existe, busco valor a borrar
		nodoABorrar = buscarEnDicc(diccionario, palabraABorrar);
		if(nodoABorrar == NULL){ //pregunto si existe la palabra a borrar en el diccionario
			return diccionario;
		}
		else{
			nodoPadre = esPadre(nodoABorrar);
			if(esHoja(nodoABorrar)){
				if(nodoPadre == NULL){//nodo hoja que es raiz
					diccionario = NULL;
				}
				else{
					if(hijoIzq(nodoPadre) == nodoABorrar){
						nodoPadre->wordIzq = NULL;
					}
					else{
						nodoPadre->wordDer = NULL;
					}
				}
				delete nodoABorrar;
				return diccionario;
			}//fin nodo hoja
			else{
				//nodo a borrar no es hoja(es INTERNO)
				if(hijoDer(nodoABorrar) == NULL){
					//en caso de que el nodo a borrar tenga solo el hijo izquierdo
					if(nodoPadre == NULL) {
						diccionario = hijoIzq(nodoABorrar);
						diccionario->wordPadre = NULL;
					}
					else{
						if(strcmp(datoWord(nodoABorrar), datoWord(nodoPadre)) < 0){
							nodoPadre->wordIzq = hijoIzq(nodoABorrar);
						}
						else {
							nodoPadre->wordDer = hijoIzq(nodoABorrar);
						}
						nodoABorrar->wordIzq->wordPadre = nodoPadre;
					}
					delete nodoABorrar;
					return diccionario;
				}
				else{
					//En caso de que el nodo a borrar tenga solo el hijo derecho
					if(hijoIzq(nodoABorrar) == NULL){
						if(nodoPadre == NULL){
							diccionario = hijoDer(nodoABorrar);
							diccionario->wordPadre = NULL;
						}
						else{
							if(strcmp(datoWord(nodoABorrar), datoWord(nodoPadre)) < 0){
								nodoPadre->wordIzq = hijoDer(nodoABorrar);
							}
							else{
								nodoPadre->wordDer = hijoDer(nodoABorrar);
							}
							nodoABorrar->wordDer->wordPadre = nodoPadre;
						}
						delete nodoABorrar;
						return diccionario;
					}
					else{
						//tiene dos hijos
						minimo = Minimo(nodoABorrar->wordDer);
						nodoABorrar->word = datoWord(minimo);
						if(minimo == hijoDer(nodoABorrar)){
							nodoABorrar->wordDer = hijoDer(minimo);
							if(hijoDer(minimo) != NULL){
								minimo->wordDer->wordPadre = nodoABorrar;
							}
						}
						else{
							minimo->wordPadre->wordIzq = hijoDer(minimo);
							if(hijoDer(minimo) != NULL){
								minimo->wordDer->wordPadre = esPadre(minimo);
							}
						}
						delete minimo;
						return diccionario;
					}
					return diccionario;
				}
			}
		}
	}
}

void Imprimir_Diccionario(dicc diccionario){ //HECHA
	if(diccionario != NULL){
		Imprimir_Diccionario(diccionario->wordIzq);
		cout << diccionario->word << endl;	
		Imprimir_Diccionario(diccionario->wordDer);
	}
}
	
void Imprimir_Texto_Incorrecto(texto text, dicc diccionario){
	int nroLinea = 1;	//se define un contador para las lineas del texto
	bool existe = false;
	texto auxText;
	auxText = text;//se crea una lista auxiliar para conservar la posicion inicial del texto
	linea auxLinea;
	
	if(esVacio(text)){ //En caso de que el texto no tenga lineas
		cout << "Texto vacío" << endl;
	}
	else{
		while(!esVacio(text)){
			cout << nroLinea << ":";
			auxLinea = text->lineas; //se crea una lista auxiliar para conservar la posicion inicial de la palabra
			while(!esVacia(text->lineas)){
				existe = existePalabraEnDicc(diccionario, text->lineas->palabras);
				if(!existe){
					cout << " " << text->lineas->palabras;
				}
				text->lineas = text->lineas->ptrSig;
			}
			text->lineas = auxLinea;
			cout << endl;
			text = text->ptrSig;
			nroLinea++;
		}
	}
	text = auxText;
}
	
///Opcional de primera entrega
texto Comprimir_Texto(texto text){
	//Sin implementar
	return text;
}

///Opcional segunda entrega
void Imprimir_Ultimas_Palabras(UltimasPalabras ultima){
	//Caso base
	if(ultima == NULL){
		return; 
	}
	else{
		cout << ultima->pal << endl;
		Imprimir_Ultimas_Palabras(ultima->palAnt);
	}
}

///Auxiliares	
bool esVacio(texto text){
	if(text == NULL){
		return true;
	}
	else{
		return false;
	}
}
	
bool esVacia(linea lineas){
	if(lineas == NULL){
		return true;
	}
	else{
		return false;
	}
}
	
void mostrarResultado(int retorno){
	switch(retorno){
	case OK:
		cout << endl << "OK" << endl;
		break;
	case ERROR:
		cout << endl << "ERROR" << endl;
		break;
	case NO_IMPLEMENTADO:
		cout << endl << "NO IMPLEMENTADO" << endl;
		break;
	}
}

int cantidadLineas(texto text){
	int cantidad = 0;
	
	while(!esVacio(text)){
		cantidad += 1;
		text = text->ptrSig;
	}
	return cantidad;
}	

int cantidadPalabrasEnLinea(texto text, Posicion lineaDeseada){
	//PRECONDICIÓN: la linea deseada debe existir en el texto
	unsigned int nroLinea = 1;
	int nroPalabras = 0;
	texto textAux;
	linea lineaAux;
	textAux = text;
	
	while(!esVacio(text)){
		if(nroLinea == lineaDeseada){
			lineaAux = text->lineas;
			while(!esVacia(text->lineas)){
				nroPalabras++;
				text->lineas = text->lineas->ptrSig;
			}
			text->lineas = lineaAux;
		}
		nroLinea++;
		text = text->ptrSig;
	}
	text = textAux;
	return nroPalabras;
}
	
linea borro_palabras(linea l){
	linea nodo_aux = l, nodo_ant = NULL;
	
	while(!esVacia(nodo_aux)){//recorre la lista
		if(nodo_ant == NULL){// 
			l = nodo_aux->ptrSig;
		}
		else{
			nodo_ant->ptrSig = nodo_aux->ptrSig;
		}
		delete nodo_aux;
		if(nodo_ant == NULL){
			nodo_aux = l;
		}
		else{
			nodo_aux = nodo_ant->ptrSig;
		}
	}
	
	return l;
}

linea borro_ocurrencias_palabra(linea l, Cadena palabra_a_borrar, bool *hayCoincidencia){
	
	linea nodo_aux = l, nodo_ant = NULL;
	
	while(!esVacia(nodo_aux)){
		if(strcmp(nodo_aux->palabras, palabra_a_borrar) == 0){
			if(nodo_ant == NULL){
				l = nodo_aux->ptrSig;
			}
			else{
				nodo_ant->ptrSig = nodo_aux->ptrSig;
			}
			delete nodo_aux;
			*hayCoincidencia = true;//si encuentra la palabra a borrar
			
			if(nodo_ant == NULL){
				nodo_aux = l;
			}
			else{
				nodo_aux = nodo_ant->ptrSig;
			}
		}
		else{ //si no encuentro la palabra
			nodo_ant = nodo_aux;
			nodo_aux = nodo_aux->ptrSig;
		}
	}
	return l;
}
	
linea insertarPalAlPrincipio(linea lineaAInsertar, Cadena palabra){
	linea nuevaPalabra;
	nuevaPalabra = new struct _linea;
	nuevaPalabra->palabras = palabra;
	nuevaPalabra->ptrSig = lineaAInsertar;
	return nuevaPalabra;
}	

texto desplazamiento_de_Palabras(texto text){
	int nroLinea = 0, nroPalabra;
	texto auxText = text;
	linea auxPalabra, antPalabra;
	
	while(!esVacio(text)){
		nroLinea++;
		nroPalabra = 1;
		auxPalabra = text->lineas; //Guardo la posicion del cabezal de las palabras
		antPalabra = NULL;
		if(!esVacia(auxPalabra)){
			//Recorro la linea hasta posicionarme en su ultima palabra
			while(!esVacia(auxPalabra->ptrSig)){
				nroPalabra++;
				antPalabra = auxPalabra;
				auxPalabra = auxPalabra->ptrSig;
			}
			//estando posicionado en la última palabra de la linea
			if(nroPalabra > MAX_CANT_PALABRAS_X_LINEA){ // Si entra a este if, si o si hay que desplazar una palabra
				if(esVacio(text->ptrSig)){
					//Si la palabra a desplazar se encuentra en la última línea del texto
					text = Insertar_Linea(text);
				}
				//Si no entra al if la palabra a desplazar se encuentra en una linea que no sea la última
				//En cualquiera de los casos se inserta la palabra en la siguiente linea y se borra la palabra 
				//De donde estaba
				text->ptrSig->lineas = insertarPalAlPrincipio(text->ptrSig->lineas, auxPalabra->palabras);
				antPalabra->ptrSig = NULL;
				delete auxPalabra;
			}
		}
		text = text->ptrSig;
	}
	text = auxText;
	return text;
}

///Auxiliares para segunda entrega
bool existePalabraEnDicc(dicc diccionario, Cadena palabra){
	//caso base
	if(diccionario == NULL){
		return false;
	}
	else{
		if(strcmp(diccionario->word, palabra) == 0){
			return true;
		}
		else{
			if(strcmp(diccionario->word, palabra) < 0){
				return existePalabraEnDicc(diccionario->wordDer, palabra);
			}
			else{
				return existePalabraEnDicc(diccionario->wordIzq, palabra);
			}
		}
	}
}
	
dicc Minimo(dicc diccionario){
	//caso base
	if(diccionario->wordIzq == NULL){
		return diccionario;
	}
	else{
		return Minimo(diccionario->wordIzq);
	}
}

dicc Maximo(dicc diccionario){
	//caso base
	if(diccionario->wordDer == NULL){
		return diccionario;
	}
	else{
		return Maximo(diccionario->wordDer);
	}
}

bool esHoja(dicc diccionario){
	if(diccionario->wordDer == NULL && diccionario->wordIzq == NULL){
		return true;
	}
	else{
		return false;
	}
}
	
void pausa(){
	cout << "Presiona ENTER para continuar" << endl;
	getchar();
}

void mostrarAyuda(){
	cout << endl << "La siguiente lista muestra los comandos disponibles del sistema: " << endl;
	cout << endl << "================================================================================" << endl;
	cout << "InsertarLinea(): " << endl << "Inserta una nueva línea al final del texto." << endl << endl;
	cout <<	"BorrarLinea(posLinea): " << endl << "Recibe cómo parámetro el número de línea a borrar." << endl << endl;
	cout << "ImprimirTexto(): " << endl << "Muestra el texto." << endl << endl;
	cout << "InsertarPalabraEnLinea(posLinea,posPalabra,palabraAIngresar): " << endl << "Recibe el nro de línea, el de palabra y la palabra a ingresar." << endl << endl;
	cout << "BorrarPalabra(posLinea,posPalabra): " << endl << "Recibe el nro de línea y la posicion de la palabra a borrar." << endl << endl;
	cout << "ImprimirLinea(posLinea): " << endl << "Recibe el nro de línea a imprimir." << endl << endl;
	cout << "InsertarLineaEnPosicion(posLinea): " << endl << "Recibe el nro de línea e inserta una nueva, enseguida de la indicada." << endl << endl;
	cout << "BorrarTodo(): " << endl << "Borra todo el texto." << endl << endl;
	cout << "BorrarOcurrenciasPalabraEnTexto(palabraABorrar): " << endl << "Borra del texto las ocurrencias de la palabra recibida por parámetro." << endl << endl;
	cout << "BorrarOcurrenciasPalabraEnLinea(posLinea,palabraABorrar):" << endl << "Borra de línea específica las ocurrencias de la palabra recibida por parámetro." << endl << endl;
	cout << "IngresarPalabraDiccionario(palabraABorrar): " << endl << "Inserta una palabra al diccionario que es recibida por parámetro." << endl << endl;
	cout << "BorrarPalabraDiccionario(palabraABorrar): " << endl << "Borra una palabra del diccionario que es recibida por parámetro." << endl << endl;
	cout << "ImprimirDiccionario(): " << endl << "Muestra el diccionario en orden alfabético." << endl << endl;
	cout << "ImprimirTextoIncorrecto(): " << endl << "Muestra el texto a excepción de las palabras que están en el diccionario." << endl << endl;
	cout << "ComprimirTexto(): " << endl << "Rellena las líneas que no tengan su máximo de palabras y luego borra las líneas vacías." << endl << endl;
	cout << "ImprimirUltimasPalabras(): " << endl << "Imprime las últimas palabras ingresadas al texto." << endl << endl;
	cout << "Ayuda: " << endl << "Imprime los comandos disponibles." << endl << endl;
	cout << "Salir: " << endl << "Detiene la ejecución del programa." << endl;
	cout << "================================================================================" << endl << endl;
}
	
dicc esPadre(dicc diccionario){
	return diccionario->wordPadre;
}

dicc hijoDer(dicc diccionario){
	return diccionario->wordDer;
}

dicc hijoIzq(dicc diccionario){
	return diccionario->wordIzq;
}
	
Cadena datoWord(dicc diccionario){
	if(diccionario == NULL){
		return NULL;
	}
	return diccionario->word;
}

dicc buscarEnDicc(dicc diccionario, Cadena palabraABorrar){
	if(diccionario != NULL){
		if(strcmp(palabraABorrar, datoWord(diccionario)) < 0){
			return buscarEnDicc(hijoIzq(diccionario), palabraABorrar);
		}
		else{
			if(strcmp(palabraABorrar, datoWord(diccionario)) >  0){
				return buscarEnDicc(hijoDer(diccionario), palabraABorrar);
			}
			else{
				return diccionario;
			}
		}
	}
	else{
		return diccionario;
	}
}

void mostrarError(){
	cout << endl << "Parámetros incorrectos. No se realizó ninguna acción." << endl << endl;
}

void mostrarTitulo(){
	cout << "Para más información ingrese 'Ayuda' sin las comillas." << endl;
	cout << endl << "Ingrese el comando que desee ejecutar" << endl;
	cout << "> ";
}

///Auxiliares para opcionales
linea InsertarPalAlFinal(linea palabraAInsertar, Cadena palabra){ //HECHA
	linea nuevaPalabra;
	nuevaPalabra = new struct _linea;
	nuevaPalabra->palabras = palabra;
	nuevaPalabra->ptrSig = NULL; //Hace que la nueva palabra apunte a NULL.
	
	/*Tanto si la linea es vacía como si no lo es, la nueva palabra va a apuntar
	a NULL, ya que en todos los casos va a ser la última palabra*/
	
	if(esVacia(palabraAInsertar)){ //Esto es lo que ocurriría si la línea nos viene vacía.
		palabraAInsertar = nuevaPalabra; //En la linea se engancha la palabra.
	}
	else{//Si la línea ya tiene palabras, se guarda su posición inicial en un nodo auxiliar.
		linea nodoAux;
		nodoAux = palabraAInsertar;
		
		while(!esVacia(palabraAInsertar->ptrSig)){ //Mientras el puntero de la palabra siguiente no apunte a null se sigue recorriendo la línea
			palabraAInsertar = palabraAInsertar->ptrSig;
		}
		palabraAInsertar->ptrSig = nuevaPalabra; //Hace que la última palabra de la línea se enganche a la nueva palabra.
		palabraAInsertar = nodoAux; //Lleva al cabezal a su espacio inicial.
	}
	return palabraAInsertar;
}
	
cabezal Insertar_Ultimas_Palabras(cabezal Palabras, Cadena palabraAIngresar){
	
	int nroPalabras = 0;
	
	UltimasPalabras Nueva_Palabra, PalabraAborrar;
	Nueva_Palabra = new _UltimasPalabras;
	Nueva_Palabra->palSig = NULL;
	Nueva_Palabra->pal = palabraAIngresar;
	Nueva_Palabra->palAnt = Palabras.Ultima_Palabra;

	if(Esta_Vacia(Palabras)){
		Palabras.Primera_Palabra = Nueva_Palabra;		
	}
	else {
		Palabras.Ultima_Palabra->palSig = Nueva_Palabra;
	}
	
	Palabras.Ultima_Palabra = Nueva_Palabra;
	nroPalabras = Cant_Palabras(Palabras.Primera_Palabra); 
	
	//Si después de insertar una palabra a la estructura se supera el valor de la constante, se elimina la primer palabra ingresada.
	if (nroPalabras > MAX_CANT_ULTIMAS_PALABRAS){
		PalabraAborrar = Palabras.Primera_Palabra; //se apunta la PalabraAborrar al cabezal.
		Palabras.Primera_Palabra = PalabraAborrar->palSig;//Se apunta el cabezal al puntero siguiente de PalabraAborrar.
		Palabras.Primera_Palabra->palAnt = NULL;//Se iguala a NULL el puntero anterior del cabezal.
		delete PalabraAborrar;//Se elimina el auxiliar.
	}
	return Palabras;
}
	
bool Esta_Vacia(cabezal Palabra){
	if (Palabra.Primera_Palabra == NULL || Palabra.Ultima_Palabra == NULL){
		return true;
		
	}
	else {
		return false;
	}
}

int Cant_Palabras(UltimasPalabras Primera){
	int nroPalabras = 0;
	
	while(Primera != NULL){
		nroPalabras++;
		Primera = Primera->palSig;
	}
	return nroPalabras;
}
