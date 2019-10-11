#ifndef Combination_H
#define Combination_H
#include "BasicInfo.h"
#include "Tool.h"
namespace qrcode{
	// qrcode::Combination
	
	// ���ݾ������ɶ���ʽ f(x)=(x-a^0)(x-a^1)(x-a^2)...(x-a^n-1);
	
	// a �� ������ GF(2^8) �� 285ȡģ

	// �ö���ʽ��alphaϵ��(a) ������qrcode::Alpha������ ���� �� ���� ������ ;
	
	// ��alphaϵ��תֵ��Ϊ������ ���ɴ�����תΪalphaϵ��

	// �� f(x) �е� �߼��� �� �߼�ָ�� ������ ��ѧ��ѧ�� �� �ӷ� �� �˷� ����

	// ��GF(2^8)��,��ֵ����ֵ������ͬ��ֵ,��ô

	// �� n = 2 ʱ,f(x) = x^2 +(a^0��a^1) x + a^0��a^1

	// �� n = 3 ʱ,f(x) = x^3 + (a^0��a^1��a^2) x^2 + (a^0��a^1��a^0��a^2��a^1��a^2) x^1 + a^0��a^1��a^2

	// ���ǿ��Զ� f(x) ������������,Ϊ�˸�ֱ�۵ı�ʾ,����a^0 Ϊa(0), a^1Ϊa(1) ... a^n-1Ϊa(n-1)

	// �� Ϊ �������

	// ������ʡ���ˡ�����

	// ����1)

	// ��һ��ϵ�� 1

	// �ڶ���ϵ�� a0��....��an-1

	// ������ϵ�� a(0)a(1)��a(0)a(2)��....��a(n-2)a(n-1)

	// �ɴ� �Ƶ� ��k��(k>2) ��ϵ��, a0a1....ak-2��...��a(n-k+1)...a(n-1)(ÿ����k-1��)

	// ��GF(2^8) �� a0a1...ak-1=a^(0+1+...+k-1)

	// ����, ��ʼչʾ qrcode::Combination �����㷨��

	// ʵ�ʾ��� �� ������ ��ʾ �������λ��

	// ��1:���� 0,1,2,3 ���ɵ��������

	// ������1) ��һ�� 1;
	//          �ڶ��� a0��....��a2;
	//          ������ a(0)a(1)��a(0)a(2)��....��a(1)a(2);
	//          ������ a(0)a(1)(a2)��....��a(1)a(2)(a3);
	//          ������ a(0)a(1)a(2)a(3)

	// ���ǿ�������һ������ Ϊ (2^4-1) �������� �������б�ʾΪ 1111;

	// ��ô 0001~1111 �Ϳ��Ա�ʾ ��1 �����е�Ԫ��

	// �� 0001 ��ʾΪ0  0010��ʾΪ1  0100��ʾΪ2  1000��ʾΪ3

	// �ɴ� ���������������

	// @param combination ԭʼ������1�������,������� ������ 255,127,63,31,15,7,3,1 ���

	// ����n=40,level=Hʱ,����������Ϊ2430,������Ҫ�������Ϊ303����255;

	// ��Ͳ��������Ǽ�����Ҫ����77265��,���ܻ�ȡһ��ϵ��

	// ��2430�ж�����,��2431��
	
	// ��Ҫ�˽����QR��ϸ�� ���� https://www.thonky.com/qr-code-tutorial/error-correction-coding

	class Combination{
	private:
		// ����������
		int length;
		// ��ȫ��1��ɵ��������� 0xff 0x7f 0x3f 0x1f 0x0f 0x07 0x03 0x01
		int * combination;
		// ��������ĳ���
		int combination_length;
		// �������ֶ���ʽalphaϵ��
		int * polynomeAlpha;
		// ��ʼ�� ��������
		void initCombination();
		// 00001 ����0 00011����01
		// 00010 ����1
		// 00100 ����2
		// 01000 ����3
		// 10000 ����4
		int getCombineNumber(int poisition);
		BasicInfo * basic_info;
	public:
		void setBasicInfo(BasicInfo * const);
		BasicInfo * getBasicInfo();
		void caculatePolynomeAlpha();
		int * getPolynomeAlpha();
		Combination();
		~Combination();

	};
}
#endif