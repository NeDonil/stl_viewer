#include <iostream>

#include "Log.h"

int main()
{
	Log::Init();

	CORE_WARNING("Hello world");
	CORE_CRITICAL("Hello world");
	CORE_INFO("Hello world");
	CORE_TRACE("Hello world");
	CORE_ERROR("Hello world");

	system("pause");
	return 0;
}