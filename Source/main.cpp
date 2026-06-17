#include <iostream> 
 
#ifdef TESTING_SUITE_LOOP

#include "update-cycle.hpp"

int main(int argc, char*argv[]) 
{ 
   Init();

   bool running = true;
   while(running)
   {
      BeginFrame();
      running = Update();
      LateUpdate();
      EndFrame();
   }

   Shutdown();
} 

#elif TESTING_SUITE_CLEAN

#include "entry-point.hpp"

int main(int argc, char*argv[]) 
{ 
   Execute(argc, argv);
} 

#endif