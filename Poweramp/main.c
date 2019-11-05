#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "string.h"
#include "time.h"
    #include "Canciones.h"
    #include "Usuarios.h"
    #include "Menu.h"

void passar();


int main()
{

    //mostrarUsers();
    //menuPrincipalPrint();

    nodoArbolCancion*arbol;
    arbol=inicArbol();
    arbol=array2Arbol(arbol);
    mostrarPreorder(arbol);


    return 0;
}

void passar(){
    stUser a;
    stUser b;
    FILE*pArchiUsuario=fopen(arUser,"rb");
    FILE*pArchiUser=fopen(arUser,"a+b");
    if(pArchiUsuario && pArchiUser){
        while(fread(&a,sizeof(stUser),1,pArchiUsuario)>0){
            b.idUsuario=a.idUsuario;
            strcpy(b.nombreUsuario,a.nombreUsuario);
            strcpy(b.password,a.password);
            b.anioNacimiento=a.anioNacimiento;
            b.genero=a.genero;
            strcpy(b.pais,a.pais);
            b.Ueliminado=a.Ueliminado;
        fwrite(&b,sizeof(stUser),1,pArchiUser);
        }
        fclose(pArchiUsuario);
        fclose(pArchiUser);
    }
}
