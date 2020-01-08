#include <iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include <ctime>



using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY( int x, int y, string text);
//void gotoXY( int x, int y, string text);
void Draw( int style, int col, int row, int length, int amount,bool filled, int shadow );
int user;
int tra;	
int d=0;
char k;
char x[1000];
char y[1000];
char o,s;
char a;
char forall;
time_t now=time(0);
 float cost[1000];
tm *itm=localtime(&now);


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void set_console_size(int x,int y)
{
	HANDLE hOut;
	SMALL_RECT DisplayArea = {0, 0, 0, 0};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DisplayArea.Right  = x;//70
    DisplayArea.Bottom = y;//24
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}
class menu{
	        private:
	        
   	struct  time    {
	                   	int t_year,t_month,t_day,t_hour,t_min,t_sec;
	            	
			    	}time[1000],t;
		struct  movie_info {
	            	         char id_no[10], m_name[10],f_name[10],l_name[10] ;
						    string movie_t,movie_l;
                    	     int m_no,quantity,p_no;
                    	     
				      }data[1000],d;		    	

				    
	struct trailer{
		                string name;
		                int year,month,day;
	              }trails[7];
		
	enum trailer_movie_no{
		movie1=1,movie2,movie3,movie4,movie5,movie6,movie7
	}movie_no;			  	
     	
     	
	     	public:
	
           	menu()
		{
					 for(int i=0; i<1000; i++)
			   	{
					data[i].f_name=='\0';
					data[i].l_name=='\0';
					data[i].id_no=='\0';
					data[i].m_name=='\0';
					data[i].movie_l=" ";
					data[i].movie_t=" ";
					data[i].m_no=0;
					data[i].p_no=0;
					data[i].quantity=0;
					time[i].t_year=0;
					time[i].t_month=0;
					time[i].t_day=0;
					time[i].t_hour=0;
					time[i].t_min=0;
					
			    }
		}
			
	
		        void f_page();             void  searched_data(int );    void getdata(); 		
                void r_movie();            void sort_ID();               void menu_f();   
                void rec_list( char &);    void search();                void sort_name();
                void setting();            void edit();                  int from_file();
                void help();               void about();                 void display_time();      
				void to_file();            void table();                 int sub_absolut(int,int);
				float tax( int );          float costf (int);            void modification(int); 
                float total(int);          void trailer();                void sort_time();
                void filter(int );         int  from_trail_file();        void to_trail_file(int);
                void end();                void get_trailer_data();       void delet_trail(string);
                void trailer_view();       void total_income_table();     void write_total_income(char id_no[] );
                int read_total_income() ;  
}f;

