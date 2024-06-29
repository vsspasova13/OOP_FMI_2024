#include "FigureFactory.h"
#include "../Figures/Bishop/Bishop.h"
#include "../Figures/King/King.h"
#include "../Figures/Knight/Knight.h"
#include "../Figures/Pawn/Pawn.h"
#include "../Figures/Queen/Queen.h"
#include "../Figures/Rook/Rook.h"

Figure* FigureFactory::createFigure(bool isWhite, FigureType type)
{
    switch (type)
    {
    case FigureType::PawnFigure:
        return new Pawn(isWhite);
    case FigureType::KingFigure:
        return new King(isWhite);
    case FigureType::KnightFigure:
        return new Knight(isWhite);
    case FigureType::QueenFigure:
        return new Queen(isWhite);
    case FigureType::RookFigure:
        return new Rook(isWhite);
    case FigureType::BishopFigure:
        return new Bishop(isWhite);
    }
}
