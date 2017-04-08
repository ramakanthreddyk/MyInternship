
// ModelControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ModelControl.h"
#include "ModelControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModelControlDlg dialog



CModelControlDlg::CModelControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MODELCONTROL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CModelControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PORT, m_edit_port);
	DDX_Control(pDX, IDC_BUTTON_CONNECT, m_btn_connect);
	DDX_Control(pDX, IDC_BUTTON_DISCONNECT, m_btn_disconnect);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_static_status);
	DDX_Control(pDX, IDC_BUTTON_LEFT, m_btn_left);
	DDX_Control(pDX, IDC_BUTTON_RIGHT, m_btn_right);
	DDX_Control(pDX, IDC_BUTTON_FORWARD, m_btn_forward);
	DDX_Control(pDX, IDC_BUTTON_BACKWARD, m_btn_backward);
	DDX_Control(pDX, IDC_BUTTON_STOPM, m_btn_stopm);
	DDX_Control(pDX, IDC_EDIT_BOARD, m_Edit_Board);
	DDX_Control(pDX, IDC_IPADDRESS, m_ipaddress);
	DDX_Control(pDX, IDC_COMBO_CARS, m_cars);
	DDX_Control(pDX, IDC_BUTTON_MID, m_btn_mid);
	DDX_Control(pDX, IDC_RADIO_OFFLINE, m_radio_offline);
	DDX_Control(pDX, IDC_COMBO_LIGHT, m_light);
	DDX_Control(pDX, IDC_BUTTON_ST_IDCS, m_btn_stop_idc);
	DDX_Control(pDX, IDC_BUTTON_RIGHTIDC, m_btn_right_idc);
	DDX_Control(pDX, IDC_BUTTON_LEFTIDC, m_btn_left_idc);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_edit_username);
	DDX_Control(pDX, IDC_EDIT_PSW, m_edit_password);
	DDX_Control(pDX, IDC_HwConnection, m_hwConnection);
	DDX_Control(pDX, IDC_BUTTON_HAZARD, m_btn_hazard);
	DDX_Control(pDX, IDC_CHECK_BEAM, m_btn_beamcheck);
	DDX_Control(pDX, IDC_CHECK_DAYLIGHT, m_btn_daylightcheck);
	DDX_Control(pDX, IDC_COMBO_WEATHER, m_weather);
	DDX_Control(pDX, IDC_EDIT_TEMP, m_edit_temp);
}

BEGIN_MESSAGE_MAP(CModelControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CModelControlDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CModelControlDlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_FORWARD, &CModelControlDlg::OnBnClickedButtonForward)
	ON_BN_CLICKED(IDC_BUTTON_BACKWARD, &CModelControlDlg::OnBnClickedButtonBackward)
	ON_BN_CLICKED(IDC_BUTTON_STOPM, &CModelControlDlg::OnBnClickedButtonStopm)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CModelControlDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CModelControlDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_RADIO_ONLINE, &CModelControlDlg::OnBnClickedRadioOnline)
	ON_BN_CLICKED(IDC_RADIO_OFFLINE, &CModelControlDlg::OnBnClickedRadioOffline)
	ON_CBN_SELCHANGE(IDC_COMBO_CARS, &CModelControlDlg::OnCbnSelchangeComboCars)
	ON_BN_CLICKED(IDC_BUTTON_MID, &CModelControlDlg::OnBnClickedButtonMid)
	ON_CBN_SELCHANGE(IDC_COMBO_LIGHT, &CModelControlDlg::OnCbnSelchangeComboLight)
	ON_BN_CLICKED(IDC_BUTTON_LEFTIDC, &CModelControlDlg::OnBnClickedButtonLeftidc)
	ON_BN_CLICKED(IDC_BUTTON_RIGHTIDC, &CModelControlDlg::OnBnClickedButtonRightidc)
	ON_BN_CLICKED(IDC_BUTTON_ST_IDCS, &CModelControlDlg::OnBnClickedButtonStIdcs)
	ON_BN_CLICKED(IDC_BUTTON_HAZARD, &CModelControlDlg::OnBnClickedButtonHazard)
	ON_BN_CLICKED(IDC_CHECK_BEAM, &CModelControlDlg::OnBnClickedCheckBeam)
	ON_BN_CLICKED(IDC_CHECK_DAYLIGHT, &CModelControlDlg::OnBnClickedCheckDaylight)
	ON_CBN_SELCHANGE(IDC_COMBO_WEATHER, &CModelControlDlg::OnCbnSelchangeComboWeather)
