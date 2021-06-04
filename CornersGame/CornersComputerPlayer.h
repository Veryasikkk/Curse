#pragma once
#include "CornersPlayer.h"
#include "CornersMonteCarloEvaluator.h"
#include <vector>
class CornersComputerPlayer : public CornersPlayer
{
public:
	CornersComputerPlayer();
	virtual ~CornersComputerPlayer();
	virtual bool MakeMove();
};

