#include<iostream>
#include<string.h>
#include <stdio_ext.h>
#include "estructuras.h"

int generarCopa (int i) {
	
	return (i%3)+1;
	
}
void menu () {
	
	system("clear");  
	
	printf(".: LA MOSQUETA :.\n");
	printf("   ==============\n");
	printf("1 - Gestionar Usuario\n");
	printf("2 - Consultas\n");
	printf("3 - Apostar\n");
	printf("4 - Salir\n");
	
}
int ingresoOpcion () {
	
	int opcion;
	
	do{
		printf("Ingrese opcion: ");
		scanf("%d", &opcion);
	}while (opcion < 1 || opcion > 4);
	
	__fpurge(stdin);
	
	return opcion;
	
}

char confirma () {
	
	char confirmar;
	
	printf("Confirma datos S/N");
	__fpurge(stdin);
	scanf("%c", &confirmar);
	__fpurge(stdin);
	
	return confirmar;
	
}

digito ingresoCedula () {
	
	int i = 0;	
	digito auxDigito;
	int valido[] = {2,9,8,7,6,3,4};
	int suma;
	int resultado;
	int val = 0;

	do{
		i=0;
		suma = 0;
		resultado = 0;
		
		__fpurge(stdin);
		printf("Ingrese Cedula: ");
		
		while (i < LARGOCI && (auxDigito.numero[i] = getchar()) != '\n') {
			auxDigito.numero[i] = auxDigito.numero[i] - 48;
			i++;
		}
		
		for ( int j=0; j < LARGOCI - 1; j++) {
			suma = auxDigito.numero[j] * valido[j]; 
			resultado += suma;
		}
		
		resultado = resultado % 10;
		
		if (resultado == 0) {
			val = 1;
		}
		
		resultado = 10 - resultado;
		
		if(resultado == auxDigito.numero[7]) {
		val = 1;
		}
		
	}while(val != 1);
	
		__fpurge(stdin);
		auxDigito.largoId = i;
		
	return auxDigito;
	
}


cadena ingresoApellido () {
	
	int i = 0;  
	cadena auxApellido;
	
	printf("Ingrese apellido: ");
	__fpurge(stdin);
	
	while (i<LARGOCADENA && (auxApellido.texto[i] = getchar()) != '\n'){
		i++;
	}
	
	__fpurge(stdin);
	auxApellido.largoTexto = i;
	
	return auxApellido;
	
}
		
cadena ingresoAlias () {
	
	int i = 0;
	cadena auxAlias;
	
	printf("Ingrese alias: ");
	__fpurge(stdin)
	;
	while (i<LARGOCADENA && (auxAlias.texto[i] = getchar()) != '\n'){
		i++;
	}
	
	__fpurge(stdin);
	auxAlias.largoTexto = i;
	
	return auxAlias;
	
}

fecha ingresoFecha () {
	
	fecha auxFecha;
	int fin;
	int diaporMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	do{
		fin=0;  
		
		printf("Ingrese fecha de nacimiento: ");
		scanf("%d/%d/%d",&auxFecha.dia, &auxFecha.mes, &auxFecha.anio);
		
		if(auxFecha.anio < 2025 && auxFecha.anio > 1900){
			if(auxFecha.mes < 13 && auxFecha.mes > 0){
				if (auxFecha.mes == 2 && (auxFecha.anio % 4 == 0)) {
					diaporMes[1] = 29;
				}else{
					diaporMes[1] = 28;
				}
				if (auxFecha.dia >= 1 && auxFecha.dia <= diaporMes[auxFecha.mes - 1]) {
					fin = 1;
				}
			}
		}
	}while(fin == 0);
	
	return auxFecha;
	
}

cadena ingresoNombre () {
	
	int i = 0;
	cadena auxNombre; 
	
	printf("Ingrese nombre: ");
	__fpurge(stdin);
	
	while (i<LARGOCADENA && (auxNombre.texto[i] = getchar()) != '\n'){
		i++;
	}
	
	__fpurge(stdin);
	auxNombre.largoTexto = i;
	
	return auxNombre;
	
}

void mostrarCi (digito cedula) {
	
	for (int x = 0; x < cedula.largoId; x++) {
		printf("%d",cedula.numero[x]);
	}
	
	printf(" ");
	
}

void mostrarNombre (cadena nombre) {
	
	for (int x = 0; x < nombre.largoTexto; x++){
		printf("%c",nombre.texto[x]);
	}
	
	printf(" ");
	
} 
void mostrarApellido (cadena apellido) {
	
	for (int x = 0; x < apellido.largoTexto; x++){
		printf("%c",apellido.texto[x]);
	}
	
	printf(" ");
	
}
	
