//Suhan Ma Skip List and Rectangle
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include "rectangle.h"
#include "skip_list.h"
using namespace std;

int skip_list::random_level()
{
    int level = 0;
    while (rand()%2 == 0) level++;//flip a coin, decide weather to "go deeper"
    if (level<MAX_LEVEL)
     return level;
    else
     return MAX_LEVEL;//it is not good to get larger than MAX_LEVEL, and it is unnecessary	
}
skip_list::skip_list()
{
    srand((int)time(0));//random seed using current time
    Rectangle r1;
    r1.set_name("~~~~~");//nil, which has very large ascii value	
     // -1 -1 -1 -1
    current_level=1;  
    head=new node(r1,MAX_LEVEL);
    for(int i=0; i<MAX_LEVEL;i++)
      head->forward[i]=head;//head points to itself at the very beginning, which means head itself works as an end point
}

skip_list::~skip_list(){
   delete head;
}

//insert a new node
void skip_list::insert(Rectangle r1){
  int new_level=random_level();//get a random_level at the beginning
  node **track= new node *[MAX_LEVEL]; //track where to insert node
  node *temp = head;
  string name;
  
  for(int i=current_level-1;i>=0;i--)
  {
    name=temp->forward[i]->r.get_name();
    while (name<r1.get_name())
    {
	temp=temp->forward[i];
	name=temp->forward[i]->r.get_name(); 
    }
	track[i]=temp;//track where to insert the new "node"
  }

  if(new_level>current_level)//is it necesssary to use more forward?
  {
     for (int i=current_level; i < new_level; i++)
       track[i]=head;//update our track array, indicates all the new added forward are all point to "nil"
     current_level=new_level;    
  }
    
  node *insert_node =new node(r1,current_level);
    for(int i=0;i<current_level;i++){
        insert_node->forward[i]=track[i]->forward[i];
        track[i]->forward[i]=insert_node;
    }
  cout<<endl<<"Insetion of "<<r1.get_name()<<" succeed!"<<endl;
}

void skip_list::remove(string k_name){
    node *temp = head;
    int level_index=0;//indicade the highest level of foward that k_name been found
    string name; 
    for(int i=current_level-1;i>=0;i--)
    {
        name=temp->forward[i]->r.get_name();
        while(name<k_name)
        {
            temp=temp->forward[i];
            name=temp->forward[i]->r.get_name();
        }
	if (name == k_name)
        {
           level_index = i;
           break;
        }
    }
    //node *temp_destruct[level_index];
    if (name==k_name)
    {	
      for(int i=level_index; i>=0;i--)
      {
	//temp_destruct[i] = temp->forward[i];
	temp->forward[i]=temp->forward[i]->forward[i];//jump off the element that will be deleted
        //delete temp_destruct[i];
      }
    } 
    cout<<endl<<"Remove "<<k_name<<" succeed!"<<endl;
}

//since we did not have a name as the key to help remove the rectangle, we search the lowest level and then remove the element 
void skip_list::remove(int x, int y, int w, int h)
{
   node *temp=head->forward[0];//start from the first rectangle data
   string name;
   Rectangle r2;
   while(temp!=head)//not run to end yet
   {
     r2=temp->r;
     if(r2.get_x()==x && r2.get_y()==y && r2.get_w()==w && r2.get_h()==h)
     {
            remove(r2.get_name());
	    break;	
     }
     temp=temp->forward[0];
   }
}    
    
void skip_list::search(string k_name){
    node *temp=head;
    string name;
    bool found=false;
    int indicator=0;
    for(int i=current_level-1;i>=0;i--)
    {
        name=temp->forward[i]->r.get_name();
        while(name<k_name)
        {
            temp=temp->forward[i];
            name=temp->forward[i]->r.get_name();
        }
        if (name == k_name)
        {
           found=true;
           indicator=i;
           break;
        }
    }
    if (found == true)
    {	
     cout<<endl<<"Found the rectangle of the given name "<<k_name<<endl;
     temp->forward[indicator]->r.print_info();
     cout<<endl;
    }
    else
    cout<<endl<<"Rectangle "<<k_name<<" not found!"<<endl;
}

//Print all nodes
void skip_list::print(){
  node *temp=head->forward[0];
  while(temp->r.get_name()!="~~~~~")
  {
     temp->r.print_info(); 
     temp=temp->forward[0];  
  }
}

//range search
void skip_list::rangesearch(int x, int y, int w, int h){
    node *temp=head->forward[0]; //search for all rectangle in given range, it is better to run through whole list 
    int count=0;
    string name;
    cout<<endl<<"Perform Range Search "<<endl;
    while(temp!=head)//not run to the nil
    {
        if(temp->forward[0]->r.recIntersect(x, y, w, h))
        {
            ++count;
            cout<<"Overlap No."<<count<<" info:"<<endl;
            temp->forward[0]->r.print_info();     
         }
         temp=temp->forward[0];
    }
    if(count==0)
	cout<<"No overlap within the given range!"<<endl<<endl;    
}



void skip_list::allintersections(){
    int count=0;
    node *temp=head->forward[0];
    node *temp2=head->forward[0]->forward[0];//one "forward" ahead
    while(temp->r.get_name()!="~~~~~") //not went to nil
    { 
        temp2=temp->forward[0];//one step ahead  
        while(temp2->r.get_name()!="~~~~~") // not went to nil
        {
            if(temp->r.recIntersect(temp2->r.get_x(),temp2->r.get_y(),temp2->r.get_w(),temp2->r.get_h())==true)
            {
                cout<<endl<<"Overlap pair "<<++count<<":"<<endl;
                cout<<"Rectangle 1: ";temp->r.print_info();
                cout<<"Rectangle 2: ";temp2->r.print_info();
            }
            temp2=temp2->forward[0];
        }
        temp=temp->forward[0];
    }
}
