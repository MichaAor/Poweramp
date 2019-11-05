#include "Playlist.h"

void cargarArchivoPlaylist(int idUsuario,int idCancion){
stPlaylist a;

FILE*pArchi=fopen(arPlaylist,"a+b"){
    if(pArchi){
            while(fread(&a,sizeof(stPlaylist),1,pArchi)>0 || idUsuario!=a.idCancion){
                a.dCancion=idCancion;
                a.idUsuario=idUsuario,
                a.idPlaylist++;
            }

    }


}

}
int UltimoIdPlaylist(int idUsuario){
stPlaylist a;
int idPlayUserDefine;

FILE*pArchi=fopen(arPlaylist,"a+b"){
    if(pArchi){
        while(fread(&a,sizeof(stPlaylist),1,pArchi)>0 || idUsuario!=a.idCancion){
             idPlayUserDefine=a.idCancion;
    }


}



}
