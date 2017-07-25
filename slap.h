#ifndef SLAP_H
#define SLAP_H
#include <exception>
#include <string>

struct Slap: public std::exception {
   std::string errMsg;
   Slap(std::string errMsg): errMsg{errMsg} {}
   ~Slap() throw () {}
   const char* what() const throw() { return errMsg.c_str(); }
};

#endif
