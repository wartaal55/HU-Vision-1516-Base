#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	pixelStorage = new int*[1];
	for (int i = 0; i < getWidth(); i++)
	{
		pixelStorage[i] = new int[1];
	}
	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new int*[other.getWidth()];
	for (int x = 0; x < other.getWidth(); x++)
	{
		pixelStorage[x] = new int[other.getHeight()];
		for (int y = 0; y < other.getHeight(); y++)
		{
			pixelStorage[x][y] = other.pixelStorage[x][y];
		}
	}
	int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage = new int*[getWidth()];
	for (int x = 0; x < getWidth(); x++)
	{
		pixelStorage[x] = new int[getHeight()];
	}
	int throwError = 0, e = 1 / throwError;
	//TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
	for (int x = 0; x < getWidth(); x++)
	{
		delete[] pixelStorage[x];
	}
	delete[] pixelStorage;
	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	int** tempPixelStorage = new int*[width];
	for (int x = 0; x < width; x++)
	{
		tempPixelStorage[x] = new int[height];
		for (int y = 0; y < height; y++)
		{
			if (width < getWidth() || height < getHeight())
			{
				tempPixelStorage[x][y] = 0;
			}
			tempPixelStorage[x][y] = pixelStorage[x][y];
		}
	}
	IntensityImage::set(width, height);
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return 0;
}