#ifndef BasicInfo_H
#define BasicInfo_H
namespace qrcode{
	static enum{
		Correction_L = 0,
		Correction_M,
		Correction_Q,
		Correction_H
	}correction_level;
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
	class BasicInfo{
	private:
		int version;
		int mode;
		int level;
	public:
		void setVerison(int arg);
		void setMode(int arg);
		void setLevel(int arg);
		int  getVersion();
		int  getMode();
		int  getLevel();
		BasicInfo(int version,int mode,int level);
		~BasicInfo();
	};
};
#endif