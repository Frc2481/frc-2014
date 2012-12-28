#include "nivision.h"
//#include "Vision/MonoImage.h"
//#include "Vision/BinaryImage.h"
#include "RoMonoImage.h"
#include "Target.h"
#include <algorithm>
#include <math.h>
#include "Utility.h"
#include "RoBinaryImage.h"

// These parameters set ellipse finding in the NI imaq (Image Aquisition) library.
// Refer to the CVI Function Reference PDF document installed with LabVIEW for
// additional information.


static RectangleDescriptor rectangleDescriptor = {
										10, 		// minWidth
										200, 	// maxWidth
										10, 		// minHeight
										200		// maxHeight
										};

static CurveOptions curveOptions = {	IMAQ_UNIFORM_REGIONS,	// extractionMode
										1, 				// threshold
										IMAQ_NORMAL, 		// filterSize
										25, 				// minLength
										15, 				// rowStepSize 
										15, 				// columnStepSize
										10, 				// maxEndPointGap
										1,					// onlyClosed
										0					// subpixelAccuracy
										};

static RangeFloat angleRange = {0,360};
static ShapeDetectionOptions shapeOptions = {
										IMAQ_GEOMETRIC_MATCH_SHIFT_INVARIANT,	// mode
										&angleRange,			// angle ranges
										1,				// num angle ranges
										{0, 200},		// scale range
										500				// minMatchScore
};

/*static ParticleFilterOptions2 particleFilterOptions = {
										
};*/

static ParticleFilterCriteria2 particleFilterCriteria = {
										IMAQ_MT_AREA,
										0,
										150,
										TRUE,
										FALSE
};

double Target::GetHorizontalAngle()
{
	double x = m_xPos;
	x = x * 9.0 / m_xMax;
	x = atan2(x, 20.0);
	x = x * 180.0 / 3.14159;
	return x;
}

/**
 * Compare two targets.
 * Compare the score of two targets for the sort function in C++.
 * @param t1 the first Target
 * @param t2 the second Target
 * @returns (1, 0, or -1) for the scores of t1 > t2, t1 == t2, and t1 < t2
 */
int compareTargets(Target t1, Target t2)
{
	if (t1.m_score > t2.m_score) return 1;
	if (t1.m_score < t2.m_score) return -1;
	return 0;
}

/**
 * Find the best circular target in the image.
 * The best target is the one with two concentric circles, largest size, and best score
 * @param image The image to examine.
 * @returns A target object with the parameters filled in.
 */
vector<Target> Target::FindRectangularTargets(HSLImage *image)
{
	wpi_assert(image != NULL);
	int width = image->GetWidth();
	int height = image->GetHeight();
	int particleCount = 0;
	double rectangleMeasurements;
	
	Threshold silverThreshold(255,226,0,255,96,255);
	
	vector<Target> sortedTargets;

	RoMonoImage  *binaryPlane = (RoMonoImage*)image->ThresholdHSL(silverThreshold);
	BinaryImage  *finalPlane = new BinaryImage(); 
	imaqConvexHull((Image*)finalPlane,(Image*)binaryPlane,8);
	delete binaryPlane;
	
	imaqParticleFilter4((Image*)binaryPlane, (Image*)finalPlane, &particleFilterCriteria, 1, NULL, NULL, &particleCount);
	//imaqMeasureParticle((Image*)binaryPlane,1,0,IMAQ_MT_BOUNDING_RECT_WIDTH,&particleMeasurements);
	//vector<RectangleMatch> *results = binaryPlane->DetectRectangles(&rectangleDescriptor, 
																	//	&curveOptions,
																	//	&shapeOptions,
																	//	NULL);
	
	
	
	// get the luminance plane only for the image to make the code
	// insensitive to lighting conditions.
	//RoMonoImage  *luminancePlane = (RoMonoImage*)image->GetLuminancePlane();
	//vector<RectangleMatch> *results = luminancePlane->DetectRectangles(&rectangleDescriptor, 
																	//NULL,
																	//NULL,
																	//NULL);
	//printf("%d", results->size());
	
	delete binaryPlane;
	delete finalPlane;
	/*if (results->size() == 0)
	{
		return sortedTargets;
	}
*/
	// create a list of targets corresponding to each ellipse found
	// in the image.
	/*for (unsigned i = 0; i < results->size(); i++)
	{
		Target target;
		RectangleMatch r = results->at(i);
		target.m_rawScore = r.score;
		target.m_score = r.score;
		target.m_height = r.height;
		target.m_width = r.width;
		//always divide by height so that x and y are same units
		target.m_xPos = (r.corner[0].x + r.corner[1].x + r.corner[2].x + r.corner[3].x) / 4;
		target.m_yPos = (r.corner[0].y + r.corner[1].y + r.corner[2].y + r.corner[3].y) / 4;
		target.m_rotation = r.rotation;
		target.m_xMax = (double)width / height;
		sortedTargets.push_back(target);
	}
	delete results;
	
	// sort the list of targets by score
	sort(sortedTargets.begin(), sortedTargets.end(), compareTargets);
	
	return sortedTargets;
	*/
}

/**
 * Print the target.
 * Print information about this target object.
 */
void Target::Print()
{
	printf("Target found: (%f, %f), height: %f, width: %f\nrotation: %f, score: %f \n\n",
						m_xPos, m_yPos,
						m_height, m_width,
						m_rotation, m_score);
}


