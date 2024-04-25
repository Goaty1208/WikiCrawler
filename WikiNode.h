#pragma once
#include <regex>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iterator>
#include <set>
#include "WikiLink.h"

//--------------------------------------------------------------|
//-----He who touches thy regex shall perish--------------------|
const std::regex WikiLinkRegex(R"(href="/wiki/[^"]+)"); //------|
//-----------------The Holy Grail-------------------------------|
//--------------------------------------------------------------|

class WikiNode {
	public:
	WikiLinks NodeWikiLinks;
	WikiNode(std::string InputFile);
	~WikiNode();
	private:
	std::string openFile(std::string InputFile);
	void SearchLinks(std::string InputText, std::regex Regex);

};

