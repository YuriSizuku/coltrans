
// coltransDlg.h : 头文件
//

#pragma once
#include "colcovert.h"
#include "coltype.h"
#include "strutil.h"
#define BUF_SIZE 200
#define SAVE_PATH "colorlog.txt"

// CcoltransDlg 对话框
class CcoltransDlg : public CDialogEx
{
// 构造
public:
	CcoltransDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_COLTRANS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	COLRGB m_colrgb;
	bool m_isCapture;

	//刷新函数(通过m_colrgb转换为各个值填入输入框中)
	void updateShowColor();
	void updateRGBdex();
	void updateRGBhex();
	void updateYUV();
	void updateCMY();
	void updateHSV();
	void updateHSL();
	void updateAll(int exception=0);

	void fromInfo(char *buf);

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedColorview();
	afx_msg void OnStnClickedPicarcher();
	afx_msg void OnBnClickedButtonCopy();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnEnChangeEditRgbhex();
	afx_msg void OnEnChangeEditRgbr();
	afx_msg void OnEnChangeEditRgbg();
	afx_msg void OnEnChangeEditRgbb();
	afx_msg void OnEnChangeEditYuvy();
	afx_msg void OnEnChangeEditYuvu();
	afx_msg void OnEnChangeEditYuvv();
	afx_msg void OnEnChangeEditCmyc();
	afx_msg void OnEnChangeEditCmym();
	afx_msg void OnEnChangeEditCmyy();
	afx_msg void OnEnChangeEditHsvh();
	afx_msg void OnEnChangeEditHsvs();
	afx_msg void OnEnChangeEditHsvv();
	afx_msg void OnEnChangeEditHslh();
	afx_msg void OnEnChangeEditHsls();
	afx_msg void OnEnChangeEditHsll();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonRgbhexupdate();
	afx_msg void OnBnClickedButtonRgbdexupdate();
	afx_msg void OnBnClickedButtonYuvupdate();
	afx_msg void OnBnClickedButtonCmyupdate();
	afx_msg void OnBnClickedButtonHsvupdate();
	afx_msg void OnBnClickedButtonHslupdate();
};
