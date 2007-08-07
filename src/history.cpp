#include <history.h>

namespace newsbeuter {

history::history() : idx(0) { }

history::~history() { }

void history::add_line(const std::string& line) {
	if (line.length() > 0) {
		lines.insert(lines.begin(), line);
	}
	idx = 0;
}

std::string history::prev() {
	if (idx < lines.size()) {
		return lines[idx++];
	}
	if (lines.size() == 0) {
		return "";
	}
	return lines[idx-1];
}

std::string history::next() {
	if (idx > 0) {
		return lines[--idx];
	}
	return "";
}


}