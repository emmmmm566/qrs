#ifndef QRCode_TOOL_H
#define QRCode_TOOL_H
#include <string>
#include "BasicInfo.h"
#include "QRCodeException.h"
namespace qrcode{
	namespace character_count_indicator{
		//表3 字符计数指示符的位数
		int length(BasicInfo * const);
	}
	namespace data_encoding{
		//表7 QR码符号字符数和数据容量 数据码字数
		int length(BasicInfo * const);
	}
	namespace correction_encoding{
		//表9 QR码符号各版本的纠错特性 纠错码字数
		int length(BasicInfo * const);
		int getPolynomeAlpha(BasicInfo * const,int *& arrays);
		
		int getModulus(int length, int position);
		void getMidModulus(int begin,int end,const int position,int &res);
	}
	namespace interleave{
		// @param settings[0] = Number of Blocks in Group 1,
		// settings[1] = Number of Data Codewords in Each of Group 1's Blocks
		// settings[2] = Number of Blocks in Group 2,
		// settings[3] = Number of Data Codewords in Each of Group 1's Blocks
		// @return <code>int</code> the length of settings array;
		int getSettingsOfEncoding(BasicInfo * const,int *& settings);
	}
	namespace matrix{
		int getSideLength(BasicInfo *);
		void getPositionPatternsCoordinate(BasicInfo * const,int **& arrays);
		int getPositionPatternsQuantity(BasicInfo *);
	}
	namespace tool{
		/**
		 *
		 * @param <code>std::string</code> object
		 * 
		 * @return <code>true</code> if the object is
		 * pure digital,otherwise return <code>false</code> 
		 *
		 */
		bool is_pure_digital(const std::string & src);
		/**
		 *
		 * @param <code>std::string &</code> source
		 *
		 * @return the code converted from number mode
		 */
		std::string number_mode_encoding(const std::string & src);
		/**
		 *
		 * @param <code>std::string</code> source
		 *
		 * @return <code>std::string</code> object
		 *  converted from decimal to binary 
		 * 
		 * 
		 */
		std::string decimal_to_binary(int src);
	}
};
#endif