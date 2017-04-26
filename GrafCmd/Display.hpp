#include <vector>
#include <sstream>

inline std::vector<std::pair<int, int>> TranslateToIncidentMatrix(bool** ppMatrix, const int& uiNumberOfVertex){ 
	std::vector<std::pair<int, int>> incidentMatrix;

	for (int i = 0; i < uiNumberOfVertex; i++)
		for (int j = 0; j < uiNumberOfVertex; j++)
			if (ppMatrix[i][j]){
				bool isFound = false;

				for (const auto& item : incidentMatrix){
					if ((item.second == i) && (item.first == j)){
						isFound = true;
						break;
					}
				}
						

				if (!isFound)
					incidentMatrix.push_back(std::pair<int, int>(i, j));

			}
				
				
	return incidentMatrix;
}

inline std::string DisplayMatrix(bool** ppMatrix, const int& uiNumberOfVertex, const int& uiNumberOfEdge){
	std::stringstream strOutput;
	
	strOutput << "  ";

	for (int i = 1; i <= uiNumberOfVertex; i++)
		strOutput << i << " ";

	strOutput << std::endl;

	for (int i = 0; i < uiNumberOfVertex; i++){
		strOutput << i + 1 << " ";
		for (int j = 0; j < uiNumberOfVertex; j++)
			strOutput << (ppMatrix[i][j] ? "1" : "0") << " ";

		strOutput << std::endl;
	}

	

	return strOutput.str();
}

inline std::string DisplayIncident(const std::vector<std::pair<int, int>>& incidentMatrix){ 
	std::stringstream strOutput;

	for (const auto& item : incidentMatrix){
		strOutput << item.first+1 << " " << item.second+1 << std::endl;
	}

	return strOutput.str();
}

inline std::string Display(bool** ppMatrix, const int& uiNumberOfVertex, const int& uiNumberOfEdge, const char& cMode)
{
	if (cMode == 'I'){
		return DisplayIncident(TranslateToIncidentMatrix(ppMatrix, uiNumberOfVertex));
	}else if (cMode == 'M'){
		return DisplayMatrix(ppMatrix, uiNumberOfVertex, uiNumberOfEdge);
	}else{
		return std::string();
	}
}