END_MESSAGE_MAP()


// CModelControlDlg message handlers

BOOL CModelControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// Initialize combo box
	m_cars.AddString(_T("Yellow Car"));
	m_cars.AddString(_T("Black Car"));
	m_cars.SetCurSel(1);
	m_light.AddString(_T("Day"));
	m_light.AddString(_T("Night"));
	m_light.SetCurSel(0);
	m_weather.SetCurSel(0);

	// Initialize GUI
	m_radio_offline.SetCheck(BST_CHECKED);
	UpdateButtonStatus(FALSE, FALSE);
	m_static_status.SetWindowText(_T("Disconnected"));
	m_ipaddress.EnableWindow(FALSE);
	m_edit_port.EnableWindow(FALSE);
	m_edit_username.EnableWindow(FALSE);
	m_edit_password.EnableWindow(FALSE);
	m_hwConnection.EnableWindow(FALSE);
	m_hwConnection.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_LedRed),
		IMAGE_ICON, 18, 18, LR_DEFAULTCOLOR));
	m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_BeamlightOFF),
		IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
	m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_DaytimelightOFF),
		IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
	m_btn_forward.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_Forward),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR));
	m_btn_backward.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_Backward),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR));
	m_btn_left.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_Left),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR));
	m_btn_right.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_Right),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR));
	m_btn_mid.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_Mid),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR));
	m_btn_stopm.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_Stop),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR));
	
	// reset the counter of sending out packet
	SendPacket.PacketNumber = 0;

	CRect rect;
	// Get size and position of the picture control
	GetDlgItem(IDC_OPENGL)->GetWindowRect(rect);

	// Convert screen coordinates to client coordinates
	ScreenToClient(rect);

	// Create OpenGL Control window
	m_oglWindow.oglCreate(rect, this);

	// Setup the OpenGL Window's timer to render
	m_oglWindow.m_unpTimer = m_oglWindow.SetTimer(1, 1, 0);

	

	////////////////////////////////////////////////////////////

	return TRUE;  // return TRUE  unless you set the focus to a control
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CModelControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CModelControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CModelControlDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	switch (nType)
	{
	case SIZE_RESTORED:
	{
		if (m_oglWindow.m_bIsMaximized)
		{
			m_oglWindow.OnSize(nType, cx, cy);
			m_oglWindow.m_bIsMaximized = false;
		}
		break;
	}

	case SIZE_MAXIMIZED:
	{
		m_oglWindow.OnSize(nType, cx, cy);
		m_oglWindow.m_bIsMaximized = true;

		break;
	}
	}
}

void CModelControlDlg::OnCbnSelchangeComboCars()
{
	// TODO: Add your control notification handler code here
	m_oglWindow.carID = m_cars.GetCurSel();
	switch (m_oglWindow.carID)
	{
	case 0:
	{
		if (m_oglWindow.b_beamlight)
		{
			m_btn_beamcheck.SetCheck(BST_CHECKED);
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Beamlight),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
		else
		{
			m_btn_beamcheck.SetCheck(BST_UNCHECKED);
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_BeamlightOFF),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
		if (m_oglWindow.b_daytimelight)
		{
			m_btn_daylightcheck.SetCheck(BST_CHECKED);
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Daytimelight),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
		else
		{
			m_btn_daylightcheck.SetCheck(BST_UNCHECKED);
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_DaytimelightOFF),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
		break;
	}
	case 1:
	{
		if (m_oglWindow.y_beamlight)
		{
			m_btn_beamcheck.SetCheck(BST_CHECKED);
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Beamlight),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
		else
		{
			m_btn_beamcheck.SetCheck(BST_UNCHECKED);
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_BeamlightOFF),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
		if (m_oglWindow.y_daytimelight)
		{
			m_btn_daylightcheck.SetCheck(BST_CHECKED);
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Daytimelight),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
		else
		{
			m_btn_daylightcheck.SetCheck(BST_UNCHECKED);
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_DaytimelightOFF),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
		break;
	}
	default:
		break;
	}
	
}

