#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	pixelStorage = new RGB*[0];
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new RGB*[other.getWidth()];
	for (int x = 0; x < other.getWidth(); x++)
	{
		pixelStorage[x] = new RGB[other.getHeight()];
		for (int y = 0; y < other.getHeight(); y++)
		{
			pixelStorage[x][y] = other.pixelStorage[x][y];
		}
	}
	//TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixelStorage = new RGB*[getWidth()];
	for (int x = 0; x < getWidth(); x++)
	{
		pixelStorage[x] = new RGB[getHeight()];
	}
	RGBImage::set(width, height);
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	for (int x = 0; x < getWidth(); x++)
	{
		delete[] pixelStorage[x];
	}
	delete[] pixelStorage;
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	RGB** tempPixelStorage = new RGB*[width];
	for (int x = 0; x < width; x++)
	{
		tempPixelStorage[x] = new RGB[height];
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
	RGBImage::set(width, height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	pixelStorage = other.pixelStorage;
	RGBImage::set(other.getWidth(), other.getHeight());
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	if (x >= 0 && y >= 0 && x < getWidth() && y < getHeight())
	{
		pixelStorage[x][y] = pixel;
	}
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
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

RGB RGBImageStudent::getPixel(int x, int y) const {
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

RGB RGBImageStudent::getPixel(int i) const {
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