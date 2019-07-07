#include <string>
#include <iostream>
#include <exception>
#include "Array.tpp"
#include <cstdlib>
#include <ctime>

template<typename T, typename U>
int func(T &A, T &B, U) {
	try {
		std::cout << "\n\033[1;34mIn the beginning\033[1;0m" << std::endl;
		for (int i = 0; i < A.size(); i++)
			A[i] = i + 65;

		std::cout << "Array A = " << A;
		std::cout << "Array B = " << B;

		std::cout << "\033[1;34m\nAfter assignation operator called\nB = A\033[1;0m" << std::endl;
		B = A;

		std::cout << "Array A = " << A;
		std::cout << "Array B = " << B;

		std::cout << "\033[1;34m\nOverwriting array A to 0\033[1;0m" << std::endl;
		for (int i = 0; i < A.size(); i++)
			A[i] = 0;
		std::cout << "Array A = " << A;
		std::cout << "Array B = " << B;

		std::cout << "\033[1;34m\nCopy constructor called\nArray<int> C( B )\033[1;0m" << std::endl;
		Array<U> C(B);
		std::cout << "Array B = " << B;
		std::cout << "Array C = " << C;

		std::cout << "\033[1;34m\nOverwriting array B to 0\033[1;0m" << std::endl;
		for (int i = 0; i < B.size(); i++)
			B[i] = 0;
		std::cout << "Array B = " << B;
		std::cout << "Array C = " << C;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\033[1;34mSetting out of range\033[1;0m" << std::endl;
	for (int i = 0; i < 5; i++) {
		int random = rand() % 100;

		try {

			A[A.size() + random] = i;
		}
		catch (std::exception &e) {
			std::cout << "A[" << i + random << "] " << e.what() << std::endl;
		}
	}

	return 0;
}


int				main(void)
{
	srand(clock());
	const int len = 5 + rand() % 20;

	switch(rand() % 4) {
		case 0: {
			Array<int> A(len);
			Array<int> B;
			func(A, B, 1);
		}
			break;
		case 1: {
			Array<double> A(len);
			Array<double> B;
			func(A, B, 0.0 );
		}
			break;
		case 2: {
			Array<float> A(len);
			Array<float> B;
			func(A, B, 0.0F );
		}
			break;
		default: {
			Array<char> A(len);
			Array<char> B;
			func(A, B, '0' );
		}
			break;
	}

	return (0);
}
