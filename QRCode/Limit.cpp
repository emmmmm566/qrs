#include "Limit.h"
int qrcode::limit::length(BasicInfo * info){
	int _level = info->getLevel();
	int _version = info->getVersion();
	int _mode = info->getMode();
	int length = 0;
	if (_level > 3 || _level < 0){
		throw QRCodeException(qrcode::error::InvalidLevel);
	}
	if (_version > 40 || _version < 1){
		throw QRCodeException(qrcode::error::InvalidVersion);
	}
	switch (_version){
	case 1:
		switch (_mode){
		case mode::Number_Mode:
			int lens[4] = { 41, 34, 27, 17 };
			length = lens[_level];
			break;
		case mode::Letter_Mode:
			int lens[4] = { 25, 20, 16, 10 };
			length = lens[_level];
			break;
		case mode::Byte_Mode:
			int lens[4] = { 17, 14, 11, 7 };
			length = lens[_level];
			break;
		case mode::Chinese_Mode:
			int lens[4] = { 10, 8, 7, 4 };
			length = lens[_level];
			break;
		}
		break;
	case 2:
		switch (_mode){
		case mode::Number_Mode:
			int lens[4] = { 0, 0, 0, 0 };
			length = lens[_level];
			break;
		case mode::Letter_Mode:
			break;
		case mode::Byte_Mode:
			break;
		case mode::Chinese_Mode:
			break;
		}
		break;
	case 3:
		switch (_mode){
		case mode::Number_Mode:
			break;
		case mode::Letter_Mode:
			break;
		case mode::Byte_Mode:
			break;
		case mode::Chinese_Mode:
			break;
		}
		break;
	case 4:
		switch (_mode){
		case mode::Number_Mode:
			break;
		case mode::Letter_Mode:
			break;
		case mode::Byte_Mode:
			break;
		case mode::Chinese_Mode:
			break;
		}
		break;
	case 5:
		switch (_mode){
		case mode::Number_Mode:
			break;
		case mode::Letter_Mode:
			break;
		case mode::Byte_Mode:
			break;
		case mode::Chinese_Mode:
			break;
		}
		break;
	case 6:
		switch (_mode){
		case mode::Number_Mode:
			break;
		case mode::Letter_Mode:
			break;
		case mode::Byte_Mode:
			break;
		case mode::Chinese_Mode:
			break;
		}
		break;
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 38:
	case 39:
	case 40:

	}

	//switch (_version)
	//{
	//	case 1:
	//		switch (_level){
	//			case level::Correction_L:
	//				switch (_mode){
	//					case mode::Number_Mode:
	//						length = 41;
	//						break;
	//					case mode::Letter_Mode:
	//						length = 25;
	//						break;
	//					case mode::Byte_Mode:
	//						length = 17;
	//						break;
	//					case mode::Chinese_Mode:
	//						length = 10;
	//						break;
	//					default:
	//						throw QRCodeException(qrcode::error::InvalidMode);
	//						break;
	//				}
	//				break;
	//			case level::Correction_M:
	//				switch (_mode){
	//					case mode::Number_Mode:
	//						length = 34;
	//						break;
	//					case mode::Letter_Mode:
	//						length = 20;
	//						break;
	//					case mode::Byte_Mode:
	//						length = 14;
	//						break;
	//					case mode::Chinese_Mode:
	//						length = 8;
	//						break;
	//					default:
	//						throw QRCodeException(qrcode::error::InvalidMode);
	//						break;
	//				}
	//				break;
	//			case level::Correction_Q:
	//				switch (_mode){
	//					case mode::Number_Mode:
	//						length = 27;
	//						break;
	//					case mode::Letter_Mode:
	//						length = 16;
	//						break;
	//					case mode::Byte_Mode:
	//						length = 11;
	//						break;
	//					case mode::Chinese_Mode:
	//						length = 7;
	//						break;
	//					default:
	//						throw QRCodeException(qrcode::error::InvalidMode);
	//						break;
	//				}
	//				break;
	//			case level::Correction_H:
	//				switch (_mode){
	//					case mode::Number_Mode:
	//						length = 17;
	//						break;
	//					case mode::Letter_Mode:
	//						length = 10;
	//						break;
	//					case mode::Byte_Mode:
	//						length = 7;
	//						break;
	//					case mode::Chinese_Mode:
	//						length = 4;
	//						break;
	//				default:
	//					throw QRCodeException(qrcode::error::InvalidMode);
	//					break;
	//				}
	//				break;
	//			default:
	//				throw QRCodeException(qrcode::error::InvalidLevel);
	//				break;
	//		}
	//		break;
	//	case 2:
	//		switch (_level){
	//			case level::Correction_L:
	//				switch (_mode){
	//					case mode::Number_Mode:
	//						break;
	//					case mode::Letter_Mode:
	//						break;
	//					case mode::Byte_Mode:
	//						break;
	//					case mode::Chinese_Mode:
	//						break;
	//					default:
	//						throw QRCodeException(qrcode::error::InvalidMode);
	//						break;
	//				}
	//				break;
	//			case level::Correction_M:
	//				break;
	//			case level::Correction_Q:
	//				break;
	//			case level::Correction_H:
	//				break;
	//			default:
	//				throw QRCodeException(qrcode::error::InvalidLevel);
	//				break;
	//		}
	//		break;
	//	case 3:
	//		switch (_level){
	//			case level::Correction_L:
	//				break;
	//			case level::Correction_M:
	//				break;
	//			case level::Correction_Q:
	//				break;
	//			case level::Correction_H:
	//				break;
	//			default:
	//				throw QRCodeException(qrcode::error::InvalidLevel);
	//				break;
	//		}
	//		break;
	//	case 4:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 5:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 6:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 7:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 8:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 9:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 10:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 11:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 12:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 13:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 14:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 15:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 16:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 17:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 18:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 19:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 20:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 21:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 22:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 23:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 24:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 25:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 26:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 27:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 28:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 29:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 30:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 31:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 32:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 33:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 34:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 35:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 36:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 37:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 38:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 39:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	case 40:
	//		switch (_level){
	//		case level::Correction_L:
	//			break;
	//		case level::Correction_M:
	//			break;
	//		case level::Correction_Q:
	//			break;
	//		case level::Correction_H:
	//			break;
	//		default:
	//			throw QRCodeException(qrcode::error::InvalidLevel);
	//			break;
	//		}
	//		break;
	//	default:
	//		throw QRCodeException(qrcode::error::InvalidVersion);
	//		break;
	//}
}