// GrafCmd.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <sstream>
#include "Generate.hpp"
#include "Display.hpp"

static const int iRET_OK = 0;
static const int iRET_NO_ARGS = -14;
static const int iRET_WRONG_ARGS = -15;

int main(int argc, char* argv[])
{
	char cEncode = '\0';
	bool** ppMatrix = nullptr;
	unsigned int uiVertex = 0;
	unsigned int uiEdge = 0;

	std::cout << "Witaj w generatorze grafow!" << std::endl
	<< "Project dla Europejska Uczelnia w Warszawie" << std::endl
	<< "Copyright@ Artur Jaworski" << std::endl << std::endl;

	if (argc < 4){
		std::cout << "WprowadŸ parametry!" << std::endl
			<< "%Kodowanie% %Wierzcholki% %Polaczenia%" << std::endl
			<< std::endl
			<< "%Kodowanie% moze przyjmowac wartosci:" << std::endl
			<< "I dla grafow reprezentowanych przez macierz incydencji" << std::endl
			<< "M dla grafow reprezentowanych przez macierz sasiedstwa" << std::endl
			<< std::endl
			<< "%Wierzcholki%: okresla ilosc wierzcholkow grafu" << std::endl
			<< "Musi byc  nioznaczona liczba calkowita" << std::endl
			<< std::endl
			<< "%Polaczenia%: okresla ilosc polaczen miedzy wierzcholkami grafu" << std::endl
			<< "Musi byc nioznaczona liczba calkowita" << std::endl;
			

		return iRET_NO_ARGS;
	
	}

	if (('I' == argv[1][0]) || ('M' == argv[1][0]))
		cEncode = argv[1][0];
	else
		return iRET_WRONG_ARGS;


	std::istringstream(argv[2]) >> uiVertex;
	std::istringstream(argv[3]) >> uiEdge;

	ppMatrix = GenerateGraphMartix(uiVertex, uiEdge);
	if (ppMatrix == nullptr){
		std::cout << "Nie mo¿na wygenerowaæ grafu o podanych parametrach." << std::endl;
		return iRET_WRONG_ARGS;
	}

	std::cout << Display(ppMatrix, uiVertex, uiEdge, cEncode) << std::endl;

	return iRET_OK;
}

