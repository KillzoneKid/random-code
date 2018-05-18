/*
	Example of setting of console window of given size
*/

#include <windows.h>
#include <iostream>

void SetConsoleWindow(SHORT cols, SHORT rows)
{
	HANDLE conout = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX sbInfoEx;
	sbInfoEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(conout, &sbInfoEx);
	sbInfoEx.dwSize = { cols, rows };
	sbInfoEx.srWindow = { 0, 0, cols, rows };
	sbInfoEx.dwMaximumWindowSize = { cols, rows };
	SetConsoleScreenBufferInfoEx(conout, &sbInfoEx);

	DWORD mode;
	GetConsoleMode(conout, &mode);
	mode &= ~ENABLE_WRAP_AT_EOL_OUTPUT;
	SetConsoleMode(conout, mode);

	SetConsoleTitle(TEXT("Console Window Test"));
}


int main()
{
	SHORT cols = 100, rows = 60;
	SetConsoleWindow(cols, rows);

	for (int y = 1; y <= rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
			std::cout << x % 10;

		if (y < rows)
			std::cout << std::endl;
	}

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

	std::cin.get();

	return 0;
}