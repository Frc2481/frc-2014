

#ifndef __Ro_Mono_Image_H__
#define __Ro_Mono_Image_H__

#include "Vision\ImageBase.h"

#include <vector>

using namespace std;

class RoMonoImage : public ImageBase
{
public:
	RoMonoImage ();
	virtual ~RoMonoImage();
	vector<RectangleMatch> * DetectRectangles(
		RectangleDescriptor *rectangleDescriptor, CurveOptions *curveOptions,
		ShapeDetectionOptions *shapeDetectionOptions, ROI *roi);
};
 
#endif
