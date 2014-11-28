#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[80];
    pid_t pid;
    int respuesta;
    char frase1[80], frase2[80];
   // char frase1[0]="";
   // char frase2[0]="";
   // int comparacion1;
   // int comparacion2;
   // int f1;
   // int f2;

    // char cadena="0";
    //comparacion1 = strcmp (frase1[0],cadena);
    //comparacion2 = strcmp (frase2[0],cadena);

//while(comparacion1!=0 || comparacion2!=0){

printf ("Escribe la frase del hijo al padre\n");
scanf("%s", frase1);

pipe (fd);
pid=fork();
        switch(pid)
        {
        case -1://ERROR
        printf("no se ha podido crear el hijo\n");
        exit(-1);
        case 0: //hijo
	close(fd[0]);
	write(fd[1], frase1, strlen(frase1));
        printf("El hijo le dice al padre: %s\n",frase1);        
	break;
        default: //padre
	wait(NULL);
        close (fd[1]);
	read(fd[0], buffer, sizeof(buffer));
        printf("El padre lee del hijo: %s\n",frase1);	
	}

printf ("Escribe la frase del padre al hijo\n");
scanf("%s", frase2);

pipe (fd);
//pid=fork();
	switch(pid)
	{
	case -1://ERROR
	printf("No se ha podido crear el hijo\n");
	exit(-1);
	break;
	case 0://hijo
	wait(NULL);
	close(fd[1]);
	read (fd[0], buffer ,sizeof(buffer));
	printf("El hijo lee del padre: %s\n", frase2);

	break;
	default://padre
	close(fd[0]);
	write(fd[1], frase2, strlen(frase2));
	printf("El padre escribe al hijo: %s\n", frase2);
	}

	//}
}