void CModelControlDlg::OnCbnSelchangeComboLight()
{
	// TODO: Add your control notification handler code here
	m_oglWindow.lightID = m_light.GetCurSel();
	
}

void CModelControlDlg::OnCbnSelchangeComboWeather()
{
	// TODO: Add your control notification handler code here
	m_oglWindow.weatherID = m_weather.GetCurSel();
}

void CModelControlDlg::OnBnClickedButtonLeftidc()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
	case 0:
	{
		m_oglWindow.SetTimer(4, 500, 0);
		m_oglWindow.KillTimer(5);
		m_oglWindow.b_countR = 0;
		break;
	}
	case 1:
	{
		m_oglWindow.SetTimer(2, 500, 0);
		m_oglWindow.KillTimer(3);
		m_oglWindow.y_countR = 0;
		break;
	}
		
	default:
		break;
	}
	

}

void CModelControlDlg::OnBnClickedButtonRightidc()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
	case 0:
	{
		m_oglWindow.SetTimer(5, 500, 0);
		m_oglWindow.KillTimer(4);
		m_oglWindow.b_countL = 0;
		break;
	}
	case 1:
	{
		m_oglWindow.SetTimer(3, 500, 0);
		m_oglWindow.KillTimer(2);
		m_oglWindow.y_countL = 0;
		break;
	}
	default:
		break;
	}
}

void CModelControlDlg::OnBnClickedButtonStIdcs()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
	case 0:
	{
		m_oglWindow.KillTimer(4);
		m_oglWindow.KillTimer(5);
		m_oglWindow.b_countL = 0;
		m_oglWindow.b_countR = 0;
		break;
	}
	case 1:
	{
		m_oglWindow.KillTimer(2);
		m_oglWindow.KillTimer(3);
		m_oglWindow.y_countL = 0;
		m_oglWindow.y_countR = 0;
		break;
	}

	default:
		break;
	}
}

void CModelControlDlg::OnBnClickedButtonHazard()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
	case 0:
	{
		m_oglWindow.b_countL = 0;
		m_oglWindow.b_countR = 0;
		m_oglWindow.SetTimer(4, 500, 0);
		m_oglWindow.SetTimer(5, 500, 0);
	}
	case 1:
	{
		m_oglWindow.y_countL = 0;
		m_oglWindow.y_countR = 0;
		m_oglWindow.SetTimer(2, 500, 0);
		m_oglWindow.SetTimer(3, 500, 0);
	}
	}
}

void CModelControlDlg::OnBnClickedCheckBeam()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
	case 0:
	{
		if (m_btn_beamcheck.GetCheck())
		{
			m_oglWindow.b_beamlight = TRUE;
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Beamlight),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
		else
		{
			m_oglWindow.b_beamlight = FALSE;
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_BeamlightOFF),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
	}
	case 1:
	{
		if (m_btn_beamcheck.GetCheck())
		{
			m_oglWindow.y_beamlight = TRUE;
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Beamlight),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
		else
		{
			m_oglWindow.y_beamlight = FALSE;
			m_btn_beamcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_BeamlightOFF),
				IMAGE_ICON, 64, 64, LR_DEFAULTCOLOR));
		}
	}
	}
}

void CModelControlDlg::OnBnClickedCheckDaylight()
{
	switch (m_oglWindow.carID)
	{
	case 0:
	{
		if (m_btn_daylightcheck.GetCheck())
		{
			m_oglWindow.b_daytimelight = TRUE;
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Daytimelight),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
		else
		{
			m_oglWindow.b_daytimelight = FALSE;
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_DaytimelightOFF),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
	}
	case 1:
	{
		if (m_btn_daylightcheck.GetCheck())
		{
			m_oglWindow.y_daytimelight = TRUE;
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_Daytimelight),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
		else
		{
			m_oglWindow.y_daytimelight = FALSE;
			m_btn_daylightcheck.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_DaytimelightOFF),
				IMAGE_ICON, 48, 48, LR_DEFAULTCOLOR));
		}
	}
	}
}


