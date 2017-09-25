//---------------------------------------------------------------------
// Name:    James Etten, Junsu Jeong, Vang Xiong. 
// Project: Program 5, Using a Concordance with a document.
// Purpose: Stores words form a text file in an STL map with their
//          corresponding line number of where the word is found.
//---------------------------------------------------------------------

#pragma once


#ifndef __CONCORDANCE_H
#define __CONCORDANCE_H
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <iostream>

#include <msclr\marshal_cppstd.h> 
using namespace msclr::interop;
using namespace std;
using namespace System::Windows::Forms;



//---------------------------------------------------------------------
// This class creates and handles adding, searching, printing and
// removing a given word from the STL map.
//---------------------------------------------------------------------
class Concordance
{
public:

   //------------------------------------------------------------------
   // Default constructor for Concordance.
   //------------------------------------------------------------------
   Concordance();

   //------------------------------------------------------------------
   // Destructor, clears the STL map.
   //------------------------------------------------------------------
   ~Concordance();

   //------------------------------------------------------------------
   // Adds a given word and its line number into the map. If the word
   // already exists then the line number is added to that word.
   // params: word, in.  line, in.
   //------------------------------------------------------------------
   void Add(string word, int line);

   //------------------------------------------------------------------
   // Displays a given word in the Display testbox.
   // params: word, in. tb, in.
   //------------------------------------------------------------------
   bool Display(string word, TextBox^ tb);

   //------------------------------------------------------------------
   // Removes a given word from the STL map.
   // params: word, in.
   //------------------------------------------------------------------
   bool Remove(string word);

   //------------------------------------------------------------------
   // Searches for a given subString that a word starts with. If found
   // the word is displayed in the listbox.
   // params: subString, in.  ln, in.
   //------------------------------------------------------------------
   void StartWith(string subString, ListBox^ lb);

   //------------------------------------------------------------------
   // Searches for a given subString that a word ends with. If found
   // the word is displayed in the listbox.
   // params: subString, in.  ln, in.
   //------------------------------------------------------------------
   void EndWith(string subString, ListBox^ lb);

   //------------------------------------------------------------------
   // Searches for a given subString that a word contains. If found
   // the word is displayed in the listbox.
   // params: subString, in.  ln, in.
   //------------------------------------------------------------------
   void Contains(string subString, ListBox^ lb);

   //------------------------------------------------------------------
   // Prints the contents of the STL map to an out file.
   // params: ofs, in.
   //------------------------------------------------------------------
   void Print(ofstream & ofs);
         

private:

   typedef map <string, set<int>> conc;
   typedef pair <string, set<int>> conc_pair;
   conc conData;
   conc::iterator concIter;
   set<int> data;
   set<int>::iterator dataIter;

};

#endif
