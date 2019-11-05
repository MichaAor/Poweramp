#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "string.h"
#include "time.h"
#include "Usuarios.h"
#include "Canciones.h"


///Funciones Swich///
void switchMenuPrincipal(int op);
void switchMenuAdmin(int op);
void switchAdminSubUsuario(int op);
void switchAdminSubCancion(int op);
void switchIngresoDivision(int op);
void switchMenuUsuario(int op,char nombreU[]);
void eleccionGenONombCancion(int op);
void modificacionCancion(int op);
void modificacionUsuario(int op);

///PRINTFS FUNCIONES//
void menuPrincipalPrint();
void submenuAdminUsuarioPrintf();
void submenuAdminCancionPrintf();
void menuIngresoUserPrintf();
void menuPrincipalUsuarioPrint();
void OrdenarPorNoGPrintf();
void menuModificacionCancionPrintf();
void menuModificacionUsuarioPrintf();

int obtenerID();

#endif // MENU_H_INCLUDED
