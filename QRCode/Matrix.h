#ifndef Matrix_H
#define Matrix_H
#include "BasicInfo.h"
#include "Tool.h"
namespace qrcode{
	class Matrix{
	private:
		int ** matrix;
		BasicInfo * basic_info;
		void finderPatterns(int x, int y);
		void positionPatterns(int x, int y);
		void positionLine();
		void initMatrix();
		void destoryMatrix();
	public:
		void setBasicInfo(BasicInfo * info);
		BasicInfo * getBasicInfo();
		int ** getMatrix();
		void Combine();
		Matrix();
		~Matrix();
	};
}
#endif