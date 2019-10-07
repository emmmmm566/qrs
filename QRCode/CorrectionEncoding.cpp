#include "CorrectionEncoding.h"
void qrcode::CorrectionEncoding::setBasicInfo(qrcode::BasicInfo * info){
	this->baisc_info = info;
}
qrcode::BasicInfo * qrcode::CorrectionEncoding::getBasicInfo(){
	return this->baisc_info;
}
std::string qrcode::CorrectionEncoding::Encode(std::string & src){
	return "";
}
std::string qrcode::CorrectionEncoding::Encode(const char * src){
	return "";
}