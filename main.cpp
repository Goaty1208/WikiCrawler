#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include "WikiNode.h"

int main() {

	std::cout << "Regex Test E --- cURL" << std::endl << std::endl;

	WikiNode RegexArticle("regex.htm");

	RegexArticle.SavePages();
}

