#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	
	IntensityImage * pixelStorage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	for (int x = 0; x < image.getWidth(); x++)
	{
		for (int y = 0; y < image.getHeight(); y++)
		{
			RGB tempRGB = image.getPixel(x,y);
			pixelStorage->setPixel(x,y, int((tempRGB.r + tempRGB.g + tempRGB.b) / 3));
		}
	}


	return pixelStorage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}