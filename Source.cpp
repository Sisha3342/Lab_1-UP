#include <windows.h>
#include <string>
#include <sstream>
#include "calculator.h"
#define AM_OF_OPER 20
#define MAX_SIZE 20

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
bool check_zeros(std::string str);
bool check_points(std::string str);

int APIENTRY WinMain(HINSTANCE This, HINSTANCE Prev, LPTSTR cmd, int mode) 
{
	std::string WinName = "MainFrame";
	HWND hWnd; 
	MSG msg; 
	WNDCLASS wc; 
	
	wc.hInstance = This;
	wc.lpszClassName = WinName.c_str(); 
	wc.lpfnWndProc = WndProc; 
	wc.style = CS_HREDRAW | CS_VREDRAW; 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wc.lpszMenuName = NULL; 
	wc.cbClsExtra = 0; 
	wc.cbWndExtra = 0; 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClass(&wc)) 
		return 0;
	hWnd = CreateWindow(WinName.c_str(), "Calculator", WS_OVERLAPPEDWINDOW&~(WS_MAXIMIZEBOX), CW_USEDEFAULT,CW_USEDEFAULT,
		500, 500, NULL, NULL,This, NULL);

	hInst = This;

	ShowWindow(hWnd, mode); 
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg); 
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND buttons[AM_OF_OPER];
	static std::string currentCalc;
	static int cxClient = 500, cyClient = 500;
	HDC hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_CREATE:
	{
		std::string buttonName;
		std::stringstream oss;

		buttons[0] = CreateWindow("button", "0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0.02*cxClient, 0.8*cyClient,
			0.13*(cyClient + cxClient), 0.06*(cxClient + cyClient), hWnd, (HMENU)0, hInst, NULL);

		for (int i = 1, xCoord = 0, yCoord = 0.8*cyClient; i < 10; i++)
		{

			if (i % 3 == 1)
			{
				yCoord -= 0.14*cyClient;
				xCoord = 0.02*cxClient;
			}
			else
				xCoord += 0.14*cxClient;

			oss << i;
			oss >> buttonName;

			buttons[i] = CreateWindow("button", buttonName.c_str(), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, xCoord, yCoord,
				0.06*(cxClient + cyClient), 0.06*(cxClient + cyClient), hWnd, (HMENU)i, hInst, NULL);

			oss.clear();
			buttonName.clear();
		}

		std::string operations = ".+-*/()C<";

		for (int i = 0, xCoord = 0.3*cxClient, yCoord = 0.8*cyClient; i < operations.size(); i++)
		{
			if (i % 3 == 1)
			{
				yCoord -= 0.14*cyClient;
				xCoord = 0.44*cxClient;
			}
			else
				xCoord += 0.14*cxClient;

			std::string sub_str = operations.substr(i, 1);

			buttons[i + 10] = CreateWindow("button", sub_str.c_str(), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, xCoord, yCoord,
				0.06*(cxClient + cyClient), 0.06*(cxClient + cyClient), hWnd, (HMENU)(i + 10), hInst, NULL);
		}

		buttons[AM_OF_OPER - 1] = CreateWindow("button", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0.3*cxClient, 0.8*cyClient,
			0.06*(cxClient + cyClient), 0.06*(cxClient + cyClient), hWnd, (HMENU)19, hInst, NULL);

		break;
	}



	case WM_SIZE:
	{
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		break;
	}

	case WM_PAINT:
	{
		double temp_coord;
		const int xCalcCoord = 0.02*cxClient, yCalcCoord = 0.32*cyClient;
		hdc = BeginPaint(hWnd, &ps);

		HFONT hfont = CreateFont(.04*cyClient, 0.02*cxClient, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE,
			DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, "customFont");
		SelectObject(hdc, hfont);
		TextOut(hdc, xCalcCoord, yCalcCoord, currentCalc.c_str(), currentCalc.size());
		DeleteObject(hfont);

		MoveToEx(hdc, 0.98*cxClient, 0.31*cyClient, NULL);
		LineTo(hdc, 0.01*cxClient, 0.31*cyClient);
		LineTo(hdc, 0.01*cxClient, 0.36*cyClient);
		LineTo(hdc, 0.98*cxClient, 0.36*cyClient);
		LineTo(hdc, 0.98*cxClient, 0.31*cyClient);

		for (int i = 1, xCoord = 0, yCoord = 0.8*cyClient; i < 10; i++)
		{

			if (i % 3 == 1)
			{
				yCoord -= 0.14*cyClient;
				xCoord = 0.02*cxClient;
			}
			else
				xCoord += 0.14*cxClient;

			if (i == 3)
				temp_coord = xCoord;

			MoveWindow(buttons[i], xCoord, yCoord, 0.06*(cxClient + cyClient), 0.06*(cxClient + cyClient), TRUE);

		}

		MoveWindow(buttons[0], 0.02*cxClient, 0.8*cyClient, 0.13*(cyClient + cxClient),
			0.06*(cxClient + cyClient), TRUE);

		for (int i = 10, xCoord = 0.3*cxClient, yCoord = 0.8*cyClient; i < AM_OF_OPER - 1; i++)
		{
			if (i % 3 == 1)
			{
				yCoord -= 0.14*cyClient;
				xCoord = 0.44*cxClient;
			}
			else
				xCoord += 0.14*cxClient;

			MoveWindow(buttons[i], xCoord, yCoord, 0.06*(cxClient + cyClient), 0.06*(cxClient + cyClient), TRUE);
		}

		MoveWindow(buttons[AM_OF_OPER - 1], temp_coord, 0.8*cyClient,
			0.06*(cxClient + cyClient), 0.06*(cxClient + cyClient), TRUE);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_COMMAND:
	{		
		switch (LOWORD(wParam))
		{
		case 0:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "0";
				}
				else
					currentCalc += "0";
			}

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 1:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "1";
				}
				else
					currentCalc += "1";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 2:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "2";
				}
				else
					currentCalc += "2";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 3:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "3";
				}
				else
					currentCalc += "3";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 4:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "4";
				}
				else
					currentCalc += "4";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 5:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "5";
				}
				else
					currentCalc += "5";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 6:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "5";
				}
				else
					currentCalc += "5";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 7:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "7";
				}
				else
					currentCalc += "7";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 8:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "8";
				}
				else
					currentCalc += "8";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 9:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (check_zeros(currentCalc))
			{
				if (currentCalc.size() != 0)
				{
					if (currentCalc[currentCalc.size() - 1] != ')')
						currentCalc += "9";
				}
				else
					currentCalc += "9";
			}
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 10:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (currentCalc.size() != 0)
				if (currentCalc[currentCalc.size() - 1] != ')' && check_points(currentCalc) && currentCalc[currentCalc.size() - 1] != '+' && currentCalc[currentCalc.size() - 1] != '-' && currentCalc[currentCalc.size() - 1] != '.'
					&& currentCalc[currentCalc.size() - 1] != '*' && currentCalc[currentCalc.size() - 1] != '/')
				currentCalc += ".";
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 11:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (currentCalc.size() != 0)
				if (currentCalc[currentCalc.size() - 1] != ')' && currentCalc[currentCalc.size() - 1] != '+' && currentCalc[currentCalc.size() - 1] != '-' && currentCalc[currentCalc.size() - 1] != '.'
					&& currentCalc[currentCalc.size() - 1] != '*' && currentCalc[currentCalc.size() - 1] != '/')
					currentCalc += "+";
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 12:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (currentCalc.size() == 0)
				currentCalc += "-";
			else
				if (currentCalc[currentCalc.size() - 1] != ')' && currentCalc[currentCalc.size() - 1] != '+' && currentCalc[currentCalc.size() - 1] != '-' && currentCalc[currentCalc.size() - 1] != '.'
					&& currentCalc[currentCalc.size() - 1] != '*' && currentCalc[currentCalc.size() - 1] != '/')
					currentCalc += "-";
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 13:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (currentCalc.size() != 0)
				if (currentCalc[currentCalc.size() - 1] != ')' && currentCalc[currentCalc.size() - 1] != '+' && currentCalc[currentCalc.size() - 1] != '-' && currentCalc[currentCalc.size() - 1] != '.'
					&& currentCalc[currentCalc.size() - 1] != '*' && currentCalc[currentCalc.size() - 1] != '/')
					currentCalc += "*";
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 14:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (currentCalc.size() != 0)
				if (currentCalc[currentCalc.size() - 1] != ')' && currentCalc[currentCalc.size() - 1] != '+' && currentCalc[currentCalc.size() - 1] != '-' && currentCalc[currentCalc.size() - 1] != '.'
					&& currentCalc[currentCalc.size() - 1] != '*' && currentCalc[currentCalc.size() - 1] != '/')
					currentCalc += "/";
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 15:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			if (currentCalc.size() == 0 || currentCalc[currentCalc.size() -1] == '+' || currentCalc[currentCalc.size() - 1] == '-' 
				|| currentCalc[currentCalc.size() - 1] == '*'|| currentCalc[currentCalc.size() - 1] == '/' || currentCalc[currentCalc.size() - 1] == '(')
					currentCalc += "(";

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 16:
		{
			if (currentCalc.size() + 1 > MAX_SIZE)
			{
				MessageBox(hWnd, "Calculation oversize! Too much operations/numbers", "exception", message);
				break;
			}

			currentCalc += ")";

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 17:
		{
			currentCalc.clear();

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 18:
		{
			if (currentCalc.size() != 0)
				currentCalc.pop_back();
			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		case 19:
		{
			if (currentCalc.size() != 0)
			{
				std::stringstream oss;
				double result;

				try
				{
					result = calculate_string(currentCalc);
				}
				catch (int code)
				{
					MessageBeep(0);

					if (code == 1)
						MessageBox(hWnd, "Incorrect brackets positioning", "exception", message);
					else if (code == 2)
						MessageBox(hWnd, "Incorrect brackets balance", "exception", message);
					else if (code == 3)
						MessageBox(hWnd, "You can't divide by 0", "exception", message);
					else
						MessageBox(hWnd, "Incorrect operations usage", "exception", message);

					break;
				}
				currentCalc.clear();
				oss << result;
				oss >> currentCalc;
			}

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		}
		default:
		{
			break;
		}
		}
	}
	default:
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	}

	return 0;
}

bool check_zeros(std::string str)
{
	if (str.size() == 0)
		return true;
	else
	{
		bool flag = false;
		int i = str.size() - 1;
		for (; i >= 0 && str[i] != '+' && str[i] != '-' && str[i] != '/'
			&& str[i] != '*'; i--)
		{
			if (str[i] != '0')
			{
				flag = true;
				break;
			}
		}
		if (flag || i == str.size() - 1)
			return true;
	}
	return false;
}

bool check_points(std::string str)
{
	int i = str.size() - 1;

	for (; i >= 0 && str[i] != '+' && str[i] != '-' && str[i] != '/'
		&& str[i] != '*'; i--)
	{
		if (str[i] == '.')
			return false;
	}
	return true;
}