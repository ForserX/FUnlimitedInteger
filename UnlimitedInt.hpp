///////////////////////////////////////////////
// CFUnlimitedInt
// ForserX 
// 2018
#pragma once
#include <string>

using fulint = class CFUnlimitedInt
{
	using string = std::string;

private: 	
	string Var;
	long long IterationsCount;

private:
	void SubtractVar(const long long &refNum);
	void SubtractVar(const string &refNum);
	void AddToVar(const long long &refNum);
	void AddToVar(const string &refNum);

public:
	CFUnlimitedInt(long long a);
//	CFUnlimitedInt(CFUnlimitedInt a);

	// Math operators
	virtual CFUnlimitedInt operator+(int a) { CFUnlimitedInt New = *this;  New += a; return New; }
	virtual CFUnlimitedInt operator-(int a) { CFUnlimitedInt New = *this;  New -= a; return New; }
	virtual CFUnlimitedInt operator+(long long a) { CFUnlimitedInt New = *this;  New += a; return New; }
	virtual CFUnlimitedInt operator-(long long a) { CFUnlimitedInt New = *this;  New -= a; return New; }

	virtual CFUnlimitedInt operator*(int a) { CFUnlimitedInt New = *this;  New *= a; return New; }
	virtual CFUnlimitedInt operator/(int a) { CFUnlimitedInt New = *this;  New /= a; return New; }
	virtual CFUnlimitedInt operator*(long long a) { CFUnlimitedInt New = *this;  New *= a; return New; }
	virtual CFUnlimitedInt operator/(long long a) { CFUnlimitedInt New = *this;  New /= a; return New; }
	//virtual CFUnlimitedInt operator-(long long a) { SubtractVar(a); }

	virtual void operator+=(long long a) { AddToVar(a); }
	virtual void operator-=(long long a) { SubtractVar(a); }
	virtual void operator*=(long long a)
	{
		const CFUnlimitedInt OriginalVar = *this;
		for (size_t iter = 1; iter < a; iter++)
		{
			AddToVar(OriginalVar.Var);
		}
	}

	virtual void operator/=(long long a)
	{
		size_t iter = 1;
		CFUnlimitedInt OriginalVar = *this;
		for (; OriginalVar > 0; iter++)
		{
			OriginalVar -= a;
		}
		Var = iter - 1 + '0';
	}

	// Cast operators
	operator const char*() const { return Var.c_str(); }
	operator long long  () const { return std::atoll(Var.c_str()); }
	operator long       () const { return std::atol(Var.c_str()); }

	// Relational operators
	inline virtual bool operator!=(const CFUnlimitedInt Right) const
	{
		return !(*this == Right);
	}
	inline virtual bool operator!=(const long long Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this != TryRight;
	}
	inline virtual bool operator!=(const int Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this != TryRight;
	}

	inline virtual bool operator==(const CFUnlimitedInt Right) const
	{
		if (Right.Var.length() == Var.length())
		{
			for (size_t Iter = 0; Iter < Right.Var.length(); Iter++)
			{
				if (Right.Var[Iter] != Var[Iter])
					return false;
			}
			return true;
		}

		return false;
	}
	inline virtual bool operator==(const long long Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this == TryRight;
	}
	inline virtual bool operator==(const int Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this == TryRight;
	}

	inline virtual bool operator>(const long long Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this > TryRight;
	}
	inline virtual bool operator>(const int Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this > TryRight;
	}

	inline virtual bool operator<(const int Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this < TryRight;
	}
	inline virtual bool operator<(const long long Right) const
	{
		CFUnlimitedInt TryRight = Right;
		return *this < TryRight;
	}
	inline virtual bool operator<(const CFUnlimitedInt Right) const
	{
		return !(*this > Right) && *this != Right;
	}

	inline virtual bool operator>(const CFUnlimitedInt Right) const
	{
		string refVal = Right.Var;

		if (Var[0] == '-' && refVal[0] != '-')
			return false;
		else if (refVal[0] == '-' && Var[0] != '-')
			return true;

		if (refVal.length() > Var.length())
			return false;
		else if (refVal.length() < Var.length())
			return true;

		unsigned long long Iter = 0;
		do
		{
			if (Var[Iter] - '0' > refVal[Iter] - '0')
				return true;
			else if (Var[Iter] - '0' < refVal[Iter] - '0')
				return false;

			Iter++;
		} while (true);
		
		return false;
	}

	// Anothers operators
	friend std::ostream& operator<<(std::ostream &os, CFUnlimitedInt& This)
	{
		os << This.Var.c_str();
		return os;
	}

	friend std::istream& operator>>(std::istream &is, CFUnlimitedInt &This)
	{
		is >> This.Var;
		return is;
	}

	char operator[](size_t idx)
	{
		return Var[idx];
	}
};