#pragma once

#include <Windows.h>

class thread
{
public:
	thread(void);
	virtual ~thread(void);

	bool create(LPVOID);
	operator HANDLE()
	{
		return handle_;
	}
	virtual DWORD run(LPVOID) = 0;

private:
	struct thread_param 
	{
		thread *pthis;
		LPVOID param;
	};

	static DWORD WINAPI proc(LPVOID);

private:
	HANDLE handle_;
};
