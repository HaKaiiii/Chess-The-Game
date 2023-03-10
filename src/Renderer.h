#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include <iostream>

/*
struct PieceInfo
{
public:
	int pieceX = 0, pieceY = 0, pieceTeam = 0, pieceType = 0;
	PieceInfo(int x, int y, int team, int type)
		: pieceX(x), pieceY(y), pieceTeam(team), pieceType(type) {};
};
*/
class Piece;
namespace Chess
{
	void MainRenderer();
	void Init(SDL_Renderer*);
	void MissingTexture(bool, std::string);
	void RenderAllPiece(SDL_Renderer*);
	void DrawChessBoard(SDL_Renderer*);

	int GetBlockX(const int&);
	int GetBlockY(const int&);
	float Lerp(const int&, const int&, const float&);
	void AddGaussianBlur(SDL_Renderer*);
	void HighlightBlockMoved(SDL_Renderer*, const int&, const int&);
	SDL_Texture* GetPieceTexture(const int&);
}

static const int WIDTH = 800;
static const int HEIGHT = 800;
//0 = game running, 1 = white checkmated black, 2 = black checkmated white, 3 = stalemate, 4 = deaposition
extern int gameEnded;
//0-63 is block number for promotion, 99 is default
extern int promotion;
extern int blocksMoved[2];

extern Piece** boardPosition;