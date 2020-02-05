#pragma once

#include "resource.h"


void UpdateScreen();
int EventLoop();
void Initialize();
double dgetUsedMemoryMB();
void DrawScreen(const char* cMsg, HDC hdc = NULL);
void DisplayInLogList(const char* cMsg);
void LogFile(const char* cMsg);