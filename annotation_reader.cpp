#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "annotation_reader.hpp"

annotation_reader::annotation_reader(std::string fp) : _fp(fp) {}

std::map<std::string, annotation_fields> annotation_reader::read() {
	std::ifstream ifs(_fp);
	if(!ifs) {
		std::cerr << "Unable to open annotation file" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string header, type_l, class_l, mechanism_l, group_l, snp_l;
	std::map<std::string, annotation_fields> annotations;
	getline(ifs, header);
	while(getline(ifs, header, ',')) {
		getline(ifs, type_l, ',');
		getline(ifs, class_l, ',');
		getline(ifs, mechanism_l, ',');
		getline(ifs, group_l, ',');
		getline(ifs, snp_l);
		annotations[header] = annotation_fields(type_l, class_l, mechanism_l, group_l);
	}

	return annotations;
}
