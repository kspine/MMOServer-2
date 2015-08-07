/*
 * TcpClientTest.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: root
 */

#include "TcpClientTest.h"

TcpClientTest::TcpClientTest(void)
{

}

TcpClientTest::~TcpClientTest(void)
{
	printf("~TcpClientTest\n");
}

void TcpClientTest::handleClosed(int fd)
{
	super::handleClosed(fd);

	printf("TcpClientTest::handleClosed fd = %d\n", fd);
}

