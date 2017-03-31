#include <stdio.h>
#include <sys/types.h>

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


#define BACKLOG		5

/*********************************************************************
Escreve nbytes para o descritor dado
@param fd Descritor de IO
@param buf Apontador do buffer a escrever
@param nbtes Numero de bytes a escrever
@return Retorna o numero de bytes realmente escrito
(em caso de erro devolve valor devolvido pelo write).
*********************************************************************/
int writeN( int fd, void *buf, int nbytes) {
	int nwritten, nleft;
	char * bufc = buf;

	nleft = nbytes;
	
	while( nleft > 0) {
		nwritten = write( fd, bufc, nleft);
		if( nwritten <= 0)		/* Erro */
			return nwritten;
		nleft -= nwritten;
		bufc += nwritten;
	}
	return nbytes - nleft;		/* == 0 */
}


/***********************************************************
Cria e faz bind de um socket a uma dada porta
@param type Tipo de socket : SOCK_DGRAM ou SOCK_STREAM
@param portNum numero da porta
Retorna -1 em caso de erro
***********************************************************/
int bindSocket( int type, int portNum) {
	int fd;
	struct sockaddr_in	fromClnt;

	if(( fd = socket( AF_INET, type, 0)) < 0)
		return -1;

		/* endereco onde se escutam mensagens do cliente */
	fromClnt.sin_family = AF_INET;
	fromClnt.sin_port = htons( portNum);
	fromClnt.sin_addr.s_addr = htonl( INADDR_ANY);

	if( bind( fd, (struct sockaddr *)&fromClnt, sizeof(fromClnt) ) <0) {
		close( fd);
		return -1;
	}
	return fd;
}


/*********************************************************
Executa o servico de ECHO
*********************************************************/
void doitService( int fd) {
	int nbytes;
	static char		msg[1024];

	for( ; ; ) {
		nbytes = read( fd, msg, 1024);
		if( nbytes <= 0)
			break;
		writeN( fd, msg, nbytes);
	}
	close( fd);
}



int main( int argc, char *argv[]) {
	struct sockaddr_in	clnt_addr;
	int			sockfd, newsockfd, size;
	
	if( argc != 1 && argc != 2) {
		printf( "Usage : %s [ServerPort]\n");
		return;
	}

	if( argc == 1)
		sockfd = bindSocket( SOCK_STREAM, SERVER_PORT);
	else
		sockfd = bindSocket( SOCK_STREAM, atoi( argv[1]));
	if( sockfd < 0) {
		perror( "BindSocket");
		return;
	}

	if( listen( sockfd, BACKLOG) < 0) {
		perror( "Listen:");
		close( sockfd);
		return;
	}
	

	for( ; ; ) {

		size = sizeof( clnt_addr);
										/* Espera novo servico  */
		if( ( newsockfd = accept( sockfd, (struct sockaddr *)&clnt_addr, &size)) < 0) {
			perror( "Accept:");
			close( sockfd);
			return;
		}

		doitService( newsockfd);
	}
	close( sockfd);
}
