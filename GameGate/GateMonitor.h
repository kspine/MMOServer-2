/*
 * GateMonitor.h
 *
 *  Created on: Jan 6, 2015
 *      Author: root
 */

#ifndef GAMEGATE_GATEMONITOR_H_
#define GAMEGATE_GATEMONITOR_H_

struct event_base;

class GateMonitor
{
private:
	GateMonitor(void);
	~GateMonitor(void);

public:
	static GateMonitor *instance(void);
	static void destroy(void);

	void eventBase(event_base *main_base);

    int init(void);
    int start(void);
    int stop(void);
    int final(void);

private:
	static GateMonitor* instance_;

	event_base* main_base_;
};

#define GATE_MONITOR GateMonitor::instance()

#endif /* GAMEGATE_GATEMONITOR_H_ */
