#include <iostream>
#include "ModeEncoding.h"
#include "DataEncoding.h"
#include "BasicInfo.h"
#include "CorrectionEncoding.h"
#include "Tool.h"
#include "QRCodePaint.h"
#include "Combination.h"
using namespace std;

using namespace qrcode;
//int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode){
//	QRCodePaint p(hThisInst);
//	p.ShowDialogBox(NULL);
//
//}
//int main(){
//	qrcode::ModeEncoding e;
//	string x=e.Encode("01234567", qrcode::mode::Number_Mode);
//	cout << (1 & 0);
////	string x= decimal_to_binary(123);
//	qrcode::BasicInfo *p=new qrcode::BasicInfo(1,mode::Number_Mode,level::Correction_M);
//	qrcode::DataEncoding c;
//	c.setBasicInfo(p);
//	std::string m=c.Encode("01234567");
//	CorrectionEncoding ppp;
//	ppp.setBasicInfo(p);
//	string aaaaa =ppp.Encode(m);
//	//string aaaaa =ppp.Encode("00100000010110110000101101111000110100010111001011011100010011010100001101000000111011000001000111101100000100011110110000010001");
//	int y = 0;
//	cin >> y;
//
//}
int main(){
	qrcode::BasicInfo *p = new qrcode::BasicInfo(1, mode::Number_Mode, level::Correction_M);
	qrcode::Combination c;
	c.setBasicInfo(p);
	c.caculatePolynomeAlpha();
	for (int i = 0; i < 77777; i++){
		for (int j = 0; j < 2431; j++){
			std::cout << i + j;
		}
	}
	int x;
	cin >> x;
}