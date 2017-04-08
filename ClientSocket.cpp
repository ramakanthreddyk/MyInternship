// ClientSocket.cpp : implementation file

#include "stdafx.h"
#include "ClientSocket.h"
#include "ModelControl.h"
#include "ModelControlDlg.h"
#include <stddef.h>
#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CClientSocket, CSocket)

CClientSocket::CClientSocket(CModelControlDlg* pDlg)
{
	m_pDlg = pDlg;
}
void CClientSocket::OnReceive(int nErrorCode)
{
	CSocket::OnReceive(nErrorCode);


	// For each OnReceive event, call the following function located
	// in main application class to handle.
	m_pDlg->ProcessPendingRead();

}
