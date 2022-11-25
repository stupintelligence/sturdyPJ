#pragma once
#include "Resource.h"
#define MAX_LOADSTRING 100

class JWindow
{
public:
	//winmain instance ��
	HINSTANCE	mhInstance;
	//����ڰ� ������ ������ Ŭ������
	//#
	//���� ���α׷����� ���޵� ���� ���� ��.
	LPWSTR	mlpCmdLine;
	//���� ���α׷����� ���޵� ���� ������ ���� ���� ��
	int				mnCmdShow;
	//�� �۾� ȭ���� ����� ������ �ڵ� ��
	HWND		mHwnd;


	WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
	WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

public:
	// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
	ATOM						MyRegisterClass(HINSTANCE hInstance);
	BOOL						InitInstance(HINSTANCE, int);
	//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
	INT_PTR CALLBACK		About(HWND, UINT, WPARAM, LPARAM);

public:
	//�ʱ�ȭ�� ��� 
	bool (*Init)();
	//������ ��� ���
	bool (*Frame)();
	//�������� ���
	bool (*Render)();
	//�޸� �Ҹ� ��ü ������ ���
	bool (*Release)();
	//����
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