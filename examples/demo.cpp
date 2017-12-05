/* alice: C++ REPL library
 * Copyright (C) 2017  EPFL
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <alice/alice.hpp>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

#include <boost/hana/for_each.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/range.hpp>
#include <boost/hana/size.hpp>
#include <boost/hana/type.hpp>
#include <fmt/format.h>

namespace alice
{

ALICE_INIT

/* setup string store */
ALICE_ADD_STORE( std::string, "str", "s", "String", "Strings" )

/* small description printed for `store -s` */
ALICE_DESCRIBE_STORE( std::string, element )
{
  return fmt::format( "{} characters", element.size() );
}

/* text printed when calling `print -s` */
ALICE_PRINT_STORE( std::string, os, element )
{
  os << element << std::endl;
}

/* register a new file type to read from and write to */
ALICE_ADD_FILE_TYPE( text, "Text" )

/* read from file into string */
ALICE_READ_FILE( std::string, text, filename, cmd )
{
  std::ifstream in( filename.c_str(), std::ifstream::in );
  std::stringstream buffer;
  buffer << in.rdbuf();
  return buffer.str();
}

/* write from string into file */
ALICE_WRITE_FILE( std::string, text, element, filename, cmd )
{
  std::ofstream out( filename.c_str(), std::ofstream::out );
  out << element;
}

}

ALICE_MAIN(demo)
