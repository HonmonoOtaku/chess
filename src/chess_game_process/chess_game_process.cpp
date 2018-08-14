#include "chess_game_process.h"

Chess_Game_Process::Chess_Game_Process()
{
	for(int i = 0; i < 8; i++)
	{
		m_white_pieces_list.push_back(new Pone(Piece_Color::WHITE, Piece_Pos(i, 1)));
		m_black_pieces_list.push_back(new Pone(Piece_Color::BLACK, Piece_Pos(i, 6)));
	}
	
	m_white_pieces_list.push_back(new Rook(Piece_Color::WHITE, Piece_Pos(0,0)));
	m_white_pieces_list.push_back(new Night(Piece_Color::WHITE, Piece_Pos(1,0)));
	m_white_pieces_list.push_back(new Bishop(Piece_Color::WHITE, Piece_Pos(2,0)));
	m_white_pieces_list.push_back(new Queen(Piece_Color::WHITE, Piece_Pos(3,0)));
	m_white_pieces_list.push_back(new King(Piece_Color::WHITE, Piece_Pos(4,0)));
	m_white_pieces_list.push_back(new Bishop(Piece_Color::WHITE, Piece_Pos(5,0)));
	m_white_pieces_list.push_back(new Night(Piece_Color::WHITE, Piece_Pos(6,0)));
	m_white_pieces_list.push_back(new Rook(Piece_Color::WHITE, Piece_Pos(7,0)));

	m_black_pieces_list.push_back(new Rook(Piece_Color::BLACK, Piece_Pos(0,7)));
	m_black_pieces_list.push_back(new Night(Piece_Color::BLACK, Piece_Pos(1,7)));
	m_black_pieces_list.push_back(new Bishop(Piece_Color::BLACK, Piece_Pos(2,7)));
	m_black_pieces_list.push_back(new King(Piece_Color::BLACK, Piece_Pos(3,7)));
	m_black_pieces_list.push_back(new Queen(Piece_Color::BLACK, Piece_Pos(4,7)));
	m_black_pieces_list.push_back(new Bishop(Piece_Color::BLACK, Piece_Pos(5,7)));
	m_black_pieces_list.push_back(new Night(Piece_Color::BLACK, Piece_Pos(6,7)));
	m_black_pieces_list.push_back(new Rook(Piece_Color::BLACK, Piece_Pos(7,7)));
	
	for(int x = 0; x < 8; x++)
	{
		m_chess_board.m_chess_board[x][1].m_piece = m_white_pieces_list[x];
		m_chess_board.m_chess_board[x][1].m_if_piece_exist = true;
		m_chess_board.m_chess_board[x][0].m_piece = m_white_pieces_list[x + 8];
		m_chess_board.m_chess_board[x][0].m_if_piece_exist = true;

		m_chess_board.m_chess_board[x][6].m_piece = m_black_pieces_list[x];
		m_chess_board.m_chess_board[x][6].m_if_piece_exist = true;
		m_chess_board.m_chess_board[x][7].m_piece = m_black_pieces_list[x + 8];
		m_chess_board.m_chess_board[x][7].m_if_piece_exist = true;
	}
	
	cout << m_chess_board << endl;
}

Chess_Game_Process::~Chess_Game_Process()
{
	for(vector<Chess_Piece*>::iterator iter = m_white_pieces_list.begin(); iter != m_white_pieces_list.end();)
	{
		delete *iter;
		iter = m_white_pieces_list.erase(iter);	
	}

	for(vector<Chess_Piece*>::iterator iter = m_black_pieces_list.begin(); iter != m_black_pieces_list.end();)
	{
		delete *iter;
		iter = m_black_pieces_list.erase(iter);	
	}

	for(int x = 0; x < 8; x++)
		for(int y = 0; y < 8; y++)
			m_chess_board.m_chess_board[x][y].m_piece = NULL;
}

int Chess_Game_Process::Move_Piece(const Piece_Pos origin_pos, const Piece_Pos destination_pos)
{	
	if(MoveAllow(origin_pos, destination_pos, m_chess_board) == false)
		return -1;

	if(m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_if_piece_exist == true)
	{
		m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_piece = NULL;

		//delete from white_Pieces_list or black_pieces_list
		if(m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_piece->ReturnPieceColor() == Piece_Color::WHITE)
		{

			for(vector<Chess_Piece*>::iterator iter = m_white_pieces_list.begin(); iter != m_white_pieces_list.end();)
			{
				if(m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_piece == *iter)
				{
					delete *iter;
					m_white_pieces_list.erase(iter);
				}	
			}
		}

		else	
		{
			for(vector<Chess_Piece*>::iterator iter = m_black_pieces_list.begin(); iter != m_black_pieces_list.end();)
			{
				if(m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_piece == *iter)
				{
					delete *iter;
					m_black_pieces_list.erase(iter);
				}
			}
		}	
	}

	m_chess_board.m_chess_board[origin_pos.x][origin_pos.y].m_if_piece_exist = false;
	m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_piece = m_chess_board.m_chess_board[origin_pos.x][origin_pos.y].m_piece;
	m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_piece->m_piece_pos = Piece_Pos(destination_pos.x, destination_pos.y);
	m_chess_board.m_chess_board[destination_pos.x][destination_pos.y].m_if_piece_exist = true;
	m_chess_board.m_chess_board[origin_pos.x][origin_pos.y].m_piece = NULL; 

	cout << m_chess_board << endl;
	
	return 0;
}

