#pragma once
#include <map>
#include <set>
#include <string>
#include <iostream>

struct WikiLink {
	std::string name = "DEFAULT_NAME";
	std::string link = "DEFAULT_LINK";

	bool operator<(const WikiLink &SecondLink) const {
		if (name == SecondLink.name)
			return link < SecondLink.link;
		return name < SecondLink.name;
	}

	bool operator==(const WikiLink &SecondLink) {
		return (*this == SecondLink);
	}

	bool operator!=(const WikiLink &SecondLink) {
		return !(*this == SecondLink);
	}

	friend std::ostream &operator<<(std::ostream &stream, const WikiLink &wikiLink) {
		stream << "\033[1;33m Name: \033[0m" << wikiLink.name << " \033[1;31m Link: \033[0m\033[4;34m" << wikiLink.link << "\033[0m";
		return stream;
	}
};

typedef std::set<WikiLink> WikiLinks;