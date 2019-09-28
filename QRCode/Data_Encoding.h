#ifndef QRCode_Data_Encoding_H
#define QRCode_Data_Encoding_H
#include "Mode_Encoding.h"
#include <string>
namespace qrcode{
	class Data_Encoding{
	private:
		int character_count_indicator;
		BasicInfo * basic_info;
		Mode_Encoding mode_encoding;
	public:
		/*
		 * Construct
		 */
		Data_Encoding();
		/*
		 * Deconstruct
		 */
		~Data_Encoding();
		/**
		* @param <code>BasicInfo *</code> object,to set the basicInfo of
		* QRCode .version,mode,and correct_level;
		*/
		void setBasicInfo(BasicInfo *);
		/**
		* @return <code>BasicInfo *</code> object,to get the basicInfo of
		* QRCode .version,mode,and correct_level;
		*/
		BasicInfo * getBasicInfo();
		/**
		*
		* @param <code>char *</code> object,the source of code
		* to encode, <code>int</code>,Number_Mode,Chinese_Mode
		* Byte_Mode,Letter_Mode.
		* @return <code>std::string</code> data encoding
		*
		*
		*/
		std::string Encode(char *src, int mode);
		/**
		*
		* @param <code>char *</code> object,the source of code
		* to encode, <code>int</code>,Number_Mode,Chinese_Mode
		* Byte_Mode,Letter_Mode.
		* @return <code>std::string</code> data encoding
		*
		*
		*/
		std::string Encode(const char *src, int mode);
		/**
		*
		* @param <code>char *</code> object,the source of code
		* to encode, <code>int</code>,Number_Mode,Chinese_Mode
		* Byte_Mode,Letter_Mode.
		* @return <code>std::string</code> data encoding
		*
		*
		*/
		std::string Encode(std::string & src, int mode);
	};

};

#endif