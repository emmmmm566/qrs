#include <iostream>
#include "Mode_Encoding.h"
#include "Data_Encoding.h"
#include "BasicInfo.h"
using namespace std;
#include "Tool.h"
using namespace qrcode::tool;
int main(){
	qrcode::Mode_Encoding e;
	string x=e.Encode("01234567", qrcode::Number_Mode);
	cout << (1 & 0);
//	string x= decimal_to_binary(123);
	qrcode::BasicInfo *p=new qrcode::BasicInfo(1, 2, 3);
	qrcode::Data_Encoding c;
	c.setBasicInfo(p);
	
	std::cout<<c.getBasicInfo()->getLevel();
	int y = 0;
	cin >> y;
}