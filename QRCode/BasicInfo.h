#ifndef QRCode_BasicInfo_H
#define QRCode_BasicInfo_H
#include <exception>
namespace qrcode{
	namespace level{
		static enum{
			Correction_L = 0,
			Correction_M,
			Correction_Q,
			Correction_H
		}correction_level;
	}
	
	namespace mode{
		static enum{
			ECI_Mode = 0,
			Number_Mode,
			Letter_Mode,
			Byte_Mode,
			Chinese_Mode,
			Link_Mode,
			FNC1_First_Mode,
			FNC1_Second_Mode,
			End_Mode
		}mode_sign;
	}
	
	class BasicInfo{
	private:
		int version;
		int mode;
		int level;
	public:
		/**
		 *
		 * @param <code>int</code> object
		 *	set Version from 1 to 40
		 * @void 
		 * @throw arg not in [1,40]
		 *
		 */
		void setVerison(int arg);
		/**
		 *
		 *
		 *
		 *
		 *
		 */
		void setMode(int arg);
		void setLevel(int arg);
		const int  getVersion();
		int  getMode();
		int  getLevel();
		BasicInfo(int version,int mode,int level);
		~BasicInfo();
	};
};
#endif