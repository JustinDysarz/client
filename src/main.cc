#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <cstdlib>
#include <cstdio>
#include <memory>
#include <cstring>
#include <string>
#include <iostream>

class client {
private:
    std::unique_ptr<sockaddr_in> serverAddress;
    int clientSocket;

public:
    client() {
        socket(AF_INET, SOCK_STREAM, 0);

        serverAddress = std::unique_ptr<sockaddr_in>();
        serverAddress.get()->sin_family = AF_INET;
        serverAddress.get()->sin_port = htons(8080);
        serverAddress.get()->sin_addr.s_addr = INADDR_LOOPBACK;

        if (connect(clientSocket, (struct sockaddr*)&*(serverAddress.get()), sizeof(*serverAddress.get())) == -1) {
            perror("Oh no. could not connect to host");
            exit(EXIT_FAILURE);
        }
        
        char *test = "Hello this is a test";
        send(clientSocket, test, strlen(test), 0);

        close(clientSocket);
    }
};

int main(void) {
       

    exit(EXIT_SUCCESS);
}
