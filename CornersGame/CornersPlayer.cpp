#include "CornersPlayer.h"



CornersPlayer::CornersPlayer()
{
}


CornersPlayer::~CornersPlayer()
{
}

void CornersPlayer::SetupPlayer(std::string name, CellType cellType)
{
	this->name = name;
	this->cellType = cellType;
}

CellType CornersPlayer::GetType()
{
	return this->cellType;
}

void CornersPlayer::SetBoard(CornersBoard * board)
{
	this->board = board;
}

std::string CornersPlayer::GetName()
{
	return this->name;
}
