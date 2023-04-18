#include <xinu.h>

unsigned int varA, varB, varC;

int proc_a(void);
int proc_b(void);
int proc_c(void);

void planificador()
{
    int pidA, ms_a, prioA;
    int pidB, ms_b, prioB;
    int pidC, ms_c, prioC;
    int pidPlanificador = getpid();
    int prioPlan;
    int duracionRafaga = 200;
    int total;

    prioPlan = chprio(pidPlanificador, 50);

    varA = 0;
    varB = 0;
    varC = 0;

    ms_a = (int)((60 * duracionRafaga) / 100);
    ms_b = (int)((30 * duracionRafaga) / 100);
    ms_c = (int)((10 * duracionRafaga) / 100);

    pidA = create(proc_a, 2048, 20, "Proceso A", 1, 0);
    pidB = create(proc_b, 2048, 20, "Proceso B", 1, 0);
    pidC = create(proc_c, 2048, 20, "Proceso C", 1, 0);

    resume(pidA);
    resume(pidB);
    resume(pidC);

    while (1)
    {
        // Proceso A
        prioA = getprio(pidA);
        chprio(pidA, prioPlan - 1);
        sleepms(ms_a);
        chprio(pidA, prioA);
        printf("PLANIFICADOR INTERRUMPIO A: %d\n", varA);

        // Proceso B
        prioB = getprio(pidB);
        chprio(pidB, prioPlan - 1);
        sleepms(ms_b);
        chprio(pidB, prioB);
        printf("PLANIFICADOR INTERRUMPIO B: %d\n", varB);

        // Proceso C
        prioC = getprio(pidC);
        chprio(pidC, prioPlan - 1);
        sleepms(ms_c);
        chprio(pidC, prioC);
        printf("PLANIFICADOR INTERRUMPIO C: %d\n", varC);

        kill(pidA);
        kill(pidB);
        kill(pidC);

        total = varA + varB + varC;
        printf("Total de los procesos: %d\n", total);
        printf("\%A= %d - \%B= %d - \%C= %d \n", (varA * 100 / total), (varB * 100 / total), (varC * 100 / total));

        kill(pidPlanificador);
    }
}

int proc_a(void)
{
    while (1)
    {
        varA++;
    }
    return 0;
}

int proc_b(void)
{
    while (1)
    {
        varB++;
    }
    return 0;
}

int proc_c(void)
{
    while (1)
    {
        varC++;
    }
    return 0;
}
