#include <xinu.h>

void produce(void), consume(void);

/* Variables globales compartidas por todos los procesos */
int32 n = 0;
sid32 semProduce, semConsume;

void prodCons(void)
{
    semProduce = semcreate(1);
    semConsume = semcreate(0);
    resume(create(consume, 1024, 20, "cons", 0));
    resume(create(produce, 1024, 20, "prod", 0));
}

/* Produce - incrementa n 2000 veces y sale  */
void produce(void)
{
    int32 i;

    for (i = 1; i <= 2000; i++)
    {
        wait(semProduce);
        n++;
        signal(semConsume);
    }
}

/* Consume - Muestra por pantalla n 2000 veces y sale  */

void consume(void)
{
    int32 i;

    for (i = 1; i <= 2000; i++)
    {
        wait(semConsume);
        printf("The value of n is %d \n", n);
        signal(semProduce);
    }
}
