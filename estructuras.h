#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#define SALDOINICIAL 1000
#define LARGOCI 8
#define LARGOCADENA 15
#define CANTJUGADORES 10
#define MAXAPUESTAS 100


typedef struct _digito {
	
	int numero[LARGOCI];
	int largoId;
	
} digito;

typedef struct _cadena {
	
	char texto[LARGOCADENA]={' '};
	int largoTexto=0;
	
} cadena;

typedef struct _fecha {
	
	int dia = 0;
	int mes = 0;
	int anio = 0;
	
} fecha;

typedef struct _apuesta {
	
	int monto;
	char resultado;
	int saldoPostApuesta;
	
} apuesta;

typedef struct _jugador {
	
	digito cedula;
	cadena nombre;
	int edad;
	fecha fechaNac;
	char estado;
	cadena apellido;
	cadena alias;
	int saldo = SALDOINICIAL;
	int cantidadAciertos = 0;
	apuesta apuestas[MAXAPUESTAS];
	int cantApuestas = 0;
	
} jugador;

#endif
