
#include <cstdlib>
#include <list>
#include "Referenced.h"


std::list<bool> Referenced::_validList;

Referenced::~Referenced() {
	*_valid = false;
}



