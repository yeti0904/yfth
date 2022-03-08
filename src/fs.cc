#include "fs.hh"

std::string FS::Read(std::string fname) {
	std::ifstream fhnd(fname);
	std::string   ret;
	std::string   line;
	while (getline(fhnd, line)) {
		ret += line + "\n";
	}
	fhnd.close();
	return ret;
}
