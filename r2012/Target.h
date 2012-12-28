#ifndef _TARGET_H
#define _TARGET_H

#include <vector>
#include "Vision/HSLImage.h"

class Target
{
public:
    double m_height;
    double m_width;
    double m_rawScore;
    double m_xPos;
    double m_yPos;
    double m_score;
    double m_rotation;
    double m_xMax;

    static vector<Target> FindRectangularTargets(HSLImage *image);
    double GetHorizontalAngle();
    void Print();
};

#endif
