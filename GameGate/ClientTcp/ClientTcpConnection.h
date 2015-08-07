/*
 * ClientTcpConnection.h
 *
 *  Created on: Jan 5, 2015
 *      Author: root
 */

#ifndef GAMEGATE_CLIENTTCP_CLIENTTCPCONNECTION_H_
#define GAMEGATE_CLIENTTCP_CLIENTTCPCONNECTION_H_

#include "TcpConnection.h"
#include "TcpMonitor.h"

class ClientTcpConnection : public TcpConnection
{
public:

	class CheckTimer : public BaseTimer
	{
	public:
		CheckTimer(void);
		virtual  ~CheckTimer(void);

		virtual void handleTimeOut(void);

		ClientTcpConnection *ptr_;
	};

	ClientTcpConnection(void);
	virtual ~ClientTcpConnection(void);

	virtual int init(int fd, //
			TcpMonitor *owner);
	virtual void handleClear(void);

	virtual void handleTimeOut(void);

private:
	CheckTimer check_timer_;
};



#endif /* GAMEGATE_CLIENTTCP_CLIENTTCPCONNECTION_H_ */