void CModelControlDlg::OnBnClickedButtonLeft()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
		case 0:
		{
			m_oglWindow.b_sp_steering = 0.5f;
			m_oglWindow.b_left = -35.0;
			m_oglWindow.b_status = 1;
			break;
		}

		case 1:
		{
			m_oglWindow.y_sp_steering = 0.5f;
			m_oglWindow.y_left = -35.0;
			m_oglWindow.y_status = 1;
			break;
		}

		default:
			break;
	}

}


void CModelControlDlg::OnBnClickedButtonRight()
{
	// TODO: Add your control notification handler code here

	switch (m_oglWindow.carID)
	{
		case 0:
		{
			m_oglWindow.b_sp_steering = -0.5f;
			m_oglWindow.b_right = 35.0;
			m_oglWindow.b_status = 2;
			break;
		}

		case 1:
		{
			m_oglWindow.y_sp_steering = -0.5f;
			m_oglWindow.y_right = 35.0;
			m_oglWindow.y_status = 2;
			break;
		}

		default:
			break;
	}

}


void CModelControlDlg::OnBnClickedButtonMid()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
		case 0:
		{
			if (m_oglWindow.b_steeringAngle != 0)
				m_oglWindow.b_sp_steering = -m_oglWindow.b_sp_steering;
			else
				m_oglWindow.b_sp_steering = 0;
			if (m_oglWindow.b_status == 1)
				m_oglWindow.b_right = 0;
			else if (m_oglWindow.b_status == 2)
				m_oglWindow.b_left = 0;

			break;
		}

		case 1:
		{
			if (m_oglWindow.y_steeringAngle != 0)
				m_oglWindow.y_sp_steering = -m_oglWindow.y_sp_steering;
			else
				m_oglWindow.y_sp_steering = 0;
			if (m_oglWindow.y_status == 1)
				m_oglWindow.y_right = 0;
			else if (m_oglWindow.y_status == 2)
				m_oglWindow.y_left = 0;

			break;
		}

		default:
			break;
	}
}

void CModelControlDlg::OnBnClickedButtonForward()
{
	// TODO: Add your control notification handler code here
	
	switch (m_oglWindow.carID)
	{
		case 0:
		{
			m_oglWindow.b_sp_trans = 4 / m_oglWindow.Framerate;
			m_oglWindow.b_sp_wRotate = 180 / m_oglWindow.Framerate;
			
			break;
		}

		case 1:
		{
			m_oglWindow.y_sp_trans = 4 / m_oglWindow.Framerate;
			m_oglWindow.y_sp_wRotate = 180 / m_oglWindow.Framerate;
			
			break;
		}

		default:
			break;
	}
	
}


void CModelControlDlg::OnBnClickedButtonBackward()
{
	// TODO: Add your control notification handler code here
	switch (m_oglWindow.carID)
	{
		case 0:
		{
			m_oglWindow.b_sp_trans = -4 / m_oglWindow.Framerate;
			m_oglWindow.b_sp_wRotate = -180 / m_oglWindow.Framerate;
			
			break;
		}

		case 1:
		{
			m_oglWindow.y_sp_trans = -4 / m_oglWindow.Framerate;
			m_oglWindow.y_sp_wRotate = -180 / m_oglWindow.Framerate;
			
			break;
		}

		default:
			break;
	}
}

void CModelControlDlg::OnBnClickedButtonStopm()
{
	// TODO: Add your control notification handler code here
	
	switch (m_oglWindow.carID)
	{
		case 0:
		{
			m_oglWindow.b_countBrake = 1;
			m_oglWindow.b_sp_trans = 0.0f;
			m_oglWindow.b_sp_wRotate = 0.0f;
			m_oglWindow.SetTimer(6, 100, 0);
			break;
		}

		case 1:
		{
			m_oglWindow.y_countBrake = 1;
			m_oglWindow.y_sp_trans = 0.0f;
			m_oglWindow.y_sp_wRotate = 0.0f;
			m_oglWindow.SetTimer(7, 100, 0);
			break;
		}

		default:
			break;
	}
}



////////////////////////////////////////////////////
//               ONLINE MODE                      //
////////////////////////////////////////////////////

