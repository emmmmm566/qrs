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
int qrcode::correction_encoding::length(BasicInfo * info){
	int _version = info->getVersion();
	int _level = info->getLevel();
	int length = 0;
	switch (_version){
	case 1:
		switch (_level){
		case level::Correction_L:
			length = 7;
			break;
		case level::Correction_M:
			length = 10;
			break;
		case level::Correction_Q:
			length = 13;
			break;
		case level::Correction_H:
			length = 17;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 2:
		switch (_level){
		case level::Correction_L:
			length = 10;
			break;
		case level::Correction_M:
			length = 16;
			break;
		case level::Correction_Q:
			length = 22;
			break;
		case level::Correction_H:
			length = 28;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 3:
		switch (_level){
		case level::Correction_L:
			length = 15;
			break;
		case level::Correction_M:
			length = 26;
			break;
		case level::Correction_Q:
			length = 36;
			break;
		case level::Correction_H:
			length = 44;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 4:
		switch (_level){
		case level::Correction_L:
			length = 20;
			break;
		case level::Correction_M:
			length = 36;
			break;
		case level::Correction_Q:
			length = 52;
			break;
		case level::Correction_H:
			length = 64;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 5:
		switch (_level){
		case level::Correction_L:
			length = 26;
			break;
		case level::Correction_M:
			length = 48;
			break;
		case level::Correction_Q:
			length = 72;
			break;
		case level::Correction_H:
			length = 88;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 6:
		switch (_level){
		case level::Correction_L:
			length = 36;
			break;
		case level::Correction_M:
			length = 64;
			break;
		case level::Correction_Q:
			length = 96;
			break;
		case level::Correction_H:
			length = 112;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 7:
		switch (_level){
		case level::Correction_L:
			length = 40;
			break;
		case level::Correction_M:
			length = 72;
			break;
		case level::Correction_Q:
			length = 108;
			break;
		case level::Correction_H:
			length = 130;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 8:
		switch (_level){
		case level::Correction_L:
			length = 48;
			break;
		case level::Correction_M:
			length = 88;
			break;
		case level::Correction_Q:
			length = 132;
			break;
		case level::Correction_H:
			length = 156;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 9:
		switch (_level){
		case level::Correction_L:
			length = 60;
			break;
		case level::Correction_M:
			length = 110;
			break;
		case level::Correction_Q:
			length = 160;
			break;
		case level::Correction_H:
			length = 192;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 10:
		switch (_level){
		case level::Correction_L:
			length = 72;
			break;
		case level::Correction_M:
			length = 130;
			break;
		case level::Correction_Q:
			length = 192;
			break;
		case level::Correction_H:
			length = 224;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 11:
		switch (_level){
		case level::Correction_L:
			length = 80;
			break;
		case level::Correction_M:
			length = 150;
			break;
		case level::Correction_Q:
			length = 224;
			break;
		case level::Correction_H:
			length = 264;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 12:
		switch (_level){
		case level::Correction_L:
			length = 96;
			break;
		case level::Correction_M:
			length = 176;
			break;
		case level::Correction_Q:
			length = 260;
			break;
		case level::Correction_H:
			length = 308;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 13:
		switch (_level){
		case level::Correction_L:
			length = 104;
			break;
		case level::Correction_M:
			length = 198;
			break;
		case level::Correction_Q:
			length = 288;
			break;
		case level::Correction_H:
			length = 352;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 14:
		switch (_level){
		case level::Correction_L:
			length = 120;
			break;
		case level::Correction_M:
			length = 216;
			break;
		case level::Correction_Q:
			length = 320;
			break;
		case level::Correction_H:
			length = 384;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 15:
		switch (_level){
		case level::Correction_L:
			length = 132;
			break;
		case level::Correction_M:
			length = 240;
			break;
		case level::Correction_Q:
			length = 360;
			break;
		case level::Correction_H:
			length = 432;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 16:
		switch (_level){
		case level::Correction_L:
			length = 144;
			break;
		case level::Correction_M:
			length = 280;
			break;
		case level::Correction_Q:
			length = 408;
			break;
		case level::Correction_H:
			length = 480;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 17:
		switch (_level){
		case level::Correction_L:
			length = 168;
			break;
		case level::Correction_M:
			length = 308;
			break;
		case level::Correction_Q:
			length = 448;
			break;
		case level::Correction_H:
			length = 532;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 18:
		switch (_level){
		case level::Correction_L:
			length = 180;
			break;
		case level::Correction_M:
			length = 338;
			break;
		case level::Correction_Q:
			length = 504;
			break;
		case level::Correction_H:
			length = 588;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 19:
		switch (_level){
		case level::Correction_L:
			length = 196;
			break;
		case level::Correction_M:
			length = 364;
			break;
		case level::Correction_Q:
			length = 546;
			break;
		case level::Correction_H:
			length = 650;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 20:
		switch (_level){
		case level::Correction_L:
			length = 224;
			break;
		case level::Correction_M:
			length = 416;
			break;
		case level::Correction_Q:
			length = 600;
			break;
		case level::Correction_H:
			length = 700;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 21:
		switch (_level){
		case level::Correction_L:
			length = 224;
			break;
		case level::Correction_M:
			length = 442;
			break;
		case level::Correction_Q:
			length = 644;
			break;
		case level::Correction_H:
			length = 750;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 22:
		switch (_level){
		case level::Correction_L:
			length = 252;
			break;
		case level::Correction_M:
			length = 476;
			break;
		case level::Correction_Q:
			length = 690;
			break;
		case level::Correction_H:
			length = 816;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 23:
		switch (_level){
		case level::Correction_L:
			length = 270;
			break;
		case level::Correction_M:
			length = 504;
			break;
		case level::Correction_Q:
			length = 750;
			break;
		case level::Correction_H:
			length = 900;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 24:
		switch (_level){
		case level::Correction_L:
			length = 300;
			break;
		case level::Correction_M:
			length = 560;
			break;
		case level::Correction_Q:
			length = 810;
			break;
		case level::Correction_H:
			length = 960;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 25:
		switch (_level){
		case level::Correction_L:
			length = 312;
			break;
		case level::Correction_M:
			length = 588;
			break;
		case level::Correction_Q:
			length = 870;
			break;
		case level::Correction_H:
			length = 1050;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 26:
		switch (_level){
		case level::Correction_L:
			length = 336;
			break;
		case level::Correction_M:
			length = 644;
			break;
		case level::Correction_Q:
			length = 952;
			break;
		case level::Correction_H:
			length = 1110;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 27:
		switch (_level){
		case level::Correction_L:
			length = 360;
			break;
		case level::Correction_M:
			length = 700;
			break;
		case level::Correction_Q:
			length = 1020;
			break;
		case level::Correction_H:
			length = 1200;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 28:
		switch (_level){
		case level::Correction_L:
			length = 390;
			break;
		case level::Correction_M:
			length = 728;
			break;
		case level::Correction_Q:
			length = 1050;
			break;
		case level::Correction_H:
			length = 1260;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 29:
		switch (_level){
		case level::Correction_L:
			length = 420;
			break;
		case level::Correction_M:
			length = 784;
			break;
		case level::Correction_Q:
			length = 1140;
			break;
		case level::Correction_H:
			length = 1350;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 30:
		switch (_level){
		case level::Correction_L:
			length = 450;
			break;
		case level::Correction_M:
			length = 812;
			break;
		case level::Correction_Q:
			length = 1200;
			break;
		case level::Correction_H:
			length = 1440;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 31:
		switch (_level){
		case level::Correction_L:
			length = 480;
			break;
		case level::Correction_M:
			length = 868;
			break;
		case level::Correction_Q:
			length = 1290;
			break;
		case level::Correction_H:
			length = 1530;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 32:
		switch (_level){
		case level::Correction_L:
			length = 510;
			break;
		case level::Correction_M:
			length = 924;
			break;
		case level::Correction_Q:
			length = 1350;
			break;
		case level::Correction_H:
			length = 1620;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 33:
		switch (_level){
		case level::Correction_L:
			length = 540;
			break;
		case level::Correction_M:
			length = 980;
			break;
		case level::Correction_Q:
			length = 1440;
			break;
		case level::Correction_H:
			length = 1710;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 34:
		switch (_level){
		case level::Correction_L:
			length = 570;
			break;
		case level::Correction_M:
			length = 1036;
			break;
		case level::Correction_Q:
			length = 1530;
			break;
		case level::Correction_H:
			length = 1800;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 35:
		switch (_level){
		case level::Correction_L:
			length = 570;
			break;
		case level::Correction_M:
			length = 1064;
			break;
		case level::Correction_Q:
			length = 1590;
			break;
		case level::Correction_H:
			length = 1890;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 36:
		switch (_level){
		case level::Correction_L:
			length = 600;
			break;
		case level::Correction_M:
			length = 1120;
			break;
		case level::Correction_Q:
			length = 1680;
			break;
		case level::Correction_H:
			length = 1980;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 37:
		switch (_level){
		case level::Correction_L:
			length = 630;
			break;
		case level::Correction_M:
			length = 1204;
			break;
		case level::Correction_Q:
			length = 1770;
			break;
		case level::Correction_H:
			length = 2100;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 38:
		switch (_level){
		case level::Correction_L:
			length = 660;
			break;
		case level::Correction_M:
			length = 1260;
			break;
		case level::Correction_Q:
			length = 1860;
			break;
		case level::Correction_H:
			length = 2220;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 39:
		switch (_level){
		case level::Correction_L:
			length = 720;
			break;
		case level::Correction_M:
			length = 1316;
			break;
		case level::Correction_Q:
			length = 1950;
			break;
		case level::Correction_H:
			length = 2310;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 40:
		switch (_level){
		case level::Correction_L:
			length = 750;
			break;
		case level::Correction_M:
			length = 1372;
			break;
		case level::Correction_Q:
			length = 2040;
			break;
		case level::Correction_H:
			length = 2430;
			break;
		default:
			throw qrcode::QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	default:
		throw qrcode::QRCodeException(qrcode::error::InvalidVersion);
		break;
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
int qrcode::correction_encoding::getPolynomeAlpha(BasicInfo * info, int *& arrays){
	int length = qrcode::correction_encoding::length(info);
	if (arrays != NULL){
		delete arrays;
		arrays = NULL;
	}
	switch (length){
		case 7:
		{
			arrays = new int[8]{0, 87, 229, 146, 149, 238, 102, 21};
		}
		break;
		case 10:
		{
			arrays = new int[11]{0, 251, 67, 46, 61, 118, 70, 64,
								94, 32, 45};
		}
		break;
		case 13:
		{
			arrays = new int[14]{0, 74, 152, 176, 100, 86, 100, 106,
							   104, 130, 218, 206, 140, 78};
		}
		break;
		case 15:
		{
			arrays = new int[16]{0, 8, 183, 61, 91, 202, 37, 51, 58,
								58, 237, 140, 124, 5, 99, 105};
		}
		break;
		case 16:
		{
			arrays = new int[17]{0, 120, 104, 107, 109, 102, 161, 76,
								 3, 91, 191, 147, 169, 182, 194, 225, 
								 120};
		}
		break;
		case 17:
		{
			arrays = new int[18]{0, 43, 139, 206, 78, 43, 239, 123,
							   206, 214, 147, 24, 99, 150, 39, 243,
				               163, 136};
		}
		break;
		case 18:
		{
			arrays = new int[19]{0, 215, 234, 158, 94, 184, 97, 118,
								170, 79, 187, 152, 148, 252, 179, 5,
								98, 96, 153};
		}
		break;
		case 20:
		{
			arrays = new int[21]{0, 17, 60, 79, 50, 61, 163, 26,
								187, 202, 180, 221, 225, 83, 239, 156, 
								164, 212, 212, 188, 190};
		}
		break;
		case 22:
		{
			arrays = new int[23]{0, 210, 171, 247, 242, 93, 230, 14,
								109, 221, 53, 200, 74, 8, 172, 98,
								80, 219, 134, 160, 105, 165, 231};
		}
		break;
		case 24:
		{
			arrays = new int[25]{0, 229, 121, 135, 48, 211, 117, 251,
								126, 159, 180, 169, 152, 192, 226, 228,
								218, 111, 0, 117, 232, 87, 96, 227,
								21};
		}
		break;
		case 26:
		{
			arrays = new int[27]{0, 173, 125, 158, 2, 103, 182, 118,
								17, 145, 201, 111, 28, 165, 53, 161,
								21, 245, 142, 13, 102, 48, 227, 153, 
								145, 218, 70};
		}
		break;
		case 28:
		{
			arrays = new int[29]{0, 168, 223, 200, 104, 224, 234, 108,
								180, 110, 190, 195, 147, 205, 27, 232,
								201, 21, 43, 245, 87, 42, 195, 212,
								119, 242, 37, 9, 123};
		}
		break;
		case 30:
		{
			arrays = new int[31]{0, 41, 173, 145, 152, 216, 31, 179, 182,
								 50, 48, 110, 86, 239, 96, 222, 125,
								 42, 173, 226, 193, 224, 130, 156, 37, 
								 251, 216, 238, 40, 192, 180};
		}
		break;
		case 32:
		{
			arrays = new int[33]{0, 10, 6, 106, 190, 249, 167, 4,
								67, 209, 138, 138, 32, 242, 123, 89,
								27, 120, 185, 80, 156, 38, 69, 171,
								60, 28, 222, 80, 52, 254, 185, 220, 
								241};
		}
		break;
		case 34:
		{
			arrays = new int[35]{0, 111, 77, 146, 94, 26, 21, 108,
								19, 105, 94, 113, 193, 86, 140, 163,
								125, 58, 158, 229, 239, 218, 103, 56,
								70, 114, 61, 183, 129, 167, 13, 98,
								62, 129, 51};
		}
		break;
		case 36:
		{
			arrays = new int[37]{0, 200, 183, 98, 16, 172, 31, 246,
								234, 60, 152, 115, 0, 167, 152, 113,
								248, 238, 107, 18, 63, 218, 37, 87,
								210, 105, 177, 120, 74, 121, 196, 117,
								251, 113, 233, 30, 120
			};
		}
		break;
		case 40:
		{
			arrays = new int[41]{0, 59, 116, 79, 161, 252, 98, 128,
				205, 128, 161, 247, 57, 163, 56, 235,
				106, 53, 26, 187, 174, 226, 104, 170,
				7, 175, 35, 181, 114, 88, 41, 47,
				163, 125, 134, 72, 20, 232, 53, 35,
				15};
		}
		break;
		case 42:
		{
			arrays = new int[43]{0, 250, 103, 221, 230, 25, 18, 137,
								231, 0, 3, 58, 242, 221, 191, 110,
								84, 230, 8, 188, 106, 96, 147, 15,
								131, 139, 34, 101, 223, 39, 101, 213,
								199, 237, 254, 201, 123, 171, 162, 194,
								117, 50, 96};
		}
		break;
		case 44:
		{
			arrays = new int[45]{0, 190, 7, 61, 121, 71, 246, 69,
								55, 168, 188, 89, 243, 191, 25, 72,
								123, 9, 145, 14, 247, 1, 238, 44,
								78, 143, 62, 224, 126, 118, 114, 68, 
								163, 52, 194, 217, 147, 204, 169, 37,
								130, 113, 102, 73, 181};
		}
		break;
		case 46:
		{
			arrays = new int[47]{0, 112, 94, 88, 112, 253, 224, 202,
								115, 187, 99, 89, 5, 54, 113, 129,
								44, 58, 16, 135, 216, 169, 211, 36,
								1, 4, 96, 60, 241, 73, 104, 234,
								8, 249, 245, 119, 174, 52, 25, 157,
								224, 43, 202, 223, 19, 82, 15};
		}
		break;
		case 48:
		{
			arrays = new int[49]{0, 228, 25, 196, 130, 211, 146, 60,
								24, 251, 90, 39, 102, 240, 61, 178,
								63, 46, 123, 115, 18, 221, 111, 135,
								160, 182, 205, 107, 206, 95, 150, 120,
								184, 91, 21, 247, 156, 140, 238, 191, 
								11, 94, 227, 84, 50, 163, 39, 34, 
								108};
		}
		break;
		case 50:
		{
			arrays = new int[51]{0, 232, 125, 157, 161, 164, 9, 118,
								46, 209, 99, 203, 193, 35, 3, 209,
								111, 195, 242, 203, 225, 46, 13, 32,
								160, 126, 209, 130, 160, 242, 215, 242,
								75, 77, 42, 189, 32, 113, 65, 124,
								69, 228, 114, 235, 175, 124, 170, 215, 
								232, 133, 205};
		}
		break;
		case 52:
			arrays = new int[53]{
					0, 116, 50, 86, 186, 50, 220, 251,
					89, 192, 46, 86, 127, 124, 19, 184,
					233, 151, 215, 22, 14, 59, 145, 37,
					242, 203, 134, 254, 89, 190, 94, 59,
					65, 124, 113, 100, 233, 235, 121, 22,
					76, 86, 97, 39, 242, 200, 220, 101,
					33, 239, 254, 116, 51
			};
			break;
		case 54:
			arrays = new int[55]{
					0, 183, 25, 201, 87, 210, 221, 113,
					21, 46, 65, 45, 50, 238, 184, 249,
					225, 102, 58, 209, 218, 109, 165, 26,
					95, 184, 192, 52, 245, 35, 254, 238,
					175, 172, 79, 123, 25, 122, 43, 120,
					108, 215, 80, 128, 201, 235, 8, 153,
					59, 101, 31, 198, 76, 31, 156
			};
			break;
		case 56:
			arrays = new int[57]{
					0, 106, 120, 107, 157, 164, 216, 112,
					116, 2, 91, 248, 163, 36, 201, 202,
					229, 6, 144, 254, 155, 135, 208, 170,
					209, 12, 139, 127, 142, 182, 249, 177,
					174, 190, 28, 10, 85, 239, 184, 101,
					124, 152, 206, 96, 23, 163, 61, 27,
					196, 247, 151, 154, 202, 207, 20, 61,
					10
			};
			break;
		case 58:
			arrays = new int[59]{
					0, 82, 116, 26, 247, 66, 27, 62,
					107, 252, 182, 200, 185, 235, 55, 251,
					242, 210, 144, 154, 237, 176, 141, 192,
					248, 152, 249, 206, 85, 253, 142, 65,
					165, 125, 23, 24, 30, 122, 240, 214,
					6, 129, 218, 29, 145, 127, 134, 206,
					245, 117, 29, 41, 63, 159, 142, 233,
					125, 148, 123
			};
			break;
		case 60:
			arrays = new int[61]{
					0, 107, 140, 26, 12, 9, 141, 243,
					197, 226, 197, 219, 45, 211, 101, 219,
					120, 28, 181, 127, 6, 100, 247, 2,
					205, 198, 57, 115, 219, 101, 109, 160,
					82, 37, 38, 238, 49, 160, 209, 121,
					86, 11, 124, 30, 181, 84, 25, 194,
					87, 65, 102, 190, 220, 70, 27, 209,
					16, 89, 7, 33, 240
			};
			break;
		case 62:
			arrays = new int[63]{
					0, 65, 202, 113, 98, 71, 223, 248,
					118, 214, 94, 0, 122, 37, 23, 2,
					228, 58, 121, 7, 105, 135, 78, 243,
					118, 70, 76, 223, 89, 72, 50, 70,
					111, 194, 17, 212, 126, 181, 35, 221,
					117, 235, 11, 229, 149, 147, 123, 213,
					40, 115, 6, 200, 100, 26, 246, 182,
					218, 127, 215, 36, 186, 110, 106
			};
			break;
		case 64:
			arrays = new int[65]{
					0, 45, 51, 175, 9, 7, 158, 159,
					49, 68, 119, 92, 123, 177, 204, 187,
					254, 200, 78, 141, 149, 119, 26, 127,
					53, 160, 93, 199, 212, 29, 24, 145,
					156, 208, 150, 218, 209, 4, 216, 91,
					47, 184, 146, 47, 140, 195, 195, 125,
					242, 238, 63, 99, 108, 140, 230, 242,
					31, 204, 11, 178, 243, 271, 156, 213,
					231
			};
			break;
		case 66:
			arrays = new int[67]{
					0, 5, 118, 222, 180, 136, 136, 162,
					51, 46, 117, 13, 215, 81, 17, 139,
					247, 197, 171, 95, 173, 65, 137, 178,
					68, 111, 95, 101, 41, 72, 214, 169,
					197, 95, 7, 44, 154, 77, 111, 236,
					40, 121, 143, 63, 87, 80, 253, 240,
					126, 217, 77, 34, 232, 106, 50, 168,
					82, 76, 146, 67, 106, 171, 25, 132,
					93, 45, 105
			};
			break;
		case 68:
			arrays = new int[69]{
					0, 247, 159, 223, 33, 224, 93, 77,
					70, 90, 160, 32, 254, 43, 150, 84,
					101, 190, 205, 133, 52, 60, 202, 165,
					220, 203, 151, 93, 84, 15, 84, 253,
					173, 160, 89, 227, 52, 199, 97, 95,
					231, 52, 177, 41, 125, 137, 241, 166,
					225, 118, 2, 54, 32, 82, 215, 175,
					198, 43, 238, 235, 27, 101, 184, 127,
					3, 5, 8, 163, 238
			};
			break;
		default:
			throw QRCodeException(qrcode::error::InvalidCorrectionLength);
			break;
	}
}
int qrcode::matrix::getSideLength(BasicInfo * info){
	int res = ((info->getVersion() - 1) << 2) + 21;
	return res;
}
int qrcode::matrix:: getPositionPatternsQuantity(BasicInfo *info){
	int length = 0;
	if (info->getVersion() <= 1){

	}
	else if (info->getVersion() < 7){
		length = 1;
	}
	else if (info->getVersion() < 14){
		length = 6;
	}
	else if (info->getVersion() < 21){
		length = 13; 
	}
	else if (info->getVersion() < 28){
		length = 22;
	}
	else if (info->getVersion() < 34){
		length = 33;
	}
	else if (info->getVersion() < 41){
		length = 46;
	}
	return length;
}
void qrcode::matrix::getPositionPatternsCoordinate(BasicInfo * info,int **&arrs){
	int *position = NULL;
	int len = 0;
	//校正图形的位置 附录E
	switch (info->getVersion()){
	case 1:
	{
	}
	break;
	case 2:
	{
		position = new int[2]{6, 18};
		len = 2;
	}
	break;
	case 3:
	{
		position = new int[2]{6, 22};
		len = 2;
	}
	break;
	case 4:
	{
		position = new int[2]{6, 26};
		len = 2;
	}
	break;
	case 5:
	{
		position = new int[2]{6, 30};
		len = 2;
	}
	break;
	case 6:
	{
		position = new int[2]{6, 34};
		len = 2;
	}
	break;
	case 7:
	{
		position = new int[3]{6, 22, 38};
		len = 3;
	}
	break;
	case 8:
	{
		position = new int[3]{6, 24, 42};
		len = 3;
	}
	break;
	case 9:
	{
		position = new int[3]{6, 26, 46};
		len = 3;
	}
	break;
	case 10:
	{
		position = new int[3]{6, 28, 50};
		len = 3;
	}
	break;
	case 11:
	{
		position = new int[3]{6, 30, 54};
		len = 3;
	}
	break;
	case 12:
	{
		position = new int[3]{6, 32, 58};
		len = 3;
	}
	break;
	case 13:
	{
		position = new int[3]{6, 34, 62};
		len = 3;
	}
	break;
	case 14:
	{
		position = new int[4]{6, 26, 46, 66};
		len = 4;
	}
	break;
	case 15:
	{
		position = new int[4]{6, 26, 48, 70};
		len = 4;
	}
	break;
	case 16:
	{
		position = new int[4]{6, 26, 50, 74};
		len = 4;
	}
	break;
	case 17:
	{
		position = new int[4]{6, 30, 54, 78};
		len = 4;
	}
	break;
	case 18:
	{
		position = new int[4]{6, 30, 56, 82};
		len = 4;
	}
	break;
	case 19:
	{
		position = new int[4]{6, 30, 58, 86};
		len = 4;
	}
	break;
	case 20:
	{
		position = new int[4]{6, 34, 62, 90};
		len = 4;
	}
	break;
	case 21:
	{
		position = new int[5]{6, 28, 50, 72, 94};
		len = 5;
	}
	break;
	case 22:
	{
		position = new int[5]{6, 26, 50, 74, 98};
		len = 5;
	}
	break;
	case 23:
	{
		position = new int[5]{6, 30, 54, 78, 102};
		len = 5;
	}
	break;
	case 24:
	{
		position = new int[5]{6, 28, 54, 80, 106};
		len = 5;
	}
	break;
	case 25:
	{
		position = new int[5]{6, 32, 58, 84, 110};
		len = 5;
	}
	break;
	case 26:
	{
		position = new int[5]{6, 30, 58, 86, 114};
		len = 5;
	}
	break;
	case 27:
	{
		position = new int[5]{6, 34, 62, 90, 118};
		len = 5;
	}
	break;
	case 28:
	{
		position = new int[6]{6, 26, 50, 74, 98, 122};
		len = 6;
	}
	break;
	case 29:
	{
		position = new int[6]{6, 30, 54, 78, 102, 126};
		len = 6;
	}
	break;
	case 30:
	{
		position = new int[6]{6, 26, 52, 78, 104, 130};
		len = 6;
	}
	break;
	case 31:
	{
		position = new int[6]{6, 30, 56, 82, 108, 134};
		len = 6;
	}
	break;
	case 32:
	{
		position = new int[6]{6, 34, 60, 86, 112, 138};
		len = 6;
	}
	break;
	case 33:
	{
		position = new int[6]{6, 30, 58, 86, 114, 142};
		len = 6;
	}
	break;
	case 34:
	{
		position = new int[6]{6, 34, 62, 90, 118, 146};
		len = 6;
	}
	break;
	case 35:
	{
		position = new int[7]{6, 30, 54, 78, 102, 126, 150};
		len = 7;
	}
	break;
	case 36:
	{
		position = new int[7]{6, 24, 50, 76, 102, 128, 154};
		len = 7;
	}
	break;
	case 37:
	{
		position = new int[7]{6, 28, 54, 80, 106, 132, 158};
		len = 7;
	}
	break;
	case 38:
	{
		position = new int[7]{6, 32, 58, 84, 110, 136, 162};
		len = 7;
	}
	break;
	case 39:
	{
		position = new int[7]{6, 26, 54, 82, 110, 138, 166};
		len = 7;
	}
	break;
	case 40:
	{
		position = new int[7]{6, 30, 58, 86, 114, 142, 170};
		len = 7;
	}
	break;
	default:
		break;
	}
	int quantity = qrcode::matrix::getPositionPatternsQuantity(info);
	arrs = new int *[quantity];
	int count = 0;
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			if (i == 0 && j == 0 || i == 0 && j == (len - 1) || j == 0 && i == (len - 1)){
				continue;
			}
			else{
				arrs[count++] = new int[2]{ position[i], position[j]};
			}
		}
	}
	delete position;
	position = NULL;
}
int qrcode::interleave::getSettingsOfEncoding(BasicInfo * info,int *& settings){
	int version = info->getVersion();
	int level = info->getLevel();
	int length = 0;
	switch (version){
		case 1:
			switch (level){
				case qrcode::level::Correction_L:
					settings = new int[2]{1, 19};
					length = 2;
					break;
				case qrcode::level::Correction_M:
					settings = new int[2]{1, 16};
					length = 2;
					break;
				case qrcode::level::Correction_Q:
					settings = new int[2]{1, 13};
					length = 2;
					break;
				case qrcode::level::Correction_H:
					settings = new int[2]{1, 9};
					length = 2;
					break;
				default:
					throw QRCodeException(qrcode::error::InvalidLevel);
					break;
			}
			break;
		case 2:
			switch (level){
				case qrcode::level::Correction_L:
					settings = new int[2]{1, 34};
					length = 2;
					break;
				case qrcode::level::Correction_M:
					settings = new int[2]{1, 28};
					length = 2;
					break;
				case qrcode::level::Correction_Q:
					settings = new int[2]{1, 22};
					length = 2;
					break;
				case qrcode::level::Correction_H:
					settings = new int[2]{1, 16};
					length = 2;
					break;
				default:
					throw QRCodeException(qrcode::error::InvalidLevel);
					break;
			}
			break;
		case 3:
			switch (level){
				case qrcode::level::Correction_L:
					settings = new int[2]{1, 55};
					length = 2;
					break;
				case qrcode::level::Correction_M:
					settings = new int[2]{1, 44};
					length = 2;
					break;
				case qrcode::level::Correction_Q:
					settings = new int[2]{2, 17};
					length = 2;
					break;
				case qrcode::level::Correction_H:
					settings = new int[2]{2, 13};
					length = 2;
					break;
				default:
					throw QRCodeException(qrcode::error::InvalidLevel);
					break;
			}
			break;
		case 4:
			switch (level){
				case qrcode::level::Correction_L:
					settings = new int[2]{1, 80};
					length = 2;
					break;
				case qrcode::level::Correction_M:
					settings = new int[2]{2, 32};
					length = 2;
					break;
				case qrcode::level::Correction_Q:
					settings = new int[2]{2, 24};
					length = 2;
					break;
				case qrcode::level::Correction_H:
					settings = new int[2]{4, 9};
					length = 2;
					break;
				default:
					throw QRCodeException(qrcode::error::InvalidLevel);
					break;
			}
			break;
		case 5:
			switch (level){
				case qrcode::level::Correction_L:
					settings = new int[2]{1, 108};
					length = 2;
					break;
				case qrcode::level::Correction_M:
					settings = new int[2]{2, 43};
					length = 2;
					break;
				case qrcode::level::Correction_Q:
					settings = new int[4]{2, 15, 2, 16};
					length = 4;
					break;
				case qrcode::level::Correction_H:
					settings = new int[4]{2, 11, 2, 12};
					length = 4;
					break;
				default:
					throw QRCodeException(qrcode::error::InvalidLevel);
					break;
			}
			break;
	case 6:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[2]{2, 68};
				length = 2;
				break;
			case qrcode::level::Correction_M:
				settings = new int[2]{4, 27};
				length = 2;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[2]{4, 19};
				length = 2;
				break;
			case qrcode::level::Correction_H:
				settings = new int[2]{4, 15};
				length = 2;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 7:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[2]{2, 78};
				length = 2;
				break;
			case qrcode::level::Correction_M:
				settings = new int[2]{4, 31};
				length = 2;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{2, 14, 4, 15};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{4, 13, 1, 14};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
			}
			break;
	case 8:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[2]{2, 97};
				length = 2;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{2, 38, 2, 39};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{4, 18, 2, 19};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{4, 14, 2, 15};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
			}
			break;
	case 9:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[2]{2, 116};
				length = 2;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{3, 36, 2, 37};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{4, 16, 4, 17};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{4, 12, 4, 13};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 10:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{2, 68, 2, 69};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{4, 43, 1, 44};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{6, 19, 2, 20};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{6, 15, 2, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 11:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[2]{4, 81};
				length = 2;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{1, 50, 4, 51};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{4, 22, 4, 23};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{3, 12, 8, 13};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 12:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{2, 92, 2, 93};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{6, 36, 2, 37};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{4, 20, 6, 21};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{7, 14, 4, 15};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
			}
		break;
	case 13:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[2]{4, 107};
				length = 2;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{8, 37, 1, 38};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{8, 20, 4, 21};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{12, 11, 4, 12};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 14:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{3, 115, 1, 116};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{4, 40, 5, 41};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{11, 16, 5, 17};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{11, 12, 5, 13};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
			}
		break;
	case 15:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{5, 87, 1, 88};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{5, 41, 5, 42};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{5, 24, 7, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{11, 12, 7, 13};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 16:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{5, 98, 1, 99};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{7, 45, 3, 46};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{15, 19, 2, 20};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{3, 15, 13, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 17:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{1, 107, 5, 108};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{10, 46, 1, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{1, 22, 15, 23};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{2, 14, 17, 15};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 18:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{5, 120, 1, 121};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{9, 43, 4, 44};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{17, 22, 1, 23};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{2, 14, 19, 15};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 19:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{3, 113, 4, 114};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{3, 44, 11, 45};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{17, 21, 4, 22};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{9, 13, 16, 14};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 20:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{3, 107, 5, 108};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{3, 41, 13, 42};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{15, 24, 5, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{15, 15, 10, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 21:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{4, 116, 4, 117};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[2]{17, 42};
				length = 2;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{17, 22, 6, 23};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{19, 16, 6, 17};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 22:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{2, 111, 7, 112};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[2]{17, 46};
				length = 2;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{7, 24, 16, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[2]{34, 13};
				length = 2;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 23:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{4, 121, 5, 122};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{4, 47, 14, 48};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{11, 24, 14, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{16, 15, 14, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 24:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{6, 117, 4, 118};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{6, 45, 14, 46};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{11, 24, 16, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{30, 16, 2, 17};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 25:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{8, 106, 4, 107};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{8, 47, 13, 48};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{7, 24, 22, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{22, 15, 13, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 26:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{10, 114, 2, 115};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{19, 46, 4, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{28, 22, 6, 23};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{33, 16, 4, 17};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 27:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{8, 122, 4, 123};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{22, 45, 3, 46};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{8, 23, 26, 24};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{12, 15, 28, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 28:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{3, 117, 10, 118};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{3, 45, 23, 46};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{4, 24, 31, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{11, 15, 31, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 29:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{7, 116, 7, 117};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{21, 45, 7, 46};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{1, 23, 37, 24};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{19, 15, 26, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 30:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{5, 115, 10, 116};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{19, 47, 10, 48};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{15, 24, 25, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{23, 15, 25, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 31:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{13, 115, 3, 116};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{2, 46, 29, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{42, 24, 1, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{23, 15, 28, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 32:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[2]{17, 115};
				length = 2;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{10, 46, 23, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{10, 24, 35, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{19, 15, 35, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 33:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{17, 115, 1, 116};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{14, 46, 21, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{29, 24, 19, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{11, 15, 46, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 34:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{13, 115, 6, 116};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{14, 46, 23, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{44, 24, 7, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{59, 16, 1, 17};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 35:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{12, 121, 7, 122};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{12, 47, 26, 48};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{39, 24, 14, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{22, 15, 41, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 36:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{6, 121, 14, 122};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{6, 47, 34, 48};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{46, 24, 10, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{2, 15, 64, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}	
		break;
	case 37:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{17, 122, 4, 123};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{29, 46, 14, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{49, 24, 10, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{24, 15, 46, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 38:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{4, 122, 18, 123};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{13, 46, 32, 47};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{48, 24, 14, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{42, 15, 32, 16};
				length = 4;
				break;
			default:
				throw QRCodeException(qrcode::error::InvalidLevel);
				break;
		}
		break;
	case 39:
		switch (level){
			case qrcode::level::Correction_L:
				settings = new int[4]{20, 117, 4, 118};
				length = 4;
				break;
			case qrcode::level::Correction_M:
				settings = new int[4]{40, 47, 7, 48};
				length = 4;
				break;
			case qrcode::level::Correction_Q:
				settings = new int[4]{43, 24, 22, 25};
				length = 4;
				break;
			case qrcode::level::Correction_H:
				settings = new int[4]{10, 15, 67, 16};
				length = 4;
				break;
		default:
			throw QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	case 40:
		switch (level){
		case qrcode::level::Correction_L:
			settings = new int[4]{19, 118, 6, 119};
			length = 4;
			break;
		case qrcode::level::Correction_M:
			settings = new int[4]{18, 47, 31, 48};
			length = 4;
			break;
		case qrcode::level::Correction_Q:
			settings = new int[4]{34, 24, 34, 25};
			length = 4;
			break;
		case qrcode::level::Correction_H:
			settings = new int[4]{20, 15, 61, 16};
			length = 4;
			break;
		default:
			throw QRCodeException(qrcode::error::InvalidLevel);
			break;
		}
		break;
	default:
		throw QRCodeException(qrcode::error::InvalidVersion);
		break;
	}
	return length;
}