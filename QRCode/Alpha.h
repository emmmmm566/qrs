#ifndef Alpha_H
#define Alpha_H
namespace qrcode{
	namespace alpha{
		int * sequence = nullptr;
		int * inverse = nullptr;
		void Init() throw();
		void Destory() throw();
	};
};
#endif