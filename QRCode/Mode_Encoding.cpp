#include "Mode_Encoding.h"
using namespace qrcode;
int Mode_Encoding::Get_Source_Length(){
	return length;
}
std::string Mode_Encoding::Number_Mode_Encoding(char *src){
	std::string source = src;
	length = source.size();
}
std::string Mode_Encoding::Number_Mode_Encoding(const char *src){
	std::string source = src;
	length = source.size();
}
std::string Mode_Encoding::Number_Mode_Encoding(std::string src){
	std::string source = src;
	length = source.size();
}
std::string Mode_Encoding::Encode(const char *src, int mode){
	std::string code;
	switch (mode){
	case Number_Mode:
		code = Number_Mode_Encoding(src);
		break;
	case Letter_Mode:
		code = Letter_Mode_Encoding(src);
		break;
	case Chinese_Mode:
		code = Chinese_Mode_Encoding(src);
		break;
	case Byte_Mode:
		code = Byte_Mode_Encoding(src);
		break;
	default:
		break;
	}
	return code;
}
std::string Mode_Encoding::Encode(std::string src, int mode){
	std::string code;
	switch (mode){
	case Number_Mode:
		code = Number_Mode_Encoding(src);
		break;
	case Letter_Mode:
		code = Letter_Mode_Encoding(src);
		break;
	case Chinese_Mode:
		code = Chinese_Mode_Encoding(src);
		break;
	case Byte_Mode:
		code = Byte_Mode_Encoding(src);
		break;
	default:
		break;
	}
	return code;
}
std::string Mode_Encoding::Encode(char *src, int mode){
	std::string code;
	switch (mode){
	case Number_Mode:
		code = Number_Mode_Encoding(src);
		break;
	case Letter_Mode:
		code = Letter_Mode_Encoding(src);
		break;
	case Chinese_Mode:
		code = Chinese_Mode_Encoding(src);
		break;
	case Byte_Mode:
		code = Byte_Mode_Encoding(src);
		break;
	default:
		break;
	}
	return code;
}