void CModelControlDlg::OnBnClickedButtonConnect()
{
	// TODO: Add your control notification handler code here

	// Obtain the server address, port, and user ID from GUI
	m_ipaddress.GetWindowText(strIP, 20);
	m_edit_port.GetWindowText(strPort, 10);
	nPort = _wtoi(strPort);
	//m_edit_userID.GetWindowText(SendPacket.UserID, sizeof(SendPacket.UserID));

	// set up local socket and connect to server socket
	if (ConnectSocket(strIP, nPort))
	{
		Send();  // send the username and password
		UpdateButtonStatus(FALSE, TRUE);
	}
	else
		UpdateButtonStatus(TRUE, FALSE);
}


void CModelControlDlg::OnBnClickedButtonDisconnect()
{
	// TODO: Add your control notification handler code here

	// Set the connection status to disconnect,
	SendPacket.ConnectStatus = 0;

	// USTEP 4.a: send the goodbye packet to disconnect
	m_pSocket->Send((BYTE*)&SendPacket, sizeof(Packet), 0);
	// USTEP 4.b: Close the socket
	if (m_pSocket != NULL) {
		m_pSocket->Close();
	}

	// delete local socket
	delete m_pSocket;
	m_pSocket = NULL;

	// Update the status of GUI
	UpdateButtonStatus(TRUE, FALSE);
	m_static_status.SetWindowText(_T("Disconnected"));
	m_hwConnection.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_LedRed),
		IMAGE_ICON, 18, 18, LR_DEFAULTCOLOR));
}

BOOL CModelControlDlg::ConnectSocket(LPCTSTR lpszAddress, UINT nPort)
{
	m_pSocket = new CClientSocket(this);

	// USTEP 1: Create local socket
	if (!m_pSocket->Create())
	{
		delete m_pSocket;
		m_pSocket = NULL;
		MessageBox(TEXT("Fail to create new socket"));
		return FALSE;
	}

	// USTEP 2: Connect to server
	while (!m_pSocket->Connect(lpszAddress, nPort)) 
	{
		MessageBox(TEXT("Fail to connect"));
		delete m_pSocket;
		m_pSocket = NULL;
		return FALSE;
	}

	// update GUI
	m_static_status.SetWindowText(_T("Connected"));
	return TRUE;
}

