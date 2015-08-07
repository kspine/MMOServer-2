/*
 * SceneTcpClient.h
 *
 *  Created on: Jan 6, 2015
 *      Author: root
 */

#ifndef GAMEGATE_SCENETCP_SCENETCPCLIENT_H_
#define GAMEGATE_SCENETCP_SCENETCPCLIENT_H_

#include "TcpClient.h"
#include "TcpConnection.h"

class SceneTcpClient : public TcpClient<TcpConnection>
{
public:
	typedef TcpClient<TcpConnection> super;

private:
	SceneTcpClient(void);
	virtual ~SceneTcpClient(void);

public:
	static SceneTcpClient *instance(void);
	static void destroy(void);

private:
	static SceneTcpClient* instance_;
};

#define SCENE_TCP_CLIENT SceneTcpClient::instance()

#endif /* GAMEGATE_SCENETCP_SCENETCPCLIENT_H_ */
