#include "CornersComputerPlayer.h"
#define DIFFICULTY 50


CornersComputerPlayer::CornersComputerPlayer()
{
}


CornersComputerPlayer::~CornersComputerPlayer()
{
}

bool CornersComputerPlayer::MakeMove()
{
	std::cout << "Computer thinking..." << std::endl;

	std::vector<CornersMonteCarloEvaluator*> evaluators;

	std::unordered_map<int, std::unordered_set<int>> possibleMoves = this->board->GetPossibleMoves();
	for (auto i = possibleMoves.begin(); i != possibleMoves.end(); ++i) {
		for (auto j = i->second.begin(); j != i->second.end(); ++j) {
			int old_x = i->first / this->board->GetBoardsize();
			int old_y = i->first % this->board->GetBoardsize();
			int new_x = *j / this->board->GetBoardsize();
			int new_y = *j % this->board->GetBoardsize();
			
			this->board->SetCell(old_x, old_y, new_x, new_y, this->cellType);
			evaluators.push_back(new CornersMonteCarloEvaluator(this->board, DIFFICULTY,
				(this->cellType == CellType_B) ? CellType_B : CellType_W, i->first, *j));
			this->board->SetCellNoRule(new_x, new_y, old_x, old_y, this->cellType);
		}
	}
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++) {
		(*evaluator)->Evalute();
	}
	int biggestVictories = -1;

	for (auto i = evaluators.begin(); i != evaluators.end(); ++i) {
		if (this->cellType == CellType_B) {
			if ((*i)->GetVictories() > biggestVictories)
				biggestVictories = (*i)->GetVictories();
		}
		else {
			if ((*i)->GetLosses() > biggestVictories)
				biggestVictories = (*i)->GetLosses();
		}
	}

	std::vector<CornersMonteCarloEvaluator*> biggestWinEvaluators;
	for (auto i = evaluators.begin(); i != evaluators.end(); ++i) {
		int numVictories;
		if (this->cellType == CellType_B)
			numVictories = (*i)->GetVictories();
		else
			numVictories = (*i)->GetLosses();
		if (numVictories == biggestVictories)
			biggestWinEvaluators.push_back((*i));
	}

	this->board->SetCell(biggestWinEvaluators[0]->GetOldPos() / this->board->GetBoardsize(), biggestWinEvaluators[0]->GetOldPos() % this->board->GetBoardsize(), 
		biggestWinEvaluators[0]->GetNewPos() / this->board->GetBoardsize(), biggestWinEvaluators[0]->GetNewPos() % this->board->GetBoardsize(), this->cellType);
	for (auto i = evaluators.begin(); i != evaluators.end(); ++i) {
		delete (*i);
	}
	evaluators.clear();
	biggestWinEvaluators.clear();
	return true;
}
