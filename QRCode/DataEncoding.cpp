#include "DataEncoding.h"
using namespace qrcode;
DataEncoding::DataEncoding(){
	basic_info = NULL;
	mode_encoding = NULL;
	mode_encoding = new ModeEncoding();
}
DataEncoding::~DataEncoding(){
	if (basic_info != NULL){
		delete basic_info;
		basic_info = NULL;
	}
	if (mode_encoding != NULL){
		delete mode_encoding;
		mode_encoding = NULL;
	}
}
std::string DataEncoding::Combine(const char * data){
	std::string res="";
	//mode_indicator
	using namespace qrcode::mode;
	switch (mode_indicator)
	{
		case Number_Mode:
			res += "0001";
			break;
		case Byte_Mode:
			res += "0100";
			break;
		case Chinese_Mode:
			res += "1101";
			break;
		case Letter_Mode:
			res += "0010";
			break;
		default:
			throw QRCodeException(qrcode::error::InvalidMode);
			break;
	}
	//character_count_indicator
	{
		int len = qrcode::character_count_indicator::length(basic_info);
		std::string count_indicator = qrcode::tool::decimal_to_binary(character_count_indicator);
		if (len > count_indicator.length()){
			for (int i = 0; i < len - count_indicator.length(); i++){
				count_indicator.insert(count_indicator.begin(), '0');
			}
		}
		else
		{
			//overflow
			//throw QRCodeException(qrcode::error::);
		}
		res += count_indicator;
	}
	//source
	res += data;
	//terminator
	int dataEncodingLength = qrcode::data_encoding::length(basic_info);
	{
		bool is_full = false;
		int len = dataEncodingLength << 3;
		int remain = len - res.length();
		switch (remain){
			case 1:
				res += "0";
				break;
			case 2:
				res += "00";
				break;
			case 3:
				res += "000";
				break;
			default:
				res += "0000";
				break;
		}
	}
	//Add More 0s to Make the Length a Multiple of 8
	{
		int mod = res.length() & 7;
		if (mod){
			for (int i = 0; i < 8 - mod; i++){
				res.push_back('0');
			}
		}
	}
	//Add Pad Bytes if the String is Still too Short
	{
		int len = res.length() >> 3;
		int remain = dataEncodingLength - len;
		bool turn = true;
		while (remain > 0){
			if (turn){
				res.append("11101100");
				turn = false;
			}
			else{
				res.append("00010001");
				turn = true;
			}
			remain--;
		}
	}
	return res;
}
std::string DataEncoding::Encode(char *src){
	std::string dst = "";
	this->mode_indicator = basic_info->getMode();
	mode_encoding->Encode(src, mode_indicator);
	this->character_count_indicator = mode_encoding->getSourceLength();
	std::string precoding = mode_encoding->Encode(src, mode_indicator);
	dst = Combine(precoding.data());
	return dst;
}
std::string DataEncoding::Encode(const char *src){
	std::string dst = "";
	this->mode_indicator = basic_info->getMode();
	mode_encoding->Encode(src, mode_indicator);
	this->character_count_indicator = mode_encoding->getSourceLength();
	std::string precoding = mode_encoding->Encode(src, mode_indicator);
	dst = Combine(precoding.data());
	return dst;
}
std::string DataEncoding::Encode(std::string & src){
	std::string dst = "";
	this->mode_indicator = basic_info->getMode();
	mode_encoding->Encode(src, mode_indicator);
	this->character_count_indicator = mode_encoding->getSourceLength();
	std::string precoding = mode_encoding->Encode(src, mode_indicator);
	dst = Combine(precoding.data());
	return dst;
}
void DataEncoding::setBasicInfo(BasicInfo * basic_info){
	this->basic_info = basic_info;
}
BasicInfo * DataEncoding::getBasicInfo(){
	return this->basic_info;
}