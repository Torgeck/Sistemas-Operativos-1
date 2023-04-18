/* mut.c - mut, operar, incrementar */ 
#include <xinu.h>

void operar(void), incrementar(void), mutex_init(void), mutex_lock(void), mutex_unlock(void);

int32 mutex;
unsigned char x = 0;

// mut -- programa con regiones criticas
void mut(void){
  int i;
  resume( create(operar, 1024, 20, "process 1", 0));
  resume( create(incrementar, 1024, 20, "process 2", 0));

  sleep(10);
}

// operar x e y
void operar(void){
  int y = 0;

  printf("Si no existen mensajes de ERROR entonces todo va OK! \n");
  while (1){

    mutex_lock();
    // si x es multiplo de 10 
    if ((x % 10) == 0){
      
      y = x * 2; 
      // Como y es el doble de x entonces y es 
      // multiplo de 10 tambien

      // Si y no es multiplo de 10 entonces hubo un error 
      if ((y % 10) != 0)
        printf("\r ERROR!!!! y=%d, x=%d \r", y , x);
    } 
    mutex_unlock();
  }
}

// incrementar x
void incrementar(void){
  while (1) {
    mutex_lock();
    x = x + 1;
    mutex_unlock();
  }
}

void mutex_init(){
  mutex = semcreate(1);
}

void mutex_unlock(){
  signal(mutex);
}

void mutex_lock(){
  wait(mutex);
}
// Tira errores porque compiten por acceder y modificar la variable x
// Se puede solucionar usando semaforos para acceder y modificar la variable
