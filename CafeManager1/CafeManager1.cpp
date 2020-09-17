// CafeManager1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CafeManager1.h"

#define MAX_LOADSTRING 100

#define IDC_BUTTON_U1 4001
#define IDC_BUTTON_U2 4002
#define IDC_BUTTON_U3 4003
#define IDC_BUTTON_U4 4004
#define IDC_BUTTON_U5 4005
#define IDC_BUTTON_U6 4006
#define IDC_BUTTON_U7 4007
#define IDC_BUTTON_U8 4008

#define IDC_EDIT1 5001
#define IDC_EDIT2 5002
#define IDC_EDIT3 5003

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hUButton1, hUButton2, hUButton3, hUButton4, hUButton5, hUButton6, hUButton7, hUButton8;
HWND hEdit1, hEdit2, hEdit3;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    CookDlgProc(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_CAFEMANAGER1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CAFEMANAGER1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CAFEMANAGER1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CAFEMANAGER1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		{
			SetWindowText(hWnd, L"Система управления работой кафе");
			MoveWindow(hWnd, 50, 50, 750, 400, true);

			hUButton1 = CreateWindowEx(0, L"BUTTON", L"Панель управления клиента",
				WS_CHILD | WS_VISIBLE, 50, 50, 300, 30, hWnd, (HMENU)IDC_BUTTON_U1,
				hInst, NULL);
            hUButton2 = CreateWindowEx(0, L"BUTTON", L"Панель управления повара",
                WS_CHILD | WS_VISIBLE, 50, 90, 300, 30, hWnd, (HMENU)IDC_BUTTON_U2,
                hInst, NULL);
            hUButton3 = CreateWindowEx(0, L"BUTTON", L"Панель управления официанта",
                WS_CHILD | WS_VISIBLE, 50, 130, 300, 30, hWnd, (HMENU)IDC_BUTTON_U3,
                hInst, NULL);
            hUButton4 = CreateWindowEx(0, L"BUTTON", L"Панель управления продавца",
                WS_CHILD | WS_VISIBLE, 50, 170, 300, 30, hWnd, (HMENU)IDC_BUTTON_U4,
                hInst, NULL);

            hUButton5 = CreateWindowEx(0, L"BUTTON", L"Панель управления бухгалтера",
                WS_CHILD | WS_VISIBLE, 380, 50, 300, 30, hWnd, (HMENU)IDC_BUTTON_U5,
                hInst, NULL);
            hUButton6 = CreateWindowEx(0, L"BUTTON", L"Панель управления админа",
                WS_CHILD | WS_VISIBLE, 380, 90, 300, 30, hWnd, (HMENU)IDC_BUTTON_U6,
                hInst, NULL);
            hUButton7 = CreateWindowEx(0, L"BUTTON", L"Панель управления менеджера",
                WS_CHILD | WS_VISIBLE, 380, 130, 300, 30, hWnd, (HMENU)IDC_BUTTON_U7,
                hInst, NULL);
            hUButton8 = CreateWindowEx(0, L"BUTTON", L"Панель управления дизайнера",
                WS_CHILD | WS_VISIBLE, 380, 170, 300, 30, hWnd, (HMENU)IDC_BUTTON_U8,
                hInst, NULL);
		}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDC_BUTTON_U1:
                {
                    //
                    MessageBox(hWnd, L"Открытие панели управление операциями клиента",
                        L"Сообщение", MB_OK | MB_ICONINFORMATION);
                }
                break;
            case IDC_BUTTON_U2:
                {
                    // Открытие диалогового окна IDD_DIALOG1
                    MessageBox(hWnd, L"Открытие панели управление операциями повара",
                        L"Сообщение", MB_OK | MB_ICONWARNING);
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, CookDlgProc);
                }
                break;
            case IDC_BUTTON_U3:
                {

                }
                break;
            case IDC_BUTTON_U4:
                {

                }
                break;
            case IDC_BUTTON_U5:
                {

                }
                break;
            case IDC_BUTTON_U6:
                {

                }
                break;
            case IDC_BUTTON_U7:
                {

                }
                break;
            case IDC_BUTTON_U8:
                {

                }
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
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
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
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

// Dialog with cook
INT_PTR CALLBACK CookDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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