#include "framework.h"
#include "Core.h"


Core::Core(HWND G_hWnd)
{
	//int i;

	//m_hWnd = hWnd;
	//m_bF1pressed = m_bF12pressed = FALSE;

	//m_iAutoShutdownCount = 10;

	//// v2.17 2002-6-3 고광현 수정 
	//m_iBuildDate = 0;

	//for (i = 0; i < DEF_MAXCLIENTS; i++)
	//	m_pClientList[i] = NULL;

	//for (i = 0; i < DEF_MAXMONITORS; i++)
	//	m_cMonitorStatus[i] = NULL;

	//memset(m_cAddress, 0, 10 * 16);

	//iTotalWorldServerClients = 0;

	//m_pPartyManager = new class PartyManager(this);
}

Core::~Core()
{
	/*int i;

	G_bThreadFlag = FALSE;

	for (i = 0; i < DEF_MAXCLIENTS; i++)
		if (m_pClientList[i] != NULL)
		{
			delete m_pClientList[i];
			m_pClientList[i] = NULL;
		}

	delete m_pPartyManager;
}*/
};

void Core::OnKeyDown(WPARAM wParam, LPARAM lParam)
{
	switch (wParam) {
	case VK_F1:
		DrawScreen("Test", NULL);

		//m_bF1pressed = TRUE;
		break;

	//case VK_F12:
	//	m_bF12pressed = TRUE;
	//	break;
	}
}

void Core::OnKeyUp(WPARAM wParam, LPARAM lParam)
{
	int i, iCnt;
	char cTxt[120];

	switch (wParam) {
	//case VK_F1:
	//	m_bF1pressed = FALSE;
	//	break;

	//	// v2.17 2002-6-3 고광현수정 
	//case VK_F2:
	//	// 등록되었지만 Activated되지 않은 게임 서버의 리스트를 출력한다.
	//	PutLogList(" ");
	//	iCnt = 0;
	//	for (i = 1; i < DEF_MAXCLIENTS; i++)
	//		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsGameServer == TRUE) && (m_pClientList[i]->m_sIsActivated <= 0)) {

	//			if (m_pClientList[i]->m_sIsActivated == 0)
	//				wsprintf(cTxt, "(X) Server(%s) Registered but not activated.", m_pClientList[i]->m_cName);
	//			else if (m_pClientList[i]->m_sIsActivated == -1)
	//				wsprintf(cTxt, "(X) Server(%s) build date mismatch !", m_pClientList[i]->m_cName);
	//			else if (m_pClientList[i]->m_sIsActivated == -2)
	//				wsprintf(cTxt, "(X) Server(%s) have Same Game Name !", m_pClientList[i]->m_cName);

	//			PutLogList(cTxt);
	//			iCnt++;
	//		}
	//	wsprintf(cTxt, "%d servers are not activated.", iCnt);
	//	PutLogList(cTxt);
	//	break;

	//case VK_F3:
	//	// 작동중인 서버 리스트를 보인다.
	//	PutLogList(" ");
	//	iCnt = 0;
	//	for (i = 1; i < DEF_MAXCLIENTS; i++)
	//		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsGameServer == TRUE) && (m_pClientList[i]->m_sIsActivated > 0)) {
	//			wsprintf(cTxt, "(!) Server(%s) activated.", m_pClientList[i]->m_cName);
	//			PutLogList(cTxt);
	//			iCnt++;
	//		}
	//	wsprintf(cTxt, "%d servers are activated.", iCnt);
	//	PutLogList(cTxt);
	//	break;
	//	// 여기까지

	//case VK_F4:
	//	// Auto-Shut down process
	//	if (m_bF1pressed == TRUE) {

	//		m_iAutoShutdownCount = 10;
	//		m_dwAutoShutdownTime = timeGetTime();

	//		for (i = 1; i < DEF_MAXCLIENTS; i++)
	//			if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsGameServer == TRUE))
	//				m_pClientList[i]->m_bIsShutDown = TRUE;

	//		PutLogList(" ");
	//		PutLogList("(!) AUTO SHUTDOWN PROCESS STARTED!");
	//	}
	//	break;

	//	/*	case VK_F5:
	//			// for Test
	//			PutLogList("(!) Testing Monitor activity...");
	//			SendMsgToMonitor(MSGID_GAMESERVERDOWN, DEF_MSGTYPE_CONFIRM, m_pClientList[i]->m_cName);
	//			break;
	//	*/
	//case VK_F6:
	//	if (m_bF1pressed == TRUE) {

	//		PutLogList("(!) Send Server shutdown Message-1");
	//		SendServerShutDownMsg(1, TRUE);
	//		break;
	//	}

	//case VK_F7:
	//	if (m_bF1pressed == TRUE) {

	//		PutLogList("(!) Send Server shutdown Message-2");
	//		SendServerShutDownMsg(2, TRUE);
	//		break;
	//	}

	//case VK_F12:
	//	m_bF12pressed = FALSE;
	//	break;
	}
}

