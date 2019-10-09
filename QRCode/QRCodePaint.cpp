#include "QRCodePaint.h"
#include "Matrix.h"
#include "BasicInfo.h"
#include "CorrectionEncoding.h"
#include "DataEncoding.h"
#include "QRCodeEncoding.h"
#include"resource.h"
static QRCodePaint * stQRCodePaint;
using namespace qrcode;
QRCodePaint::QRCodePaint(HINSTANCE inst){
	stQRCodePaint = this;
}
QRCodePaint::~QRCodePaint(){

}
LRESULT CALLBACK CodeDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	return(stQRCodePaint->DoCommand(hDlg, message, wParam, lParam));
}
int QRCodePaint::ShowDialogBox(HWND hDlg){
	DialogBox(m_hInst, MAKEINTRESOURCE(IDD_PAINT), hDlg, (DLGPROC)CodeDlgProc);
	return 0;
}
BOOL QRCodePaint::DoCommand(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	switch (message){
	case WM_SYSCOMMAND:
		switch (LOWORD(wParam)){
		case SC_CLOSE:
			EndDialog(hDlg, 0);
			return TRUE;
		}
	case WM_PAINT:{
		HDC hDC;
		PAINTSTRUCT PtStr;
		hDC = BeginPaint(hDlg, &PtStr);

		qrcode::BasicInfo * basic_info = new qrcode::BasicInfo(5, mode::Number_Mode, level::Correction_Q);
		qrcode::DataEncoding de;
		de.setBasicInfo(basic_info);
		std::string data_code=de.Encode("01234567");
		qrcode::CorrectionEncoding ce;
		ce.setBasicInfo(basic_info);
		std::string correct_code = ce.Encode(data_code);
		qrcode::QRCodeEncoding qre;
		qre.setBasicInfo(basic_info);
		qre.Combine(data_code, correct_code);

		qrcode::Matrix m;
		
		m.setBasicInfo(basic_info);
		m.Combine();

		
		
		
		Paint(hDC, m.getMatrix(), qrcode::matrix::getSideLength(basic_info));
		EndPaint(hDlg, &PtStr);
		}
	default:
		break;
	}
	return FALSE;
}
void QRCodePaint::Paint(HDC hDC, int ** qrcode_array, int side_length){
	int pen_pixel = 1;
	HPEN hBlackPen = ::CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hWhitePen = ::CreatePen(PS_SOLID, 1, RGB(255, 255, 255));

	int left_offset = 20;
	int top_offset = 6;

	for (int i = 0; i < side_length; i++){
		for (int j = 0; j < side_length; j++){
			if (qrcode_array[i][j] == 1){
				PaintPixel(hBlackPen, hDC, j + left_offset, i + top_offset);
				//::SelectObject(hDC, hBlackPen);
				//::MoveToEx(hDC, j << pen_pixel, i << pen_pixel, 0);
				//::LineTo(hDC, j << pen_pixel, (i + 1) << pen_pixel);
			}
			else if (qrcode_array[i][j] == 0){
				PaintPixel(hWhitePen, hDC, j + left_offset, i + top_offset);
				//::SelectObject(hDC, hWhitePen);
				//::MoveToEx(hDC, j << pen_pixel, i << pen_pixel, 0);
				//::LineTo(hDC, j << pen_pixel, (i + 1) << pen_pixel);
			}
		}
	}
	::DeleteObject(hBlackPen);
	::DeleteObject(hWhitePen);
}
void QRCodePaint::PaintPixel(HPEN pen, HDC hDC, int x, int y){
	int pixel = 3;
	::SelectObject(hDC, pen);
	int left_top_x = x << pixel;
	int left_top_y = y << pixel;
	int right_bot_x = (x + 1) << pixel;
	int right_bot_y = (y + 1) << pixel;


	//for (int i = 0; i < 16; i++){
	//	cout << (i & 3) << " ";
	//	if ((i & 3) == 3){
	//		cout << endl;
	//	}
	//}

	int loops = 1 << pixel;

	for (int i = 0; i < loops; i++){
		::MoveToEx(hDC, left_top_x + i, left_top_y, 0);
		::LineTo(hDC, left_top_x + i, right_bot_y);
	}

	//for (int j = 0; j < 4; j++){
	//	for (int i = 0; i < 4; i++){
	//		::MoveToEx(hDC, x, y, 0);
	//		::LineTo(hDC, x+j, y+i + 1);
	//	}
	//}



}