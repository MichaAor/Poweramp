#include "Menu.h"


///LOGUEO admin
int logeoAdmin(char nombre[],char contrasenia[],int contraseniaAdmin){
    stUser a;
    int flag=0;
    FILE*pArchiUser = fopen(arUser,"rb");
    if(pArchiUser!=NULL){
        while(flag==0&&(fread(&a,sizeof(stUser),1,pArchiUser))>0){
            if(strcmp(a.nombreUsuario,nombre)==0&&strcmp(a.password,contrasenia)==0&&contraseniaAdmin==123){
                flag=1;
        }
    }
    fclose(pArchiUser);
    }
return flag;
}

///LOGUEO USER
int logeoUser(char nombre[],char contrasenia[]){
    stUser a;
    int flag=0;
    FILE*pArchiUser = fopen(arUser,"rb");
    if(pArchiUser!=NULL){
                printf("%s\n",nombre);
                printf("%s\n",contrasenia);
                printf("==================\n");

        while(flag==0&&(fread(&a,sizeof(stUser),1,pArchiUser))>0){
            if(strcmp(a.nombreUsuario,nombre)==0&&strcmp(a.password,contrasenia)==0){
                printf("%s\n",a.nombreUsuario);
                printf("%s\n",a.password);
                flag=1;
        }
    }
    fclose(pArchiUser);
    }
return flag;
}




