#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::executeLogic() const
{
    // Define the ASCII art for the tree
    std::string tree(
        "            * *    \n"
        "        *    *  *\n"
        "    *  *    *     *  *\n"
        "    *     *    *  *    *\n"
        "* *   *    *    *    *   *\n"
        "*     *  *    * * .#  *   *\n"
        "*   *     * #.  .# *   *\n"
        "*     \"#.  #: #\" * *    *\n"
        "*   * * \"#. ##\"       *\n"
        "*       \"###\n"
        "            ##\n"
        "            ##.\n"
        "            .##:\n"
        "            :###\n"
        "            ;###\n"
        "            ,####.\n"
        "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n"
    );

    // Create a file with the target name and "_shrubbery" suffix
    std::ofstream file(target + "_shrubbery");

    // Check if the file was successfully opened
    if (file)
    {
        // Write the tree ASCII art to the file
        file << tree << "\n" << tree;
    }
}