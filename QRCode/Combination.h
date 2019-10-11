#ifndef Combination_H
#define Combination_H
#include "BasicInfo.h"
#include "Tool.h"
namespace qrcode{
	// qrcode::Combination
	
	// 根据纠错生成多项式 f(x)=(x-a^0)(x-a^1)(x-a^2)...(x-a^n-1);
	
	// a 是 有限域 GF(2^8) 对 285取模

	// 该多项式的alpha系数(a) 可以由qrcode::Alpha类生成 正向 或 逆向 的数组 ;
	
	// 由alpha系数转值成为纯数字 或由纯数字转为alpha系数

	// 该 f(x) 中的 逻辑加 与 逻辑指数 并不是 中学数学中 的 加法 与 乘方 运算

	// 在GF(2^8)中,负值与正值具有相同的值,那么

	// 当 n = 2 时,f(x) = x^2 +(a^0⊕a^1) x + a^0·a^1

	// 当 n = 3 时,f(x) = x^3 + (a^0⊕a^1⊕a^2) x^2 + (a^0·a^1⊕a^0·a^2⊕a^1·a^2) x^1 + a^0·a^1·a^2

	// 我们可以对 f(x) 进行演绎推理,为了更直观的表示,假设a^0 为a(0), a^1为a(1) ... a^n-1为a(n-1)

	// ⊕ 为 异或运算

	// 下例中省略了“·”

	// 推理1)

	// 第一项系数 1

	// 第二项系数 a0⊕....⊕an-1

	// 第三项系数 a(0)a(1)⊕a(0)a(2)⊕....⊕a(n-2)a(n-1)

	// 由此 推得 第k项(k>2) 的系数, a0a1....ak-2⊕...⊕a(n-k+1)...a(n-1)(每项有k-1个)

	// 在GF(2^8) 中 a0a1...ak-1=a^(0+1+...+k-1)

	// 至此, 开始展示 qrcode::Combination 的运算法则

	// 实际就是 用 二进制 表示 组合数的位数

	// 例1:计算 0,1,2,3 生成的排列组合

	// 由推理1) 第一项 1;
	//          第二项 a0⊕....⊕a2;
	//          第三项 a(0)a(1)⊕a(0)a(2)⊕....⊕a(1)a(2);
	//          第四项 a(0)a(1)(a2)⊕....⊕a(1)a(2)(a3);
	//          第五项 a(0)a(1)a(2)a(3)

	// 我们可以设置一个数字 为 (2^4-1) 该数字在 二进制中表示为 1111;

	// 那么 0001~1111 就可以表示 例1 中所有的元素

	// 即 0001 表示为0  0010表示为1  0100表示为2  1000表示为3

	// 由此 便产生了如下数组

	// @param combination 原始数据由1组成数组,这个数组 可以由 255,127,63,31,15,7,3,1 组成

	// 由于n=40,level=H时,纠错码字最为2430,我们需要生成最多为303个的255;

	// 这就产生了我们几乎需要运算77265次,才能获取一项系数

	// 而2430有多少项,有2431项
	
	// 想要了解更多QR码细节 请点击 https://www.thonky.com/qr-code-tutorial/error-correction-coding

	class Combination{
	private:
		// 纠错码字数
		int length;
		// 完全由1组成的任务数组 0xff 0x7f 0x3f 0x1f 0x0f 0x07 0x03 0x01
		int * combination;
		// 任务数组的长度
		int combination_length;
		// 纠错码字多项式alpha系数
		int * polynomeAlpha;
		// 初始化 任务数组
		void initCombination();
		// 00001 代表0 00011代表01
		// 00010 代表1
		// 00100 代表2
		// 01000 代表3
		// 10000 代表4
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