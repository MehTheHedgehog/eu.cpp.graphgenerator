#ifndef _GENERATE_HPP
#define _GENERATE_HPP

#include <vector>
#include <ctime>

inline bool isCreatable(const unsigned int& iNumberOfVertex, const unsigned int& iNumberOfEdge){
	return ((((iNumberOfVertex * (iNumberOfVertex - 1)) / 2) + iNumberOfEdge) > iNumberOfEdge);
}

//Generuje nieskierowany graf o danej liczbie kraw�dzi i wierzcho�k�w
//Po��czenia miedzy wierzcho�kami mog� by� tylko pojedy�cze
inline bool** GenerateGraphMartix(const unsigned int& iNumberOfVertex, const unsigned int& iNumberOfEdge){
	
	if (!isCreatable(iNumberOfVertex, iNumberOfEdge))
		return nullptr;
	
	srand(time(NULL));
	//Tworzenie tablicy wska�nik�w		
	bool** Matrix = new bool * [iNumberOfVertex];

	//W ka�dym elemencie tablicy wska�nik�w tworzymy tablice warto�ci boolowskich
	for (unsigned int iIt = 0; iIt < iNumberOfVertex; iIt++)
		Matrix[iIt] = new bool[iNumberOfVertex];

	for (unsigned int iIt = 0; iIt < iNumberOfVertex; iIt++)
		for (unsigned int iIt2 = 0; iIt2 < iNumberOfVertex; iIt2++)
			Matrix[iIt][iIt2] = false;

	for (unsigned int existingEdge = 0; existingEdge <= iNumberOfEdge;)
	{
		unsigned int uiFirstVertex = rand() % iNumberOfVertex;
		unsigned int uiSecondVertex = rand() % iNumberOfVertex;

		if (!Matrix[uiFirstVertex][uiSecondVertex])
		{
			Matrix[uiFirstVertex][uiSecondVertex] = true;
			Matrix[uiSecondVertex][uiFirstVertex] = true;
			existingEdge += 1;
		}
	}


	return Matrix;
}

#endif