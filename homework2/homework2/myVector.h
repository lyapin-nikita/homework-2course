#pragma once



class my3mVector
{
private:
	float numbers[3];
	float length;



public:
	my3mVector();
	my3mVector(float n1, float n2, float n3);
	my3mVector(const my3mVector& vec);

	

	my3mVector operator+(const my3mVector& other);
	my3mVector operator-(const my3mVector& other);
	const my3mVector& operator=(const my3mVector& other);
	double operator*(my3mVector& other); 
	friend std::ostream& operator<<(std::ostream& stream, const my3mVector& vec);
	friend std::istream& operator>>(std::istream& stream, my3mVector& vec);
	void countLength();
	float getLength();
	float vectorCos(my3mVector& other);
};

