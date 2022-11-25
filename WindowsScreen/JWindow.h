#pragma once
#include "Resource.h"
#define MAX_LOADSTRING 100

class JWindow
{
public:
	//winmain instance 값
	HINSTANCE	mhInstance;
	//사용자가 지정한 윈도우 클래스명
	//#
	//응용 프로그램으로 전달된 실행 인자 값.
	LPWSTR	mlpCmdLine;
	//응용 프로그램으로 전달된 메인 윈도우 실행 상태 값
	int				mnCmdShow;
	//주 작업 화면을 담당할 윈도우 핸들 값
	HWND		mHwnd;


	WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
	WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

public:
	// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
	ATOM						MyRegisterClass(HINSTANCE hInstance);
	BOOL						InitInstance(HINSTANCE, int);
	//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
	INT_PTR CALLBACK		About(HWND, UINT, WPARAM, LPARAM);

public:
	//초기화를 담당 
	bool (*Init)();
	//프레임 계산 담당
	bool (*Frame)();
	//렌더링을 담당
	bool (*Render)();
	//메모리 소멸 객체 해제를 담당
	bool (*Release)();
	//시작
	bool Run();
	LRESULT (CALLBACK *WndProc)(HWND, UINT, WPARAM, LPARAM);


public:
	JWindow()
		:mhInstance(nullptr)
		,mlpCmdLine(nullptr)
		,Init(nullptr)
		,Frame(nullptr)
		,Render(nullptr)
		,Release(nullptr)
	{

	}
	virtual ~JWindow()
	{
		
	}
};