#include "Data_Encoding.h"
using namespace qrcode;
Data_Encoding::Data_Encoding(){
	basic_info = NULL;
}
Data_Encoding::~Data_Encoding(){
	if (basic_info != NULL){
		delete basic_info;
		basic_info = NULL;
	}
}
std::string Data_Encoding::Encode(char *src, int mode){
	std::string dst = "";
	mode_encoding.Encode(src, mode);
	this->character_count_indicator = mode_encoding.Get_Source_Length();
	return dst;
}
std::string Data_Encoding::Encode(const char *src, int mode){
	std::string dst = "";
	mode_encoding.Encode(src, mode);
	return dst;
}
std::string Data_Encoding::Encode(std::string & src, int mode){
	std::string dst = "";
	mode_encoding.Encode(src, mode);
	return dst;
}
void Data_Encoding::setBasicInfo(BasicInfo * basic_info){
	this->basic_info = basic_info;
}
BasicInfo * Data_Encoding::getBasicInfo(){
	return this->basic_info;
}