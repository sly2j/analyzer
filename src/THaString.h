#ifndef ROOT_THaString
#define ROOT_THaString

//**********************************************************************
//
//       THaString.h  (interface)
//
// Authors:  R. Holmes, A. Vacheret, R. Michaels 
//
// Derives from STL string; provides additional methods.  No
// additional storage is defined, so strings and THaStrings can be
// converted back and forth as needed; e.g. to convert a string to
// lowercase you can do something like
//
//      string mixedstring ("MixedCaseString");
//      THaString temp = mixedstring;
//      string lowerstring = temp.ToLower();
//
////////////////////////////////////////////////////////////////////////

#include "Rtypes.h"
#include <string>
#include <vector>

typedef unsigned UInt_t;  // take out when done debugging!!!!!!

class THaString : public string
{

public:

  // Constructors/destructors/operators

  THaString () {};
  THaString (const string s): string(s) {};
  THaString (const char* c): string(c) {};
  virtual ~THaString() {};

  // Major functions

  int CmpNoCase (const THaString& s); // case insensitive compare
  vector<THaString> Split();   // split on whitespace
  UInt_t Hex();      // conversion to to unsigned interpreting as hex
  THaString ToLower (); // conversion to lower case
  THaString ToUpper (); // conversion to lower case

private:
  
  ClassDef(THaString, 0)   // Improved string class

};

#endif