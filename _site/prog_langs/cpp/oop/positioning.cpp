#include <iostream>

class Position
{
	public:
		int x = 10;
		int y = 20;

		Position operator + (Position p)
		// pos1 calls this operator, and the operator see pos2, and adds it to pos1
		// it returns the object of Position
		{
			Position new_pos;
			new_pos.x = x + new_pos.x;
			new_pos.y = y + new_pos.y;

			return new_pos;
		}

		bool operator == (Position p)
		{
			Position new_pos;
			return (new_pos.x == x && new_pos.y == y);
		}

};

// remember, & is the "address of" operator
// it gives you the address of the variable
std::ostream& operator << (std::ostream &output, const Position pos)
		{
			output << "X: " << pos.x << " Y: " << pos.y;
			return output;
		}

int main()
{
	Position pos1, pos2, pos3;
	pos3 = pos1 + pos2;
	std::cout << pos3.x  << " " << pos3.y << std::endl;
	bool res = pos1 == pos2;
	std::cout << res << std::endl;

	std::cout << pos1 << std::endl;
	return 0;
}
