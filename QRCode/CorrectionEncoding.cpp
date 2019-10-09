#include "CorrectionEncoding.h"
void qrcode::CorrectionEncoding::setBasicInfo(qrcode::BasicInfo * info){
	this->basic_info = info;
}
qrcode::BasicInfo * qrcode::CorrectionEncoding::getBasicInfo(){
	return this->basic_info;
}
std::string qrcode::CorrectionEncoding::Encode(std::string & src){
	getSrc(src);
	Combine();
	return getDst();
}
std::string qrcode::CorrectionEncoding::Encode(const char * src){
	std::string real_src = src;
	getSrc(real_src);
	Combine();
	return getDst();
}
qrcode::CorrectionEncoding::CorrectionEncoding(){
	this->dst = NULL;
	this->basic_info = NULL;
	this->src = NULL;
}
qrcode::CorrectionEncoding::~CorrectionEncoding(){
	if (this->dst != NULL){
		delete this->dst;
		this->dst = NULL;
	}
	if (this->src != NULL){
		delete this->src;
		this->src = NULL;
	}
	if (this->basic_info != NULL){
		basic_info = NULL;
	}
}
void qrcode::CorrectionEncoding::getSrc(std::string & source){
	//get length of data_encoding
	int set_length = qrcode::data_encoding::length(this->basic_info) << 3;
	if (set_length != source.length()){
		throw QRCodeException(qrcode::error::InvalidDataLength);
	}
	int length = qrcode::data_encoding::length(this->basic_info);
	src = new int[length];
	int src_position = 0;
	int src_data = 0;
	for (int i = 0; i < source.length(); i++){
		if (source.at(i) == '1'){
			int bit_position = i & 7;
			src_data += (1 << (7 - bit_position));
		}
		if ((i & 7)== 7){
			src[src_position++] = src_data;
			src_data = 0;
		}
	}
}

void qrcode::CorrectionEncoding::Combine(){
	int polynome_length = qrcode::correction_encoding::length(this->basic_info)
		+ qrcode::data_encoding::length(this->basic_info);
	dst = new int[polynome_length];
	memset(dst, 0, polynome_length << 2);
	int length = qrcode::data_encoding::length(this->basic_info);
	memcpy(dst, src, length << 2);
	for (int i = 0; i < length; i++){
		Divide(i);
	}
	
}
std::string qrcode::CorrectionEncoding::getDst(){
	int length = qrcode::data_encoding::length(this->basic_info);
	int correct = qrcode::correction_encoding::length(this->basic_info);
	std::string res="";
	for (int i = length; i < length + correct; i++){
		int operate = dst[i];
		std::string number="";
		while (operate != 0){
			if (operate & 1){
				number.insert(number.begin(), '1');
			}
			else
			{
				number.insert(number.begin(), '0');
			}
			operate = operate >> 1;
		}
		res += number;
		
	}
	
	return res;
}
void qrcode::CorrectionEncoding::Divide(int i){
	// get the set of length for data encoding
	int length = qrcode::data_encoding::length(this->basic_info);
	// get the set of length for correction encoding
	int correction_length = qrcode::correction_encoding::length(this->basic_info);
	// division operate init
	int * correction_alpha = NULL;
	// get the division alpha
	qrcode::correction_encoding::getPolynomeAlpha(this->basic_info, correction_alpha);
	// get the dst
	int * sequence = dst + i;
	// alpha init
	qrcode::Alpha alpha;
	alpha.Init();
	int d_value_alpha = alpha.inverse[sequence[0]] - correction_alpha[0];

	if (d_value_alpha < 0){
		d_value_alpha += 0xff;
	}

	for (int i = 0; i < correction_length + 1; i++){
		if (correction_alpha[i] + d_value_alpha < 0xff)
		{
			correction_alpha[i] = (correction_alpha[i] + d_value_alpha) & 0xff;
		}
		else
		{
			correction_alpha[i] = (correction_alpha[i] + d_value_alpha) % 0xff;
		}
		
	}

	for (int i = 0; i < correction_length + 1; i++){
		sequence[i] = sequence[i] ^ alpha.sequence[correction_alpha[i]];
	}

	delete correction_alpha;
	correction_alpha = NULL;
}
void qrcode::CorrectionEncoding::showDst(){
	int polynome_length = qrcode::correction_encoding::length(this->basic_info)
		+ qrcode::data_encoding::length(this->basic_info);
	for (int i = 0; i < polynome_length; i++){
		std::cout << dst[i] << " ";
	}
	std::cout << std::endl;
}

