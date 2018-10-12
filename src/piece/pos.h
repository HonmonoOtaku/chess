#ifndef _POS_H_
#define _POS_H_

class Pos
{
public:
	int x;
	int y;

public:
	Pos(const unsigned int x, const unsigned int y);
	Pos();

	bool operator==(const Pos& rhs) const;
	bool operator!=(const Pos& rhs) const;
};

#endif // _POS_H_
