#include "Matrix.h"
void::qrcode::Matrix::Combine(){
	int side = qrcode::matrix::getSideLength(this->basic_info);
	initMatrix();
	int arrs[3][2] = { { 0, 0 }, { side - 7, 0 }, { 0, side - 7 } };
	for (int i = 0; i < 3; i++){
		finderPatterns(arrs[i][0], arrs[i][1]);
	}
	positionLine();
	int **patterns = NULL;
	qrcode::matrix::getPositionPatternsCoordinate(this->basic_info, patterns);
	int length = qrcode::matrix::getPositionPatternsQuantity(this->basic_info);
	for (int i = 0; i < length; i++){
		positionPatterns(patterns[i][0], patterns[i][1]);
	}
}
void::qrcode::Matrix::positionLine(){
	int side = qrcode::matrix::getSideLength(this->basic_info);
	for (int i = 7; i < side - 7; i++){
		if (i & 1){
			matrix[6][i] = 0;
			matrix[i][6] = 0;
		}
		else
		{
			matrix[6][i] = 1;
			matrix[i][6] = 1;
		}
	}
	for (int i = 0; i < 8; i++){
		matrix[7][i] = 0;
		matrix[i][7] = 0;
		matrix[side - 8][i] = 0;
		matrix[side - 8 + i][7] = 0;
		matrix[i][side - 8] = 0;
		matrix[7][side - 8 + i] = 0;
	}
	
}
void qrcode::Matrix::positionPatterns(int x, int y){
	matrix[x][y] = 1;

	for (int m_x = x - 2; m_x <= x + 2; m_x++){
		matrix[m_x][y - 2] = 1;
	}
	for (int m_y = y - 1; m_y < y + 2; m_y++){
		matrix[x - 2][m_y] = 1;
		matrix[x + 2][m_y] = 1;
	}
	for (int m_x = x - 2; m_x <= x + 2; m_x++){
		matrix[m_x][y + 2] = 1;
	}
	for (int m_x = x - 1; m_x < x + 2; m_x++){
		matrix[m_x][y + 1] = 0;
		matrix[m_x][y - 1] = 0;
	}
	matrix[y + 1][x] = 0;
	matrix[y - 1][x] = 0;
}
void qrcode::Matrix::finderPatterns(int x, int y){
	for (int j = 0; j < 7; j++)
	{
		matrix[0 + x][j + y] = 1;
	}
	matrix[1 + x][0 + y] = 1;
	matrix[1 + x][1 + y] = 0;
	matrix[1 + x][2 + y] = 0;
	matrix[1 + x][3 + y] = 0;
	matrix[1 + x][4 + y] = 0;
	matrix[1 + x][5 + y] = 0;
	matrix[1 + x][6 + y] = 1;

	matrix[2 + x][0 + y] = 1;
	matrix[2 + x][1 + y] = 0;
	matrix[2 + x][2 + y] = 1;
	matrix[2 + x][3 + y] = 1;
	matrix[2 + x][4 + y] = 1;
	matrix[2 + x][5 + y] = 0;
	matrix[2 + x][6 + y] = 1;

	matrix[3 + x][0 + y] = 1;
	matrix[3 + x][1 + y] = 0;
	matrix[3 + x][2 + y] = 1;
	matrix[3 + x][3 + y] = 1;
	matrix[3 + x][4 + y] = 1;
	matrix[3 + x][5 + y] = 0;
	matrix[3 + x][6 + y] = 1;

	matrix[4 + x][0 + y] = 1;
	matrix[4 + x][1 + y] = 0;
	matrix[4 + x][2 + y] = 1;
	matrix[4 + x][3 + y] = 1;
	matrix[4 + x][4 + y] = 1;
	matrix[4 + x][5 + y] = 0;
	matrix[4 + x][6 + y] = 1;

	matrix[5 + x][0 + y] = 1;
	matrix[5 + x][1 + y] = 0;
	matrix[5 + x][2 + y] = 0;
	matrix[5 + x][3 + y] = 0;
	matrix[5 + x][4 + y] = 0;
	matrix[5 + x][5 + y] = 0;
	matrix[5 + x][6 + y] = 1;

	for (int j = 0; j < 7; j++)
	{
		matrix[6 + x][j + y] = 1;
	}
}
void qrcode::Matrix::initMatrix(){
	int side = qrcode::matrix::getSideLength(this->basic_info);
	this->matrix = new int *[side];
	for (int i = 0; i < side; i++){
		matrix[i] = new int[side];
	}
	for (int i = 0; i < side; i++){
		for (int j = 0; j < side; j++){
			matrix[i][j] = -1;
		}
	}
}
qrcode::Matrix::Matrix(){
	matrix = nullptr;
}
qrcode::Matrix::~Matrix(){
	destoryMatrix();
}
void qrcode::Matrix::setBasicInfo(BasicInfo * info){
	this->basic_info = info;
}
int ** qrcode::Matrix::getMatrix(){
	return this->matrix;
}
void qrcode::Matrix::destoryMatrix(){
	int side = qrcode::matrix::getSideLength(this->basic_info);
	if (matrix != nullptr){
		for (int i = 0; i < side; i++)
		{
			if (matrix[i] != nullptr){
				delete[]matrix[i];
				matrix[i] = nullptr;
			}

		}
		if (matrix != nullptr){
			delete[]matrix;
			matrix = nullptr;
		}
	}
}