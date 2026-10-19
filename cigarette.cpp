#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int const height=10;
int const width=40;
char framebuffer[width];

int cigLength = width;

char pixel ='@';
char shades1='*';
char shades2='-';

int quartColor = width/4;

void displayCig(char shades)

    {
        cout<<"\r";
        cout << "\r\033[2K";
          for(int i = 0; i<cigLength; i++)
    {
        framebuffer[i]='=';

        if(i==cigLength-1)
        {
            framebuffer[i]=shades;
        }

        
        if(i==0)
        {
cout << "\033[38;5;202m";
        
        }
        
 else if(i==quartColor)       
cout<<"\033[0m";

else if(i)
cout<<framebuffer[i];

        
        
    }

    }


void burn(int &cigLength)
{
cigLength--;
return;
}

int main(){


 
while(true){
 
  
    displayCig(shades1);
    
     cout.flush();
  this_thread::sleep_for(std::chrono::milliseconds(500));
  displayCig(shades2);
  cout.flush();
  this_thread::sleep_for(std::chrono::milliseconds(1000));
   burn(cigLength);
   cout.flush();
   
   if(cigLength==quartColor)
   {
    break;
   }
}


  return 0;

}
