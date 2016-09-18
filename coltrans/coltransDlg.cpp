
// coltransDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "coltrans.h"
#include "coltransDlg.h"
#include "afxdialogex.h"
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcoltransDlg �Ի���




CcoltransDlg::CcoltransDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcoltransDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CcoltransDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcoltransDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_COLORVIEW, &CcoltransDlg::OnStnClickedColorview)
	ON_STN_CLICKED(IDC_PICARCHER, &CcoltransDlg::OnStnClickedPicarcher)
	ON_BN_CLICKED(IDC_BUTTON_COPY, &CcoltransDlg::OnBnClickedButtonCopy)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CcoltransDlg::OnBnClickedButtonSave)
	ON_EN_CHANGE(IDC_EDIT_RGBR, &CcoltransDlg::OnEnChangeEditRgbr)
	ON_EN_CHANGE(IDC_EDIT_RGBG, &CcoltransDlg::OnEnChangeEditRgbg)
	ON_EN_CHANGE(IDC_EDIT_RGBB, &CcoltransDlg::OnEnChangeEditRgbb)
	ON_EN_CHANGE(IDC_EDIT_YUVY, &CcoltransDlg::OnEnChangeEditYuvy)
	ON_EN_CHANGE(IDC_EDIT_YUVU, &CcoltransDlg::OnEnChangeEditYuvu)
	ON_EN_CHANGE(IDC_EDIT_YUVV, &CcoltransDlg::OnEnChangeEditYuvv)
	ON_EN_CHANGE(IDC_EDIT_CMYC, &CcoltransDlg::OnEnChangeEditCmyc)
	ON_EN_CHANGE(IDC_EDIT_CMYM, &CcoltransDlg::OnEnChangeEditCmym)
	ON_EN_CHANGE(IDC_EDIT_CMYY, &CcoltransDlg::OnEnChangeEditCmyy)
	ON_EN_CHANGE(IDC_EDIT_HSVH, &CcoltransDlg::OnEnChangeEditHsvh)
	ON_EN_CHANGE(IDC_EDIT_HSVS, &CcoltransDlg::OnEnChangeEditHsvs)
	ON_EN_CHANGE(IDC_EDIT_HSVV, &CcoltransDlg::OnEnChangeEditHsvv)
	ON_EN_CHANGE(IDC_EDIT_HSLH, &CcoltransDlg::OnEnChangeEditHslh)
	ON_EN_CHANGE(IDC_EDIT_HSLS, &CcoltransDlg::OnEnChangeEditHsls)
	ON_EN_CHANGE(IDC_EDIT_HSLL, &CcoltransDlg::OnEnChangeEditHsll)
	ON_EN_CHANGE(IDC_EDIT_RGBHEX, &CcoltransDlg::OnEnChangeEditRgbhex)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_RGBHEXUPDATE, &CcoltransDlg::OnBnClickedButtonRgbhexupdate)
	ON_BN_CLICKED(IDC_BUTTON_RGBDEXUPDATE, &CcoltransDlg::OnBnClickedButtonRgbdexupdate)
	ON_BN_CLICKED(IDC_BUTTON_YUVUPDATE, &CcoltransDlg::OnBnClickedButtonYuvupdate)
	ON_BN_CLICKED(IDC_BUTTON_CMYUPDATE, &CcoltransDlg::OnBnClickedButtonCmyupdate)
	ON_BN_CLICKED(IDC_BUTTON_HSVUPDATE, &CcoltransDlg::OnBnClickedButtonHsvupdate)
	ON_BN_CLICKED(IDC_BUTTON_HSLUPDATE, &CcoltransDlg::OnBnClickedButtonHslupdate)
END_MESSAGE_MAP()


// CcoltransDlg ��Ϣ�������

