#include "Alpha.h"
void qrcode::Alpha::Destory(){
	if (sequence != nullptr){
		delete sequence;
		sequence = nullptr;
	}
	if (inverse != nullptr){
		delete inverse;
		inverse = nullptr;
	}
}
qrcode::Alpha::Alpha(){
	inverse = nullptr;
	sequence = nullptr;
}
qrcode::Alpha::~Alpha(){
	if (sequence != nullptr){
		delete sequence;
		sequence = nullptr;
	}
	if (inverse != nullptr){
		delete inverse;
		inverse = nullptr;
	}
}
void qrcode::Alpha::Init(){
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