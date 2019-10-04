#include "ModeEncoding.h"
using namespace qrcode;
ModeEncoding::ModeEncoding(){
}
ModeEncoding::~ModeEncoding(){

}
int ModeEncoding::getSourceLength(){
	return length;
}
std::string ModeEncoding::letterModeEncoding(char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}
std::string ModeEncoding::letterModeEncoding(const char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}
std::string ModeEncoding::letterModeEncoding(std::string & src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}


std::string ModeEncoding::byteModeEncoding(char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}
std::string ModeEncoding::byteModeEncoding(const char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}
std::string ModeEncoding::byteModeEncoding(std::string & src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}


std::string ModeEncoding::chineseModeEncoding(char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}
std::string ModeEncoding::chineseModeEncoding(const char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}
std::string ModeEncoding::chineseModeEncoding(std::string & src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	return destination;
}



std::string ModeEncoding::numberModeEncoding(char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	do{
		if (!tool::is_pure_digital(source)){
			break;
		}
		destination = tool::number_mode_encoding(source);
		
	}while(false);

	return destination;
}
std::string ModeEncoding::numberModeEncoding(const char *src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	do{
		if (!tool::is_pure_digital(source)){
			break;
		}
		destination = tool::number_mode_encoding(source);

	} while (false);
	return destination;
}
std::string ModeEncoding::numberModeEncoding(std::string & src){
	std::string source = src;
	length = source.size();
	std::string destination = "";
	do{
		if (!tool::is_pure_digital(source)){
			break;
		}
		destination = tool::number_mode_encoding(source);

	} while (false);
	return destination;
}

std::string ModeEncoding::Encode(const char *src, int mode){
	std::string code;
	using namespace qrcode::mode;
	switch (mode){
	case Number_Mode:
		code = numberModeEncoding(src);
		break;
	case Letter_Mode:
		code = letterModeEncoding(src);
		break;
	case Chinese_Mode:
		code = chineseModeEncoding(src);
		break;
	case Byte_Mode:
		code = byteModeEncoding(src);
		break;
	default:
		break;
	}
	return code;
}
std::string ModeEncoding::Encode(std::string & src, int mode){
	std::string code;
	using namespace qrcode::mode;
	switch (mode){
	case Number_Mode:
		code = numberModeEncoding(src);
		break;
	case Letter_Mode:
		code = letterModeEncoding(src);
		break;
	case Chinese_Mode:
		code = chineseModeEncoding(src);
		break;
	case Byte_Mode:
		code = byteModeEncoding(src);
		break;
	default:
		break;
	}
	return code;
}
std::string ModeEncoding::Encode(char *src, int mode){
	std::string code;
	using namespace qrcode::mode;
	switch (mode){
	case Number_Mode:
		code = numberModeEncoding(src);
		break;
	case Letter_Mode:
		code = letterModeEncoding(src);
		break;
	case Chinese_Mode:
		code = chineseModeEncoding(src);
		break;
	case Byte_Mode:
		code = byteModeEncoding(src);
		break;
	default:
		break;
	}
	return code;
}