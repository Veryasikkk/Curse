#pragma once
#include "CornersBoard.h"
#include <string>
class CornersPlayer
{
protected:
	CornersBoard* board;
	CellType cellType;
	std::string name;
public:
	CornersPlayer();
	virtual ~CornersPlayer();
	void SetupPlayer(std::string name, CellType cellType);
	CellType GetType();
	void SetBoard(CornersBoard* board);
	virtual bool MakeMove() = 0;
	std::string GetName();
};

