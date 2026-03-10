#ifndef SORTEO_H
#define SORTEO_H
#include "estructuras.h"

int inicioJuego();

int realizaApuesta(int saldo, int &apuestaFinal);
void registrarApuesta(jugador &jugadores, int monto, bool acierto);
void Apostar(jugador jugadores[], int pos);

void juego(int copa, int &saldo, int &aciertos, int i, int apuestaFinal);
void juegoEstafa(int copa, int &saldo, int &aciertos, int i, int apuestaFinal);

void menu();
void fin();
void consultaUsuario();
void gestionarUsuario();

void menuGestionUsuario(jugador jugadores[],int &pos);
void menuConsultaUsuario(jugador jugadores[], int pos);

int ingresoOpcion();
char confirma();

digito ingresoCedula(); 
cadena ingresoApellido();
cadena ingresoAlias();

cadena ingresoNombre();
int ingresoEdad();
fecha ingresoFecha();


void mostrarCi(digito cedula); 
void mostrarNombre(cadena nombre);
void mostrarApellido(cadena apellido);
void mostrarEdad(int edad); 
void mostrarFecha(fecha fechaNac); 

int buscarAlias(jugador jugadores[],cadena auxAli,int pos);
int generarCopa(int i);

void altaJugador(jugador jugadores[], int &pos);
void bajaJugador(jugador jugadores[],int pos);
void modificoJugador(jugador jugadores[],int pos);

void listadoJugadores(jugador jugadores[],int pos);
void ListadoTodasApuestas(jugador jugadores[],int pos);
void listadoApuestasJugador(jugador jugadores[],int pos);
void listoJugadores(jugador jugadores[],int pos);



#endif
