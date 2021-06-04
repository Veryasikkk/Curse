#pragma once
#include "CornersBoard.h"
#include "CornersPlayer.h"
#include <string>
class CornersHumanPlayer : public CornersPlayer
{
public:
	CornersHumanPlayer();
	virtual ~CornersHumanPlayer();
	virtual bool MakeMove();
};

