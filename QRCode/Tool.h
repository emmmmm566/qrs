#ifndef QRCode_TOOL_H
#define QRCode_TOOL_H
#include <string>
#include "BasicInfo.h"
#include "QRCodeException.h"
namespace qrcode{
	namespace character_count_indicator{
		//��3 �ַ�����ָʾ����λ��
		int length(BasicInfo * const);
	}
	namespace data_encoding{
		//��7 QR������ַ������������� ����������
		int length(BasicInfo * const);
	}
	namespace correction_encoding{
		//��9 QR����Ÿ��汾�ľ������� ����������
		int length(BasicInfo * const);
		int getPolynomeAlpha(BasicInfo * const,int * arrays);
		int code_to_polynome(std::string &,int * arrays);
	}
	namespace tool{
		/**
		 *
		 * @param <code>std::string</code> object
		 * 
		 * @return <code>true</code> if the object is
		 * pure digital,otherwise return <code>false</code> 
		 *
		 */
		bool is_pure_digital(const std::string & src);
		/**
		 *
		 * @param <code>std::string &</code> source
		 *
		 * @return the code converted from number mode
		 */
		std::string number_mode_encoding(const std::string & src);
		/**
		 *
		 * @param <code>std::string</code> source
		 *
		 * @return <code>std::string</code> object
		 *  converted from decimal to binary 
		 * 
		 * 
		 */
		std::string decimal_to_binary(int src);
	}
};
#endif