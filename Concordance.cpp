//---------------------------------------------------------------------
// Name:    James Etten, Junsu Jeong, Vang Xiong. 
// Project: Program 5, Using a Concordance with a document.
// Purpose: Stores words form a text file in an STL map with their
//          corresponding line number of where the word is found.
//---------------------------------------------------------------------

#include "Concordance.h"
using namespace System;

Concordance::Concordance()
{
}

Concordance::~Concordance()
{
   conData.clear();
}

void Concordance::Add(string word, int line)
{
   set<int> temp;
   concIter = conData.find(word);
   if (concIter == conData.end())
   {  
      temp.insert(line);
      conData.insert(conc_pair(word, temp));
   }
   else
   {
      data = concIter->second;
      data.insert(line);
      conData[word] = data;
   }
}

bool Concordance::Display(string word, TextBox ^ tb)
{
   String^ wordToAdd;
   concIter = conData.find(word);
   if (concIter == conData.end())
      return false;
   else
   {
      wordToAdd = gcnew String((concIter->first).c_str());
      data = concIter->second;
      dataIter = data.begin();
      for (dataIter; dataIter != data.end(); dataIter++)
      {
         if (dataIter == data.begin())
            wordToAdd += ( "   " + *dataIter);
         else
            wordToAdd += ("," + *dataIter);
      }
      wordToAdd += "\r\n";
      tb->AppendText(wordToAdd);
      return true;
   }
}

void Concordance::StartWith(string subString, ListBox^ lb)
{
   String^ word;
   lb->Items->Clear();
   concIter = conData.begin();
   for (concIter; concIter != conData.end(); ++concIter)
   {
      string key = concIter->first;
      if (key.compare(0, subString.length(), subString) == 0)
      {
         word = gcnew String(key.c_str());
         lb->Items->Add(word);
      }
   }
}

void Concordance::EndWith(string subString, ListBox^ lb)
{
   String^ word;
   lb->Items->Clear();
   concIter = conData.begin();
   for (concIter; concIter != conData.end(); ++concIter)
   {
      string key = concIter->first;
      if (key.compare(key.length() - subString.length(), key.length(), subString) == 0)
      {
         word = gcnew String(key.c_str());
         lb->Items->Add(word);
      }
   }
}

void Concordance::Contains(string subString, ListBox ^ lb)
{
   String^ word;
   lb->Items->Clear();
   concIter = conData.begin();
   for (concIter; concIter != conData.end(); ++concIter)
   {
      string key = concIter->first;
      if (key.find(subString) != -1)
      {
         word = gcnew String(key.c_str());
         lb->Items->Add(word);
      }
   }
}

void Concordance::Print(ofstream & ofs)
{
   for (concIter = conData.begin(); concIter != conData.end(); concIter++)
   {
      ofs << concIter->first;
      data = concIter->second;
      dataIter = data.begin();
      for (dataIter; dataIter != data.end(); dataIter++)
      {
         if (dataIter == data.begin())
         {
            ofs << "   " << *dataIter;
         }
         else
         {
            ofs << "," << *dataIter;
         }
      }
      ofs << endl;
   }
}

bool Concordance::Remove(string word)
{
   concIter = conData.begin();
   for (concIter; concIter != conData.end(); ++concIter)
   {
      if (concIter->first == word)
      {
         conData.erase(word);
         return true;
      }
   }
   return false;
}
