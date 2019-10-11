#include "Combination.h"
void qrcode::Combination::setBasicInfo(BasicInfo * info){
	this->basic_info = info;
}
qrcode::BasicInfo * qrcode::Combination::getBasicInfo(){
	return this->basic_info;
}
qrcode::Combination::Combination(){
	length = 0;
	combination = NULL;
	polynomeAlpha = NULL;
}
int * qrcode::Combination::getPolynomeAlpha(){
	return this->polynomeAlpha;
}
void qrcode::Combination::caculatePolynomeAlpha(){
	initCombination();
}
int qrcode::Combination::getCombineNumber(int position){

	return 0;
}
void qrcode::Combination::initCombination(){
	this->length = qrcode::correction_encoding::length(this->basic_info);
	//¾À´íÂë×Ö³¤¶È ³ý16
	int combination_length = length >> 3;
	if (combination_length > 0){
		combination = new int[combination_length + 1];
		for (int i = 0; i < combination_length; i++){
			combination[i] = 0xff;
		}
		int remain = length & 0x07;
		switch (remain){
		case 1:
			combination[combination_length] = 0x01;
			break;
		case 2:
			combination[combination_length] = 0x03;
			break;
		case 3:
			combination[combination_length] = 0x07;
			break;
		case 4:
			combination[combination_length] = 0x0f;
			break;
		case 5:
			combination[combination_length] = 0x1f;
			break;
		case 6:
			combination[combination_length] = 0x3f;
			break;
		case 7:
			combination[combination_length] = 0x7f;
			break;
		default:
			break;
			//throw QRCodeException()

		}
	}
	else{
		combination = new int[1];
		int remain = length & 0x07;
		switch (remain){
		case 1:
			combination[0] = 0x01;
			break;
		case 2:
			combination[0] = 0x03;
			break;
		case 3:
			combination[0] = 0x07;
			break;
		case 4:
			combination[0] = 0x0f;
			break;
		case 5:
			combination[0] = 0x1f;
			break;
		case 6:
			combination[0] = 0x3f;
			break;
		case 7:
			combination[0] = 0x7f;
			break;
		default:
			break;
			//throw QRCodeException()

		}
	}

}
qrcode::Combination::~Combination(){
	if (combination != NULL){
		delete combination;
		combination = NULL;
	}
	if (polynomeAlpha != NULL){
		delete polynomeAlpha;
		polynomeAlpha = NULL;
	}
}