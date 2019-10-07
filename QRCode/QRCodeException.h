#ifndef QRCode_Exception_H
#define QRCode_Exception_H
#include <exception>
#include <string>
namespace qrcode{
	namespace error{
		enum ExceptionMessage
		{
			InvalidVersion,
			InvalidMode,
			InvalidLevel,
			InvalidCorrectionLength,

		};
	}
	class QRCodeException : public std::exception{
	public:
		const char * what(const char * msg)const throw(){
			return msg;
		};
		QRCodeException(unsigned int code){
			switch (code)
			{
			case error::InvalidMode:
				what("Invalid Mode");
				break;
			case error::InvalidVersion:
				what("Invalid Version");
				break;
			case error::InvalidLevel:
				what("Invalid Level");
				break;
			case error::InvalidCorrectionLength:
				what("Invalid Correction Length");
				break;
			default:
				break;
			}
		}
	};
	
	
}
#endif