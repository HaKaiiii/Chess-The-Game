#include "Bishop.h"

Bishop::Bishop(SDL_Renderer* m_Renderer, bool m_pieceTeam, float m_XPos, float m_YPos)
	: Piece(m_Renderer, BISHOP, m_pieceTeam, m_XPos, m_YPos)
{

}

Bishop::~Bishop()
{
	PossibleMovesVector().clear();
}

void Bishop::RenderPossibleMoves(SDL_Renderer* Renderer)
{
	CalculateLegitMoves();
	RenderPossMovesBlock(Renderer);
}

std::vector<int> Bishop::CalculatePossibleMoves()
{
	int x = static_cast<int>(m_XPos);
	int y = static_cast<int>(m_YPos);
	std::vector<int> possibleMoves;

	int arrayX[4] = { x + 1, x + 1, x - 1, x - 1 };
	int arrayY[4] = { y + 1, y - 1, y + 1, y - 1 };

	possibleMoves.clear();
	for (int i = 0; i < 4; i++)
	{
		while (arrayX[i] > -1 && arrayX[i] < 8 && arrayY[i] > -1 && arrayY[i] < 8)
		{
			//no piece present
			if (!boardPosition[arrayX[i] + (arrayY[i] * 8)])
				possibleMoves.push_back(arrayX[i] + (arrayY[i] * 8));
			//if enemy piece present
			else if (boardPosition[arrayX[i] + (arrayY[i] * 8)] && boardPosition[arrayX[i] + (arrayY[i] * 8)]->GetPieceTeam() != GetPieceTeam())
			{
				possibleMoves.push_back(arrayX[i] + (arrayY[i] * 8));
				//no need to loop further in row
				break;
			}
			//same team so break loop
			else if (boardPosition[arrayX[i] + (arrayY[i] * 8)] && boardPosition[arrayX[i] + (arrayY[i] * 8)]->GetPieceTeam() == GetPieceTeam())
				break;

			if (i == 0)
			{
				arrayX[i]++;
				arrayY[i]++;
			}
			else if (i == 1)
			{
				arrayX[i]++;
				arrayY[i]--;
			}
			else if (i == 2)
			{
				arrayX[i]--;
				arrayY[i]++;
			}
			else
			{
				arrayX[i]--;
				arrayY[i]--;
			}
		}
	}
	return possibleMoves;
}