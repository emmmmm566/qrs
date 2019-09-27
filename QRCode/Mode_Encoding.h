#ifndef Encoding_H
#define Encoding_H
#include "BasicInfo.h"
#include <string>
namespace qrcode{
	class Mode_Encoding{
	private:
		int length;

		std::string Number_Mode_Encoding(char *);
		std::string Chinese_Mode_Encoding(char *);
		std::string Byte_Mode_Encoding(char *);
		std::string Letter_Mode_Encoding(char *);

		std::string Number_Mode_Encoding(const char *src);
		std::string Chinese_Mode_Encoding(const char *src);
		std::string Byte_Mode_Encoding(const char *src);
		std::string Letter_Mode_Encoding(const char *src);

		std::string Number_Mode_Encoding(std::string src);
		std::string Chinese_Mode_Encoding(std::string src);
		std::string Byte_Mode_Encoding(std::string src);
		std::string Letter_Mode_Encoding(std::string src);
	public:
		std::string Encode(char *src,int mode);
		std::string Encode(const char *src, int mode);
		std::string Encode(std::string src, int mode);

		int Get_Source_Length();
	};
};

#endif