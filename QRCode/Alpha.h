#ifndef Alpha_H
#define Alpha_H
namespace qrcode{
	class Alpha{
	public:
		int * sequence;
		int * inverse;
		void Init() throw();
		void Destory() throw();
		Alpha();
		~Alpha();
	};
}
#endif