int users =f.from_file();		
int trail=f.from_trail_file();
int income=f.read_total_income();
int main()
{    

   system("title KDE SOFTWARE STUDIO");
   system("color f0");
 	
string PressKey = "WELCOME TO KDES MOVIE CENTER............" ;
int x, y, len, frame;
y = 1;
frame = 2;
char holder;
Draw(1,2,1,76,23,0,0); // Box, 1 line, around screen
Draw(2,12,4,56,16,1,4); // Box, 2 lines, around screen
Draw(1,28,6,25,3,0,2); // Box, 1 line,  for Title
gotoxy(30,7);
cout<<"        GROUP 6" ;
gotoxy(50,18);
cout<<"press any key ";
Draw(2,23,13,36,3,0,2); // Box for moving text
len = PressKey.length();
do
{
gotoxy( 25,14);
for (x=0;x<32;x++)
cout << PressKey[x]; //scrolling the string called PressKey
holder = PressKey[0];
for ( x=0;x<len;x++)
PressKey[x] = PressKey
[x+1];
PressKey[len] = holder;
Sleep(120);
Draw(frame,23,13,36,3,0,0);
y++;
if (y>5)
{
Draw
(frame,28,6,25,3,0,0);
frame--;
y=0;
}
if ( frame==0)
frame=+2;
} while (_kbhit() == '\0' );
{
	gotoxy(25,14);
Sleep(500);


   system("color f0");
 	
	 
    f.f_page();
   	f.from_file();
   	f.menu_f();
}     }      
             void menu::f_page()
 {
    system("cls");
   	system("color 70");
   	set_console_size(70,24);
          
    int x[10]={10,15,25,30,55,70,75,80,90,100};
  
	for(int j=20; j>=5;j--)  
	{
	    system("cls"); 
		 gotoxy(k++,j);
		 cout<<"KDE SOFTWARE";
		 gotoxy(j-k,j);
		 cout<<" STUDIO ";
	}
	
	gotoxy(10,15);
    cout<<"Loading ";

	for(int i=0; i<=9; i++)
	{ 
		gotoxy(i+20,15);
    	cout<<"**";
		gotoxy(30,15);
		cout<<x[i]<<"%";
		Sleep(1000);
	}
	
	for(int i=0; i<20;i++)
	{    gotoxy(5,20-i);
		cout<<x[i];
	}  
		}
		void menu::end()
		{ 
		    	system("cls");     
			for(int i=3;i<25;i++)
			{
				
				gotoxy(16,i);
				cout<<"KDE !!!!! SOFTWARE !!!!! GOOd !!!!! BYE " ;
				
			
				Sleep(80);
				system("cls");
			 
				
			}
		}
      void menu::menu_f( )
	{  
		     	system("cls");
				system("type menu.txt");
		     	display_time();
		
				::k=getch();
		
				while(1)
				{
				
				if (k=='1')
			   	 getdata();
			    else if(k=='2')
			       r_movie();
		     	else if (k=='3')
				   rec_list( s);
				else if (k=='4')
			       setting( );
				else if (k=='5') 
				    help( );
				else if(k=='6')
				    about( );
				else if(k=='7')
				  	search();
			    else if ( k=='8')
				  {
				  	trailer();
				  }
				else if(k=='9')
				   system("start b.html");
				else if(k==13)
				 total_income_table();
				else if(k==27)
				{     end();
					 exit(0); 
				}
				
				  
				  else
				  menu_f();
			menu_f();
      }
			}
            
			 void menu::display_time() {   gotoxy(7,23);cout<<1900+itm->tm_year<<"/"<<1+itm->tm_mon<<"/"<<itm->tm_mday;    }
             
     
	  void menu::getdata()
   {     
                 system("cls");
               	system("type null.txt");
               	gotoxy(12,9); 	
                cout<<"How many movie do u want :";
               	cin>>::user;  
         system("cls");
         ofstream fwrite;
         fwrite.open("student.txt");
          
                 for(int i=users;i<users+(::user);i++)
                 {
                
		    	system("cls");c:
              	system("type taking.txt");
              	display_time();
              		l:
       ::x[i]=getch();
	    if(::x[i] =='1')           f.data[i].movie_l="English";
	    else if(::x[i] =='2')      f.data[i].movie_l="Amaharic";
	    else if(::x[i]==8)         
		{
		
			 getdata();
			 
				  }          
         else                      goto l;
                
                 
				
                 	system("cls");
                 	system("type movie.txt");
                 	h:
                 	::y[i]=getch();
                 	if(::y[i]=='1')           f.data[i].movie_t="Action";
                 	else if(::y[i]=='2')      f.data[i].movie_t="serise";
                 	else if (::y[i]=='3')     f.data[i].movie_t="Tragedy";
                 	else if (::y[i]=='4')     f.data[i].movie_t="Documentery";
                 	else if(::y[i]=='5')      f.data[i].movie_t="Comedy";
                 	else if(::y[i]=='6')      f.data[i].movie_t="Romantic";
                 	else  goto h;
	        
	              
	               	system("cls"); 
				 	system("type moviei.txt");
				    	gotoxy(36,5);
				  		cin>>f.data[i].m_name;
				  		gotoxy(36,7);
				  		cin>>f.data[i].m_no;
				  		gotoxy(36,9);
				  		cin>>f.data[i].quantity;
				  		gotoxy(36,11);
				  		cin>>f.data[i].f_name;
				  		gotoxy(36,13);
				  		cin>>f.data[i].l_name;
				  		gotoxy(36,15);
				  		cin>>f.data[i].p_no;
				  		gotoxy(36,17);
				  		cin>>f.data[i].id_no;
				  			filter(i);
				  	 
					     	gotoxy(36,19);
						 f.time[i]. t_year=1900+itm->tm_year;  
					     f.time[i].t_month=1+itm->tm_mon; 
				    	 f.time[i].t_day=itm->tm_mday;
		               	 f.time[i].t_hour=itm->tm_hour;  
					     f.time[i].t_min=1+itm->tm_min;
					     f.time[i].t_sec=1+itm->tm_sec;
					    
	}
		
		::users+=::user;
			to_file();
					

		
		
menu_f(); 
	}
	               void menu::filter(int i)
	               {
	                      filter:
						   bool filter_f=false,filter_last;
				  	
				  		if(f.data[i].m_no<=0)
				  	     {  gotoxy(36,7);cout<<"         "; ;cout<<"wrong input";forall=getch();  gotoxy(46,7);cout<<"            ";
				  		    gotoxy(36,7);cin>>f.data[i].m_no;
							 goto filter;
							  }
				  		 else if(f.data[i].quantity<=0) 
						   {   gotoxy(36,9);cout<<"         "<<"wrong input"; forall=getch();  gotoxy(46,9);cout<<"              ";
				  		    gotoxy(36,9);cin>>f.data[i].quantity;
				  		      	 goto filter;
							  }   
				          
				  	else if(f.data[i].p_no<=0)
				  		{
						  
				  		gotoxy(36,15);cout<<"                  "<<"wrong input";forall=getch();  gotoxy(46,15);cout<<"             ";
				  		gotoxy(36,15);cin>>f.data[i].p_no;
				  		 	 goto filter;
				      	}
				  else	if(f.data[i].id_no<=0)
				  		{
						  gotoxy(36,17);cout<<"          "<<"Wrong input";forall=getch();  gotoxy(46,16);cout<<"            ";
				  		gotoxy(36,17);cin>>f.data[i].id_no;
				  		 	 goto filter;
				  	}    d:
				  	      	for(int k=0;f.data[i].f_name[k]!='\0';k++)
				  	                 if(f.data[i].f_name[k]>='0'&&f.data[i].f_name[k]<='9')
				  	                {
									 filter_f=true;
				  	                if(filter_f)
				  		      {gotoxy(36,11);cout<<"          "<<"wrong input";forall=getch();  gotoxy(46,11);cout<<"            ";
				  			gotoxy(36,11);cin>>f.data[i].f_name;   	 goto e; break;
							  } }
							   
							     e:
							  for(int k=0; f.data[i].f_name[k]!=0;k++)
							   if (f.data[i].f_name[k]>='0'&& f.data[i].f_name[k]<='9')
							        {
								     filter_last=true;
							        if(filter_last)
				  		      {gotoxy(36,13);cout<<"          "<<"wrong input";forall=getch();  gotoxy(46,13);cout<<"             ";
				  			gotoxy(36,13);cin>>f.data[i].l_name; break;
				  		  goto d;
							  }}
							  gotoxy(9,22);
							  cout<<"Do you want to save the data ? (y/n)";
							  ::forall=getch();
							  if(::forall=='y'||::forall=='Y') to_file();
							  else if(::forall=='n'||::forall=='N') 
							  {
							  		f.data[i].f_name=='\0';
					f.data[i].l_name=='\0';
					f.data[i].id_no=='\0';
					f.data[i].m_name=='\0';
					f.data[i].movie_l=" ";
					f.data[i].movie_t=" ";
					f.data[i].m_no=0;
					f.data[i].p_no=0;
					f.data[i].quantity=0;
					f.time[i].t_year=0;
					f.time[i].t_month=0;
					f.time[i].t_day=0;
					f.time[i].t_hour=0;
					f.time[i].t_min=0;
						::users--;
							  	
							  }
							  
				   }

				 	void menu::r_movie()
				{
					char id_no[10];
					system("cls");system("type null.txt");	display_time();
					bool found=false;
                    char id[10];
                    ifstream fread;
                    ofstream fwrite;
                    gotoxy(6,9);cout<<"Enter your ID number  " ; cin>>id_no;
                    fwrite.open("temp.txt");
                    fread.open("student.txt");
                    int user=0;
                    int m=0,indx=0;
       while(fread>>f.data[m].f_name>>f.data[m].l_name>>f.data[m].id_no>> f.data[m].movie_l>> f.data[m].movie_t>>f.data[m].m_name
                  >>f.data[m].m_no>>f.data[m].quantity>>f.data[m].p_no>> f.time[m].t_year>> f.time[m].t_month >> f.time[m].t_day
                   >> f.time[m].t_hour>>f.time[m].t_min>>f.time[m].t_sec)
         {
         	
          if(strcmp(id_no,f.data[m].id_no)==0)
            {
              found=true;
              continue;
              m==indx;
            }
           else
           {
              fwrite<<f.data[m].f_name<<"\t"<<f.data[m].l_name<<"\t"<<f.data[m].id_no<<"\t"<<f.data[m].movie_l<<"\t"
            	    <<f.data[m].movie_t<<"\t"<<f.data[m].m_name<<"\t"<<f.data[m].m_no<<"\t"<<f.data[m].quantity<<"\t"
					<<f.data[m].p_no<<"\t"<< f.time[m].t_year<<"\t"<< f.time[m].t_month<<"\t"<< f.time[m].t_day
                    <<" \t"<< f.time[m].t_hour<<"\t"<< f.time[m].t_min<<"\t"<<f.time[m].t_sec<< endl;
            }
			m++; 
		 }
		   if(found)
	 {  a:
	 	gotoxy(13,12); cout<<"Id Found. Are sure ? (y/n)"; ::forall=getch();
	 	  if(::forall=='N'||::forall=='n')  
		   {
		   remove("temp.txt");
		   menu_f();
		   }
		   else  if(::forall=='Y'||::forall=='y')  
		   {
		    write_total_income(id_no );
		   	goto b;
		   }
		   else goto a;
	 }
          b:
           fread.close();   
           fwrite.close();
           
           
          
           
           
		   fread.open("temp.txt");
		   fwrite.open("student.txt");
		   
     
     int k=0;
      
        while(fread>>f.data[k].f_name>>f.data[k].l_name>>f.data[k].id_no>> f.data[k].movie_l>> f.data[k].movie_t>>f.data[k].m_name
                     >>f.data[k].m_no>>f.data[k].quantity>>f.data[k].p_no>> f.time[k].t_year>> f.time[k].t_month >> f.time[k].t_day
                     >> f.time[k].t_hour>>f.time[k].t_min>>f.time[k].t_sec)
      {
				        
           fwrite<<f.data[k].f_name<<"\t"<<f.data[k].l_name<<"\t"<<f.data[k].id_no<<"\t"<<f.data[k].movie_l<<"\t"
            	 <<f.data[k].movie_t<<"\t"<<f.data[k].m_name<<"\t"<<f.data[k].m_no<<"\t"<<f.data[k].quantity<<"\t"<<f.data[k].p_no
				 <<"\t"<< f.time[k].t_year<<"\t"<< f.time[k].t_month<<"\t"<< f.time[k].t_day <<"\t"<< f.time[k].t_hour
                 <<"\t"<< f.time[k].t_min<<"\t"<<f.time[k].t_sec<<endl;
                  
        k++;
     }
     fread.close();
     fwrite.close();
     if(found)
     ::users--;
     to_file();
   
               
            
     
     
	
    
   
         
     if(found==false)
    {
	   gotoxy(6,14);
	   cout<<"ID NOT FOUND \n";}
     else
    { 
	   gotoxy(6,14);
	   cout<<"DELETED SUCCESSFULLY ...\n";
	}
       ::forall=getch();
        to_file();
        menu_f();
				}
				void menu::rec_list( char &s)	
		{ 
			
			
			     	int a=119,b=40; set_console_size(a,b);
			     	system("cls");
						if(s=='1')     sort_name();
			       else if(s=='2')     sort_ID();
				   else if(s=='3')     sort_time();
				   else                  sort_time(); 
				   to_file();          
			
                    char m=getch();
        if(::o=='1')             set_console_size(70,24);
	 else if(::o=='2')      	set_console_size(80,30);
	else if(::o=='3')			set_console_size(60,24);
	else                        set_console_size(70,24);
                     menu_f();
				}
				void menu::to_file()
			{ 
		
					ofstream fwrite;
	fwrite.open("student.txt");
 
   
		 
          for(int i=0; i<(::users); i++)
          {
		  
            	  
                   fwrite<<f.data[i].f_name<<"\t";
                   fwrite<<f.data[i].l_name<<"\t";
                   fwrite<<f.data[i].id_no<<"\t";
                   fwrite<<f.data[i].movie_l<<"\t";
                   fwrite<< f.data[i].movie_t<<"\t";
                   fwrite<<f.data[i].m_name<<"\t";
                   fwrite<<f.data[i].m_no<<"\t";
                 	fwrite<<f.data[i].quantity<<"\t"; 
               		fwrite<<f.data[i].p_no<<"\t"; 
               		fwrite<< f.time[i].t_year<<"\t"; 
                   fwrite<< f.time[i].t_month<<"\t";
                   	fwrite<< f.time[i].t_day<<"\t";
					fwrite<<f.time[i].t_hour<<"\t";  
					fwrite<<f.time[i].t_min<<"\t"; 
					fwrite<<f.time[i].t_sec<<"\t";
	   }
	         
       
   
                  
fwrite.close();             		
			}
			
	    	 int menu::from_file(){
				ifstream fread;
                fread.open("student.txt");
                int i=0;
                while(fread>>f.data[i].f_name>>f.data[i].l_name>>f.data[i].id_no>>f.data[i].movie_l>> f.data[i].movie_t>>f.data[i].m_name>>f.data[i].m_no
				>>f.data[i].quantity>>f.data[i].p_no>> f.time[i].t_year>> f.time[i].t_month>> f.time[i].t_day>> f.time[i].t_hour>>f.time[i].t_min>>f.time[i].t_sec)
                   {
				   i++; 
				   }
				   
													
				 
				 return i;
					
				 }

			float menu::costf(int i)
			{  
			      cost[i]= ((sub_absolut(f.time[i].t_day,itm->tm_mday))*5+(sub_absolut(f.time[i].t_hour,1+itm->tm_hour))*0.5
				  +(sub_absolut(f.time[i].t_min,1+itm->tm_min))*0.00833+(sub_absolut(f.time[i].t_sec,1+itm->tm_sec))*0.000139);
				  return cost[i]*f.data[i].quantity;
			
				 }	 
				 float menu::tax(int i)
				 {
				 	return costf(i)*0.15;
				 }
				  float menu::total(int i)
				  {
				  	return tax(i)+costf(i);
				  }
				 int  menu::sub_absolut(int x ,int y )
				 {
				 return y-x;
					 }
				 
				 void menu::table()
				 {
				 	
				 
				 
				 	      gotoxy(0,0); cout<<"  Full name ";  gotoxy(15,0);cout<<"| Id ";gotoxy(15,1);cout<<"| No";
	   gotoxy(20,0); cout<<"| Movie type"; gotoxy(20,1);cout<<"|";gotoxy(42,0);cout<<"| Movie";gotoxy(42,1); cout<<"| name";
	   gotoxy(55,0);cout<<"| Movie"; gotoxy(55,1);cout<<"| No";gotoxy(62,0);cout<<"| Quan"; gotoxy(62,1); cout<<"| tity";
         gotoxy(68,0);cout<<"| Phone No";gotoxy(68,1); cout<<"| +251";gotoxy(79,0); cout<<"| Date";gotoxy(79,1);cout<<"|";
		  gotoxy(90,0); cout<<"| Time"; gotoxy(90,1);cout<<"|"; gotoxy(101,0);cout<<"| Cost ";gotoxy(101,1);cout<<"| Birr"; 
		  gotoxy(107,0);cout<<"| Tax";gotoxy(107,1); cout<<"| 15%"; gotoxy(112,0);cout<<"| Total "; gotoxy(112,1);cout<<"| Birr";
         gotoxy(0,2);
          

         	cout<<"------------------------------------------------------------------------------------------------------------------------";
       
   
    int j=3;
      for(int i=0;i<(::users);i++)
     {      gotoxy(0,j);
		 	cout<<f.data[i].f_name<<" "<<f.data[i].l_name; gotoxy(15,j); cout<<"|"<<f.data[i].id_no; gotoxy(20,j);  cout<<"| "<<f.data[i].movie_l<<" "<<f.data[i].movie_t; gotoxy(42,j); 
		 	cout<<"|"<<f.data[i].m_name; gotoxy(55,j); cout<<"| "<<f.data[i].m_no;  gotoxy(62,j);    cout<<"| "<<f.data[i].quantity; gotoxy(68,j);
		 	cout<<"| "<<f.data[i].p_no;   gotoxy(79,j) ;cout<<"| "<< f.time[i].t_year<<"/"<< f.time[i].t_month<< "/"<<f.time[i].t_day; gotoxy(90,j);
            cout<<"| "<<f.time[i].t_hour<<":"<< f.time[i].t_min<<":"<<f.time[i].t_sec; gotoxy(101,j); cout<<"|"<<costf(i); gotoxy(106,j);cout<<"    ";
            gotoxy(107,j); cout<<"| "<<tax(i); gotoxy(112,j); cout<<"      "; gotoxy(112,j); cout<<"| "<<total(i); gotoxy(118,j);cout<<"    ";
          j+=2;
		  
      }
      int k=4;
      for(int i=0; i<(::users); i++)
      {
      	gotoxy(0,k);
      			  
      	cout<<"------------------------------------------------------------------------------------------------------------------------";
      	k+=2;
	  }
   
				 }
				 
				 void menu::sort_time()
				 {
				 	ifstream fread;
				 	fread.open("student.txt");
				 	if(fread.is_open())
				 	{
				 		for(int i=0; i<(::users);i++)
				 		{
				 			for(int j=0; j<(::users);j++)
				 			{
				 			if(f.time[j].t_month>f.time[i].t_month)
				 			{
				 					swap(f.time[j],f.time[i]); swap(f.data[j],f.data[i]);
						   }
						   if(f.time[j].t_month == f.time[i].t_month&&f.time[j].t_day>f.time[i].t_day)
						     	{
				 					swap(f.time[j],f.time[i]); swap(f.data[j],f.data[i]);
								 }
								 if(f.time[j].t_month==f.time[i].t_month&&f.time[j].t_day==f.time[i].t_day&&f.time[j].t_hour>f.time[j].t_hour)
				 				{
				 					swap(f.time[j],f.time[i]); swap(f.data[j],f.data[i]);
								 }
								 if(f.time[j].t_month==f.time[i].t_month&&f.time[j].t_day==f.time[i].t_day&&f.time[j].t_hour==f.time[i].t_hour&&f.time[j].t_min>f.time[i].t_min)
								 {
				 					swap(f.time[j],f.time[i]); swap(f.data[j],f.data[i]);
								 }
								 if(f.time[j].t_month==f.time[i].t_month&&f.time[j].t_day==f.time[i].t_day&&f.time[j].t_hour==f.time[i].t_hour&&f.time[j].t_min==f.time[i].t_min
								      &&f.time[j].t_sec>f.time[i].t_sec)
								  {
				 					swap(f.time[j],f.time[i]); swap(f.data[j],f.data[i]);
								 }
				 				
					
					   }
				      }
				      	 to_file();
   
                             table();

							        
			   }
				 			
	else
{  system("cls");system("type null.txt");
	gotoxy(6,9);cout<<"  NO DATA  ";

}
     fread.close();				 				
		
 
	  
 
}

				 				      
							 
						 
						 
					
					 
				 
				 
				 
				void  menu::sort_ID()
{
	int cost[1000];	

	                    
	ifstream fread;                    
	       
 fread.open("student.txt");
 if(fread.is_open())
  {
        for(int i=0;i<(::users);i++)
  {
   for(int j=0;j<(::users);j++)
   {
      if(strcmp(f.data[j].id_no,f.data[i].id_no)>0)
     {
       	swap(f.data[j],f.data[i]); 
		swap(f.time[j],f.time[i]);
     }
    }
  }
   
   to_file();
   
   table();

 
	  
 
}
else
{  system("cls");system("type null.txt");
	gotoxy(6,9);cout<<"  NO DATA  ";

}
     fread.close();

}
				
				void  menu::sort_name()	
{
	
	system("cls");
	 

 ifstream fread;
 	 
   fread.open("student.txt");
if(fread.is_open())
{
	      for(int i=0;i<(::users);i++)
  {
   for(int j=0;j<(::users);j++)
    {
       if(strcmp(f.data[j].f_name , f.data[i].f_name)>0) 
	   {
       		swap(f.data[j],f.data[i]); swap(f.time[j],f.time[i]);
	   }   
      
       
       	 
    
  }}
    
 table();
 }
else
{  system("cls");system("type null.txt");
	gotoxy(6,9);cout<<"  NO DATA  ";

}

	    fread.close();}
		
	    
	    

