/*
 * GateMonitor.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: root
 */

#include "GateMonitor.h"
#include "ClientTcpServer.h"
#include "SceneTcpClient.h"

GateMonitor::GateMonitor(void)
	: main_base_(0)
{

}

GateMonitor::~GateMonitor(void)
{

}

GateMonitor* GateMonitor::instance_ = 0;

GateMonitor* GateMonitor::instance(void)
{
    if (instance_ == 0)
    {
        instance_ = new GateMonitor();
    }
    return instance_;
}

void GateMonitor::destroy(void)
{
    if (instance_ != 0)
    {
        delete instance_;
        instance_ = 0;
    }
}

void GateMonitor::eventBase(event_base *main_base)
{
	this->main_base_ = main_base;
}

int GateMonitor::init(void)
{
	if (this->main_base_)
	{
		CLIENT_TCP_SERVER->eventBase(this->main_base_);
		SCENE_TCP_CLIENT->eventBase(this->main_base_);

//		CLIENT_TCP_SERVER->init(1, 1);
//		SCENE_TCP_CLIENT->init(1, 1);

		CLIENT_TCP_SERVER->init();
		SCENE_TCP_CLIENT->init();
	}
	else
	{
		CLIENT_TCP_SERVER->init(1, 1, 1);
		SCENE_TCP_CLIENT->init(1, 1, 1);
	}

	return 0;
}

int GateMonitor::start(void)
{
	CLIENT_TCP_SERVER->start();
	SCENE_TCP_CLIENT->start();

	return 0;
}

int GateMonitor::stop(void)
{
	CLIENT_TCP_SERVER->stop();
	SCENE_TCP_CLIENT->stop();

	return 0;
}

int GateMonitor::final(void)
{
	CLIENT_TCP_SERVER->final();
	SCENE_TCP_CLIENT->final();

	return 0;
}




