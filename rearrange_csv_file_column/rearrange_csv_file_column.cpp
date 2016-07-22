#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <cstdlib>

using namespace std;


int getNumberOfColumn(ifstream& file)
{
   int column_count = 0 ;
   string current_line;

   getline(file,current_line);

   stringstream  currentStream(current_line);
   string  cell;

   while(getline(currentStream,cell,','))
   {
      column_count+=1;
   }
   return column_count;
}


void readAndUpdateLine(ifstream& file, ofstream& new_file, int  new_column_sequence[], int no_of_columns)
{
   string current_line;
   while(getline(file,current_line))
   {
      int column_count = 0;
      string row[no_of_columns];
      stringstream  currentStream(current_line);
      string  cell; 
      while(getline(currentStream,cell,','))
      {
         row[column_count] = cell;
         column_count++;
      }

      for (int i=0; i < no_of_columns; i++)
      {
         new_file << row[new_column_sequence[i]];
         if (i != (no_of_columns -1))
           new_file <<",";
      }
      new_file << "\n";
   }
} 

int main(int argc, char* argv[])
{ 

   if (argc != 4)
   {
      cout << "Usuage: " << argv[0] << "  csv_file_name   no_of_columns new_sequence_of_columns"  << endl;
      cout <<  "example : " <<  argv[0] << "  csv_file_name      5      \"0 1 2 3 4 \"    " <<endl;
      exit(0);
   }
   
   string csv_file_name = argv[1];
   int number_of_column_in_file = atoi(argv[2]);
   string new_sequence = argv[3];
   string csv_new_file_name = "output.csv";
   
   stringstream ss(new_sequence);
   int new_column_sequence[number_of_column_in_file];
      
   for (int i = 0; i < number_of_column_in_file; i++) 
      ss >> new_column_sequence[i] ;
   
   //open a csv file in read mode.
   ifstream  csv_read_file;
   csv_read_file.open(csv_file_name.c_str());

   //open a csv file in write mode.
   ofstream  csv_write_file;
   csv_write_file.open(csv_new_file_name.c_str(),ios::trunc);
    
   // string variable is declared to hold current line. 
   string current_line;
   int number_of_column;

   // number of column in csv file.
   number_of_column = getNumberOfColumn(csv_read_file);
   csv_read_file.seekg (0, ios::beg); 

   if (number_of_column_in_file != number_of_column)
   {
       cout << "column count specified as an arquement does not match with column count in .csv file" << endl;;
       exit(0);
   }  
   
   readAndUpdateLine(csv_read_file, csv_write_file, new_column_sequence, number_of_column_in_file);
   csv_read_file.close();
   csv_write_file.close();
   return 0;
}
