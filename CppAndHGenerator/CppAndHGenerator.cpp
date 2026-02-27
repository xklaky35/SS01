#include "CppAndHGenerator.h"
#include <fstream>
#include <iostream>

bool isInAlphabet(char);


// run generator
void CppAndHGenerator::StartGenerator() {

	// ask user for name
	std::string classname; // = "" by default
	std::cout << "New class name? > ";
	std::cin >> classname;

	// keep asking if provided filename is wrong
	while (!IsInputValid(classname)) {
		std::cout << "New class name? > ";
		std::cin >> classname;
	}

	std::string hTemplate = GetHeaderTemplate();
	std::string cppTemplate = GetCppTemplate();

	BuildContent(classname, cppTemplate, hTemplate);
	GenerateFiles(classname);
}

// validates the filename
bool CppAndHGenerator::IsInputValid(const std::string& classname) {
	// leads to bad template file structure
	if (classname.empty()) return false;

	// only letters allowed
	for (const char& c : classname) {
		if (!isInAlphabet(c)) return false;
	}

	return true;
}

// insert the classname the user provided into the templates (.h and .cpp)
void CppAndHGenerator::BuildContent(std::string& classname, std::string& templateCppText, std::string& templateHText) {

	// insert in .cpp
	for (int i = 0; i < templateCppText.size(); i++) {
		if (templateCppText[i] == CAPS_SUBSTITUTION_SYMBOL) {
			TransformAllToUpper(classname);
			templateCppText.replace(i,1,classname);
		}
		if (templateCppText[i] == CLASS_SUBSTITUTION_SYMBOL) {
			TransformToClassName(classname);
			templateCppText.replace(i,1,classname);
		}
		if (templateCppText[i] == LOWERCASE_SUBSTITUTION_SYMBOL) {
			TransformAllToLower(classname);
			templateCppText.replace(i,1,classname);
		}
	}

	// insert in .h
	for (int i = 0; i < templateHText.size(); i++) {
		if (templateHText[i] == CAPS_SUBSTITUTION_SYMBOL) {
			TransformAllToUpper(classname);
			templateHText.replace(i,1,classname);
		}
		if (templateHText[i] == CLASS_SUBSTITUTION_SYMBOL) {
			TransformToClassName(classname);
			templateHText.replace(i,1,classname);
		}
		if (templateHText[i] == LOWERCASE_SUBSTITUTION_SYMBOL) {
			TransformAllToLower(classname);
			templateHText.replace(i,1,classname);
		}
	}
}

// create the files in the filesystem and writes file contents them
void CppAndHGenerator::GenerateFiles(std::string& classname, const std::string& cppTemplate, const std::string& hTemplate) {
	TransformAllToLower(classname);

	// create and write headerfile
	std::ofstream h(classname + ".h");
	h << hTemplate;
	h.close();

	// create and write cpp file
	std::ofstream cpp(classname + ".cpp");
	cpp << cppTemplate;
	cpp.close();
}

// makes the first letter caps and the rest of the work lowercase
void CppAndHGenerator::TransformToClassName(std::string& classname) {
	for (char& c : classname) {
		c = static_cast<char>(std::tolower(c));
	}
	if (!classname.empty()) {
		classname[0] = static_cast<char>(std::toupper(classname[0]));
	}
}
// makes all letters lowercase
void CppAndHGenerator::TransformAllToLower(std::string& classname) {
	for (char& c : classname) {
		c = static_cast<char>(std::tolower(c));
	}
}
// makes all letters uppercase
void CppAndHGenerator::TransformAllToUpper(std::string& classname) {
	for (char& c : classname) {
		c = static_cast<char>(std::toupper(c));
	}
}


// provides the header template
std::string CppAndHGenerator::GetHeaderTemplate() {
	   return "// COMP710 YOUR NAME\n"
	   "#ifndef @_H\n"
	   "#define @_H\n"
	   "\n"
	   "// Forward declarations:\n"
	   "class Renderer;\n"
	   "\n"
	   "// Class declaration:\n"
	   "class $\n"
	   "{\n"
	   "// Member methods:\n"
	   "public:\n"
	   "    $();\n"
	   "    ~$();\n"
	   "\n"
	   "    bool Initialise();\n"
	   "    void Process(float deltaTime);\n"
	   "    void Draw(Renderer& renderer);\n"
	   "\n"
	   "protected:\n"
	   "\n"
	   "private:\n"
	   "    $(const $& template);\n"
	   "    $& operator=(const $& template);\n"
	   "\n"
	   "// Member data:\n"
	   "public:\n"
	   "\n"
	   "protected:\n"
	   "\n"
	   "private:\n"
	   "};\n"
	   "\n"
	   "#endif // @_H\n";


}

// provides the cpp template
std::string CppAndHGenerator::GetCppTemplate() {
		return "// COMP710 YOUR NAME\n"
		"\n"
		"// This include:\n"
		"#include \"`.h\"\n"
		"\n"
		"// Local includes:\n"
		"#include \"renderer.h\"\n"
		"\n"
		"// Library includes:\n"
		"#include <cassert>\n"
		"\n"
		"$::$()\n"
		"{\n"
		"\n"
		"}\n"
		"\n"
		"$::~$()\n"
		"{\n"
		"\n"
		"}\n"
		"\n"
		"bool\n"
		"$::Initialise()\n"
		"{\n"
		"return false;\n"
		"}\n"
		"\n"
		"void\n"
		"$::Process(float deltaTime)\n"
		"{\n"
		"assert(0);\n"
		"}\n"
		"\n"
		"void\n"
		"$::Draw(Renderer& renderer)\n"
		"{\n"
		"assert(0);\n"
		"}\n";
}


