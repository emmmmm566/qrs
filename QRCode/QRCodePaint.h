#ifndef Paint_H
#define Paint_H
#include <Windows.h>
class QRCodePaint{
public:
	QRCodePaint(HINSTANCE inst);
	~QRCodePaint();
	HINSTANCE m_hInst;
	int ShowDialogBox(HWND hDlg);
	BOOL DoCommand(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	void Paint(HDC hDC,int ** arrs,int side);
private:
	void PaintPixel(HPEN pen, HDC hDC, int x, int y);
};
#endif