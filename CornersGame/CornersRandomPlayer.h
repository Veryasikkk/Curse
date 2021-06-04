#pragma once
#include "CornersPlayer.h"
class CornersRandomPlayer : public CornersPlayer
{
public:
	CornersRandomPlayer();
	~CornersRandomPlayer();
	virtual bool MakeMove();
};

