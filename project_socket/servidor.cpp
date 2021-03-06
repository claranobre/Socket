#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <thread>
#include <iostream>
#include <vector>

#define MAXMSG 1024
#define MAXNAME 100
#define PORTNUM 4325

using namespace std;

#define TAM_MAX_MENSAGEM_STATUS_LED    100
#define NUM_MAX_CONEXAO_CLIENTS        1
#define GPIO_LED                       2   //GPIO escolhido para colocar o LED.
#define PORTA_SOCKET_SERVER            8888

/*class Mensagem {
    public:
        char msg[MAXMSG];
        char nome[MAXNAME];
        int idade;
        Mensagem();
};
*/

struct things_t {
 std::int32_t update_interval; //receber dados do cliente
 char led_color;
 std::int32_t pot_adc;
 float humidity;
 float temperature;
};

/*Mensagem::Mensagem()
{
    idade = 20;
}
*/

things_t::things_t(){
    int socket_desc , client_sock , c , read_size;           //socket_desc: descriptor do socket servidor
                                                             //client_sock: descriptor da conexao com o client
                                                             //read_size: contem o tamanho da estrutura que contem os dados do socket
    struct sockaddr_in server , beaglebone;                  //server: estrutura com informações do socket (lado do servidor)
                                                             //beaglebone: estrutura com informações do socket (lado do client)
    char client_message[TAM_MAX_MENSAGEM_CLIENT];            //array utilizado como buffer dos bytes enviados pelo client
    //char MensagemBoasvindas[TAM_MAX_MENSAGEM_BOAS_VINDAS];   //array que contem a mensagem de boas vindas (enviada no momento que a conexao e estabelecida)
    char MensagemStatusLed[TAM_MAX_MENSAGEM_STATUS_LED];     //array que contem a mensagem do status do LED (enviada apos qualquer alteracao do status do LED)
}

void socketHandler(int socketDescriptor)
{
    //Verificando erros
    if ( socketDescriptor == -1)
    {
        printf("Falha ao executar accept()");
        exit(EXIT_FAILURE);
    }

    close(socketDescriptor);
}


int main(int argc, char *argv[])
{
    //variáveis do servidor
    struct sockaddr_in endereco;
    int socketId;

    //variáveis relacionadas com as conexões clientes
    struct sockaddr_in enderecoCliente;
    socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
    int conexaoClienteId;

    /*
     * Configurações do endereço
    */
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    //endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_addr.s_addr = inet_addr("127.0.0.1");

    /*
     * Criando o Socket
     *
     * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
     * PARAM2: SOCK_STREAM ou SOCK_DGRAM
     * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
    */
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    //Verificar erros
    if (socketId == -1)
    {
        printf("Falha ao executar socket()\n");
        exit(EXIT_FAILURE);
    }

    //Conectando o socket a uma porta. Executado apenas no lado servidor
    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
    {
        printf("Falha ao executar bind()\n");
        exit(EXIT_FAILURE);
    }

    //Habilitando o servidor a receber conexoes do cliente
    if ( listen( socketId, 10 ) == -1)
    {
        printf("Falha ao executar listen()\n");
        exit(EXIT_FAILURE);
    }

    //Servidor ficar em um loop infinito
    while(1)
    {
        printf("Servidor: esperando conexões clientes\n");

        //Servidor fica bloqueado esperando uma conexão do cliente
        conexaoClienteId = accept( socketId,(struct sockaddr *) &enderecoCliente,&tamanhoEnderecoCliente );

        printf("Servidor: recebeu conexão de %s\n", inet_ntoa(enderecoCliente.sin_addr));

        //disparar a thread
        thread t(socketHandler,conexaoClienteId);
        t.detach();
    }

    return 0;
}
