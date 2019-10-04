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
int qrcode::character_count_indicator::length(BasicInfo  *info){
	int length = 0;
	int _version = info->getVersion();
	int _mode = info->getMode();
	if (_version >= 1 && _version <= 9){
		switch (_mode){
			case mode::Number_Mode:
				length = 10;
				break;
			case mode::Letter_Mode:
				length = 9;
				break;
			case mode::Byte_Mode:
				length = 8;
				break;
			case mode::Chinese_Mode:
				length = 8;
				break;
			default:
				throw qrcode::QRCodeException(qrcode::error::InvalidMode);
				break;
		}
	}
	else if (_version >= 10 && _version <= 26){
		switch (_mode){
		case mode::Number_Mode:
			length = 12;
			break;
		case mode::Letter_Mode:
			length = 11;
			break;
		case mode::Byte_Mode:
			length = 16;
			break;
		case mode::Chinese_Mode:
			length = 10;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidMode);
			break;
		}
	}
	else if (_version >= 27 && _version <= 40){
		switch (_mode){
		case mode::Number_Mode:
			length = 14;
			break;
		case mode::Letter_Mode:
			length = 13;
			break;
		case mode::Byte_Mode:
			length = 16;
			break;
		case mode::Chinese_Mode:
			length = 12;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidMode);
			break;
		}
	}
	else{
		throw qrcode::QRCodeException(qrcode::error::InvalidVersion);
	}
	return length;
}
int qrcode::data_encoding::length(BasicInfo * info){
	int _version = info->getVersion();
	int _level = info->getLevel();
	int res = 0;
	switch (_version){
	case 1:
		switch (_level){
		case level::Correction_L:
			res = 19;
			break;
		case level::Correction_M:
			res = 16;
			break;
		case level::Correction_Q:
			res = 13;
			break;
		case level::Correction_H:
			res = 9;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 2:
		switch (_level){
		case level::Correction_L:
			res = 34;
			break;
		case level::Correction_M:
			res = 28;
			break;
		case level::Correction_Q:
			res = 22;
			break;
		case level::Correction_H:
			res = 16;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 3:
		switch (_level){
		case level::Correction_L:
			res = 55;
			break;
		case level::Correction_M:
			res = 44;
			break;
		case level::Correction_Q:
			res = 34;
			break;
		case level::Correction_H:
			res = 26;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 4:
		switch (_level){
		case level::Correction_L:
			res = 80;
			break;
		case level::Correction_M:
			res = 64;
			break;
		case level::Correction_Q:
			res = 48;
			break;
		case level::Correction_H:
			res = 36;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 5:
		switch (_level){
		case level::Correction_L:
			res = 108;
			break;
		case level::Correction_M:
			res = 86;
			break;
		case level::Correction_Q:
			res = 62;
			break;
		case level::Correction_H:
			res = 46;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 6:
		switch (_level){
		case level::Correction_L:
			res = 136;
			break;
		case level::Correction_M:
			res = 108;
			break;
		case level::Correction_Q:
			res = 76;
			break;
		case level::Correction_H:
			res = 60;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 7:
		switch (_level){
		case level::Correction_L:
			res = 156;
			break;
		case level::Correction_M:
			res = 124;
			break;
		case level::Correction_Q:
			res = 88;
			break;
		case level::Correction_H:
			res = 66;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 8:
		switch (_level){
		case level::Correction_L:
			res = 194;
			break;
		case level::Correction_M:
			res = 154;
			break;
		case level::Correction_Q:
			res = 110;
			break;
		case level::Correction_H:
			res = 86;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 9:
		switch (_level){
		case level::Correction_L:
			res = 232;
			break;
		case level::Correction_M:
			res = 182;
			break;
		case level::Correction_Q:
			res = 132;
			break;
		case level::Correction_H:
			res = 100;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 10:
		switch (_level){
		case level::Correction_L:
			res = 274;
			break;
		case level::Correction_M:
			res = 216;
			break;
		case level::Correction_Q:
			res = 154;
			break;
		case level::Correction_H:
			res = 122;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 11:
		switch (_level){
		case level::Correction_L:
			res = 324;
			break;
		case level::Correction_M:
			res = 254;
			break;
		case level::Correction_Q:
			res = 180;
			break;
		case level::Correction_H:
			res = 140;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 12:
		switch (_level){
		case level::Correction_L:
			res = 370;
			break;
		case level::Correction_M:
			res = 290;
			break;
		case level::Correction_Q:
			res = 206;
			break;
		case level::Correction_H:
			res = 158;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 13:
		switch (_level){
		case level::Correction_L:
			res = 428;
			break;
		case level::Correction_M:
			res = 334;
			break;
		case level::Correction_Q:
			res = 244;
			break;
		case level::Correction_H:
			res = 180;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 14:
		switch (_level){
		case level::Correction_L:
			res = 461;
			break;
		case level::Correction_M:
			res = 365;
			break;
		case level::Correction_Q:
			res = 261;
			break;
		case level::Correction_H:
			res = 197;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 15:
		switch (_level){
		case level::Correction_L:
			res = 523;
			break;
		case level::Correction_M:
			res = 415;
			break;
		case level::Correction_Q:
			res = 295;
			break;
		case level::Correction_H:
			res = 223;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 16:
		switch (_level){
		case level::Correction_L:
			res = 589;
			break;
		case level::Correction_M:
			res = 453;
			break;
		case level::Correction_Q:
			res = 325;
			break;
		case level::Correction_H:
			res = 253;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 17:
		switch (_level){
		case level::Correction_L:
			res = 647;
			break;
		case level::Correction_M:
			res = 507;
			break;
		case level::Correction_Q:
			res = 367;
			break;
		case level::Correction_H:
			res = 283;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 18:
		switch (_level){
		case level::Correction_L:
			res = 721;
			break;
		case level::Correction_M:
			res = 563;
			break;
		case level::Correction_Q:
			res = 397;
			break;
		case level::Correction_H:
			res = 313;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 19:
		switch (_level){
		case level::Correction_L:
			res = 795;
			break;
		case level::Correction_M:
			res = 627;
			break;
		case level::Correction_Q:
			res = 445;
			break;
		case level::Correction_H:
			res = 341;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 20:
		switch (_level){
		case level::Correction_L:
			res = 861;
			break;
		case level::Correction_M:
			res = 669;
			break;
		case level::Correction_Q:
			res = 485;
			break;
		case level::Correction_H:
			res = 385;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 21:
		switch (_level){
		case level::Correction_L:
			res = 932;
			break;
		case level::Correction_M:
			res = 714;
			break;
		case level::Correction_Q:
			res = 512;
			break;
		case level::Correction_H:
			res = 406;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 22:
		switch (_level){
		case level::Correction_L:
			res = 1006;
			break;
		case level::Correction_M:
			res = 782;
			break;
		case level::Correction_Q:
			res = 568;
			break;
		case level::Correction_H:
			res = 442;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 23:
		switch (_level){
		case level::Correction_L:
			res = 1094;
			break;
		case level::Correction_M:
			res = 860;
			break;
		case level::Correction_Q:
			res = 614;
			break;
		case level::Correction_H:
			res = 464;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 24:
		switch (_level){
		case level::Correction_L:
			res = 1174;
			break;
		case level::Correction_M:
			res = 914;
			break;
		case level::Correction_Q:
			res = 664;
			break;
		case level::Correction_H:
			res = 514;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 25:
		switch (_level){
		case level::Correction_L:
			res = 1276;
			break;
		case level::Correction_M:
			res = 1000;
			break;
		case level::Correction_Q:
			res = 718;
			break;
		case level::Correction_H:
			res = 538;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 26:
		switch (_level){
		case level::Correction_L:
			res = 1370;
			break;
		case level::Correction_M:
			res = 1062;
			break;
		case level::Correction_Q:
			res = 754;
			break;
		case level::Correction_H:
			res = 596;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 27:
		switch (_level){
		case level::Correction_L:
			res = 1468;
			break;
		case level::Correction_M:
			res = 1128;
			break;
		case level::Correction_Q:
			res = 808;
			break;
		case level::Correction_H:
			res = 628;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 28:
		switch (_level){
		case level::Correction_L:
			res = 1531;
			break;
		case level::Correction_M:
			res = 1193;
			break;
		case level::Correction_Q:
			res = 871;
			break;
		case level::Correction_H:
			res = 661;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 29:
		switch (_level){
		case level::Correction_L:
			res = 1631;
			break;
		case level::Correction_M:
			res = 1267;
			break;
		case level::Correction_Q:
			res = 911;
			break;
		case level::Correction_H:
			res = 701;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 30:
		switch (_level){
		case level::Correction_L:
			res = 1735;
			break;
		case level::Correction_M:
			res = 1373;
			break;
		case level::Correction_Q:
			res = 985;
			break;
		case level::Correction_H:
			res = 745;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 31:
		switch (_level){
		case level::Correction_L:
			res = 1843;
			break;
		case level::Correction_M:
			res = 1455;
			break;
		case level::Correction_Q:
			res = 1033;
			break;
		case level::Correction_H:
			res = 793;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 32:
		switch (_level){
		case level::Correction_L:
			res = 1955;
			break;
		case level::Correction_M:
			res = 1541;
			break;
		case level::Correction_Q:
			res = 1115;
			break;
		case level::Correction_H:
			res = 845;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 33:
		switch (_level){
		case level::Correction_L:
			res = 2071;
			break;
		case level::Correction_M:
			res = 1631;
			break;
		case level::Correction_Q:
			res = 1171;
			break;
		case level::Correction_H:
			res = 901;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 34:
		switch (_level){
		case level::Correction_L:
			res = 2191;
			break;
		case level::Correction_M:
			res = 1725;
			break;
		case level::Correction_Q:
			res = 1231;
			break;
		case level::Correction_H:
			res = 961;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 35:
		switch (_level){
		case level::Correction_L:
			res = 2306;
			break;
		case level::Correction_M:
			res = 1812;
			break;
		case level::Correction_Q:
			res = 1286;
			break;
		case level::Correction_H:
			res = 986;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 36:
		switch (_level){
		case level::Correction_L:
			res = 2434;
			break;
		case level::Correction_M:
			res = 1914;
			break;
		case level::Correction_Q:
			res = 1354;
			break;
		case level::Correction_H:
			res = 1054;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 37:
		switch (_level){
		case level::Correction_L:
			res = 2566;
			break;
		case level::Correction_M:
			res = 1992;
			break;
		case level::Correction_Q:
			res = 1426;
			break;
		case level::Correction_H:
			res = 1096;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 38:
		switch (_level){
		case level::Correction_L:
			res = 2702;
			break;
		case level::Correction_M:
			res = 2102;
			break;
		case level::Correction_Q:
			res = 1502;
			break;
		case level::Correction_H:
			res = 1142;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 39:
		switch (_level){
		case level::Correction_L:
			res = 2812;
			break;
		case level::Correction_M:
			res = 2216;
			break;
		case level::Correction_Q:
			res = 1582;
			break;
		case level::Correction_H:
			res = 1222;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 40:
		switch (_level){
		case level::Correction_L:
			res = 2956;
			break;
		case level::Correction_M:
			res = 2334;
			break;
		case level::Correction_Q:
			res = 1666;
			break;
		case level::Correction_H:
			res = 1276;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	default:
		throw QRCodeException(qrcode::error::InvalidVersion);
		break;
	}
	return res;
}