void CModelControlDlg::ProcessPendingRead(void)
{
	int nRead;
	CString strBuf;
	int id, data;

	// USTEP-3 (R): get the received packet
	nRead = m_pSocket->Receive(&RecvPacket, sizeof(Packet));
	if (nRead > 0) 
	{
		if (RecvPacket.ConnectStatus == 0) // if the other party disconnects
		{
			// USTEP-4: close socket
			if (m_pSocket != NULL)
			{
				m_pSocket->Close();
			}

			delete m_pSocket;
			m_pSocket = NULL;

			// update GUI
			UpdateButtonStatus(TRUE, FALSE);
			m_static_status.SetWindowText(_T("Server Disconnected"));
			m_hwConnection.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
				MAKEINTRESOURCE(IDI_ICON_LedRed),
				IMAGE_ICON, 18, 18, LR_DEFAULTCOLOR));
		}
		else if (RecvPacket.ConnectStatus == 2)
		{
			
			// Set the connection status to wrong username or password
			SendPacket.ConnectStatus = 2;

			// USTEP 4.a: send the goodbye packet to disconnect
			m_pSocket->Send((BYTE*)&SendPacket, sizeof(Packet), 0);
			// USTEP 4.b: Close the socket
			if (m_pSocket != NULL) 
			{
				m_pSocket->Close();
			}

			// delete local socket
			delete m_pSocket;
			m_pSocket = NULL;

			// Update the status of GUI
			UpdateButtonStatus(TRUE, FALSE);
			// update GUI
			m_static_status.SetWindowText(_T("Wrong username or password"));

			MessageBox(TEXT("Wrong username or password"));

			
		}
		else {
			// read the message
			strBuf = RecvPacket.Message;

			// paste the message to displaying area
			BoardMessage = strBuf;
			m_Edit_Board.SetWindowText(BoardMessage);
			m_static_status.SetWindowText(_T("Received"));

			// check commands		
			if (strBuf == "carstands")
			{
				m_hwConnection.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
					MAKEINTRESOURCE(IDI_ICON_LedGreen),
					IMAGE_ICON, 18, 18, LR_DEFAULTCOLOR));
			}
			if (strBuf == "ll")
				OnBnClickedButtonLeft();
			if (strBuf == "rr")
				OnBnClickedButtonRight();
			if (strBuf == "mm")
				OnBnClickedButtonMid();
			if (strBuf == "ff")
				OnBnClickedButtonForward();
			if (strBuf == "bb")
				OnBnClickedButtonBackward();
			if (strBuf == "ss")
				OnBnClickedButtonStopm();
			if (strBuf == "enginestops")
				OnBnClickedButtonStopm();
			
			if (strBuf.GetAt(4) == 'L')
				OnBnClickedButtonLeftidc();
			else if (strBuf.GetAt(3) == 'R')
				OnBnClickedButtonRightidc();
			else if (strBuf.GetAt(2) == 'H')
				OnBnClickedButtonHazard();
			else
				OnBnClickedButtonStIdcs();
			
			if (strBuf.GetAt(1) == 'B')
			{
				switch (m_oglWindow.carID)
				{
				case 0:
				{
					m_oglWindow.b_beamlight = TRUE;
					break;
				}
				case 1:
				{
					m_oglWindow.y_beamlight = TRUE;
					break;
				}
				default:
					break;
				}
			}
			else
			{
				switch (m_oglWindow.carID)
				{
				case 0:
				{
					m_oglWindow.b_beamlight = FALSE;
					break;
				}
				case 1:
				{
					m_oglWindow.y_beamlight = FALSE;
					break;
				}
				default:
					break;
				}
			}

			if (strBuf.GetAt(0) == 'D')
			{
				switch (m_oglWindow.carID)
				{
				case 0:
				{
					m_oglWindow.b_daytimelight = TRUE;
					break;
				}
				case 1:
				{
					m_oglWindow.y_daytimelight = TRUE;
					break;
				}
				default:
					break;
				}
			}
			else
			{
				switch (m_oglWindow.carID)
				{
				case 0:
				{
					m_oglWindow.b_daytimelight = FALSE;
					break;
				}
				case 1:
				{
					m_oglWindow.y_daytimelight = FALSE;
					break;
				}
				default:
					break;
				}
			}


			if (strBuf == "day")
				m_oglWindow.lightID = 0;
			if (strBuf == "night")
				m_oglWindow.lightID = 1;
			if (strBuf == "black")
				m_oglWindow.carID = 0;
			if (strBuf == "yellow")
				m_oglWindow.carID = 1;
	
		}
	}
}

void CModelControlDlg::UpdateButtonStatus(bool bConnect, bool bDisconnect)
{
	m_btn_connect.EnableWindow(bConnect);
	m_btn_disconnect.EnableWindow(bDisconnect);

	
}

void CModelControlDlg::Send()
{
	// Prepare the packet
	// set up the serial number of the current pakcet
	SendPacket.PacketNumber++;
	// obtain the message from the input panel and move data to packet
	m_edit_username.GetWindowText(SendPacket.Username, 20);
	m_edit_password.GetWindowText(SendPacket.Message, 100);

	// set the connection status as active (1)
	SendPacket.ConnectStatus = 1;
	// USTEP-3 (S): send the whole packet
	m_pSocket->Send((BYTE*)&SendPacket, sizeof(Packet), 0);
}

void CModelControlDlg::OnBnClickedRadioOnline()
{
	// TODO: Add your control notification handler code here
	m_btn_left.EnableWindow(FALSE);
	m_btn_right.EnableWindow(FALSE);
	m_btn_mid.EnableWindow(FALSE);
	m_btn_forward.EnableWindow(FALSE);
	m_btn_backward.EnableWindow(FALSE);
	m_btn_stopm.EnableWindow(FALSE);
	m_light.EnableWindow(FALSE);
	m_weather.EnableWindow(FALSE);
	m_btn_right_idc.EnableWindow(FALSE);
	m_btn_left_idc.EnableWindow(FALSE);
	m_btn_stop_idc.EnableWindow(FALSE);
	m_btn_hazard.EnableWindow(FALSE);
	m_btn_beamcheck.EnableWindow(FALSE);
	m_btn_daylightcheck.EnableWindow(FALSE);

	UpdateButtonStatus(TRUE, FALSE);
	m_ipaddress.EnableWindow(TRUE);
	m_edit_port.EnableWindow(TRUE);
	m_edit_username.EnableWindow(TRUE);
	m_edit_password.EnableWindow(TRUE);
	m_hwConnection.EnableWindow(TRUE);
	m_static_status.SetWindowText(_T("Please specify IP, Port, Username and Password"));

}


