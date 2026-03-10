#include<iostream>
#include "estructuras.h"
#include "prototipos.h"

using namespace std;

int main (int argc, char *argv[]) {
	

	jugador jugadores[CANTJUGADORES];

	int opcion;
	int pos =0;
	
	menu();
	opcion = ingresoOpcion();
	
	while (opcion != 4) {
		
		switch (opcion) {
			
		case 1:
			menuGestionUsuario(jugadores,pos);
			break;
			
		case 2:
			menuConsultaUsuario(jugadores,pos);
			break;
			
		case 3:
			Apostar(jugadores,pos);
			break;
			
		}
		
		menu();
		opcion = ingresoOpcion();	
		
	}
	
	fin();	

	return 0;
}
