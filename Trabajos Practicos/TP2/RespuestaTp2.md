1.  a) El planificador de procesos de Xinu usa una política de planificación por prioridades combinado con round robin. Utiliza varias colas para agregar procesos a medida que se van creando o liberando la cpu. Si varios procesos de la misma prioridad necesitan utilizar cpu, xinu le va a dar el cpu a cada uno por un tiempo determinado (este depende del quantum y el proceso puede liberar el cpu antes de que se acabe el quantum si es que termina). En caso de que las prioridades de los procesos sean diferentes se va a dar cpu solo a aquellos procesos con mayor prioridad primero (hasta que estos se hayan terminado su ejecución) y después se le da el cpu a los de una prioridad menor a los procesos anteriores. Esto puede generar starvation con los procesos que tienen menor prioridad, ya que no pasaran al estado de ejecución mientras hayan procesos de mayor prioridad presentes en la cola.

    c) Este planificador no le daría cpu a cada proceso correctamente si cada uno solicita al SO un servicio que sea bloqueante porque el SO le daría el cpu a otro proceso mientras el proceso que solicito un servicio al SO cambia de estado a suspendido, mientras otro pasa al estado de current o ejecutando. Entonces cambiarían los porcentajes de tiempo y no serian siempre iguales.

2.  b) Se ejecutan los dos procesos y ambos compiten por el recurso compartido, al no estar sincronizados los resultados pueden ser 2 que primero se ejecute el proceso produce y aumente la variable n a 2000 y luego el proceso consume muestre la variable ya en 2000.
    El otro caso es que el proceso consume se ponga en estado de ejecución y muestre a n en 0, para que luego el proceso produce se ejecute ya que consume solicita imprimir por pantalla (que es un servicio bloqueante).
    
Los comando en el shell son 'planificador' y 'sincronizacion'

5. a) Orden de ejecucion y rafagas de los procesos

    |   P1  | P1 |  P2  |   P3  |   P4  |   P3  |  P5  |    P4  |   P6  |   P6  | P3 | P4 |     P2       |
    0       9    14     20      30      40      45     50       55      65      70   75   80             94
    
   b) Tiempo de turnaround para cada proceso 
   P1: 14 - P2: 94 - P3: 55 - P4: 55 - P5: 5 - P6: 15

      Valor medio para todos los procesos es de: 39,66666666 

   c) Tiempo de espera para cada proceso 
   P1: 0 - P2: 74 - P3: 25 - P4: 35 - P5: 0 - P6: 0

      Valor medio de espera para todos los procesos es de: 22,3333333

6) 


