/*
 * test.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: root
 */

#include <event2/event.h>
#include "TcpClientTest.h"
#include "InetAddr.h"
#include "BaseTimer.h"
#include "TcpServerTest.h"
#include <pthread.h>
#include <event2/thread.h>
#include "BlockingQueue.h"
#include <string>
#include "GlobalInfo.h"
#include "ThreadMonitor.h"
#include "Buffer.h"


//void eventCallback(int fd, short which, void *arg)
//{
//	event_base *base = (event_base*)arg;
//	event_base_loopexit(base, NULL);
//
//	printf("stop eventCallback\n");
//}

//int main()
//{
//	GlobalInfo::useThreads();
//
//	GlobalInfo::print();
//
//	struct event_base *base = event_base_new();
//
//	event *ev = evsignal_new(base, 2, eventCallback, (void* )base);
//	if (!ev || event_add(ev, NULL) < 0)
//	{
//		event_del(ev);
//		return false;
//	}
//
//	InetAddr serverAddr(2015);
//
//	TcpServerTest server;
//	server.init(0, 0, 1);
//	server.start();
//	server.listen(serverAddr);
//
//	event_base_dispatch(base);
//
//	event_base_free(base);
//
//	server.stop();
//	server.final();
//
//	printf("end of server\n");
//
//	return 0;
//}

