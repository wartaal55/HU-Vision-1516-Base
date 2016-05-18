#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	pixelStorage = new int*[0];
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
	//TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage = new int*[getWidth()];
	for (int x = 0; x < getWidth(); x++)
	{
		pixelStorage[x] = new int[getHeight()];
	}
	IntensityImage::set(width, height);
	//TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {
	for (int x = 0; x < getWidth(); x++)
	{
		delete[] pixelStorage[x];
	}
	delete[] pixelStorage;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	int** tempPixelStorage = new int*[width];
	for (int x = 0; x < width; x++)
	{
		tempPixelStorage[x] = new int[height];
		for (int y = 0; y < height; y++)
		{
			if (x < getWidth() && y < getHeight())
			{
				tempPixelStorage[x][y] = pixelStorage[x][y];
			}
			else
			{
				tempPixelStorage[x][y] = 0;
			}
		}
	}
	for (int x = 0; x < getWidth(); x++)
	{
		delete[] pixelStorage[x];
	}
	delete[] pixelStorage;
	pixelStorage = tempPixelStorage;
	IntensityImage::set(width, height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	pixelStorage = other.pixelStorage;
	IntensityImage::set(other.getWidth(), other.getHeight());
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	if (x >= 0 && y >=0 && x < getWidth() && y < getHeight())
	{
		pixelStorage[x][y] = pixel;
	}
	//TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (getWidth() != 0)
	{
		int x = i % getWidth();
		int y = i / getWidth();
		if (x >= 0 && y >= 0 && x < getWidth() && y < getHeight())
		{
			pixelStorage[x][y] = pixel;
		}
	}
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
	//TODO: no comment needed :)
	if (x >= 0 && y >= 0 && x < getWidth() && y < getHeight())
	{
		return pixelStorage[x][y];
	}
	else
	{
		return -1;
	}
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if (getWidth() != 0)
	{
		int x = i % getWidth();
		int y = i / getWidth();
		//TODO: see setPixel(int i, RGB pixel)
		if (x >= 0 && y >= 0 && x < getWidth() && y < getHeight())
		{
			return pixelStorage[x][y];
		}
		else
		{
			return -2;
		}
	}
	else
	{
		return -1;
	}
}