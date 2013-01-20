//#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "rectangle.h"
#include "skip_list.h"
using namespace std;

bool check_name(string name)
{
  /*if (!(('a'<=name[0] && name[0]<='z') || ('A'<=name[0] && name[0]<='Z')))
     return false;
  for(int i=1; i<name.length()-1;i++)
  {
    if(!(('a'<=name[i] && name[i]<='z') ||
         ('A'<=name[i] && name[i]<='Z') ||
         ('0'<=name[i] && name[i]<='9') ||
         (name[i]=='_')))
    cout<<"Illegal name for rectangle! Failed to execute this command line!";
    return false;
  }*/
  return true;
}

int main (int argc, char* argv[])
{
   fstream readFile;
   readFile.open(argv[1],ios::in);
   string line;//line buffer
   Rectangle temp;
   skip_list s;
   while(getline(readFile,line))
   {
     string command[6];
     int c_count=0;//count how many component of each command line
     int start=0;
     int x,y,w,h;
     if (line=="allintersections")
	command[0]=line;
     //if not allintersections, read the command
     else
       for(int current=0; current<=line.length();current++)
       {
	  if(line[current]==' '|| line[current]=='\t'
	     ||line[current]=='\n'||line[current]=='\0')
          {
	    command[c_count]=line.substr(start,current-start);
            start=current+1;
            c_count++; 
          }
       }//get the command line
 
     if (command[0]=="search")
       {	
         string name=command[1];
	 if(check_name(name)==true)
 	 {
            s.search(name);//search
         }
       } 
     else if (command[0]=="insert")
	{ 
	 temp.set_name(command[1]);
	 temp.set_x(atoi(command[2].c_str()));
	 temp.set_y(atoi(command[3].c_str()));
	 temp.set_w(atoi(command[4].c_str()));
	 temp.set_h(atoi(command[5].c_str()));
	 if(check_name(temp.get_name())==true)
	 {   
           s.insert(temp);//insert"
         }	
	}
             
     else if (command[0]=="rangesearch")
        {
	 x=atoi(command[1].c_str());
         y=atoi(command[2].c_str());
         w=atoi(command[3].c_str());
         h=atoi(command[4].c_str());
	 s.rangesearch(x, y, w, h);
        }
               
     else if (command[0]=="allintersections")
         s.allintersections();

     else if (command[0]=="remove")
	{
	  if (c_count > 2)
	   {
	      x=atoi(command[1].c_str());
              y=atoi(command[2].c_str());
              w=atoi(command[3].c_str());
              h=atoi(command[4].c_str());
	      s.remove(x,y,w,h);
	   }
           else
           {
	     string name=command[1];
             if (check_name(name)==true)
	     {
              	s.remove(name);//remove
             }
	   }
        }
    }
    readFile.close();
    cout<<endl<<"All commands performed, final skip list contains:"<<endl;
    s.print();
    return 0;
}
