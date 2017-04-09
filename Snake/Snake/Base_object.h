#pragma once
class Base_object
{
private:
	int vel[2], x, y, width, hight;
	char image;
	bool Alive;
public:
	Base_object();
	~Base_object();
	//getters and setters
	void setWidth(int w) { width = w; }
	void setHight(int h) { hight = h; }
	void SetVel(int* _vel) { vel[0] = _vel[0]; vel[1] = _vel[1]; }
	void setX(int _x) { x = _x; }
	void setY(int _y){ y = _y; }
	void setAlive(bool _alive){ Alive = _alive; }
	void setImage(char _i){ image = _i; }
	int* getvel() { return vel; }
	int getX() { return x; }
	int getY() { return y; }
	char getImage() { return image; }
	bool getAlive() { return Alive; }
	int getHight() { return hight; }
	int getWidth() { return width; }

	virtual void Input();
	virtual void Update(int _frame);
	virtual void Render();
};

