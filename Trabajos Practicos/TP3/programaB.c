#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main(){
    const char *name = "OS";
    const int SIZE = 1024;

    int shm_fd;
    void *ptr;
    int i;

    /* abro el espacio de memoria compartida */
    shm_fd = smh_open(name, O_RDONLY, 0666);
    if (shm_fd == -1){
        printf("shared memory failed \n");
        exit(-1);
    }

    /* ahora mapeo el segmento de memoria
     a la direccion de memoria del proceso*/
    ptr = mmap(0, SIZE , PROT_READ , MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED){
        printf("Map failed \n");
        exit (-1);
    }

    /* ahora leo de la region de memoria compartida */
    printf('%s', (char *)ptr);

    if(shm_unlink(name) == 1){
        printf("Error removing %s\n", name);
        exit(-1);
    }

    return 0;
}