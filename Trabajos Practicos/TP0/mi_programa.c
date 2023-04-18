#include <xinu.h>

void sndch(char);

void mi_programa(){
	int pidA,pidB;
	printf("Hola mundo! \n");

/*------------------------------------------------------------------------
 * main  --  example of creating processes in Xinu
 *------------------------------------------------------------------------
 */
	pidA = create(sndch, 1024, 20, "send C", 1, 'C');
	pidB = create(sndch, 1024, 20, "send D", 1, 'D');

	resume(pidA);
	resume(pidB);

	sleep(5);
	kill(pidA);
	kill(pidB);
}
void sndch(char ch)
{
	while( 1 )
		putc(CONSOLE, ch);
}

