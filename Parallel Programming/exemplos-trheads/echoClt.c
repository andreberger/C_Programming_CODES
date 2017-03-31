/**********************************************************
Cliente para um servico de echo
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#ifndef WIN32

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#else

#include <io.h>
#include <winsock.h>

#define bcopy( X, Y, Z)	memcpy( Y, X, Z)

#endif

#define SERVER_PORT	7007



/*********************************************************************
Le uma sequencia de caracteres dum descritor terminada numa segunda
sequencia. O buffer e null-terminated.
@param fd Descritor de IO
@param buf Apontador do buffer onde se guarda a sequencia lida
@param nbtes Numero de bytes maximo a ler
@param seq Sequencia final a encontrar.
@param nseq Numero de bytes da sequencia
@param found Retorna a indicacao de se a sequencia foi encontrada
	(NULL permitido, caso nao seja importante saber esse valor)
@return Retorna o numero de bytes realmente lido
(em caso de erro devolve valor devolvido pelo lido).
*********************************************************************/
int readUntil( int fd, void *buf, int nbytes, void *seq, int nseq, int *found) {
	char * bufc, *seqc, *ptr1, *ptr2;
	int count;
	int nread = 0;

	if( found != NULL)
		*found = 0;
	
	bufc = buf;
	seqc = seq;

	for( nread = 0; nread < nbytes - 1;) {
		count = read( fd, bufc, 1);
		if( count < 0)		/* Erro */
			return count;
		if( count == 0)		/* EOF */
			break;

		nread++;
		bufc++;
		if( nread >= nseq) {
			ptr1 = bufc;
			ptr2 = &(seqc[nseq]);
			count = nseq;
			for( ptr1--, ptr2--; count > 0 && *ptr1 == *ptr2; count--, ptr1--, ptr2--)
				/* do nothing */;
			if( count == 0) {
				if( found != NULL)
					*found = 1;
				break;
			}
		}
	}
	*bufc = 0;

	return nread;
}
 
/*********************************************************************
Le uma sequencia de caracteres dum descritor terminada num <newline>.
O buffer e null-terminated. Se devolver um numero de bytes igual a nbytes - 1
nao se garante que a sequencia lida termine com <newline>
@param fd Descritor de IO
@param buf Apontador do buffer onde se guarda a sequencia lida
@param nbtes Numero de bytes maximo a ler
@return Retorna o numero de bytes realmente lido
(em caso de erro devolve valor devolvido pelo lido).
*********************************************************************/
int readLine( int fd, void *buf, int nbytes) {
	char newLine[] = "\n";
	
	return readUntil( fd, buf, nbytes, newLine, strlen(newLine), NULL);
}

/***********************************************************
Cria e conecta um socket a um dado servidor
@param type Tipo de socket  : SOCK_DGRAM or SOCK_STREAM
@param serverHost Nome do servidor
@param portnum Numero da porta
Retorna -1 em caso de erro
***********************************************************/
int connectSocket( int type, char *serverHost, int portNum) {
	int fd;
	struct sockaddr_in toServer;
	struct hostent *h;

	if(( fd = socket( AF_INET, type, 0)) < 0)
		return -1;
    
		/* endereco para contactar o servidor */
	toServer.sin_family = AF_INET;
	toServer.sin_port = htons( portNum);
	if( (h = gethostbyname( serverHost)) == NULL) {
		close( fd);
		return -1;
	}
	bcopy( h->h_addr, &toServer.sin_addr, h->h_length);
  
	if( connect( fd, (struct sockaddr *)&toServer, sizeof(toServer)) < 0) {
		close( fd);
		return -1;
	}
	return fd;
}


int main( int argc, char *argv[]) {
	int sockfd, nbytes, aux;
	static char		msg[1024];
	
	if( argc != 2 && argc != 3) {
		printf( "Usage : %s [ServerHost [ServerPort]]\n", argv[0]);
		return;
	}

	if( argc == 2)
		sockfd = connectSocket( SOCK_STREAM, argv[1], SERVER_PORT);
	else
		sockfd = connectSocket( SOCK_STREAM, argv[1], atoi( argv[2]));
	if( sockfd < 0) {
		perror( "ConnectSocket");
		return;
	}

	printf( "Enter -quit- to exit\n");
	for( ; ; ) {
		nbytes = readLine( 0, msg, 1024);
		if( nbytes <= 0 || ( nbytes >= 4 && strncmp( msg, "quit", 4) == 0))
			break;
		write( sockfd, msg, nbytes);
		aux = read( sockfd, msg, 1024);
		if( aux <= 0)
			break;
		write( 1, msg, aux);
	}
	close( sockfd);
}
