
// ROFLAN_MFC.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CROFLANMFCApp:
// Сведения о реализации этого класса: ROFLAN_MFC.cpp
//

class CROFLANMFCApp : public CWinApp
{
public:
	CROFLANMFCApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CROFLANMFCApp theApp;
