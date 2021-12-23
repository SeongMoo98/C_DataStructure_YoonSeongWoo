#pragma once
#ifndef __POINT_H_
#define __POINT_H_

typedef struct _point
{
	int xpos;
	int ypos;
}Point;

void SetPointPos(Point* ppos, int xpos, int ypos);
void ShowPointPos(Point* ppos);
int PointComp(Point* pos1, Point* pos2);

#endif