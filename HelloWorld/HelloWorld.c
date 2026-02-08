// HelloWorld.c : Определяет точку входа для приложения.
//
#include "framework.h"
#include "HelloWorld.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;// текущий экземпляр

// Отправить объявления функций, включенных в этот модуль кода:
BOOL                InitInstance(HINSTANCE, int);
INT_PTR CALLBACK    HelloWorldDlg(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    return 0;
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    INT_PTR nResponse;
    INITCOMMONCONTROLSEX InitCtrls;
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
    InitCtrls.dwSize = sizeof(InitCtrls);
    // Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
    // в вашем приложении.
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);
    nResponse = DialogBox(hInst, MAKEINTRESOURCE(IDD_HELLOWORLD_DIALOG), NULL, HelloWorldDlg);
    if (nResponse == IDOK)
    {
        // TODO: Введите код для обработки закрытия диалогового окна
        //  с помощью кнопки "ОК"
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: Введите код для обработки закрытия диалогового окна
        //  с помощью кнопки "Отмена"
    }
    else if (nResponse == -1)
        return FALSE;
   return TRUE;
}

// Обработчик сообщений для окна "HelloWorld".
INT_PTR CALLBACK HelloWorldDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
        if (LOWORD(wParam) == IDC_BUTTON1)
        {
            MessageBox(hDlg, _T("Hello,World!!!"), _T("Hello"), 0);
        }
        if (LOWORD(wParam) == IDC_BUTTON2)
        {
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}