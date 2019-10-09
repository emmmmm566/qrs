#include "QRCodeEncoding.h"
std::string qrcode::QRCodeEncoding::Combine(std::string & dataCode,std::string &errorCode){
	std::string res = "";
	int *settings = NULL;
	int size = qrcode::interleave::getSettingsOfEncoding(basic_info, settings);
	// a group
	if (size == 2){
		{
			int blocks_length = settings[1];
			int blocks_number = settings[0];
			//the first group blocks init;
			std::string * blocks = new std::string[blocks_number];
			for (int i = 0; i < blocks_number; i++){
				blocks[i] = std::string(dataCode, (blocks_number + i) << 3, (blocks_length) << 3);
			}
			for (int i = 0; i < blocks_length; i++){
				for (int j = 0; j < blocks_number; j++){
					res += blocks[j].substr(i << 3, 8);
				}
			}
			delete[]blocks;
			blocks = NULL;
		}
		{
			
			int blocks_number = settings[0];
			int error_length = qrcode::correction_encoding::length(this->basic_info) / blocks_number;
			std::string * blocks = new std::string[blocks_number];
			for (int i = 0; i < blocks_number; i++){
				blocks[i] = std::string(errorCode, (blocks_number + i) << 3, (error_length) << 3);
			}
			for (int i = 0; i < error_length; i++){
				for (int j = 0; j < blocks_number; j++){
					res += blocks[j].substr(i << 3, 8);
				}
			}
			delete[]blocks;
			blocks = NULL;
		}
		
	}
	// two groups
	else if(size == 4){
		//  DataCode Encoding!!!
		//	Let's see how this program work!
		//  We have two groups at the current time,and it seems like the table as follow.
		//    
		//  group 1: block1          byte1 byte2 byte3 ... byte8
		//           block2          byte9 ...             byte16
		//           block3
		//             ...
		//           block10                               byte80 
		//  group 2:
		//           block1          byte1 ...             byte8 byte9
		//           block2          
		//           block3 
		//		       ...
		//           block8                                      byte72
		// 
		// Let's mark the table now.
		//                           A1,A2,A3...A8
		//		FIRST GROUP			 A9...
		//                           ...        A80
		//     
		//      SECOND GROUP         B1...      B8,B9
		//                           ...        ...
		//                                        ,B72
		//		THE REAL SEQUENCE GOES  A1+A9+...+A73+B1+B10+...B64
		//								+A2+A10+...A74 + B2+B11+B65
		//								+...+
		//								+A8+...+A80+B8+...     +B71
		//								+B9+B18+B27+...		   +B72
		//      this function is not the best,because it used std::string to make the sequence.
		//      you can use int arrays to make it,just for fun.
		int f_blocks_length = settings[1];
		int f_blocks_number = settings[0];
		int s_blocks_length = settings[3];
		int s_blocks_number = settings[2];
		//the first group blocks init;
		std::string * f_blocks = new std::string[f_blocks_number];
		for (int i = 0; i < f_blocks_number; i++){
			f_blocks[i] = std::string(dataCode, (f_blocks_number + i) << 3, (f_blocks_length) << 3);
		}
		//the second group blocks init;
		std::string * s_blocks = new std::string[s_blocks_number];
		for (int i = 0; i < s_blocks_number; i++){
			s_blocks[i] = std::string(dataCode, (s_blocks_number + i) << 3, (s_blocks_length) << 3);
		}
		for (int i = 0; i < f_blocks_length; i++){
			//first group blocks;
			for (int j = 0; j < f_blocks_number; j++){
				res += f_blocks[j].substr(i << 3, 8);
			}
			//second group blocks;
			for (int j = 0; j < s_blocks_number; j++){
				res += s_blocks[j].substr(i << 3, 8);
			}
		}
		//second blocks length= 1 + first blocks length
		for (int j = 0; j < s_blocks_number; j++){
			res += s_blocks[j].substr(f_blocks_length << 3, 8);
		}

		delete[]f_blocks;
		f_blocks = NULL;

		delete[]s_blocks;
		s_blocks = NULL;
		// CorrectionCode Encoding!!!
		// it is so easy to understand.
		// we have two groups.
		//                           A1,A2,A3...A8
		//		FIRST GROUP			 A9...
		//                           ...        A80
		//     
		//      SECOND GROUP         B1...      B8,B9
		//                           ...        ...
		//                           B64          ,B72
		// we divide the correctionCode with the length of (A1 to B64)
		// JUST FOR THE LENGTH OF COLUMN ,DON'T BE FROM A1-A8(8)+....+B64
		// JUST A1 A9...A73(10) B1 ...B64(8)  IT WAS JUST 18.
		{

			int blocks_number = settings[0] + settings[2];
			int error_length = qrcode::correction_encoding::length(this->basic_info) / blocks_number;
			std::string * blocks = new std::string[blocks_number];
			for (int i = 0; i < blocks_number; i++){
				blocks[i] = std::string(errorCode, (blocks_number + i) << 3, (error_length) << 3);
			}
			for (int i = 0; i < error_length; i++){
				for (int j = 0; j < blocks_number; j++){
					res += blocks[j].substr(i << 3, 8);
				}
			}
			delete[]blocks;
			blocks = NULL;
		}
	}
	delete settings;
	settings = NULL;
	return res;
}
void qrcode::QRCodeEncoding::setBasicInfo(BasicInfo * info){
	this->basic_info = info;
}
qrcode::BasicInfo * qrcode::QRCodeEncoding::getBasicInfo(){
	return this->basic_info;
}