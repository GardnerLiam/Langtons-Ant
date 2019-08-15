class Ant {
public:
	int x;
	int y;
	int dir;

	Ant(int X, int Y);
	void move(bool state);
	void turnLeft(void);
	void turnRight(void);
};
