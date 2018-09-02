///////////////////////////////////////////////
// CFUnlimitedInt
// ForserX 
// 2018
#pragma once

using fulint = class CFUnlimitedInt
{
	using string = std::string;

private: 	
	string Var;
	long long IterationsCount;

private:
	void SubtractVar(const long long &refNum);
	void AddToVar(const long long &refNum);

public:
	CFUnlimitedInt(long long a);

	// Math operators
	virtual void operator+(long long a) { AddToVar(a); }
	virtual void operator-(long long a) { SubtractVar(a); }

	virtual void operator+=(long long a) { AddToVar(a); }
	virtual void operator-=(long long a) { SubtractVar(a); }
	virtual void operator*=(long long a)
	{
		for (size_t iter = 1; iter <= a; iter++)
		{
			// do no nothing yet
		}
	}

	// Cast operators
	operator const char*() const { return Var.c_str(); }
	operator long long  () const { return std::atoll(Var.c_str()); }
	operator long       () const { return std::atol(Var.c_str()); }

	// Anothers operators
	friend std::ostream& operator<<(std::ostream &s, CFUnlimitedInt& This)
	{
		s << This.Var;
		return s;
	}
	char operator[](size_t idx)
	{
		return Var[idx];
	}

	//std::istream& operator>>(std::istream &s)
	//{
	//}
};