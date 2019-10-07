#include <iostream>
#include "ModeEncoding.h"
#include "DataEncoding.h"
#include "BasicInfo.h"
using namespace std;
#include "Tool.h"
using namespace qrcode;
int main(){
	qrcode::ModeEncoding e;
	string x=e.Encode("01234567", qrcode::mode::Number_Mode);
	cout << (1 & 0);
//	string x= decimal_to_binary(123);
	qrcode::BasicInfo *p=new qrcode::BasicInfo(1,mode::Number_Mode,level::Correction_M);
	qrcode::DataEncoding c;
	c.setBasicInfo(p);
	std::string m=c.Encode("01234567");
	std::cout<<c.getBasicInfo()->getLevel();
	
	int y = 0;
	cin >> y;

}