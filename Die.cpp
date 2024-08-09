#include "Die.h"

std::ostream& operator<<(std::ostream& strm, const Die& obj) {
	strm << "A Die with " << obj.sides << " sides";
	return strm;
}

int Die::roll() {
	return (std::rand() % sides) + 1;
}