void mostrarAlias (cadena alias) {
	
	for (int x = 0; x < alias.largoTexto; x++){
		printf("%c",alias.texto[x]);
	}
	
	printf(" ");
	
}
void mostrarFecha (fecha fechaNac) {
	
	printf("%d/%d/%d",fechaNac.dia, fechaNac.mes, fechaNac.anio);
	printf(" ");	
	
}
	
void mostrarSaldo (int saldo) {
	
	printf("%d",saldo);
	printf("\n");
	
}	

int buscarAlias (jugador jugadores[], cadena auxAli, int pos) {
	for (int i = 0; i < pos; i++) {
		
		if (strcmp(jugadores[i].alias.texto, auxAli.texto) == 0) {
			
			return i; // Retorna la posición donde se encontró el alias
		
		}
	}
	
	return -1; // No se encontró el alias
	
}

int inicioJuego () {
	
	system("clear");
	
	int copa;
	
	printf("o o o\n1 2 3\nCopa?: \n");
	scanf("%d",&copa);
	
	return copa;
	
}
		
void juego (int copa, int &saldo, int &aciertos, int semilla, int apuestaFinal) {
	
	int copaAcierto = generarCopa(semilla);
	
	if (copaAcierto == 1 && copa == 1){
		saldo=saldo + apuestaFinal*2;
		printf(". o o\nHa acertado\n");
		aciertos++;
		
	}else if (copaAcierto == 1 && copa != 1) {
		printf(". o o\nNo ha acertado\n");
		aciertos = 0;
		
	}else if (copaAcierto == 2 && copa == 2 ){
		saldo = saldo + apuestaFinal * 2;
		printf("o . o\nHa acertado\n");
		aciertos++;
		
	}else if (copaAcierto == 2 && copa != 2) {
		printf("o . o\nNo ha acertado\n");
		aciertos = 0;
		
	}else if (copaAcierto == 3 && copa == 3) {
		saldo = saldo + apuestaFinal * 2;
		printf("o o .\nHa acertado\n");
		aciertos++;
		
	}else if (copaAcierto == 3 && copa != 3) {
		printf("o o .\nNo ha acertado\n");
		aciertos = 0;
	}
}

void juegoEstafa (int copa, int &saldo, int &aciertos, int semilla, int apuestaFinal) {
	
	int copaAcierto = generarCopa(semilla);
	
	if (copaAcierto == 1 && copa == 1) {
		printf("  o o\nNo ha acertado\n");
		aciertos = 0;
		
	} else if (copaAcierto == 1 && copa != 1) {
		printf(". o o\nNo ha acertado");
		aciertos = 0;
		
	} else if (copaAcierto == 2 && copa == 2) {
		printf("o   o\nNo ha acertado");
		aciertos = 0;
		
	} else if (copaAcierto == 2 && copa != 2) {
		printf("o . o\nNo ha acertado\n");
		aciertos = 0;
		
	} else if (copaAcierto == 3 && copa == 3) {
		printf("o o  \nNo ha acertado\n");
		aciertos = 0;
		
	} else if (copaAcierto == 3 && copa != 3) {
		printf("o o .\nNo ha acertado\n");
		aciertos = 0;
		
	}
}

void gestionarUsuario () {
	
	system("clear");
	
	printf(".: GESTIONAR USUARIO :.\n");
	printf("   =================\n");
	printf("1 - Alta de Jugador\n");
	printf("2 - Baja de jugador\n");
	printf("3 - Modificacion de jugador\n");
	printf("4 - Volver al Menu\n");
	
}
void altaJugador (jugador jugadores[],int &pos) {
	
	digito auxCi;
	cadena auxNom;
	cadena auxApe;
	cadena auxAli;
	fecha auxFecha;
	char confirmar;
	int lugar;
	
	auxAli = ingresoAlias();
	lugar = buscarAlias(jugadores,auxAli,pos);
	
	if (lugar == -1) {
		
		auxCi = ingresoCedula();
		auxNom = ingresoNombre();
		auxApe = ingresoApellido();
		auxFecha = ingresoFecha();
		confirmar = confirma();
		
		if (confirmar == 'S' || confirmar == 's') {
			
			jugadores[pos].cedula = auxCi;
			jugadores[pos].nombre = auxNom;
			jugadores[pos].fechaNac = auxFecha;
			jugadores[pos].apellido = auxApe;
			jugadores[pos].alias = auxAli;
			jugadores[pos].estado = 'A';
			pos++;
			printf("\nJugador registrado correctamente\n");
		}
		
	} else {
		printf("\nAlias de jugador ya Existente\n");
		
	}
	
	printf("Pulse enter para continuar");
	__fpurge(stdin);
	getchar();
	
}

void bajaJugador (jugador jugadores[],int pos) {
	
	//opcional
}

