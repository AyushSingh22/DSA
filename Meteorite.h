#pragma once

class Meteorite
{
private:
	int x1;	//we only need x1 and x2 coordinates since y coordinates do not affect the result
	int x2;
public:
	Meteorite(int x1, int x2) :x1(x1), x2(x2) {}	//initializer for Meteorite
	~Meteorite() {}	//destructor
	Meteorite() :x1(0), x2(0) {}
	void setX1(int x1) { this->x1 = x1; }	//setter for x1
	void setX2(int x2) { this->x2 = x2; }	//setter for x2

	int getX1() { return x1; }	//getter for x1
	int getX2() { return x2; }	//getter for x2
	bool operator<(const Meteorite& m2) { return x2 < m2.x2; }
	bool operator>(const Meteorite& m2) { return x2 > m2.x2; }
	bool operator<=(const Meteorite& m2) { return x2 <= m2.x2; }
	bool operator==(const Meteorite& m2) { return x2 == m2.x2&& x1 == m2.x1; }
	bool operator!=(const Meteorite& m2) { return x2 != m2.x2 || x1 != m2.x1; }
	bool operator>=(const Meteorite& m2) { return x2 >= m2.x2; }

};