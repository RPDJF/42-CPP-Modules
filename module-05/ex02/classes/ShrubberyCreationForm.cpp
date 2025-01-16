#include "./ShrubberyCreationForm.hpp"

static void repeatFileAppend(std::ofstream& file, const std::string& str, int i) {
    for(int j = 0; j < i; j++) {
        file << str;
    }
    file << std::endl;
}

void ShrubberyCreationForm::createShrubberyFile() const {
    const std::string fileName = std::string(this->target_).append("_shruberry");
    
    std::ofstream file(fileName.c_str());
    if(!file) {
        throw ShrubberyCreationForm::ShrubberyFileNotCreated();
        return;
    }
    repeatFileAppend(file, "       _-_         ", 4);
    repeatFileAppend(file, "    /~~   ~~\\      ", 4);
    repeatFileAppend(file, " /~~         ~~\\   ", 4);
    repeatFileAppend(file, "{               }  ", 4);
    repeatFileAppend(file, " \\  _-     -_  /   ", 4);
    repeatFileAppend(file, "   ~  \\\\ //  ~     ", 4);
    repeatFileAppend(file, "_- -   | | _- _    ", 4);
    repeatFileAppend(file, "  _ -  | |   -_    ", 4);
    repeatFileAppend(file, "      // \\\\        ", 4);
    file << std::endl;
    file.close();
}

std::ostream& ShrubberyCreationForm::annonce() const {
    return std::cout << C_MAGENTA << "ShrubberyCreationForm " << C_YELLOW << "(" << this->getName() << ") " << C_RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyForm", REQ_SIGN_GRADE_, REQ_EXEC_GRADE_), target_("target") {
    this->annonce() << "has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyForm", REQ_SIGN_GRADE_, REQ_EXEC_GRADE_), target_(target) {
    this->annonce() << "has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form): AForm(form) {
    this->annonce() << "has been created!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    this->annonce() << "has been destroyed!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign) {
    if (this == &assign)
        return *this;
    AForm::operator=(assign);
    this->annonce() << "form as been assigned from " << C_YELLOW << assign.getName() << C_RESET << std::endl;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) {
    AForm::execute(executor);
    createShrubberyFile();
}

const char * ShrubberyCreationForm::ShrubberyFileNotCreated::what() const throw() { return "shrubbery file not created!"; }