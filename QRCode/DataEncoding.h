#ifndef QRCode_Data_Encoding_H
#define QRCode_Data_Encoding_H
#include "ModeEncoding.h"
#include <string>
#include "QRCodeException.h"
namespace qrcode{

	class DataEncoding{
	private:
		int character_count_indicator;
		int mode_indicator;
		BasicInfo * basic_info;
		ModeEncoding * mode_encoding;
		/*
		 * This Function is used to Combine Data Information
		 * @param const char *
		 * @return the result
		 */
		std::string Combine(const char *src);
	public:
		/*
		 * Construct
		 */
		DataEncoding();
		/*
		 * Deconstruct
		 */
		~DataEncoding();
		/**
		* @param <code>BasicInfo *</code> object,to set the basic_info of
		* QRCode .version,mode,and correct_level;
		*/
		void setBasicInfo(BasicInfo *);
		/**
		* @return <code>BasicInfo *</code> object,to get the basic_info of
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
		std::string Encode(char *src);
		/**
		*
		* @param <code>const char *</code> object,the source of code
		* to encode, <code>int</code>,Number_Mode,Chinese_Mode
		* Byte_Mode,Letter_Mode.
		* @return <code>std::string</code> data encoding
		*
		*
		*/
		std::string Encode(const char *src);
		/**
		*
		* @param <code>std::string &</code> object,the source of code
		* to encode, <code>int</code>,Number_Mode,Chinese_Mode
		* Byte_Mode,Letter_Mode.
		* @return <code>std::string</code> data encoding
		*
		*
		*/
		std::string Encode(std::string & src);
	};

};

#endif