void modificoJugador (jugador jugadores[],int pos) {
	
	cadena auxAli;
	digito auxCi;
	cadena auxNom;
	cadena auxApe;
	fecha auxFecha;
	char confirmar;
	int lugar;
	
	auxAli = ingresoAlias();
	lugar = buscarAlias(jugadores,auxAli,pos);
	
	if (lugar == -1) {
		
		printf("No existe jugador con ese alias\n");
		
	} else {
		if (jugadores[lugar].estado == 'E') {
			
			printf("Desea activar dicho jugador?\n");
			confirmar = confirma();
			
			if (confirmar == 'S' || confirmar == 's') {
				
				jugadores[lugar].estado = 'A';
				printf("jugador acaba de activarse\n");
				
			}
		} else {
			
			printf("\nCi: ");
			mostrarCi(jugadores[lugar].cedula);
			printf("\nNombre: ");
			mostrarNombre(jugadores[lugar].nombre);
			printf("\nApellido: ");
			mostrarApellido(jugadores[lugar].apellido);
			printf("\nFecha Nacimiento: ");
			mostrarFecha(jugadores[lugar].fechaNac);
			printf("Desea modificar los datos\n");
			confirmar = confirma();
			
			if (confirmar == 'S' || confirmar == 's' ) {
				
				auxCi = ingresoCedula();
				auxNom = ingresoNombre();
				auxApe = ingresoApellido();
				auxFecha = ingresoFecha();
				confirmar = confirma();
				
				if (confirmar == 'S' || confirmar == 's') {
					
					jugadores[lugar].cedula = auxCi;
					jugadores[lugar].nombre = auxNom;
					jugadores[lugar].apellido = auxApe;
					jugadores[lugar].fechaNac = auxFecha;
					printf("\nJugador Modificado\n");
					
				}
			}
		}
	}
	
	printf("\nPulse enter para continuar");
	__fpurge(stdin);
	getchar();
	
}

void consultaUsuario () {
	
	system("clear");
	
	printf(".: CONSULTA :.\n");
	printf("   =========\n");
	printf("1 - Listado de jugadores\n");
	printf("2 - Listado de todas las apuestas\n");
	printf("3 - Listado de apuestas por jugador\n");
	printf("4 - Volver al Menu\n");
	
}

void listadoJugadores (jugador jugadores[],int pos) {
	
	system("clear");
	
	printf(".: LISTA DE JUGADORES :.\n");
	printf("   ===================\n");
	printf(" CEDULA NOMBRE APELLIDO ALIAS SALDO\n");
	printf("------------------------------------\n");
	
	for (int i = 0; i < pos; i++) {
		
		if(jugadores[i].estado =='A') {
			
			mostrarCi(jugadores[i].cedula);
			mostrarNombre(jugadores[i].nombre);
			mostrarApellido(jugadores[i].apellido);
			mostrarAlias(jugadores[i].alias);
			mostrarSaldo(jugadores[i].saldo);
			
		}
	}
	
	printf("Pulse enter para continuar");
	__fpurge(stdin);
	getchar();
}
	
void ListadoTodasApuestas (jugador jugadores[],int pos) {
	
	//opcional
}

void listadoApuestasJugador (jugador jugadores[], int pos) {
	
	system("clear");
	
	cadena auxAli;
	int lugar;
	
	printf(".: Apuestas por Jugador :.\n");
	printf("==========================\n");
	
	auxAli = ingresoAlias();
	lugar = buscarAlias(jugadores, auxAli, pos);
	
	if (lugar == -1 || jugadores[lugar].estado != 'A') {
		
		printf("Alias no encontrado o jugador inactivo.\n");
		
	} else {
		
		printf("Alias: ");
		mostrarAlias(jugadores[lugar].alias);
		printf("\nSaldo actual: %d\n", jugadores[lugar].saldo);
		printf("-------------------------------------------\n");
		printf("Resultado | Monto Apostado | Saldo Posterior\n");
		printf("-------------------------------------------\n");
		
		for (int i = 0; i < jugadores[lugar].cantApuestas; i++) {
			
			printf("    %c     |      %4d      |      %4d\n",
				   jugadores[lugar].apuestas[i].resultado,
				   jugadores[lugar].apuestas[i].monto,
				   jugadores[lugar].apuestas[i].saldoPostApuesta);
		}
	}
	
	printf("\nPulse enter para continuar...");
	__fpurge(stdin);
	getchar();
	
}
void menuGestionUsuario (jugador jugadores[],int &pos) {
	
	int opcion;
	
	gestionarUsuario();
	opcion = ingresoOpcion();
	
	while (opcion != 4) {
		
		switch (opcion) {
			
		case 1:
			altaJugador(jugadores,pos);
			break;
			
		case 2:
			bajaJugador(jugadores,pos);
			break;
			
		case 3:
			modificoJugador(jugadores,pos);
			break;
			
		}
		gestionarUsuario();
		opcion = ingresoOpcion();	
	}

}

