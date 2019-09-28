#include "Tool.h"
using namespace qrcode::tool;
bool qrcode::tool::is_pure_digital(const std::string & src){
	bool flag = true;
	for (auto a : src){
		if (a >= 48 && a <= 57){
			continue;
		}
		else
		{
			flag = false;
		}
	}
	return flag;
}
std::string qrcode::tool::number_mode_encoding(const std::string &source){
	std::string destination = "";
	const int length = source.size();
	for (int i = 0; i < length; i = i + 3){
		std::string operator_data = "";
		char * dst = NULL;
		//if the remain sequence has 3 numbers or more
		if (length - i >= 3){
			dst = new char[11];
			operator_data = source.substr(i, 3);
			int number = std::stoi(operator_data);
			std::string result = tool::decimal_to_binary(number);
			sprintf_s(dst, 11, "%010s", result.data());
		}
		else{
			if (length - i == 2){
				dst = new char[8];
				operator_data = source.substr(i, 2);
				int number = std::stoi(operator_data);
				std::string result = tool::decimal_to_binary(number);
				sprintf_s(dst, 8, "%07s", result.data());
			}
			else if (length - i == 1){
				dst = new char[4];
				operator_data = source.substr(i, 1);
				int number = std::stoi(operator_data);
				std::string result = tool::decimal_to_binary(number);
				sprintf_s(dst, 5, "%04s", result.data());
			}
		}
		destination += dst;
		delete dst;
		dst = NULL;
	}
	return destination;
}
std::string qrcode::tool::decimal_to_binary(const int src){
	std::string dst = "";
	for (int source = src; source != 0; source = source >> 1){
		if (source & 1){
			dst.insert(dst.begin(), '1');//49
		}
		else{
			dst.insert(dst.begin(), '0');//48
		}
	}
	return  dst;
}