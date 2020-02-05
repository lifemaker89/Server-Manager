// Server Manager.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Server Manager.h"
#include "Core.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//global
HWND G_hwnd;
HDC G_hdc;

char G_cMsgMaxList[256];

//classes
class Core* g_pCore = NULL;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SERVERMANAGER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    Initialize();
    EventLoop();

    

    


}
int EventLoop()
{
    HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_SERVERMANAGER));
    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            UpdateScreen();
        }
    }
    return (int)msg.wParam;
}
void Initialize()
{
    //if (_InitWinsock() == FALSE) {
    //    MessageBox(G_hWnd, "Socket 1.1 not found! Cannot execute program.", "ERROR", MB_ICONEXCLAMATION | MB_OK);
    //    PostQuitMessage(0);
    //    return;
    //}

    // Allocate memory for the object
    Core* g_pCore = new Core(G_hwnd);
    
    /*if (G_pGateCore == NULL) {
        MessageBox(G_hWnd, "Init fail!", "ERROR", MB_ICONEXCLAMATION | MB_OK);
        PostQuitMessage(0);
        return;
    }

    if (G_pGateCore->bInit() == FALSE) {
        MessageBox(G_hWnd, "Init fail!", "ERROR", MB_ICONEXCLAMATION | MB_OK);
        PostQuitMessage(0);
        return;
    }

    G_pListenSock = new class XSocket(G_hWnd, 300);
    G_pListenSock->bListen(G_pGateCore->m_cGateServerAddr, G_pGateCore->m_iGateServerPort, WM_USER_ACCEPT);

    G_mmTimer0 = _StartTimer(3000);

    PutLogList("(!) Gate Server Listening...");*/

    DisplayInLogList("Test");
}
//  FUNCTION: MyRegisterClass()
//  PURPOSE: Registers the window class.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SERVERMANAGER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SERVERMANAGER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//   FUNCTION: InitInstance(HINSTANCE, int)
//   PURPOSE: Saves instance handle and creates main window
//   COMMENTS:
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   G_hwnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!G_hwnd)
   {
      return FALSE;
   }

   ShowWindow(G_hwnd, nCmdShow);
   UpdateWindow(G_hwnd);

   return TRUE;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//  PURPOSE: Processes messages for the main window.
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
// MB_OK
// MB_OKCANCEL
// MB_ABORTRETRYIGNORE
// MB_YESNOCANCEL
// MB_YESNO
// MB_RETRYCANCEL
// MB_HELP
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                if (MessageBox(
                    NULL,
                    (LPCWSTR)L"Close Server Manager",
                    (LPCWSTR)L"Please close down server and reboot", MB_ICONEXCLAMATION | MB_YESNO)== IDYES) {
                    return (DefWindowProc(hWnd, message, wParam, lParam));
                } 
                DestroyWindow(hWnd);
                break;
    
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        G_hdc = BeginPaint(hWnd, &ps);
        DrawScreen(NULL, G_hdc); //, 88, 99
        EndPaint(hWnd, &ps);
    }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
        g_pCore->OnKeyDown(wParam, lParam);
        break;

    case WM_KEYUP:
        g_pCore->OnKeyUp(wParam, lParam);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;

    /*case WM_USER_TIMERSIGNAL:
        if (wParam == G_mmTimer0) G_pGateCore->OnTimer(0);
        break;

    case WM_USER_ACCEPT:
        OnAccept();
        break;

*/
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

////
////
////
//// Lifemaker89 Coding ////

void UpdateScreen()
{
      //  if (G_cMsgUpdated == TRUE) {
      //      InvalidateRect(G_hwnd, NULL, TRUE);
    //        G_cMsgUpdated = FALSE;
   // }
}

void DrawScreen(const char* cMsg, HDC hdc)
{
    TCHAR ctext[256];

    SelectObject(hdc, hInst);

    //always on screen
    swprintf_s(ctext, 256, L"Ram Usage: %d", "100"); //add ram check
    TextOut(hdc, 10, 70, ctext, wcslen(ctext));
    swprintf_s(ctext, 256, L"Memory Usage: %d", dgetUsedMemoryMB());
    TextOut(hdc, 10, 85, ctext, wcslen(ctext));

    swprintf_s(ctext, 256, L"Press [F1 + F4]  Shut down all map servers");
    TextOut(hdc, 10, 10, ctext, wcslen(ctext));
    swprintf_s(ctext, 256, L"Press [F2] Shows not activated game server list");
    TextOut(hdc, 10, 25, ctext, wcslen(ctext));
    swprintf_s(ctext, 256, L"Press [F3] Shows activated game server list");
    TextOut(hdc, 10, 40, ctext, wcslen(ctext));
    swprintf_s(ctext, 256, L"________________________________________________________________________________");
    TextOut(hdc, 10, 55, ctext, wcslen(ctext));
 
    //List text
   // for (int i = 0; i < 35; i++) {
   //     cMsg = (char*)(G_cMsgMaxList + i * 60);
   //     TextOut(hdc, 10, 70 - i * 15, (LPCWSTR)cMsg, strlen(cMsg));
   // }

   // LogFile(cMsg);
}

double dgetUsedMemoryMB()
{
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return static_cast<double>(pmc.WorkingSetSize) / static_cast<double>(1024 * 1024);
}

void DisplayInLogList(const char* cMsg)
{
    char cTemp[120 * 50];
    TCHAR cListtext[256];

   // G_cMsgUpdated = TRUE;
    ZeroMemory(cTemp, sizeof(cTemp));
    memcpy((cTemp + 120), G_cMsgMaxList, 120 * 49);
    memcpy(cTemp, cMsg, strlen(cMsg));

//    PAINTSTRUCT ps;
//    HDC hdc;
//
//    G_hdc = BeginPaint(hWnd, &ps);
//    
//    hdc = BeginPaint(G_hWnd, &ps);
//
//    SetBkMode(hdc, TRANSPARENT);
//    
//    TextOut(G_hdc, 10, 70, (LPCWSTR)cMsg, strlen(cMsg));
//;
//   // UpdateScreen();
//    LogFile(cMsg);
//    EndPaint(hWnd, &ps);

}

void LogFile(const char* cMsg)
{
    FILE* pFile;
    TCHAR cBuffer[512];
    SYSTEMTIME SysTime;
    int line, line2;

    fopen_s(&pFile, "Logs\\Login.log", "at");
    if (pFile == NULL) return;
    ZeroMemory(cBuffer, sizeof(cBuffer));

    GetLocalTime(&SysTime);
    line = swprintf_s(cBuffer, 256, L"(% 4d: % 2d : % 2d : % 2d : % 2d) - ", SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wHour, SysTime.wMinute);
    line2 = swprintf_s(cBuffer + line, 256 - line - 1, L"%", cMsg);
    swprintf_s(cBuffer + line2, 256 - line - 1, L"\n");
    fwrite(cBuffer, sizeof(char), sizeof(cBuffer), pFile);
    fclose(pFile);
}