#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  // Check if an argument was given
  if (argc != 2) {
    std::cout << "A C++ file with a .cpp extension is required." << std::endl;
    return 1;
  }

  // Get the filename from the first command-line argument
  std::string filename = argv[1];

  // Check if the filename ends with ".cpp"
  if (filename.substr(filename.length() - 4) != ".cpp") {
    std::cout << "A C++ file with a .cpp extension is required." << std::endl;
    return 1;
  }

  // Compile the file using g++
  std::string cmd = "g++ " + filename + " -o " + filename.substr(0, filename.length() - 4);
  int status = system(cmd.c_str());

  if (status != 0) {
    std::cout << "Error compiling file." << std::endl;
    return 1;
  }

  // Run the executable file that was created
  cmd = "./" + filename.substr(0, filename.length() - 4);
  status = system(cmd.c_str());

  if (status != 0) {
    std::cout << "Error running executable." << std::endl;
    return 1;
  }

  return 0;
}
