#include "RoMonoImage.h"


RoMonoImage::RoMonoImage () : ImageBase(IMAQ_IMAGE_U8) {}
RoMonoImage::~RoMonoImage() 
{
}

vector<RectangleMatch> * RoMonoImage::DetectRectangles(
	RectangleDescriptor *rectangleDescriptor, CurveOptions *curveOptions,
	ShapeDetectionOptions *shapeDetectionOptions, ROI *roi)
{
	int numberOfMatches;
	RectangleMatch *e = imaqDetectRectangles(m_imaqImage, rectangleDescriptor,
					curveOptions, shapeDetectionOptions, roi, &numberOfMatches);
	printf(" Number: %d ", numberOfMatches);
	vector<RectangleMatch> *rectangles = new vector<RectangleMatch>;
	if (e == NULL)
	{
		return rectangles;
	}
	for (int i = 0; i < numberOfMatches; i++)
	{
		rectangles->push_back(e[i]);
	}
	imaqDispose(e);
	
	//return rectangles;
}
