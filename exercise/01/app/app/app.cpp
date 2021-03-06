// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include  "pch.h"
#include "public.h"
#include "../../dll2/public.h"
#include <windows.h>
#include <iostream>
void use_dll1()
{
	typedef double(*get_value_func_ptr)(int);
	HMODULE hmodule = LoadLibrary(L"dynamic_library.dll");
	if (!hmodule) return;
	FARPROC ptr = GetProcAddress(hmodule, "get_value");
	if (ptr)
	{
		get_value_func_ptr pf = reinterpret_cast<get_value_func_ptr>(ptr);
		std::cout << "get_value_func_ptr() returned " << pf(8) << std::endl;
	}
	FreeLibrary(hmodule);
}

void use_dll2()
{
	auto a = get_value(8);
	std::cout << "dll2 get_value() " << a << std::endl;
}

void use_static_lib()
{
	auto a = static_lib::get_value(6);
	std::cout << "static_lib " << a << std::endl;
}


int main()
{
	use_static_lib();
	use_dll1();
	use_dll2();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
