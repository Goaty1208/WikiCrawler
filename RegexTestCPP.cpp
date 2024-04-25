#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include "WikiNode.h"

int main() {

	std::regex Regex(R"(href="/wiki/[^"]+)"); //What the fuck

	std::cout << "Regex Test D --- WikiNode Class" << std::endl << std::endl;

	WikiNode RegexArticle("regex.htm");

}

