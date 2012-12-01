#include <string>
#include <cmath>

class Shape {
private:
public:
	virtual std::string draw(){
		return "drew a ";
	}
	virtual float area(){return 0.0f;}
};

class Square : public Shape {
private:
	float side;
public:
	Square(float s) {
		side = s;
	}

	std::string draw() {
		return Shape::draw() + "square";
	}

	float area(){
		return side * side ;
	}
};

class Triangle : public Shape {
private:
	float a, b, c;
public:
	Triangle(float _a, float _b, float _c) {
		a = _a;
		b = _b;
		c = _c;
	}

	std::string draw(){
		return Shape::draw() + "triangle";
	}
	
	float area(){
		if(isTriangle(a, b, c)){
			float s = (a + b + c) / 2;
			return sqrt(s * (s-a) * (s-b) * (s-c));
		} else {
			return -1;
		}
	}

	bool isTriangle(float _a, float _b, float _c){
		if(a < (b + c) || b < (a + c) || c < (a + b))
			return true;
		else 
			return false;
	}
};




















