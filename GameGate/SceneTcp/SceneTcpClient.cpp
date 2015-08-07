/*
 * SceneTcpClient.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: root
 */

#include "SceneTcpClient.h"

SceneTcpClient::SceneTcpClient(void)
{

}

SceneTcpClient::~SceneTcpClient(void)
{

}

SceneTcpClient* SceneTcpClient::instance_ = 0;

SceneTcpClient* SceneTcpClient::instance(void)
{
    if (instance_ == 0)
    {
        instance_ = new SceneTcpClient();
    }
    return instance_;
}

void SceneTcpClient::destroy(void)
{
    if (instance_ != 0)
    {
        delete instance_;
        instance_ = 0;
    }
}



