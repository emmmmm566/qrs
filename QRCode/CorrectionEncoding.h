#ifndef Correction_Encoding_H
#define Correction_Encoding_H
#include "BasicInfo.h"
#include <string>
namespace qrcode{
	class CorrectionEncoding{
	private:
		BasicInfo * baisc_info;
		int * result;
		void Combine();
	public:
		CorrectionEncoding();
		~CorrectionEncoding();
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
		* @param <code>std::string &</code> object,to caculate the correctionEncoding
		* @return std::string correctionEncoding
		*/
		std::string Encode(std::string &);
		/**
		* @param <code>std::string &</code> object,to caculate the correctionEncoding
		* @return std::string correctionEncoding
		*/
		std::string Encode(const char *);
		
	};
}
#endif