#ifndef _ERROR_HANDLE_H_
#define _ERROR_HANDLE_H_

#include <iostream>
#include <string>

#include "../main/USING_NAMESPACE_STD.h"

namespace ErrorHandle
{
	void ShowErrorMessage(const string& func_name, const string& error_message);
	void ShowAndExit(const string& func_name, const string& error_message);
	void Exit(void);

}

#endif //_ERROR_HANDLE_H_
