#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
    //Create a socket
    int listening = socket(AF_INET, SOCK_STREAM,0);
    if (listening == -1){
        cerr << "Can't create a socket Quitting" << endl;
        return -1;
    }

    //Bind the ip address and a port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(9999);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint,sizeof(hint));
    cout << "The server is running at port: " << hint.sin_port << endl;
    //Tell winsock the socket is for listening
    listen(listening, SOMAXCONN);

    //Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    memset(host,0,NI_MAXHOST);
    memset(service,0,NI_MAXSERV);
    if(getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV,0) == 0){
        cout << host << "connected on port" << service << endl;
    }else{
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    //close listening socket
    close(listening);
    // while loop, accept and echo message back to client
    char buf[4096];

    while(true){
        memset(buf, 0, 4906);
        //Wait for client to send data
        int bytesReceived = recv(clientSocket,buf,4096,0);
        if(bytesReceived == -1){
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if(bytesReceived == 0){

            cout << "Client disconnected " << endl;
            break;
        }

        cout << string(buf,0,bytesReceived) << endl;
        //echo message back to client

        send(clientSocket, buf, bytesReceived +1, 0);
    }

    //close the socket
    close(clientSocket);

    return 0;



}