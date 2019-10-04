#ifndef QRCode_Encoding_H
#define QRCode_Encoding_H
#include "BasicInfo.h"
#include "Tool.h"
#include <string>
namespace qrcode{
	
	class ModeEncoding{
	private:
		int length;
		/**
		 *
		 * @param <code>char *</code> object
		 *
		 * @return <code>std::string</code> "" if the object is
		 * not pure digital,otherwise return <code>std::string</code>
		 * code which is encoded by number mode; 
		 */
		std::string numberModeEncoding(char *);
		std::string chineseModeEncoding(char *);
		std::string byteModeEncoding(char *);
		std::string letterModeEncoding(char *);

		/**
		 *
		 * @param <code>const char *</code> object
		 *
		 * @return <code>std::string</code> "" if the object is
		 * not pure digital,otherwise return <code>std::string</code>
		 * code which is encoded by number mode;
		 */
		std::string numberModeEncoding(const char *src);
		std::string chineseModeEncoding(const char *src);
		std::string byteModeEncoding(const char *src);
		std::string letterModeEncoding(const char *src);

		/**
		 *
		 * @param <code>std::string</code> object
		 *
		 * @return <code>std::string</code> "" if the object is
		 * not pure digital,otherwise return <code>std::string</code>
		 * code which is encoded by number mode;
		 */
		std::string numberModeEncoding(std::string & src);
		std::string chineseModeEncoding(std::string & src);
		std::string byteModeEncoding(std::string & src);
		std::string letterModeEncoding(std::string & src);

	public:
		std::string Encode(char *src,int mode);
		std::string Encode(const char *src, int mode);
		std::string Encode(std::string & src, int mode);

		int getSourceLength();
		ModeEncoding();
		~ModeEncoding();
	};
};

#endif