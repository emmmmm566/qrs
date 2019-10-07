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
			{
				int lens[4] = { 41, 34, 27, 17 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 25, 20, 16, 10 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 17, 14, 11, 7 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 10, 8, 7, 4 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 2:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 77, 63, 48, 34 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 47, 38, 29, 20 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 32, 26, 20, 14 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 20, 16, 12, 8 };
				length = lens[_level];
				break;
			}
			
		}
		break;
	case 3:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 127, 101, 77, 58 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 77, 61, 47, 35 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 53, 42, 32, 24 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 32, 26, 20, 15 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 4:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 187, 149, 111, 82 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 114, 90, 67, 34 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 78, 62, 46, 34 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 48, 38, 28, 21 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 5:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 255, 202, 144, 106 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 154, 122, 87, 64 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 106, 84, 60, 44 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 65, 52, 37, 27 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 6:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 322, 255, 178, 139 };
				length = lens[_level];
				break;
			}	
			case mode::Letter_Mode:
			{
				int lens[4] = { 195, 154, 108, 84 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 134, 106, 74, 58 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 82, 65, 45, 36 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 7:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 370, 293, 207, 154 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 224, 178, 125, 93 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 154, 122, 86, 64 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 95, 75, 53, 39 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 8:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 461, 365, 259, 202 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 279, 221, 157, 122 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 192, 152, 108, 84 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 118, 93, 56, 52 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 9:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 552, 432, 312, 235 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 335, 262, 189, 143 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 230, 180, 130, 98 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 141, 111, 80, 60 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 10:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 652, 513, 364, 288 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 395, 311, 221, 174 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 271, 213, 151, 119 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 167, 131, 93, 74 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 11:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 772, 604, 427, 331 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 468, 366, 259, 200 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 321, 251, 177, 137 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 198, 155, 109, 85 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 12:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 883, 691, 489, 374 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 535, 419, 296, 227 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 367, 287, 203, 155 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 226, 177, 125, 96 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 13:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 1022, 796, 580, 427 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 619, 483, 352, 259 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 425, 331, 241, 177 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 262, 204, 149, 109 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 14:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 1101, 871, 621, 468 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 667, 528, 376, 283 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 458, 362, 258, 194 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 282, 223, 159, 120 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 15:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 1250, 991, 703, 530 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 758, 600, 426, 321 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 520, 412, 292, 220 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 320, 254, 180, 136 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 16:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 1408, 1082, 775, 602 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 854, 656, 470, 365 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 586, 450, 322, 250 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 361, 277, 198, 154 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 17:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 1548, 1212, 876, 674 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 938, 734, 531, 408 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 644, 504, 364, 280 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 397, 310, 224, 173 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 18:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 1725, 1346, 948, 746 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1046, 816, 574, 452 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 718, 560, 394, 310 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 442, 345, 243, 191 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 19:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 1903, 1500, 1063, 813 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1153, 909, 644, 493 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 792, 624, 442, 338 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 488, 384, 272, 208 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 20:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 2061, 1600, 1159, 919 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1249, 970, 702, 557 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 858, 666, 482, 382 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 528, 410, 297, 235 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 21:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 2232, 1708, 1224, 969 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1352, 1035, 742, 587 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 929, 711, 509, 403 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 572, 438, 314, 248 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 22:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 2409, 1872, 1358, 1056 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1460, 1134, 823, 640 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1003, 779, 565, 439 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 618, 480, 348, 270 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 23:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 2620, 2059, 1468, 1108 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1588, 1248, 890, 672 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1091, 857, 611, 461 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 672, 528, 376, 284 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 24:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 2812, 2188, 1588, 1228 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1704, 1326, 963, 744 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1171, 911, 661, 511 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 721, 561, 407, 315 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 25:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 3057, 2395, 1718, 1286 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1853, 1451, 1041, 779 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1273, 997, 715, 535 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 784, 614, 440, 330 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 26:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 3283, 2544, 1804, 1425 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 1990, 1542, 1094, 864 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1367, 1059, 751, 593 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 842, 652, 462, 365 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 27:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 3517, 2701, 1933, 1501 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 2132, 1637, 1172, 910 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1465, 1125, 805, 625 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 902, 692, 496, 385 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 28:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 3669, 2857, 2085, 1581 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 2223, 1732, 1263, 958 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1528, 1190, 868, 658 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 940, 732, 534, 405 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 29:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 3909, 3035, 2181, 1677 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 2369, 1839, 1322, 1016 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1628, 1264, 908, 698 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1002, 778, 559, 430 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 30:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 4158, 3289, 2358, 1782 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 2520, 1994, 1429, 1080 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1732, 1370, 982, 742 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1066, 843, 604, 457 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 31:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 4417, 3486, 2473, 1897 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 2677, 2113, 1499, 1150 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1840, 1452, 1030, 790 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1132, 894, 634, 486 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 32:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 4686, 3693, 2670, 2022 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 2840, 2238, 1618, 1226 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 1952, 1538, 1112, 842 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1201, 947, 684, 518 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 33:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 4965, 3909, 2805, 2157 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 3009, 2369, 1700, 1307 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2068, 1628, 1168, 898 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1273, 1002, 719, 553 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 34:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 5253, 4134, 2949, 2301 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 3183, 2506, 1787, 1394 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2188, 1722, 1228, 958 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1347, 1060, 756, 590 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 35:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 5529, 4343, 3081, 2361 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 3351, 2632, 1867, 1431 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2303, 1809, 1283, 983 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1417, 1113, 790, 605 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 36:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 5836, 4588, 3244, 2524 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 3537, 2780, 1966, 1530 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2431, 1911, 1351, 1051 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1496, 1176, 832, 647 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 37:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 6153, 4775, 3417, 2625 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 3729, 2894, 2071, 1591 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2563, 1989, 1423, 1093 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1577, 1224, 876, 673 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 38:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 6479, 5039, 3599, 2735 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 3927, 3054, 2181, 1658 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2699, 2099, 1499, 1139 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1661, 1292, 923, 701 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 39:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 6743, 5313, 3791, 2927 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 4087, 3220, 2298, 1774 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2809, 2213, 1579, 1219 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1729, 1362, 972, 750 };
				length = lens[_level];
				break;
			}
		}
		break;
	case 40:
		switch (_mode){
			case mode::Number_Mode:
			{
				int lens[4] = { 7089, 5596, 3993, 3057 };
				length = lens[_level];
				break;
			}
			case mode::Letter_Mode:
			{
				int lens[4] = { 4296, 3391, 2420, 1852 };
				length = lens[_level];
				break;
			}
			case mode::Byte_Mode:
			{
				int lens[4] = { 2953, 2331, 1663, 1273 };
				length = lens[_level];
				break;
			}
			case mode::Chinese_Mode:
			{
				int lens[4] = { 1817, 1435, 1024, 784 };
				length = lens[_level];
				break;
			}
		}
		break;
	}
	return length;

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