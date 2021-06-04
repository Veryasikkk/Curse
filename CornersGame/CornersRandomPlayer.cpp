#include "CornersRandomPlayer.h"



CornersRandomPlayer::CornersRandomPlayer()
{
}


CornersRandomPlayer::~CornersRandomPlayer()
{
}

bool CornersRandomPlayer::MakeMove()
{
	unsigned int row, col;
	std::unordered_map<int, std::unordered_set<int>> possibleMoves = this->board->GetPossibleMoves();
	if (possibleMoves.size() == 0) return false;

	auto i_oldPos = std::next(std::begin(possibleMoves), rand() % possibleMoves.size());
	int oldPos = i_oldPos->first;

	auto i_newPos = std::next(std::begin(i_oldPos->second), rand() % i_oldPos->second.size());
	int newPos = *i_newPos;

	return board->SetCell(oldPos / this->board->GetBoardsize(), oldPos % this->board->GetBoardsize(),
		newPos / this->board->GetBoardsize(), newPos % this->board->GetBoardsize(), this->cellType);

}
