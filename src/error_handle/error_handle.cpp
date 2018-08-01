#include "error_handle.h"

void ErrorHandle::ShowErrorMessage(const string& func_name, const string& error_message)
{
	cout << "func_name : " << func_name << " | error_message : " << error_message << endl;
}
void ErrorHandle::ShowAndExit(const string& func_name, const string& error_message)
{
	ErrorHandle::ShowErrorMessage(func_name, error_message);
	ErrorHandle::Exit();
}
void ErrorHandle::Exit(void)
{
	exit(EXIT_FAILURE);
}
