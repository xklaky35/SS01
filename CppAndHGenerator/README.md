# COMP710: Studio Session 01 – Exercise:

## EXERCISE NAME: Tools Dev – cpp and h Generator

Add a new C++ Project named “Cpp and h Generator” to your “SS01” Visual Studio Solution for this exercise Create a program that prompts the user for a new class name and then generates a skeleton .h header file and .cpp implementation file based upon the new class name specified by the user. This tool will save you time when creating your own new C++ classes, easily creating two skeleton files to begin programming work on a new class.

An example of the program’s console output is as follows:

```
New class name? Template
Done, template.h and template.cpp written to disk.
```

After executing the above example, the following template.h file has been saved to disk:

```cpp
// COMP710 YOUR NAME

#ifndef TEMPLATE_H
#define TEMPLATE_H

// Forward declarations:
class Renderer;

// Class declaration:
class Template
{
public:
    Template();
    ~Template();

    bool Initialise();
    void Process(float deltaTime);
    void Draw(Renderer& renderer);

protected:

private:
    Template(const Template& template);
    Template& operator=(const Template& template);
};

#endif // TEMPLATE_H
```

And the accompanying template.cpp file has also been saved to disk:

```cpp
// COMP710 YOUR NAME

// This include:
#include "template.h"

// Local includes:
#include "renderer.h"

// Library includes:
#include <cassert>

Template::Template()
{
}

Template::~Template()
{
}

bool
Template::Initialise()
{
    return false;
}

void
Template::Process(float deltaTime)
{
    assert(0);
}

void
Template::Draw(Renderer& renderer)
{
    assert(0);
}
```

In the two example files above, anywhere the user specified “Template” class name appears must be replaced by the appropriate new class name. Further core requirements:

- The filenames are to always be lowercase (no uppercase characters).
- All class names start with an uppercase letter.
- The .h file header guards is always uppercase, in the CLASSNAME_H style.
  - All variable names start with a lowercase letter. Ensure the parameters of the private copy constructor and assignment operator start with a lowercase character.

### Getting started hints:

- Create a new console project.
- ```#include <iostream>``` to access ```std::cin and std::cout```
- ```#include <string>``` to access ```std::string```
- ```#include <fstream>``` to access ```std::ofstream```
- After reading in the user’s new class name…
  - Use a std::string to store the class name in the required style (uppercase first
    letter).
  -  Use a std::string to store the class name in the filename required style (all
    lowercase).
  - Use a std::string to store the class name in the required uppercase header
    guard style (all uppercase with surrounding underscores).

Once complete, commit your program’s source code to your individual GitHub repository.

Possible function declarations:

```cpp
bool WriteHFile(const std::string& className);
bool WriteCPPFile(const std::string& className);

std::string GetAsClassName(const std::string& className);
std::string GetAllLowerCase(const std::string& className);
std::string GetHeaderGuard(const std::string& className);
```

Once complete, commit your program’s source code to your individual GitHub repository.