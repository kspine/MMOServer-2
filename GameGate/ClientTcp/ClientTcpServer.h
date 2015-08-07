/*
 * ClientTcpServer.h
 *
 *  Created on: Jan 5, 2015
 *      Author: root
 */

#ifndef GAMEGATE_CLIENTTCP_CLIENTTCPSERVER_H_
#define GAMEGATE_CLIENTTCP_CLIENTTCPSERVER_H_

#include "TcpServer.h"
#include "ClientTcpConnection.h"

class ClientTcpServer : public TcpServer<ClientTcpConnection>
{
public:
	typedef TcpServer<ClientTcpConnection> super;

private:
	ClientTcpServer(void);
	virtual ~ClientTcpServer(void);

public:
	static ClientTcpServer *instance(void);
	static void destroy(void);

	virtual int start(void);

	virtual int receive(int fd, Buffer *buffer);

private:
	static ClientTcpServer* instance_;
};

#define CLIENT_TCP_SERVER ClientTcpServer::instance()

#endif /* GAMEGATE_CLIENTTCP_CLIENTTCPSERVER_H_ */
