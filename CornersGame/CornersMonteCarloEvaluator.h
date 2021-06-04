#pragma once
#include "CornersBoard.h"
#include "CornersRandomPlayer.h"
#include "CellType.h"

class CornersMonteCarloEvaluator
{
private:
	CornersBoard* board;
	int numGames;
	int numVictories;
	int numLosses;
	int numDraws;
	unsigned int oldPos, newPos;
	CellType startCellType;
public:
	CornersMonteCarloEvaluator(CornersBoard* board, int numIterations, CellType startCellType,
		unsigned int oldPos, unsigned newPos);
	~CornersMonteCarloEvaluator();
	void EvaluteBoard();
	void Evalute();
	int GetVictories() { return numVictories; }
	int GetLosses() { return numLosses; }
	int GetDraws() { return numDraws; }
	int GetOldPos() { return oldPos; }
	int GetNewPos() { return newPos; }
};