BOOL CcoltransDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_isCapture=false;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcoltransDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcoltransDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcoltransDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//ˢ�º���
void CcoltransDlg::updateShowColor()
{
	CStatic *pColview=(CStatic *)this->GetDlgItem(IDC_COLORVIEW);
	CDC *pDC = pColview->GetDC();
	CRect rct;
	pColview->GetWindowRect(&rct);
	CBrush brs;
	brs.CreateSolidBrush(RGB(m_colrgb.r,m_colrgb.g,m_colrgb.b));
	CRect picrct;
	picrct.top = 0;picrct.left = 0;
	picrct.bottom = rct.Height();picrct.right = rct.Width();
	pDC->FillRect(&picrct, &brs); 
}
void CcoltransDlg::updateRGBdex()
{
	this->SetDlgItemInt(IDC_EDIT_RGBR,m_colrgb.r,false);
	this->SetDlgItemInt(IDC_EDIT_RGBG,m_colrgb.g,false);
	this->SetDlgItemInt(IDC_EDIT_RGBB,m_colrgb.b,false);
}
void CcoltransDlg::updateRGBhex()
{
	char buf[BUF_SIZE];
	sprintf(buf,"%02x%02x%02x",m_colrgb.r,m_colrgb.g,m_colrgb.b);
	this->SetDlgItemText(IDC_EDIT_RGBHEX,buf);
}
void CcoltransDlg::updateYUV()
{
	COLYUV yuv;
	rgb2yuv(&m_colrgb,&yuv);
	this->SetDlgItemInt(IDC_EDIT_YUVY,yuv.y,false);
	this->SetDlgItemInt(IDC_EDIT_YUVU,yuv.u,false);
	this->SetDlgItemInt(IDC_EDIT_YUVV,yuv.v,false);
}
void CcoltransDlg::updateCMY()
{
	COLCMY cmy;
	rgb2cmy(&m_colrgb,&cmy);
	this->SetDlgItemInt(IDC_EDIT_CMYC,cmy.c,false);
	this->SetDlgItemInt(IDC_EDIT_CMYM,cmy.m,false);
	this->SetDlgItemInt(IDC_EDIT_CMYY,cmy.y,false);
}
void CcoltransDlg::updateHSV()
{
	COLHSV hsv;
	char buf[BUF_SIZE];
	rgb2hsv(&m_colrgb,&hsv);
	sprintf(buf,"%013.9lf",hsv.h);
	this->SetDlgItemText(IDC_EDIT_HSVH,buf);
	sprintf(buf,"%14.12lf",hsv.s);
	this->SetDlgItemText(IDC_EDIT_HSVS,buf);
	sprintf(buf,"%14.12lf",hsv.v);
	this->SetDlgItemText(IDC_EDIT_HSVV,buf);
}
void CcoltransDlg::updateHSL()
{
	COLHSL hsl;
	char buf[BUF_SIZE];
	rgb2hsl(&m_colrgb,&hsl);
	sprintf(buf,"%013.9lf",hsl.h);
	this->SetDlgItemText(IDC_EDIT_HSLH,buf);
	sprintf(buf,"%14.12lf",hsl.s);
	this->SetDlgItemText(IDC_EDIT_HSLS,buf);
	sprintf(buf,"%14.12lf",hsl.l);
	this->SetDlgItemText(IDC_EDIT_HSLL,buf);
}
void CcoltransDlg::updateAll(int exception)
{
	if(exception!=1)
		updateShowColor();
	if(exception!=2)
		updateRGBdex();
	if(exception!=3)
		updateRGBhex();
	if(exception!=4)
		updateYUV();
	if(exception!=5)
		updateCMY();
	if(exception!=6)
		updateHSV();
	if(exception!=7)
		updateHSL();
}

void CcoltransDlg::fromInfo(char *buf)
{
	char tbuf[BUF_SIZE];
	buf[0]=0;
	strcpy(buf,"#");
	this->GetDlgItemText(IDC_EDIT_RGBHEX,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,"\n");

	strcat(buf,"[RGB] ");
	this->GetDlgItemText(IDC_EDIT_RGBR,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_RGBG,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_RGBB,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,"\n");

	strcat(buf,"[YUV] ");
	this->GetDlgItemText(IDC_EDIT_YUVY,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_YUVU,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_YUVV,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,"\n");

	strcat(buf,"[CMY] ");
	this->GetDlgItemText(IDC_EDIT_CMYC,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_CMYM,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_CMYY,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,"\n");

	strcat(buf,"[HSV] ");
	this->GetDlgItemText(IDC_EDIT_HSVH,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_HSVS,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_HSVV,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,"\n");

	strcat(buf,"[HSL] ");
	this->GetDlgItemText(IDC_EDIT_HSLH,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_HSLS,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,",");
	this->GetDlgItemText(IDC_EDIT_HSLL,tbuf,BUF_SIZE);
	strcat(buf,tbuf);strcat(buf,"\n");
}


void CcoltransDlg::OnStnClickedColorview()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	COLORREF color=RGB(m_colrgb.r,m_colrgb.g,m_colrgb.b);
	CColorDialog colorDlg(0);
	if (IDOK == colorDlg.DoModal())       // ��ʾ��ɫ�Ի��򣬲��ж��Ƿ����ˡ�ȷ����   
    {   
        color = colorDlg.GetColor();      // ��ȡ��ɫ�Ի�����ѡ�����ɫֵ   
		m_colrgb.r=GetRValue(color);
		m_colrgb.g=GetGValue(color);
		m_colrgb.b=GetBValue(color);
    }
	updateAll();
}


void CcoltransDlg::OnStnClickedPicarcher()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_isCapture=true;
	SetCapture();
	HCURSOR hc = LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE (IDC_CURSOR1));
	::SetCursor(hc);//����ȵ�λ����cur�ļ�ȷ��
}


void CcoltransDlg::OnBnClickedButtonCopy()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	fromInfo(buf);
	if(CopyToClipboard(buf))
		MessageBox("copy color information successfully!");
	else
		MessageBox("copy failed!","error");
}


