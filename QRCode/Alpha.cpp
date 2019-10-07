#include "Alpha.h"
void qrcode::alpha::Init(){
	using namespace qrcode::alpha;
	if (sequence == nullptr){
		sequence = new int[256];
	}
	if (inverse == nullptr){
		inverse = new int[256];
	}
	int _operator = 1;
	inverse[0] = -1;
	for (int i = 0; i < 256; i++){
		sequence[i] = _operator;
		inverse[_operator] = i;
		_operator = _operator << 1;
		if (_operator > 255){
			_operator = _operator ^ 285;
		}
	}
}
void qrcode::alpha::Destory(){
	using namespace qrcode::alpha;
	if (sequence != nullptr){
		delete sequence;
		sequence = nullptr;
	}
	if (inverse != nullptr){
		delete inverse;
		inverse = nullptr;
	}
}