void menuConsultaUsuario (jugador jugadores[], int pos) {
	
	int opcion;
	
	consultaUsuario();
	opcion = ingresoOpcion();
	
	while (opcion != 4) {
		
		switch (opcion) {
			
		case 1:
			listadoJugadores(jugadores,pos);
			break;
			
		case 2:
			ListadoTodasApuestas(jugadores,pos);
			break;
			
		case 3:
			listadoApuestasJugador(jugadores,pos);
			break;
			
		}
		consultaUsuario();
		opcion = ingresoOpcion();	
	}
	
}

int realizaApuesta (int saldo, int &apuestaFinal) {
	
	printf("Apuesta?: \n");
	scanf("%d",&apuestaFinal);
	saldo = saldo - apuestaFinal;
	
	return saldo;
}
	
void registrarApuesta (jugador &jugadores, int monto, bool acierto) {
	
	if(jugadores.cantApuestas < MAXAPUESTAS) {
		
		jugadores.apuestas[jugadores.cantApuestas].monto = monto;
		
		if(acierto) {
			
			jugadores.apuestas[jugadores.cantApuestas].resultado = 'A';
		} else{
			
			jugadores.apuestas[jugadores.cantApuestas].resultado = 'N';
		}
		
		jugadores.apuestas[jugadores.cantApuestas].saldoPostApuesta = jugadores.saldo;
		jugadores.cantApuestas++;
	}
}
		
void Apostar (jugador jugadores[], int pos) {
	
	cadena auxAli;
	char seguir = 'S';
	int lugar;
	int aciertosAntes;
	bool acierto;
	int semilla;
	int copa;
	int apuestaFinal;
	
	if(pos == 0) {
		
		printf("No hay jugadores registrados.\nPulse enter para continuar...");
		__fpurge(stdin);
		getchar();
		
		return;
	}
	
	auxAli = ingresoAlias();
	lugar = buscarAlias(jugadores, auxAli, pos);
	
	if(lugar == -1 || jugadores[lugar].estado != 'A') {
		
		printf("Alias no encontrado o jugador inactivo.\nPulse enter para continuar");
		__fpurge(stdin);
		getchar();
		
		return;
	}

	if (jugadores[lugar].cantApuestas == 0) {
		jugadores[lugar].saldo = SALDOINICIAL; 
	}
	if (jugadores[lugar].saldo <= 0) {
		
		printf("No tiene saldo disponible para apostar.\nPulse enter para continuar...");
		__fpurge(stdin);
		getchar();
		
		return;
	}
	
	
	
	while ((seguir == 'S' || seguir == 's') && jugadores[lugar].saldo > 0) {
		
		apuestaFinal = 0;
		copa = inicioJuego();
		
		do {
			
			printf("Saldo disponible: %d\n", jugadores[lugar].saldo);
			printf("Ingrese monto a apostar: ");
			scanf("%d", &apuestaFinal);
			__fpurge(stdin);
			
		} while (apuestaFinal > jugadores[lugar].saldo || apuestaFinal <= 0);
		
		aciertosAntes = jugadores[lugar].cantidadAciertos;
		jugadores[lugar].saldo -= apuestaFinal;
		semilla = jugadores[lugar].cantApuestas + 1; 
		acierto = false;

		if (jugadores[lugar].cantidadAciertos >= 2) {
			
			juegoEstafa(copa, jugadores[lugar].saldo, jugadores[lugar].cantidadAciertos, semilla, apuestaFinal);
			acierto = false;
			
		} else {
			juego(copa, jugadores[lugar].saldo, jugadores[lugar].cantidadAciertos, semilla, apuestaFinal);
			acierto = (jugadores[lugar].cantidadAciertos > aciertosAntes);
		}
		
		registrarApuesta(jugadores[lugar], apuestaFinal, acierto);
		
		printf("Saldo actual: %d\n", jugadores[lugar].saldo);
		
		if (jugadores[lugar].saldo <= 0) {
			
			printf("Se ha quedado sin saldo para continuar apostando.\n");
			break;
			
		}
		
		printf("Desea seguir apostando? (S/N): ");
		scanf(" %c", &seguir);
		__fpurge(stdin);
		
	}
	
	printf("Volviendo al menu principal...\nPulse enter para continuar...");
	__fpurge(stdin);
	getchar();
	
}
void fin () {
	
	system("clear");
	
	printf("Gracias por Jugar a -LA MOSQUETA- ");
	
}