void CModelControlDlg::OnBnClickedRadioOffline()
{
	// TODO: Add your control notification handler code here
	m_btn_left.EnableWindow(TRUE);
	m_btn_right.EnableWindow(TRUE);
	m_btn_mid.EnableWindow(TRUE);
	m_btn_forward.EnableWindow(TRUE);
	m_btn_backward.EnableWindow(TRUE);
	m_btn_stopm.EnableWindow(TRUE);
	m_btn_hazard.EnableWindow(TRUE);
	m_btn_daylightcheck.EnableWindow(TRUE);
	m_light.EnableWindow(TRUE);
	m_weather.EnableWindow(TRUE);
	m_btn_right_idc.EnableWindow(TRUE);
	m_btn_left_idc.EnableWindow(TRUE);
	m_btn_stop_idc.EnableWindow(TRUE);
	m_btn_beamcheck.EnableWindow(TRUE);
	m_edit_username.EnableWindow(FALSE);
	m_edit_password.EnableWindow(FALSE);
	m_hwConnection.EnableWindow(FALSE);
	m_edit_username.SetWindowText(_T(""));
	m_edit_password.SetWindowText(_T(""));
	m_hwConnection.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_ICON_LedRed),
		IMAGE_ICON, 18, 18, LR_DEFAULTCOLOR));

	// Set the connection status to disconnect,
	SendPacket.ConnectStatus = 0;

	// USTEP 4.a: send the goodbye packet to disconnect
	// USTEP 4.b: Close the socket
	if (m_pSocket != NULL) 
	{
		m_pSocket->Send((BYTE*)&SendPacket, sizeof(Packet), 0);
		m_pSocket->Close();
	}

	// delete local socket
	delete m_pSocket;
	m_pSocket = NULL;

	// Update the status of GUI
	m_static_status.SetWindowText(_T("Disconnected"));

	UpdateButtonStatus(FALSE, FALSE);
	m_ipaddress.EnableWindow(FALSE);
	m_edit_port.EnableWindow(FALSE);	

}




BOOL CModelControlDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL Result = FALSE;

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (m_oglWindow.carID)
		{
		case 0:
		{
			if (pMsg->wParam == 'W')
			{
				m_oglWindow.b_angle += 0.1;
				if (m_oglWindow.b_angle >= 1.57)
					m_oglWindow.b_angle = 1.57;
			}
			if (pMsg->wParam == 'S')
			{
				m_oglWindow.b_angle -= 0.1;
				if (m_oglWindow.b_angle <= 0)
					m_oglWindow.b_angle = 0;
			}
			if (pMsg->wParam == 'A')
			{
				m_oglWindow.b_roll -= 0.1;

			}
			if (pMsg->wParam == 'D')
			{
				m_oglWindow.b_roll += 0.1;

			}
			break;
		}

		case 1:
		{
			if (pMsg->wParam == 'W')
			{
				m_oglWindow.y_angle += 0.1;
				if (m_oglWindow.y_angle >= 1.57)
					m_oglWindow.y_angle = 1.57;
			}
			if (pMsg->wParam == 'S')
			{
				m_oglWindow.y_angle -= 0.1;
				if (m_oglWindow.y_angle <= 0)
					m_oglWindow.y_angle = 0;
			}
			if (pMsg->wParam == 'A')
			{
				m_oglWindow.y_roll -= 0.1;

			}
			if (pMsg->wParam == 'D')
			{
				m_oglWindow.y_roll += 0.1;

			}
			break;
		}

		default:
			break;
		}
		Result = TRUE;
	}

	//if (Result == FALSE)
	//	Result = CDialogEx::PreTranslateMessage(pMsg);
	if (m_radio_offline.GetCheck())
		return Result;
	else
		return CDialogEx::PreTranslateMessage(pMsg);
}