////////////////////////////////////////////////////////////////////////////////////////
///SWICHS DE TODOS:
////////////////////////////////////////////////////////////////////////////////////////
///Swich de MENU PRINCIPAL
void switchMenuPrincipal(int op){
    switch(op){
        case 1:
            menuPrincipalAdmiPrint();
            system("pause");
            system("cls");
            break;
        case 2:
            menuIngresoUserPrintf();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            printf("========================================================================\n");
            printf("\n\tGracias por utilizar nuestro sistema! :D\n\n");
            printf("========================================================================");
            exit(-1);
            break;


        default:
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
///SWICH MENU ADMIN
void switchMenuAdmin(int op){
    switch(op){
        case 1:
            submenuAdminUsuarioPrintf();
            system("pause");
            system("cls");
            break;
        case 2:
            submenuAdminCancionPrintf();
            system("pause");
            system("cls");
            break;
        case 3:
            menuPrincipalPrint();
            break;
        default:
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;
    }
}
///SWICH ADMIN SUBMENU CANCION:
void switchAdminSubCancion(int op){
    char nombreC[30];

    switch(op){
        case 1:
            system("cls");
            cargaArchiCanciones();
            system("pause");
            system("cls");
            break;
        case 2:
                system("cls");
                printf("Ingrese la cancion que desee eliminar: \n");
                fflush(stdin);
                gets(nombreC);
            elimininarCancion(nombreC);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            menuModificacionCancionPrintf();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
                printf("Ingrese la cancion que desee mostrar: \n");
                fflush(stdin);
                gets(nombreC);
            ConsultaCancion(nombreC);
            system("pause");
            system("cls");
            break;
        case 5:
            OrdenarPorNoGPrintf();
            system("pause");
            system("cls");
            break;
        case 6:
            menuPrincipalAdmiPrint();
            break;
        default:
            system("cls");
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;
    }
}

///SWICH ADMIN SUBMENU USUARIO:
void switchAdminSubUsuario(int op){
    char usuarioEliminar[30];
    int idgenerico=0;
    int dimension=55;
    stUser a[dimension];
    int validos=passTOarchivoUsuario(a,dimension,validos);
    switch(op){
        case 1:
            system("cls");
            CargarArchiUsuario();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
                printf("Ingrese el nombre del usuario que desea eliminar: \n");
                fflush(stdin);
                gets(usuarioEliminar);
            elimininarUser(usuarioEliminar);
            ConsultaUserXName(usuarioEliminar);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            menuModificacionUsuarioPrintf();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
                printf("ID del Usuario a Consultar \n");
                fflush(stdin);
                scanf("%i",&idgenerico);
            ConsultaUser(idgenerico);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            ordenarNombre(a,validos);
            mostrarArregloUsuario(a,validos);
            system("pause");
            system("cls");
            break;
        case 6:
            menuPrincipalAdmiPrint();
            break;
        default:
            system("cls");
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
///SWITCH DIV INGRESO PESTAÑA USUARIO
void switchIngresoDivision(int op){

    switch(op){
        case 1:
            system("cls");
            menuPrincipalUsuarioPrint();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            CargarArchiUsuario();
            system("cls");
            printf("Registro Exitoso! :D \n\n");
            printf("[Confirme sus datos]\n");
            menuPrincipalUsuarioPrint();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            menuPrincipalPrint();
            system("pause");
            system("cls");
        default:
            system("cls");
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
///SWICH MENU USUARIO:
void switchMenuUsuario(int op,char nombreU[]){
int idActualUs=encontrarIDUSERxNombre(nombreU);
printf("%d",idActualUs);
int idCanPlaylist=0;
char control='s';


    switch(op){
        case 1:
            system("cls");
            ConsultaUser(idActualUs);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            //mostrarPlaylist(idActualUs);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            do{
                printf("QUE CANCION DESEA AGREGAR A SU PLAYLIST?: ");
                fflush(stdin);
                scanf("%d",&idCanPlaylist);
                //cargarPlaylist(idCanPlaylist,idActualUs);
                printf("Desea seguir cargando?: S/N\n");
                fflush(stdin);
                scanf("%c",&control);
            }while(control=='s');
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            printf("\t\t\nLAS CANCIONES RECOMENDADAS POR EL PROGRAMA SON:\n\n");
            cancionesRecomendadas();
            system("pause");
            system("cls");
            break;
        case 5:
            menuPrincipalPrint();
            break;
        default:
            system("cls");
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
///SWICH ORDENACION POR NOMBRE O GENERO(SIRVE PARA ADMINISTRADOR>SUBMENUCANCIONES>LISTADOS)
void eleccionGenONombCancion(int op){
int dimension=55;
stCancion a[dimension];
int validos=passTOarchivoCanciones(a,dimension,validos);
    switch(op){
        case 1:
            ordenarGenero(a,validos);
            mostrarArregloCanciones(a,validos);
            system("pause");
            system("cls");
            break;
        case 2:
            ordenarTitulo(a,validos);
            mostrarArregloCanciones(a,validos);
            system("pause");
            system("cls");
            break;
}
}

///////////////////////////////////////////////////////////////////////////////////////
///SWICH Modificacion:
void modificacionCancion(int op){
    char ModificarGenerico[30];
    char modificarComentarioGenerico[80];
    int generico=0;
    int idCancionesGenerico=0;
    if(op!=9){
        mostrarCanciones();
        printf("Ingrese el id de la cancion que desea modificar: \n");
        fflush(stdin);
        scanf("%d",&idCancionesGenerico);
    }
    switch(op){
        case 1:
            system("cls");
                printf("Ingrese el titulo nuevo: \n");
                fflush(stdin);
                gets(ModificarGenerico);
            modificarTituloCancion(ModificarGenerico,idCancionesGenerico);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
                printf("Ingrese el nuevo nombre del artista: \n");
                fflush(stdin);
                gets(ModificarGenerico);
            modificarArtistaCancion(ModificarGenerico,idCancionesGenerico);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
                printf("Ingresar la nueva duracion: ");
                fflush(stdin);
                scanf("%d",&generico);
            modificarDuracionCancion(generico,idCancionesGenerico);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
                printf("Ingrese el nuevo nombre del album: \n");
                fflush(stdin);
                gets(ModificarGenerico);
            modificarAlbumCancion(ModificarGenerico,idCancionesGenerico);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
                printf("Ingrese el nuevo año: \n");
                fflush(stdin);
                scanf("%d",&generico,idCancionesGenerico);
            modificarAnioCancion(generico,idCancionesGenerico);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
                printf("Ingrese el nuevo genero: \n");
                fflush(stdin);
                gets(ModificarGenerico);
            modificarGeneroCancion(ModificarGenerico,idCancionesGenerico);
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
                printf("Ingrese el nuevo comentario: \n");
                fflush(stdin);
                gets(modificarComentarioGenerico);
            modificarComentarioCancion(modificarComentarioGenerico,idCancionesGenerico);
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
                printf("Ingrese el nombre de la cancion a recuperar: \n");
                fflush(stdin);
                gets(ModificarGenerico);
            recuperarCancion(ModificarGenerico);
            system("pause");
            system("cls");
            break;
        case 9:
            system("cls");
            submenuAdminCancionPrintf();
            break;

        default:
            system("cls");
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;

}
}

void modificacionUsuario(int op){
    char UserGenerico[30];
    int idGenerico=0;
    int Generico=0;
    char genero;
    if(op!=8){
    printf("Ingrese el id del usuario a modificar: \n");
    fflush(stdin);
    scanf("%d",&idGenerico);
    }
    switch(op){
        case 1:
            system("cls");
                printf("Ingrese el nuevo nombre: \n");
                fflush(stdin);
                gets(UserGenerico);
            modificarNombreUsuario(UserGenerico,idGenerico);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
                printf("Ingrese la nueva contraseña: \n");
                fflush(stdin);
                gets(UserGenerico);
            modificarContraseniaUsuario(UserGenerico,idGenerico);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
                printf("Ingrese el nuevo anio de Nacimiento: \n");
                fflush(stdin);
                scanf("%d",&Generico);
            ModifAnioNacimiento(Generico,idGenerico);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
                printf("Ingrese el nuevo genero: \n");
                fflush(stdin);
                scanf("%c",&genero);
            Modificargenero(genero,idGenerico);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
                printf("Ingrese el nuevo pais: \n");
                fflush(stdin);
                gets(UserGenerico);
            ModificarPais(UserGenerico,idGenerico);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            elimininarUser(UserGenerico);
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            recuperarUser(UserGenerico);
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            submenuAdminUsuarioPrintf();
            break;

        default:
            system("cls");
            printf("Ingreso una opcion invalida, reintente nuevamente\n");
            system("pause");
            system("cls");
            break;
}
}
////////////////////////////////////////////////////////////////////////////////////////
///PRINTFS DE TODOS:
////////////////////////////////////////////////////////////////////////////////////////
///PRINTF MENU PRINCIPAL
void imprimirCabecera(char cabecera[]){
    printf("%c", 220);
    for(int i=0;i<=48;i++){
        printf("%c",220);
    }
    printf("%c\n", 220);
    printf("%c\    %s     %c\n",219,cabecera,219);
    printf("%c", 219);
    for(int i=0;i<=48;i++){
        printf("%c",220);
    }
    printf("%c\n", 219);
}

void menuPrincipalPrint(){
    char control;
    int opcion;
    do{




        ////////////////////////////////////////////////////////////
        system("cls");

        system("color F4");
        imprimirCabecera("BIENVENIDO AL SISTEMA DE MUSICA POWERAMP");
        /*
        for(int i=0;i<=50;i++){
            printf("%c",220);
        }
        printf("\n");
        printf("%c\    BIENVENIDO AL SISTEMA DE MUSICA POWERAMP     %c\n",219,219);

        printf("%c",219);
        for(int i=0;i<=48;i++){
            printf("%c",220);
        }
        printf("%c",219);
        printf("\n");*/

        printf("%c\tComo desea Ingresar?\t\t\t  %c\n",219,219);
        printf("%c\t(1)Administrador\t\t\t  %c\n",219,219);
        printf("%c\t(2)Usuario\t\t\t\t  %c\n",219,219);
        printf("%c\t(3)Salir\t\t\t\t  %c\n",219,219);
        printf("%c",219);
        for(int i=0;i<=48;i++){
            printf("%c",220);
        }
        printf("%c\n",219);





        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        switchMenuPrincipal(opcion);
        system("cls");
        printf("Desea probar otro Ingreso? (s/n) ");
        printf("%c\n", control = getch());

    }while(control == 's');
    system("cls");
    printf("Gracias por utilizar nuestro sistema");
}
////////////////////////////////////////////////////////////////////////////////////////
///PRINTF INGRESO PESTAÑA USUARIO
void menuIngresoUserPrintf(){

    char control;
    int opcion;

    do{
        system("cls");
        system("color F5");
        //imprimirCabecera("PESTANIA USUARIO");

        for(int i=0;i<=48;i++){
            printf("%c",220);
        }
        printf("\n");
        printf("%c\t      PESTANIA USUARIO             \t%c\n",219,219);
        printf("%c",219);
        for(int i=0;i<=46;i++){
            printf("%c",220);
        }
        printf("%c",219);

        printf("\n%c\t\t(1)LOGIN\t\t\t%c\n",219,219);
        printf("%c\t\t(2)SIGN IN\t\t\t%c",219,219);
        printf("\n%c\t\t(3)Volver\t\t\t%c\n",219,219);
        printf("%c",219);
        for(int i=0;i<=46;i++){
            printf("%c",220);
        }
        printf("%c",219);
        printf("\n");

        printf("\n");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        switchIngresoDivision(opcion);
        //system("cls");
        //printf("Desea Ingresar Otra Opcion? (s/n):");
        //printf("%c\n", control = getch());
    }while(control == 's');
    system("cls");
}
////////////////////////////////////////////////////////////////////////////////////////
///PRINTF MENU PRINCIPAL ADMIN
void menuPrincipalAdmiPrint(){

    char control='s';
    int opcion=0;
    char nombre[30];
    char contrasenia[30];
    int contraseniaAdmin;
    int log=0;

    system("color F5");


    for(int i=0;i<=48;i++){
        printf("%c",220);
    }
    printf("\n");
    printf("%c\t  PESTANIA DEL ADMINISTRADOR         \t%c\n",219,219);
    printf("%c",219);
    for(int i=0;i<=46;i++){
        printf("%c",220);
    }
    printf("%c",219);
    printf("\n%c\tNOMBRE:  \t\t\t\t%c",219);
    fflush(stdin);
    //scanf("%s",nombre);
    gets(nombre);
    printf("\t\t\t\t%c",219);
    printf("\nCONTRASENIA: ");
    fflush(stdin);
    gets(contrasenia);
    printf("\nCONTRASENIA ADMIN: ");
    fflush(stdin);
    scanf("%d",&contraseniaAdmin);
    //printf("\n=======================================\n");
    log=logeoAdmin(nombre,contrasenia,contraseniaAdmin);

    if(log==1){
    do{
        system("cls");
        printf("===========================\n");
        printf("*====MENU ADMINISTRADOR====*");
        printf("\n===========================\n");
        printf("A Que Submenu Desea Acceder?:\n");
        printf("(1)Submenu Administracion Usuarios\n");
        printf("(2)Submenu Administracion Canciones\n");
        printf("(3)Volver\n");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        switchMenuAdmin(opcion);

        system("cls");
        printf("Desea Ingresar a otra Administracion? (s/n)");
        printf("%c\n", control = getch());

    }while(control == 's');
system("cls");
}else{
    printf("EL ADMIN NO EXISTE\n");
}
    }


///PRINTF ADMIN SUBMENU USUARIO:
void submenuAdminUsuarioPrintf(){

    char control;
    int opcion;
    do{
        system("cls");
        printf("========================================\n");
        printf("*====SUBMENU ADMINISTRACION USUARIO====*");
        printf("\n========================================\n");
        printf("Que funcion desea ejecutar:\n");
        printf("(1)ALTA\n");
        printf("(2)BAJA\n");
        printf("(3)MODIFICACION\n");
        printf("(4)CONSULTA\n");
        printf("(5)LISTADO\n");
        printf("(6)Volver\n");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        switchAdminSubUsuario(opcion);
        system("cls");
        printf("Desea ejecutar otra funcion?: (s/n)");
        printf("%c\n", control = getch());

    }while(control == 's');
    system("cls");
}
///PRINTF ADMIN SUBMENU CANCION:

void submenuAdminCancionPrintf(){

    char control;
    int opcion;
    do{
        system("cls");
        printf("=======================================\n");
        printf("*====SUBMENU ADMINISTRACION CANCION====*");
        printf("\n=======================================\n");
        printf("Que funcion desea ejecutar:\n");
        printf("(1)ALTA\n");
        printf("(2)BAJA\n");
        printf("(3)MODIFICACION\n");
        printf("(4)CONSULTA\n");
        printf("(5)LISTADO\n");
        printf("(6)Volver\n");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        switchAdminSubCancion(opcion);

        system("cls");
        printf("Desea ejecutar otra funcion?:(s/n) ");
        printf("%c\n", control = getch());

    }while(control == 's');
    system("cls");
}


///PRINTF MENU PRINCIPAL USUARIO:
void menuPrincipalUsuarioPrint(){

    char control='s';
    int opcion=0;
    char nombre[30];
    char contrasenia[30];
        printf("=======================================\n");
        printf("*=========INICIO SESION USER==========*");
        printf("\n=======================================\n");
        printf("NOMBRE:");
        fflush(stdin);
        gets(nombre);
        printf("\nCONTRASENIA:");
        fflush(stdin);
        gets(contrasenia);
        printf("\n=======================================\n");
    int Log=logeoUser(nombre,contrasenia);
    if(Log==1){
    do{
        system("cls");
        printf("=========================\n");
        printf("*======MENU USUARIO======*\n");
        printf("=========================\n");
        printf("Que funcion desea ejecutar?:\n");
        printf("(1)Ver Perfil\n");
        printf("(2)Mostrar Playlist\n");
        printf("(3)Escuchar Cancion\n");
        printf("(4)Canciones Recomendadas\n");
        printf("(5)Volver\n");

        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");
        switchMenuUsuario(opcion,nombre);
        system("cls");
        printf("Desea ejecutar otra funcion? (s/n) ");
        printf("%c\n", control = getch());

    }while(control == 's');
    system("cls");
}
else{
    printf("EL USUARIO NO EXISTE\n");
}
}
////////////////////////////////////////////////////////////////////////////////////////
///PRINT FUNCION ORDENAR POR NOMBRE O GENERO
void OrdenarPorNoGPrintf(){

    char control;
    int opcion;
    do{
        system("cls");
        printf("Como desea ordenar?:\n");
        printf("(1)Por Genero\n");
        printf("(2)Por Nombre\n");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        eleccionGenONombCancion(opcion);

        system("cls");
        printf("Desea ordenar de otra forma? (s/n)");
        printf("%c\n", control = getch());

    }while(control == 's');
    system("cls");
}

////////////////////////////////////////////////////////////////////////////////////////
///PRINTF MODIFICACIONES:
void menuModificacionCancionPrintf(){

    char control;
    int opcion;
    int validacion=obtenerID();
    do{
        if(validacionCancionXId(validacion)==1){
        system("cls");
        printf("===================================\n");
        printf("*====MENU MODIFICACION CANCION====*\n");
        printf("===================================\n");
        printf("Que desea Modificar?:\n");
        printf("(1)TITULO\n");
        printf("(2)ARTISTA\n");
        printf("(3)DURACION\n");
        printf("(4)ALBUM\n");
        printf("(5)ANIO\n");
        printf("(6)GENERO\n");
        printf("(7)COMENTARIO\n");
        printf("(8)RECUPERAR\n");
        printf("(9)VOLVER\n");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        modificacionCancion(opcion);
        }
        system("cls");
        printf("Desea ejecutar otra modificacion? (s/n)");
        printf("%c\n",control=getch());
    }while(control == 's');
    system("cls");
}

void menuModificacionUsuarioPrintf(){

    char control;
    int opcion;
    int validacion=obtenerID();
    do{
        if(ValidacionUsuarioXId(validacion)==0){
        system("cls");
        printf("===================================\n");
        printf("*====MENU MODIFICACION USUARIO====*\n");
        printf("===================================\n");
        printf("Que desea Modificar?:\n");
        printf("(1)NOMBRE\n");
        printf("(2)PASSWORD\n");
        printf("(3)ANIO NACIMIENTO\n");
        printf("(4)GENERO\n");
        printf("(5)PAIS\n");
        printf("(6)ELIMINAR\n");
        printf("(7)RECUPERAR\n");
        printf("(8)VOLVER\n");

        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        modificacionUsuario(opcion);
        }

        system("cls");
        printf("Desea ejecutar otra funcion? (s/n)");
        printf("%c\n", control = getch());

    }while(control == 's');
    system("cls");
}

////////////////////////////////////////////////////////////////////////////////////////
int obtenerID(){
    int IDGen=0;
    printf("Ingrese el ID de Cancion/Usuario que desee modificar: ");
    fflush(stdin);
    scanf("%d",&IDGen);
return IDGen;
}
