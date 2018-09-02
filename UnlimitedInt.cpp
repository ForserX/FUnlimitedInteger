#include "UnlimitedInt.hpp"

void CFUnlimitedInt::SubtractVar(const long long &refNum)
{
	string StringNumber = std::to_string(refNum);

	if (StringNumber[0] == '-')
	{
		AddToVar(refNum);
	}

	if (!Var.length() || Var[0] == '0')
	{
		Var = "-" + StringNumber;
	}
	else
	{
		const size_t IterLen = StringNumber.length();
		for (size_t RevIter = IterLen, Iter = 0; IterLen > Iter; --RevIter, ++Iter)
		{
			int Sub = 0;
			if (Iter >= Var.length())
			{
				if (Var.length() != IterLen)
				{
					Sub = (StringNumber[RevIter - 1] - '0');
				}
				else
				{
					StringNumber = StringNumber[RevIter - 1] + StringNumber;
					continue;
				}
			}
			else Sub = (StringNumber[RevIter - 1] - '0') - (Var[Var.length() - Iter - 1] - '0');

			if (Sub < 0)
			{
				if (Var.length() - 1 == Iter)
				{
					StringNumber = "1" + StringNumber;
					StringNumber[IterLen - Iter] = Sub - 10 + '0';
					continue;
				}
				else
				{
					IterationsCount++;
					AddToVar(10 + 10 * (Iter + IterationsCount));
					IterationsCount--;
				}
				StringNumber[IterLen - Iter - 1] = Sub - 10 + '0';
			}
			else StringNumber[IterLen - Iter - 1] = Sub + '0';
		}
		if (Var.length() > IterLen)
		{
			size_t summary = Var.length() - IterLen;

			for (size_t iter = 0; iter < summary; ++iter)
				StringNumber = Var[summary - iter - 1] + StringNumber;
		}
		Var = StringNumber;
	}
	// do no nothing yet
}

void CFUnlimitedInt::AddToVar(const long long &refNum)
{
	string StringNumber = std::to_string(refNum);
	if (StringNumber[0] == '-')
	{
		SubtractVar(refNum);
	}

	if (!Var.length() || Var[0] == '0')
	{
		Var = StringNumber;
	}
	else
	{
		const size_t IterLen = StringNumber.length();
		for (size_t RevIter = IterLen, Iter = 0; IterLen > Iter; --RevIter, ++Iter)
		{
			int Sum = 0;
			if (Iter >= Var.length())
			{
				if (Var.length() != IterLen)
				{
					Sum = (StringNumber[RevIter - 1] - '0');
				}
				else
				{
					StringNumber = StringNumber[RevIter - 1] + StringNumber;
					continue;
				}
			}
			else Sum = (StringNumber[RevIter - 1] - '0') + (Var[Var.length() - Iter - 1] - '0');

			if (Sum > 9)
			{
				if (Var.length() - 1 == Iter)
				{
					StringNumber = "1" + StringNumber;
					StringNumber[IterLen - Iter] = Sum - 10 + '0';
					continue;
				}
				else
				{
					IterationsCount++;
					AddToVar(10 + 10 * (Iter + IterationsCount));
					IterationsCount--;
				}
				StringNumber[IterLen - Iter - 1] = Sum - 10 + '0';
			}
			else StringNumber[IterLen - Iter - 1] = Sum + '0';
		}
		if (Var.length() > IterLen)
		{
			size_t summary = Var.length() - IterLen;

			for (size_t iter = 0; iter < summary; ++iter)
				StringNumber = Var[summary - iter - 1] + StringNumber;
		}
		Var = StringNumber;
	}
}

CFUnlimitedInt::CFUnlimitedInt(long long a) : IterationsCount(-1)
{
	Var = std::to_string(a);
}