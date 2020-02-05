#pragma once
#include "Server Manager.h"

class Core
{
public:

	Core(HWND G_hWnd);
	virtual ~Core();

	void OnKeyDown(WPARAM wParam, LPARAM lParam);
	void OnKeyUp(WPARAM wParam, LPARAM lParam);

};