void menu::edit()
{
	system("cls");	system("type null.txt");
	gotoxy(7,5);cout<<"  EDIT DATA ";
	
}
void menu::searched_data(int i)
{    system("cls");system("type null.txt");	display_time();
		gotoxy(6,3);cout<<"1.FULL name = "<<f.data[i].f_name<<" "<<f.data[i].l_name;
					 gotoxy(6,5);cout<<"2.ID number = "<<f.data[i].id_no; 
				      gotoxy(6,7);cout<<"3.phone number = +251"<<f.data[i].p_no;
				       gotoxy(6,9);cout<<"4.Movie name = "<<f.data[i].m_name;
				        gotoxy(6,11);cout<<"5.Movie language = "<<f.data[i].movie_l;
				         gotoxy(6,13);cout<<"6.Movie Type = "<<f.data[i].movie_t;
				          gotoxy(6,15);cout<<"7.Movie number = "<<f.data[i].m_no;
				          gotoxy(6,17);cout<<"8.Quantity = "<<f.data[i].quantity;
				           gotoxy(6,19);cout<<"[].DATE = "<<f.time[i].t_year<<"/"<<f.time[i].t_month<<"/"<<f.time[i].t_day;
				             gotoxy(6,21);cout<<"[].TIME = "<<f.time[i].t_hour<<":"<<f.time[i].t_min<<":"<<f.time[i].t_sec;
				               
				               if(:: a=='4')
				               {
				               	 modification(i);
							   }
				               
				               
}
        
		 void menu::search()
{    
      ifstream fread;
	 int user=0;
	 char f_name[10],l_name[10],id_no[10],m_name[10]; int m_no,p_no; bool searcher=true;
     k: 
	 system("cls");   	system("type null.txt"); 	    display_time();    
	
	 gotoxy(7,4);cout<<"SEARCH BY: ";
	 gotoxy(6,7);cout<<"  1. FIRST NAME "<<endl<<"\n"<<" \t"<<"2. ID NUMBER"<<endl<<"\n"<<"\t"<<"3. MOVIE NAME "<<endl<<"\n"
	                <<"\t"<<"4. MOVIE NO "<<endl<<"\n"<<"\t"<<"5. PHONE NUMBER";
     ::forall=getch();

   	system("cls");    	system("type null.txt");        display_time();
   	
	switch(::forall)
{
	case '1':
			gotoxy(6,9);cout<<"Enter your first name " ;gotoxy(6,11); cout<<"Enter your last name ";
			gotoxy(28,9); cin>>f_name;                    gotoxy(28,11); cin>>l_name;
			  
		      	for(int i=0;i<(::users);i++)
			{
				if(strcmp(f.data[i].f_name,f_name)==0 && strcmp(f.data[i].l_name,l_name)==0)
				{
					
				
						searched_data(i);
				          searcher =false;
				}
			}
			
		     	if(searcher) m:
		{     
			  gotoxy(8,16);cout<<"NOT found. DO YOU WANT TO TSEARCH AGAIN ? (y/N)";
			 ::forall=getch();
			 
			 if(::forall=='y'||::forall=='y')       	 goto k;
			 else if(::forall=='N'||::forall=='n')       break;
	     	else                                         goto m;
		}    
		   
		  break;
		  
        case '2':
	                gotoxy(6,9);cout<<"Enter your ID number ";cin>>id_no;
	             	for(int i=0;i<(::users);i++)
			{
				if(strcmp(f.data[i].id_no,id_no)==0)
				{
				  searched_data(i);
				  searcher =false;
				}
			}
			
			if(searcher) 
		{ 
		
		     	gotoxy(8,12);cout<<"NOT found. DO YOU WANT TO TSEARCH AGAIN ? (y/N)";
			   ::forall=getch();
			   if(::forall=='y'||::forall=='y')           goto k;
		       else if(::forall=='N'||::forall=='n')      break;
		}
		   break;
		   
    case '3':
			   	gotoxy(6,9);cout<<"Enter the movie name ";cin>>m_name;
	           	for(int i=0;i<(::users);i++)
			{
				if(strcmp(f.data[i].m_name,m_name)==0)
				{
			    	searched_data(i);
				     searcher =false;
				}
			}
			 
			if(searcher) 
			{
			     gotoxy(8,12);  cout<<"NOT found. DO YOU WANT TO TSEARCH AGAIN ? (y/N)";
			    ::forall=getch();
			    if(::forall=='y'||::forall=='y')               goto k;
		        else if(::forall=='N'||::forall=='n')          break;
		        else goto m;
			}     
			   break;
			   
	case '4':
			   	gotoxy(6,9);cout<<"Enter the movie number  ";    cin>>m_no;
			    
					for(int i=0;i<(::users) ;i++)
		{
			if ( f.data[i].m_no==m_no)
		    	{
			     	searched_data(i);
			       searcher =false;
				}
	   }
			if(searcher) 
			  {
			     gotoxy(8,12);cout<<"NOT found. DO YOU WANT TO TSEARCH AGAIN ? (y/N)";
			     ::forall=getch();
			    if(::forall=='y'||::forall=='y') goto k;
	        	else if(::forall=='N'||::forall=='n') break;
	        	else goto m;
			  }  
		         break;
		         
	case '5':
				gotoxy(6,9);cout<<"Enter your phone number  ";cin>>p_no;
			    	
	              		for(int i=0;i<(::users) ;i++)
			{
				if(f.data[i].p_no==p_no)
				{
				
				searched_data(i);
				          searcher =false;
				}
			}
			if(searcher) 
			{ gotoxy(8,12);cout<<"NOT found. DO YOU WANT TO TSEARCH AGAIN ? (y/N)";
			 ::forall=getch();
			 if(::forall=='y'||::forall=='y') goto k;
		else if(::forall=='N'||::forall=='n') break;
		else goto m;}   break;
		case 8:
			if(::a==4)
			setting();
			else 
			menu_f();
			break;
		default:
			search();
}
	
	forall=getch();
	menu_f();
}
				void menu::setting()
		{	
				system("cls");
				system("type setting.txt ");	display_time();
				::a=getch();
			
		 if(::a=='1')
		  
		 {          m:
		            system("cls");
				   system("type c_size.txt");	display_time();
				    ::o=getch();
        if(::o=='1')             set_console_size(70,24);
	 else if(::o=='2')      	set_console_size(80,30);
	else if(::o=='3')			set_console_size(60,24);
    else if(::o==8)             setting();
	else                       goto m;
          
				   
	 
			
	     }
		else if(::a=='2')
	
		 {	        
		              k:
		             system("cls");
				 	system("type c_color.txt"); 	display_time();
				  	::o=getch();
				 		if(::o=='1')system("color 07");
				 		else if(::o=='2')system("color f0");
				 		else if(::o=='3')system("color 70");
				 		else if(::o=='4')system("color b0");
				 		else if(::o==8)    setting();
				 		else              goto k;
		 }
		 
	    else if(::a=='3')
		 {
		 	            j: char s;
						system("cls");
					 	system("type sorting_data.txt"); 	display_time();
					 	s=getch();
					rec_list(s);
				   if(s==8)        setting();
				   else                   goto j;
					 		
					 	 menu_f();
		 }
				
		else if (::a=='4')
	   	{     
	     	          search();
	     	          ::a='\0';
		  
        }
        else if(::a=='5')
        {       char format;  
		           eyu: 
                   system("cls"); system("type null.txt"); display_time();
		        gotoxy(10,10);cout<<"Aru sure do you want to format ?(y/n) ";
               ::forall=getch();
              
               if(::forall=='y'||::forall=='y')
			   {   top:
			   	    system("cls"); system("type null.txt"); display_time();
			   	    gotoxy(9,10);cout<<"1.custemers Data     2.trailers Data      3.All Data";
                format=getch();
                if(format=='1')
			   	{	remove("student.txt");
			   		::users=0;
			   	}
			   	else if(format=='2')
			   	   {  remove("trailer_v.txt");
			   	      ::trail=o;
			   	   	}
			   	else if(format=='3')
			   	{  	remove("student.txt");
			   		::users=0;
			   		 remove("trailer_v.txt");
			   	      ::trail=o;
			   		
				   }
				   else goto top;
			      system("cls"); system("type null.txt");  display_time();
			    
			    	gotoxy(10,10);	cout<<"Formating ";
			    		for(int i=0; i<5;i++)
			    		{
			    			cout<<"**";
			    			Sleep(400);
						}
							gotoxy(10,10);
			     	cout<<"Formated successfully ";
		        	::forall=getch();
			   }
			   else if(::forall=='n'||::forall=='N')
			        menu_f();
			   else if(::forall==8)  setting();    
			        else goto eyu;
			        
        
               
			 
			 
                           
		 }
		 else if(::a=='6')
		 
		 { 		    system("cls"); system("type null.txt"); display_time();
		        up: 
		    gotoxy(7,7);cout<<"1.ADD TRAILER                    2.DELET TRAILER";
		   
		    ::forall=getch();
		    if(::forall=='1')  
		     get_trailer_data(); 
		     else if(::forall=='2')
		     {   string m_name; bool found=false;
		     	 system("cls"); system("type null.txt"); display_time();
		     	 gotoxy(7,7);cout<<"Enter movie name "; cin>>m_name;
		     	 for(int i=0; i<(::trail);i++)
		     	 {
		     	 	if(m_name==f.trails[i].name)
		     	 	{  system("cls"); system("type null.txt"); display_time();
		     	 	    gotoxy(9,8);cout<<"Movie Name ";  gotoxy(25,8);cout<<"Time";
		     	 	   gotoxy(8,10);cout<<f.trails[i].name; gotoxy(25,10);cout<<f.trails[i].year<<"/"<<f.trails[i].month<<"/"<<f.trails[i].day;
		     	 	   ob:
		     	 	 gotoxy(10,12);cout<<" Are youe sure ? (y/n) "; ::forall=getch();
							if(::forall=='y'||::forall=='Y')     goto e;
					else if (::forall=='n'||::forall=='N')        setting();
					else goto ob;
							
						e:
		     	 	   delet_trail(m_name); ::trail--;from_trail_file();
		     	 	   gotoxy(12,14);cout<<"DELETED SUCCESSFULLY ";
		     	 	   ::forall=getch();
		     	 	   found = true;
		     	 		
					  }
					   
					 
				  }
				  if(!found)
				  {
				  	system("cls"); system("type null.txt"); display_time();
				  	gotoxy(10,10);cout<<"MOVIE NAME NOT FOUND";
					  	::forall=getch();
					  	setting();
				  }
			 }
			 
			 else if(::forall==8)   setting();
			 else goto up;
		 }
		 else if(::a==8)             menu_f();
		 else                        setting();    
	}
	              
	             
	
			
				
		     	void menu::help()
			     	{	system("cls");
				     	system("type help.txt"); 	display_time();
				     	char j=getch();
				    	menu_f();
			    	}
				void menu::about()
				   {	system("cls");
				        system("type about.txt"); 	display_time();
				      	char j=getch();
				     	menu_f();
				   }
				   void menu::modification(int i)
				   {
				   	      ::a='\0';
				   	  
				   	   gotoxy(40,9);cout<<"1.To modify all data "; gotoxy(40,10);cout<<"2.To modify single data ";
				   	   ::forall=getch();
				   	   if(::forall=='1')
				   	   {
				   	   	               gotoxy(40,9);cout<<"                                 ";     gotoxy(40,10); cout<<"                                     ";
				   	   	             	gotoxy(6,3);cout<<"1.FULL name =                                       ";   gotoxy(21,3); cin>>f.data[i].f_name; gotoxy(28,3) ;cin >>f.data[i].l_name;
				   	   	               gotoxy(6,5);cout<<"2.ID number =                                     ";   gotoxy(21,5); cin>>f.data[i].id_no;
				   	   	               gotoxy(6,7);cout<<"3.phone number =                                       ";  gotoxy(23,7); cin>>f.data[i].p_no;
				   	   	               gotoxy(6,9);cout<<"4.Movie name =                                           "; gotoxy(22,9); cin>>f.data[i].m_name;
				   	   	               gotoxy(6,11);cout<<"5.Movie language =                                    ";   gotoxy(23,11); cin>>f.data[i].movie_l;
				   	   	         	   gotoxy(6,13);cout<<"6.Movie Type =                                          ";  gotoxy(23,13); cin>>f.data[i].movie_t;
				   	   	         	   gotoxy(6,15);cout<<"7.Movie number =                                         ";   gotoxy(21 ,15); cin>>f.data[i].m_no;
				   	   	         	     gotoxy(6,17);cout<<"8.Quantity =                                              ";gotoxy(21,17);cin>>f.data[i].quantity;
	                                   gotoxy(40,9);cout<<"Changed successfuly ."; Sleep(1000);
				   	   	         
						  }
				   	   else if(::forall=='2')
				   	   {
				   	   	
						   gotoxy(40,9);cout<<"                                      ";     gotoxy(40,10); cout<<"                                     ";
				   	   there: 
				   	    gotoxy(38,9); cout<<"[::].choose the data you want to change ? ";
				   	   ::forall=getch();
				   	    gotoxy(38,9); cout<<"                                               ";
				   	   switch(::forall)
				   	 {
				   	 	case '1':
				   	 			gotoxy(6,3);cout<<"1.FULL name =                                       ";   gotoxy(21,3); cin>>f.data[i].f_name; gotoxy(28,3) ;cin >>f.data[i].l_name;
				   	 			break;
				   	 	case '2':
				   	 		 gotoxy(6,5);cout<<"2.ID number =                                     ";   gotoxy(21,5); cin>>f.data[i].id_no;
							 break; 
				   	 	case '3':
				   	 		  gotoxy(6,7);cout<<"3.phone number =                                       ";  gotoxy(23,7); cin>>f.data[i].p_no;
				   	 		  break;
				   	 	case '4':
				   	 		 gotoxy(6,9);cout<<"4.Movie name =                                           "; gotoxy(22,9); cin>>f.data[i].m_name;
				   	 		 break;
				   	 	case '5':
				   	 	      gotoxy(6,11);cout<<"5.Movie language =                                    ";   gotoxy(25,11); cin>>f.data[i].movie_l;
				   	 	      break;
				   	 	case '6':
				   	 		 gotoxy(6,13);cout<<"6.Movie Type =                                          ";  gotoxy(23,13); cin>>f.data[i].movie_t;
				   	 		 break;
				   	 	case '7':
				   	 		 gotoxy(6,15);cout<<"7.Movie number =                                         ";   gotoxy(23 ,15); cin>>f.data[i].m_no;
				   	 		 break;
				   	    case '8':
				   	          gotoxy(6,17);cout<<"8.Quantity =                                              ";gotoxy(21,17);cin>>f.data[i].quantity;
				   	          break;
				   	 	default:
				   	 		goto there;
				   	 	
				   	} 
				   		here:
				   	 	
				   	 		gotoxy(35,9); cout<<"[::].Do you want to choose again  ";
				   	 		gotoxy(42,10);cout<<"(y/n)";
							char choice=getch();
							
							if(choice=='y'||choice=='Y')
							    goto there;
							    
							else if(choice=='n'||choice=='N')
						      	menu_f();
						      	
							else 
							     goto here;   
				   	
					   }
				   	else if(::forall==8)     search();
				   	else                     modification(i);
				   	 	  
   
						
	                                gotoxy(8,17);cout<<"DATE = "<<f.time[i].t_year<<"/"<<f.time[i].t_month<<"/"<<f.time[i].t_day;
				                    gotoxy(8,19);cout<<"TIME = "<<f.time[i].t_hour<<":"<<f.time[i].t_min<<":"<<f.time[i].t_sec;
				                    ::a='\0';
				                    
				                    to_file();
				   }
				   
				   void menu::trailer()
                { 
                    system("cls"); system("type null.txt"); display_time();
                     gotoxy(16,3); cout<<"  New  trailers  ";
                     gotoxy(6,5);cout<<"      Movie Name "; gotoxy(35,5);cout<<"Time left"; 
					 ifstream fread;  bool trailer=false;
                     fread.open("trailer_v.txt");
                     ::trail=from_trail_file();
                     
                     if(fread.is_open())
                     {
					 
                     int y=5;
                   for(int i=0; i<(::trail);i++)
                   {
                   	  trailer=true;
                     gotoxy(6,y+=1)	;cout<<i+1<<"."<<f.trails[i].name;   
                     gotoxy(34,y);
                      if((f.trails[i].year)-(1900+itm->tm_year)>0)
                      cout<<(f.trails[i].year)-(1900+itm->tm_year)<<" Year"<<setw(2);
                        if((f.trails[i].month)-(1+itm->tm_mon)>0)
                      cout<<(f.trails[i].month)-(1+itm->tm_mon)<<" Month"<<setw(2);
                       if((f.trails[i].day)-(itm->tm_mday)>0)
                      cout<<(f.trails[i].day)-(itm->tm_mday)<<" Day";
                       if   ( ((f.trails[i].day)-(itm->tm_mday)<=0)&&((f.trails[i].month)-(1+itm->tm_mon)==0)&&((f.trails[i].year)-(1900+itm->tm_year)==0) ||((f.trails[i].month)-(1+itm->tm_mon)<0)&&((f.trails[i].year)-(1900+itm->tm_year)==0)
					   ||((f.trails[i].year)-(1900+itm->tm_year)<0)||((f.trails[i].year)-(1900+itm->tm_year)<=0) && ((f.trails[i].month)-(1+itm->tm_mon)<=0) &&((f.trails[i].day)-(itm->tm_mday)<=0))
					     
					                    
					    delet_trail(f.trails[i].name); 
                      
				   }
				    ::forall=getch();
				}
				else {
					system("cls"),system("type null.txt"); gotoxy(10,10); cout<<"NO DATA",::forall=getch();
				}
				if(trailer)
				{ 
				      k:
					gotoxy(9,20);cout<<"DO YOU WANT TO SEE THE TRAILER? (y/n)";
					::forall=getch();
					if(::forall=='y'||::forall=='Y')      trailer_view();
					else if (::forall=='n'||::forall=='N')    menu_f();
					else goto k;
				}
	      
				}	
				
				void menu::to_trail_file(int i)
				{
					ofstream mo;
					mo.open("trailer_v.txt",ios::app);
				
						mo<<f.trails[i].name<<"\t"<<f.trails[i].year<<"\t"<<f.trails[i].month<<"\t"<<f.trails[i].day;
					
					mo.close();
				}
				
				int menu::from_trail_file()
				{
		           ifstream eyu;  
				   eyu.open("trailer_v.txt");
				   int i=0;
				   	while(eyu>>f.trails[i].name>>f.trails[i].year>>f.trails[i].month>>f.trails[i].day)
				   	 {
				   	 	i++;
						}
					  
					  return i;		
				}		
				
				void menu::get_trailer_data()
				{
					 system("cls");  system("type null.txt"); display_time();   int movie;
		       gotoxy(10,10); cout<<"How many Movie do you want to register "; cin>>movie;
		       
		       system("cls");  system("type null.txt"); display_time(); 
		        ::trail=from_trail_file();
		        for(int k=(::trail);k<movie+(::trail);k++)
		       {
		       	gotoxy(6,6);cout<<"1.Movie name = ";   	gotoxy(6,8);cout<<"2.Year = ";
		     	gotoxy(6,10); cout<<"3.Month = ";    	    gotoxy(6,12); cout<<"4.Day = "; 
		      
			     gotoxy(22,6);	cin>>f.trails[k].name;               gotoxy(16,8);cin>>f.trails[k].year;   
		       	 gotoxy(16,10); cin>>f.trails[k].month;            gotoxy(15,12);  cin>>f.trails[k].day;
		       	 system("cls");  system("type null.txt"); display_time();
		       	   to_trail_file(k);
			   }
			 

					}	
					
					void menu::delet_trail(string name)
					{
						ofstream fwrite;  ifstream fread; 
						fread.open("trailer_v.txt");
						fwrite.open("tempo.txt");
						int i=0,k;
						while(fread>>f.trails[i].name>>f.trails[i].year>>f.trails[i].month>>f.trails[i].day)
						{
							if(name ==f.trails[i].name )
						{      
								continue;
						}
							else{
									fwrite<<f.trails[i].name<<"\t"<<f.trails[i].year<<"\t"<<f.trails[i].month<<"\t"<<f.trails[i].day<<"\t"<<endl;
					           }
					           i++;
					       }
					           fread.close(); 	fwrite.close();
					          
					    fread.open("tempo.txt");
						fwrite.open("trailer_v.txt"); 
				
						   i=0;
						  
							while(fread>>f.trails[i].name>>f.trails[i].year>>f.trails[i].month>>f.trails[i].day)
						{
							
					           fwrite<<f.trails[i].name<<"\t"<<f.trails[i].year<<"\t"<<f.trails[i].month<<"\t"<<f.trails[i].day<<"\t"<<endl;
					           i++;
					           
						}
						remove("tempo.txt");
					}
					void menu::trailer_view()
					{
					 int tra;  start:
					   gotoxy(9,20);cout<<"Enter the movie trailer  you want to see ";cin>> tra;
					   if(tra==movie1 &&(::trail)>=1)           system("start 1.mp4");
					   else if(tra==movie2 &&(::trail>=2))      system("start 2.mp4");
					   else if(tra==movie3 &&(::trail)>=3)      system("start 3.mp4");
					    else if(tra==movie4 &&(::trail)>=4)     system("start 4.mp4");
					     else if(tra==movie5 &&(::trail)>=5)    system("start 5.mp4");
					      else if(tra==movie6 &&(::trail)>=6)   system("start 6.mp4");
					       else if(tra==movie7 &&(::trail)>=7)  system("start 7.mp4");
					       else {
					       	 gotoxy(9,18);cout<<"Enter the correct butten ";
					       	 goto start;
						   }
					   
					}
						void menu::write_total_income(char id_no[10] )
						{
							 ofstream write;
							 write.open("total_income.txt",ios::app);
							for(int i=0; i<(::users);i++)
							{
								if(strcmp(id_no,f.data[i].id_no))
								{
								write<<f.data[i].movie_l<<"\t"  <<f.data[i].movie_t<<"\t"<<f.data[i].m_name
            	                      <<"\t"<<f.data[i].m_no<<"\t"<<f.data[i].quantity<<"\t"
					                  << f.time[i].t_year<<"\t"<< f.time[i].t_month<<"\t"<< f.time[i].t_day
                                    <<" \t"<< f.time[i].t_hour<<"\t"<< f.time[i].t_min<<"\t"<<f.time[i].t_sec<< endl;
                                  }
								}
							}
						
					 int menu::read_total_income()
					 {
					 	ifstream read;
					 	read.open("total_income.txt");
					 	int m=0;
					 	while(read>>f.data[m].movie_l>>f.data[m].movie_t>>f.data[m].m_name>>f.data[m].m_no>>f.data[m].quantity>>
            	             f.time[m].t_year>> f.time[m].t_month>> f.time[m].t_day >>f.time[m].t_hour>> f.time[m].t_min>>f.time[m].t_sec)
							{
								m++;
								  }	  
					                  
                                    return m;  
					 }
					 
					  void menu::total_income_table()
					  {
					  		 
				 	     
	   gotoxy(0,0); cout<<"| Movie type"; gotoxy(0,1);cout<<"|";gotoxy(22,0);cout<<"| Movie";gotoxy(22,1); cout<<"| name";
	   gotoxy(35,0);cout<<"| Movie"; gotoxy(35,1);cout<<"| No";gotoxy(42,0);cout<<"| Quan"; gotoxy(42,1); cout<<"| tity";
        gotoxy(68,1); cout<<"| +251";gotoxy(48,0); cout<<"| Date";gotoxy(48,1);cout<<"|";
		  gotoxy(59,0); cout<<"| Time"; gotoxy(59,1);cout<<"|"; gotoxy(70,0);cout<<"| Cost ";gotoxy(70,1);cout<<"| Birr"; 
		  gotoxy(76,0);cout<<"| Tax";gotoxy(76,1); cout<<"| 15%"; gotoxy(81,0);cout<<"| Total "; gotoxy(81,1);cout<<"| Birr";
         gotoxy(0,2);
          

         	cout<<"------------------------------------------------------------------------------------------------------------------------";
       
   
    int j=3;
      for(int i=0;i<(::income);i++)
     {      gotoxy(0,j);  cout<<f.data[i].movie_l<<" "<<f.data[i].movie_t; gotoxy(22,j); 
		 	cout<<"|"<<f.data[i].m_name; gotoxy(35,j); cout<<"| "<<f.data[i].m_no;  gotoxy(42,j);    cout<<"| "<<f.data[i].quantity;
		 	  gotoxy(48,j) ;cout<<"| "<< f.time[i].t_year<<"/"<< f.time[i].t_month<< "/"<<f.time[i].t_day; gotoxy(59,j);
            cout<<"| "<<f.time[i].t_hour<<":"<< f.time[i].t_min<<":"<<f.time[i].t_sec; gotoxy(70,j); cout<<"|"<<costf(i); gotoxy(76,j);cout<<"    ";
            gotoxy(76,j); cout<<"| "<<tax(i); gotoxy(81,j); cout<<"      "; gotoxy(81,j); cout<<"| "<<total(i); gotoxy(86,j);cout<<"    ";
          j+=2;
		  
      }
      int k=4;
      for(int i=0; i<(::income); i++)
      {
      	gotoxy(0,k);
      			  
      	cout<<"------------------------------------------------------------------------------------------------------------------------";
      	k+=2;
	  }
   ::forall=getch();
					  }
					  	void Draw( int style, int col, int row, int length, int amount,bool fill, int sw )
{
   	system("color 70");
   	set_console_size(70,24);
// Draws a 1 or 2 line box
int a;
if ( sw >4)
sw = 4;
style=(style-1)*6;
char box[12];
char shdw[5];
box[0] = '\xDA' ;//  ?
box[1] = '\xBF' ;//  ?
box[2] = '\xC0' ;//  ?
box[3] = '\xD9' ;//  ?
box[4] = '\xB3' ;//  ?
box[5] = '\xC4' ;//  ?
box[6] = '\xC9' ;//  ?
box[7] = '\xBB' ;//  ?
box[8] = '\xC8' ;//  ?
box[9] = '\xBC' ;//  ?
box[10] = '\xBA' ;// ?
box[11] = '\xCD' ;// ?
shdw[1] = '\xB0' ;// ?
shdw[2] = '\xB1' ;// ?
shdw[3] = '\xB2' ;// ?
shdw[4] = '\xDB' ;// ?
char tl,tr,bl,br,side,edge,shadow;
tl = box[style];
tr = box[style+1];
bl = box[style+2];
br = box[style+3];
side = box[style+4];
edge = box[style+5];
shadow = shdw[sw];
string Line(length-2,edge);
string Shadow(length,shadow);
string Fill(length-2, ' ' );
gotoxy(col,row);
cout << tl << Line << tr;
for (a = 1; a <amount-1;a++)
{
gotoxy(col,row+a);
cout << side;
if (fill)
cout << Fill;
else
gotoxy(col+length-1,row+a);
cout << side;
if (sw)
cout << shadow;
}
gotoxy(col,(amount+row)-1);
cout << bl << Line << br;
if (sw)
{
cout << shadow;
gotoXY(col+1,row+amount ,Shadow );
}
}
void gotoXY( int x, int y, string text)
{
CursorPosition.X = x;
CursorPosition.Y = y;
SetConsoleCursorPosition
(console,CursorPosition);
cout << text;

}
					
