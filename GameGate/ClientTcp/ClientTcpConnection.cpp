/*
 * ClientTcpConnection.cpp
 *
 *  Created on: Jan 5, 2015
 *      Author: root
 */
#include "ClientTcpConnection.h"

ClientTcpConnection::CheckTimer::CheckTimer(void)
	  : ptr_(NULL)
{

}

ClientTcpConnection::CheckTimer::~CheckTimer(void)
{

}

void ClientTcpConnection::CheckTimer::handleTimeOut(void)
{
	if (ptr_ != NULL)
	{
		ptr_->handleTimeOut();
	}
}

ClientTcpConnection::ClientTcpConnection(void)
{
//	this->check_timer_.
}

ClientTcpConnection::~ClientTcpConnection(void)
{

}

void ClientTcpConnection::handleTimeOut(void)
{

}

int ClientTcpConnection::init(int fd, //
		TcpMonitor *owner)
{
	if (TcpConnection::init(fd, owner) != 0)
	{
		return -1;
	}

	this->check_timer_.ptr_ = this;
	this->check_timer_.event_base(owner->eventBase());
	this->check_timer_.scheduleTimer(1);

	return 0;
}

void ClientTcpConnection::handleClear(void)
{
	this->check_timer_.cancelTimer();
	return TcpConnection::handleClear();
}

