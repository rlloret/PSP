#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

/*OK
Implementa un programa que cree un hijo. El hijo debe escribir “Soy el hijo” diez veces.
El padre debe escribir “Soy el padre” diez veces. 
El padre debe esperar a que termine el hijo y mostrar el mensaje “Mi proceso hijo ya ha terminado”.
*/
int main() {
	int pid;
	int i,x;
	int status1, status2;
 
	pid = fork();
 
	switch(pid)
	{
		case -1: // Si pid es -1 quiere decir que ha habido un error
			perror("No se ha podido crear el proceso hijo\n");
			break;
		case 0: // Cuando pid es cero quiere decir que es el proceso hijo
			for(i=0;i<10;i++){
				sleep(1);
				printf("Soy el hijo\n");
			}
			break;
		default: // Cuando es distinto de cero es el padre
			 waitpid(pid, &status1, 0);
			for(x=0;x<10;x++){
				sleep(1);
				printf("Soy el padre\n");
			}
			// La función wait detiene el proceso padre y se queda esperando hasta
			// que termine el hijo
			waitpid(pid, &status2, 0);
			printf("Mi proceso hijo ya ha terminado.\n");
			break;
	}
 
}
