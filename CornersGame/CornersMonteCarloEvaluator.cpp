#include "CornersMonteCarloEvaluator.h"




CornersMonteCarloEvaluator::CornersMonteCarloEvaluator(CornersBoard * board, int numIterations, CellType startCellType, unsigned int oldPos, unsigned newPos)
{
	this->board = board;
	this->numGames = numIterations;
	this->numDraws = 0;
	this->numVictories = 0;
	this->numLosses = 0;
	this->oldPos = oldPos;
	this->newPos = newPos;
	this->startCellType = startCellType;
}

CornersMonteCarloEvaluator::~CornersMonteCarloEvaluator()
{
}

void CornersMonteCarloEvaluator::EvaluteBoard()
{
	CornersBoard* tempBoard = new CornersBoard(this->board);
	CornersRandomPlayer* player1 = new CornersRandomPlayer();
	CornersRandomPlayer* player2 = new CornersRandomPlayer();
	CornersRandomPlayer* currentPlayer;
	bool bGameFinished = false;

	player1->SetupPlayer("RandomB", CellType_B);
	player2->SetupPlayer("RandomW", CellType_W);
	player1->SetBoard(tempBoard);
	player2->SetBoard(tempBoard);
	currentPlayer = (this->startCellType == CellType_B) ? player1 : player2;

	if (tempBoard->CheckEndCondition()) {
		if (tempBoard->GetWinner() == 0) {
			numDraws++;
		}
		if (tempBoard->GetWinner() == CellType_B) {
			numVictories++;
		}
		if (tempBoard->GetWinner() == CellType_W) {
			numLosses++;
		}
		bGameFinished = true;
		return;
	}

	while (!bGameFinished) {
		tempBoard->SetAvailableMoves(currentPlayer->GetType());
		
		while (!currentPlayer->MakeMove()){}
		
		if (tempBoard->CheckEndCondition()) {
			//tempBoard->Show();
			if (tempBoard->GetWinner() == 0) numDraws++;
			if (tempBoard->GetWinner() == player1->GetType()) numVictories++;
			if (tempBoard->GetWinner() == player2->GetType()) numLosses++;
			bGameFinished = true;
		}
		currentPlayer = (currentPlayer == player1) ? player2 : player1;
	}


}

void CornersMonteCarloEvaluator::Evalute()
{
	for (unsigned int i = 0; i < numGames; ++i) {
		EvaluteBoard();
	}
}
