#ifndef SLAP_H
#define SLAP_H
#include <exception>
#include <string>

struct Slap: public std::exception {
   std::string errMsg;
   Slap(std::string errMsg): errMsg{errMsg} {}
   ~Slap() throw () {}
   std::string get() const throw() { return errMsg; }
};

#endif
