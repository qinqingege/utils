#include "thread.h"

thread::thread(void)
: handle_(NULL)
{
}

thread::~thread(void)
{
}

bool thread::create(LPVOID param)
{
	thread_param *p = new thread_param;
	p->pthis = this;
	p->param = param;
	handle_ = ::CreateThread(NULL, 0, proc, p, 0, NULL);
	return handle_ != NULL;
}

DWORD thread::proc(LPVOID param)
{
	thread_param *p = static_cast<thread_param*>(param);
	DWORD ret = p->pthis->run(p->param);
	delete p;
	return ret;
}
