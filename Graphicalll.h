#include<iostream>
#include"Log.h"
using  namespace std;
char a=177, b=219;
class Graphical_functions{  
	   public:
	   void title_main_page();
	   void loading();
	   void  welcome();	   
};

///////////////////////////////////////////////
inline void Graphical_functions::welcome(){   	LOG_INFO("Graphicalll.h header file is open for welcome");
            cout<<"\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
			cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
			cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
			cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
}


////////////////////////
inline void Graphical_functions::title_main_page(){  	LOG_INFO("Graphicalll.h header file is open for title_main_page");
   cout<<"\n\n\n\n\t\t";
   
  	for(int i=0;i<=20;i++){
		cout<<b;
		if(a<=123){
		}
	}
	cout<<"\t Pakistani Pahiya DSA project\t ";
	for(int i=0;i<=20;i++){
		cout<<b;
	}
}

//////////////////////////////////////////////////////////////////////
inline void Graphical_functions::loading(){     LOG_INFO("Graphicalll.h header file is open for loading opion");
	//	system("color 0B");
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tPlease wait while loading\n\n";
 	system("color 0C");
 char a=176, b=219;  // +-     
 cout<<"\t\t\t\t";
 for (int i=0;i<=80;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t";
 for (int i=0;i<=80;i++)
 {
  cout<<b;
  for (int j=0;j<=1e7;j++);
 }
}


