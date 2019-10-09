#ifndef QRCodeEncoding_H
#define QRCodeEncoding_H
#include "BasicInfo.h"
#include "Tool.h"
#include <string>
namespace qrcode{
	class QRCodeEncoding{
		BasicInfo * basic_info;
		
	public:
		void setBasicInfo(BasicInfo * const);
		BasicInfo * getBasicInfo();
		std::string Combine(std::string & dataCode, std::string & errorCorrectionCode);
	};
}

#endif