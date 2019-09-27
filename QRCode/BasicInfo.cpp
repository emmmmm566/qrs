#include "BasicInfo.h"
using namespace qrcode;
BasicInfo::BasicInfo(int version,int mode,int level){
	this->version = version;
	this->mode = mode;
	this->level = level;
}
BasicInfo::~BasicInfo(){
}
void BasicInfo::setLevel(int level){
	this->level = level;
}
void BasicInfo::setMode(int mode){
	this->mode = mode;
}
void BasicInfo::setVerison(int version){
	this->version = version;
}
int BasicInfo::getLevel(){
	return this->level;
}
int BasicInfo::getMode(){
	return this->mode;
}
int BasicInfo::getVersion(){
	return this->version;
}