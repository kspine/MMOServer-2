/*
 * ClientTcpServer.cpp
 *
 *  Created on: Jan 5, 2015
 *      Author: root
 */

#include "ClientTcpServer.h"

ClientTcpServer::ClientTcpServer(void)
{

}

ClientTcpServer::~ClientTcpServer(void)
{

}

ClientTcpServer* ClientTcpServer::instance_ = 0;

ClientTcpServer* ClientTcpServer::instance(void)
{
    if (instance_ == 0)
    {
        instance_ = new ClientTcpServer();
    }
    return instance_;
}

void ClientTcpServer::destroy(void)
{
    if (instance_ != 0)
    {
        delete instance_;
        instance_ = 0;
    }
}

int ClientTcpServer::start(void)
{
	if (super::start() != 0)
	{
		printf("ClientTcpServer::start error \n");
		return -1;
	}

	InetAddr clientTcpServerAddr(5000);

	if (this->listen(clientTcpServerAddr) != 0)
	{
		printf("ClientTcpServer::start listen error \n");
		return -1;
	}

	return 0;
}

int ClientTcpServer::receive(int fd, Buffer *buffer)
{
	if (super::receive(fd, buffer) != 0)
	{
		printf("ClientTcpServer::receive error \n");
		return -1;
	}

	printf("ClientTcpServer::receive fd = %d, size = %d\n", fd, (int)buffer->Length());

	Buffer * sendBuffer = new Buffer();
	*sendBuffer = *buffer;
	super::send(fd, sendBuffer);

	return 0;
}
