#include <iterator>
#include "WikiNode.h"

std::string WikiNode::openFile(std::string InputFile) {
	std::string Output;
	std::string Temp;
	
	std::ifstream currentFile(InputFile);
	
	if (currentFile.is_open()) {
		while (std::getline(currentFile, Temp)) {
			Output.append(Temp);
		}
		currentFile.close();
		//std::cout << Output;
		return Output;
	}

	std::cout << "Error while opening file!" << std::endl;

	return "";
}

void WikiNode::SearchLinks(std::string InputText, std::regex Regex) {
	std::smatch matches;

	std::string result;
	auto iter = InputText.cbegin();

	while (std::regex_search(iter, InputText.cend(), matches, Regex)) {

		WikiLink link;
		std::string IntermediateLink = matches[0];
		std::string IntermediateName;
		//Start of string processing ----------------------------------------------------------------------

		IntermediateName = IntermediateLink.substr(12, IntermediateLink.size());
		IntermediateLink = IntermediateLink.substr(6, IntermediateLink.size());
		IntermediateLink.insert(0, "https://www.wikipedia.org");

		//End of string processing ------------------------------------------------------------------------
		link.link = IntermediateLink;
		link.name = IntermediateName;
		this->NodeWikiLinks.insert(link);

		iter = matches[0].second;
	}

	for (auto const &CurrentLink : this->NodeWikiLinks) {
		std::cout << CurrentLink << std::endl;
	}
}

WikiNode::WikiNode(std::string InputFile) {
	this->SearchLinks(this->openFile(InputFile), WikiLinkRegex);
}

WikiNode::~WikiNode() {
}
