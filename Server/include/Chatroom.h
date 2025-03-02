#pragma once

#include "Client.h"
#include "Packet.h"

class Chatroom {
private:
    Client m_client1, m_client2;

    // Echo message to everyone in chatroom
    void echo(const Client& sentFrom, const std::string& message);

    // Return message to sender
    void rts(const Client& sentFrom, const std::string& message);

    // Send function
    void chatSend(const Client& client, const std::string& message);

    // Receive function
    void chatRecv();

    // Polling an fd
    char* pollRecv(int fd);

    // Check received data
    void checkData(const Packet& packet);

public:
    // Takes 2 clients into chatroom
    Chatroom(Client c1, Client c2);

    void chat();

    ~Chatroom();
};

