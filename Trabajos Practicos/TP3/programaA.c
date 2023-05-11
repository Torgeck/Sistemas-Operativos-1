#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
    const int SIZE = 1024;
    const char *name = "OS";
    const char *archivo = "/export/home/diego.barros/Descargas/Parcial/1Parcial.txt";
    int arc;
    int shm_fd;
    void *ptr;

    /* creo el espacio de memoria compartido */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    /* Configuro el tamanio de memoria */
    ftruncate(shm_fd,SIZE);

    /* mapeo el espacio de memoria compartido a la 
    direccion del espacio de la memoria del proceso*/
    ptr = mmap(0, SIZE , PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED){
        printf("Map failed \n");
        return -1;
    }

    /* ahora leo el archivo y escribo en el espacio de memoria*/
    arc = open(archivo, O_RDONLY);
    read(arc, ptr, SIZE);
    

    return 0;
}

