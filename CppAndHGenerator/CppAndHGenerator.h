#ifndef SS01_CPPANDHGENERATOR_H
#define SS01_CPPANDHGENERATOR_H
#include <string>

#define CAPS_SUBSTITUTION_SYMBOL '@'
#define LOWERCASE_SUBSTITUTION_SYMBOL '`'
#define CLASS_SUBSTITUTION_SYMBOL '$'

// could just not use a class
// but all other exercises are also setup in a class so...
class CppAndHGenerator {
public:
    // methods
    static void StartGenerator();
private:
    // methods
    static bool IsInputValid(const std::string&);
    static void GenerateFiles(std::string&, const std::string&, const std::string&);
    static void TransformToClassName(std::string&);
    static void TransformAllToLower(std::string&);
    static void TransformAllToUpper(std::string&);
    static std::string GetHeaderTemplate();
    static std::string GetCppTemplate();
    static void BuildContent(std::string&, std::string&, std::string&);
};


#endif