void CcoltransDlg::OnBnClickedButtonSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	int pos=0;
	fromInfo(buf);
	FILE *fp=fopen(SAVE_PATH,"a");
	if(fp==NULL)
	{
		MessageBox("can't open the file!","error");
	}
	while(pos<strlen(buf))
	{
		pos+=fprintf(fp,"%s",&buf[pos]);
	}
	fclose(fp);
}

//�����ı���ı�ĺ�����ʱ����
void CcoltransDlg::OnEnChangeEditRgbhex()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditRgbr()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditRgbg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditRgbb()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditYuvy()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditYuvu()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditYuvv()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditCmyc()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditCmym()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditCmyy()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditHsvh()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditHsvs()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditHsvv()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditHslh()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditHsls()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnEnChangeEditHsll()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcoltransDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(m_isCapture)
	{
		POINT pnt;
		COLORREF color;
		::GetCursorPos(&pnt);
		color=::GetPixel(::GetDC(NULL),pnt.x,pnt.y);//������::GetDC��NULL��
		m_colrgb.r=GetRValue(color);
		m_colrgb.g=GetGValue(color);
		m_colrgb.b=GetBValue(color);
		updateShowColor();
		updateRGBhex();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CcoltransDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(m_isCapture)
	{
		m_isCapture=false;
		ReleaseCapture();
		updateAll();
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CcoltransDlg::OnBnClickedButtonRgbhexupdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	unsigned int col;
	this->GetDlgItemText(IDC_EDIT_RGBHEX,buf,BUF_SIZE);
	if(str2inthex(buf,&col,0,0xffffff)!=0)
		col=0;
	this->m_colrgb.r=col/0x10000;
	this->m_colrgb.g=(col%0x10000)/0x100;
	this->m_colrgb.b=col%0x100;
	updateAll(3);
}


void CcoltransDlg::OnBnClickedButtonRgbdexupdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	int num;
	this->GetDlgItemText(IDC_EDIT_RGBR,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	this->m_colrgb.r=num;
	this->GetDlgItemText(IDC_EDIT_RGBG,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	this->m_colrgb.g=num;
	this->GetDlgItemText(IDC_EDIT_RGBB,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	this->m_colrgb.b=num;
	updateAll(2);
}


void CcoltransDlg::OnBnClickedButtonYuvupdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	COLYUV yuv;
	int num;
	this->GetDlgItemText(IDC_EDIT_YUVY,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	yuv.y=num;
	this->GetDlgItemText(IDC_EDIT_YUVU,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	yuv.u=num;
	this->GetDlgItemText(IDC_EDIT_YUVV,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	yuv.v=num;
	yuv2rgb(&yuv,&m_colrgb);
	updateAll(4);
}


void CcoltransDlg::OnBnClickedButtonCmyupdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	COLCMY cmy;
	int num;
	this->GetDlgItemText(IDC_EDIT_CMYC,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	cmy.c=num;
	this->GetDlgItemText(IDC_EDIT_CMYM,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	cmy.m=num;
	this->GetDlgItemText(IDC_EDIT_CMYY,buf,BUF_SIZE);
	if(str2intdex(buf,&num,0,255)!=0)
		num=0;
	cmy.y=num;
	cmy2rgb(&cmy,&m_colrgb);
	updateAll(5);
}


void CcoltransDlg::OnBnClickedButtonHsvupdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	COLHSV hsv;
	double num;
	this->GetDlgItemText(IDC_EDIT_HSVH,buf,BUF_SIZE);
	if(str2double(buf,&num,0,255)!=0)
		num=0;
	hsv.h=num;
	this->GetDlgItemText(IDC_EDIT_HSVS,buf,BUF_SIZE);
	if(str2double(buf,&num,0,255)!=0)
		num=0;
	hsv.s=num;
	this->GetDlgItemText(IDC_EDIT_HSVV,buf,BUF_SIZE);
	if(str2double(buf,&num,0,255)!=0)
		num=0;
	hsv.v=num;
	hsv2rgb(&hsv,&m_colrgb);
	updateAll(6);
}


void CcoltransDlg::OnBnClickedButtonHslupdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buf[BUF_SIZE];
	COLHSL hsl;
	double num;
	this->GetDlgItemText(IDC_EDIT_HSLH,buf,BUF_SIZE);
	if(str2double(buf,&num,0,255)!=0)
		num=0;
	hsl.h=num;
	this->GetDlgItemText(IDC_EDIT_HSLS,buf,BUF_SIZE);
	if(str2double(buf,&num,0,255)!=0)
		num=0;
	hsl.s=num;
	this->GetDlgItemText(IDC_EDIT_HSLL,buf,BUF_SIZE);
	if(str2double(buf,&num,0,255)!=0)
		num=0;
	hsl.l=num;
	hsl2rgb(&hsl,&m_colrgb);
	updateAll(7);
}