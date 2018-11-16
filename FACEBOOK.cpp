
//friend request , deleting previous status and account settings is remaining
//ucli=user currently logged in


#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>

void status();
void panel();
void settings();
void request();
void news();
void logout();
void search();
void see();
void statusdel();
void msg();
char ucli[100];      //for storing the name of the user logged in
void newpass(char a[],char name[]);


class user        //main class for storing data of users
{
	public:
	char name[100];     //name of user

	protected:
	char password[100];    //password of the account
	public:
	int age;             //age of the user
	char email_ID[100];  //email id of the user
	char dob[100];      //date of birth of user
	char gender[30];    //gender of the user


	void updatepass(char a[100]); //updates password
	void enter()       // user at the time of signup
	{
		cout<<"enter your name"<<endl;
		cin>>name;
		cout<<"enter your email ID"<<endl;
		cin>>email_ID;
		cout<<"enter the new password"<<endl;
		cin>>password;
		cout<<"enter your date of birth(kids can also use it lol)"<<endl;
		cin>>dob;
		cout<<"enter your gender"<<endl;
		cin>>gender;
	}
	void disp()   //not really used for normal user (only for admin)
	{
		cout<<"the name is\t "<<name<<endl;
		cout<<"email ID\t"<<email_ID<<endl;
		cout<<"the date of birth\t"<<dob<<endl;
		cout<<"gender (lol)\t"<<gender<<endl;
	}
	char* remail()  // return email(no need as such
	{
		return email_ID;
	}
	char* rpass()  //return password
	{
		return password;
	}
}z;
void user::updatepass(char a[100])     //updates password
{
	strcpy(password,a);
}

class status      //class for handling status

{     public:
	char status[100]; //main status
	char name[100];  // name of the person posting that status
}st;
class noti       //class for notifications
{
	public:
	char likeof[100],dislikeof[100];  //as the name suggests
	char commentof[100];
	char likeby[100],dislikeby[100],commentby[100];
	char comment[100];
}noti;

class message      //class for handling the messages
{
public:
	char msg[100];     //main message
	char msgof[100];   // name of the person for whom message is
	char msgby[100];   //name of the sender
}talk;

class friends         //for friend requests
{
	public:
	char requestfrom[100]; //name of the sender
	char requestfor[100];  //name of the receiver
}fri;


void internal()    // function which call different important functions
{

	two:
	clrscr();

	cout<<"\t\t\t\t\t The Facebook.."<<endl;
	cout<<"logged in user is\t"<<ucli<<endl;

	int option;   //for making the program menu driven

	cout<<"1-post a status"<<endl;
	cout<<"2-news feed(see friends' status)"<<endl;
	cout<<"3-send a friend request"<<endl;
	cout<<"4-search a person by username"<<endl;
	cout<<"5-notification panel"<<endl;
	cout<<"6-account settings"<<endl;

	cout<<"7-logout"<<endl;
	cout<<"8-see received message"<<endl;
	cout<<"9-send a message"<<endl;
	cout<<"10-delete your previous status"<<endl;

	cin>>option;
		 if(option==1)
		 {
			status();
				char ans;
			cout<<"wanna go back"<<endl;
			cin>>ans;
			if(ans=='y')
				goto two;
			else
			exit(0);
		 }
		 else if(option==2)
		 {
			news();
			getch();
			goto two;
		 }
		 else if(option==3)
		 {
		 request();
		 goto two;
		}
		 else if(option==4)
		 {
		 search();
			char ans;
			cout<<"wanna go back"<<endl;
			cin>>ans;
			if(ans=='y')
				goto two;
			else
			exit(0);
		 }
		 else if(option==5)
		  {	panel();
			goto two;
		  }
		 else if(option==6)
		   {
		   settings();
		   goto two;
		 }
		 else if(option==7)
			logout();
		 else if(option==8)
		 {
			see();
			goto two;
		 }
		 else if(option==9)
		 {
			msg();
			goto two;
		 }
		 else if(option==10)
		 {
			clrscr();
				cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
				statusdel();
			getch();
			goto two;
		 }
		 else
		 {
			cout<<"comeon boy/girl you have entered the wrong number don't try to act smarter cause you are not select from the number mentioned otherwise if you don't wish to      continue kindly logout"<<endl;
			cout<<"-message by programmer"<<endl;
			getch();
			goto two;
		 }
}

		void status()   //function which helps in posting the status
		{
		char status[100];
			cout<<"Enter the status"<<endl;
			ifstream a("us");
			gets(status);
			ofstream b("status1",ios::app);

			while(a.read((char*)&z,sizeof(z)))
			{
				if(strcmp(ucli,z.name)==0)
				{
					strcpy(st.status,status);
					strcpy(st.name,ucli);
					b.write((char*)&st,sizeof(st));
				}
			}

		}

		void news()    //function which display the news feed and different options
		{
			clrscr();
				cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			ifstream a("status1");
			int i=1;
			while(a.read((char*)&st,sizeof(st)))
			{
				cout<<i<<"--"<<st.status<<"    by  "<<st.name<<endl;
				i++;
			}
			int like,dislike;
			char comment[100];
			cout<<endl<<endl<<endl;
			cout<<"1-wanna like someone's status"<<endl;
			cout<<"2-wanna dislike someone's status"<<endl;
			cout<<"3-wanna post a comment on someone's status"<<endl;
			cin>>i;
			if(i==1)
			{
				char name[100];

				cout<<"enter the name corresponding to the status you wanna like"<<endl;
				cin>>name;


				ifstream b("us");
				ofstream a("noti",ios::app);

				while(b.read((char*)&z,sizeof(z)))
				{
					if(strcmp(name,z.name)==0)
					{
						 strcpy(noti.likeof,name);
						 strcpy(noti.likeby,ucli);

						 a.write((char*)&noti,sizeof(noti));
					}

				}
			}
			else if(i==2)
			{
				char name[100];

				cout<<"enter the name corresponding to the status you wanna dislike"<<endl;
				cin>>name;


				ifstream b("us");
				ofstream a("noti",ios::app);
				while(b.read((char*)&z,sizeof(z)))
				{
					if(strcmp(name,z.name)==0)
					{
						 strcpy(noti.dislikeof,name);
						 strcpy(noti.dislikeby,ucli);

						 a.write((char*)&noti,sizeof(noti));
					}
				}
			}
			else if(i==3)
			{
				char name[100];

				cout<<"enter the name corresponding to the status you wanna comment"<<endl;
				cin>>name;
				char comment[30];
				cout<<"enter your comment"<<endl;
				gets(comment);

				ifstream b("us");
				ofstream a("noti",ios::app);
				while(b.read((char*)&z,sizeof(z)))
				{
					if(strcmp(name,z.name)==0)
					{
						 strcpy(noti.commentof,name);
						 strcpy(noti.commentby,ucli);
						 strcpy(noti.comment,comment);

						 a.write((char*)&noti,sizeof(noti));
					}

				}
			}
			else
			{
				cout<<"atleast enter the number which is on the screen ,and i don't give a second chance "<<endl;
				getch();
			}

		}

		void request()     // function for sending friend requests
		{
			clrscr();
				cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			fstream a("us",ios::in|ios::out);
			int i=1;
			while(a.read((char*)&z,sizeof(z)))
			{
				cout<<i<<"--"<<z.name<<endl;
				  i++;
			}

			cout<<endl<<"type the name in order to send the friend request to that person"<<endl;
			cin>>fri.requestfor;
			strcpy(fri.requestfrom,ucli);

			ofstream b("friend",ios::app);
			b.write((char*)&fri,sizeof(fri));
			clrscr();
			cout<<"**friend request sent to \t"<<fri.requestfor<<endl;


			b.close();
			a.close();
			getch();

		}

		void search()  //for searching other users
		{
			clrscr();
				cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			char name[20];
			cout<<"enter the name"<<endl;
			cin>>name;
			ifstream a("us");
			while(a.read((char*)&z,sizeof(z)))
			{
				if(strcmp(name,z.name)==0)
				{
					z.disp();
				}
			}
		}

		void panel()  //notification panel
		{
			clrscr();
			another:
				cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			cout<<"choose from the followings"<<endl;
			int choose;
			cout<<"1-see who has liked your status"<<endl;
			cout<<"2-see who has disliked"<<endl;
			cout<<"3-see the comments"<<endl;
			cout<<"4-see the friend request received"<<endl;

			cin>>choose;
			if(choose==1)
			{                    int i=1;
				ifstream a("noti");
				while(a.read((char*)&noti,sizeof(noti)))
				{
					if(strcmp(ucli,noti.likeof)==0)
					{
						cout<<i<<"--"<<noti.likeby<<"\t liked your status"<<endl;
						i++;
					}
				}
				getch();
			}
			else if(choose==2)
			{
				int i=1;
				ifstream a("noti");
				while(a.read((char*)&noti,sizeof(noti)))
				{
					if(strcmp(ucli,noti.dislikeof)==0)
					{
						cout<<i<<"--"<<noti.dislikeby<<"\t disliked your status"<<endl;

						i++;
					}

				}
				getch();
			}
			else if(choose==3)
			{                    int i=1;
				ifstream a("noti");
				while(a.read((char*)&noti,sizeof(noti)))
				{
					if(strcmp(ucli,noti.commentof)==0)
					{
						cout<<i<<"--"<<noti.comment<<endl<<"by \t"<<noti.commentby<<endl;
						i++;
					}
				}
				getch();
			}
			else if(choose==4)
			{
				int i=1;
				fstream a("friend",ios::in|ios::out);
				while(a.read((char*)&fri,sizeof(fri)))
				{
					if(strcmp(fri.requestfor,ucli)==0)
					{
						cout<<i<<"-"<<fri.requestfrom<<endl;
						i++;
					}
				}
				char ans[100];
				cout<<"type name of the person to respond to the request"<<endl;
				cin>>ans;
				clrscr();
				cout<<"press y to confirm else press any key to reject"<<endl;
				char answer;
				cin>>answer;
				ofstream b("temp");
				while(a.read((char*)&fri,sizeof(fri)))
				{
					if(strcmp(fri.requestfrom,ans)!=0)
					{
						b.write((char*)&fri,sizeof(fri));
					}
				}
				a.close();
				remove("friend");
				rename("temp","friend");
				b.close();
				getch();
			}


			else
		 {
			cout<<"comeon boy/girl you have entered the wrong number don't try to act smarter cause you are not select from the number mentioned otherwise if you don't wish to continue kindly logout"<<endl;
			getch();
			goto another;
		 }



		}
		void settings()  //account settings(update any info)
		{

			clrscr();
				cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			cout<<"under construction"<<endl;
			getch();


		}
		void logout()  //logout of the account
		{
			cout<<"you are logged out"<<endl;
			getch();
			exit(0);
		}
		void see()    //see the received messages
		{
			clrscr();
				cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			int i=1;
			ifstream a("msg");
			while(a.read((char*)&talk,sizeof(talk)))
			{
				if(strcmp(talk.msgof,ucli)==0)
				{

				cout<<i<<"-"<<talk.msg<<"\t by   "<<talk.msgby<<endl;
				i++;
				}
			}
			getch();
		}
		void msg()     //send the message
		{     clrscr();
			cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			char message[100],name[100];
			cout<<"enter the name of the person you want to message"<<endl;
			cin>>name;
			cout<<"enter your message"<<endl;
			gets(message);
			ifstream a("us");
			ofstream b("msg",ios::app);
			while(a.read((char*)&z,sizeof(z)))
			{
				if(strcmp(name,z.name)==0)
				{
					strcpy(talk.msgby,ucli);
					strcpy(talk.msg,message);
					strcpy(talk.msgof,name);
					b.write((char*)&talk,sizeof(talk));

				}
			}


		}

		void statusdel()  //delete the previous status
		{
			ifstream a("status1");
			ofstream b("temp");
			char ans[100];
			cout<<"enter  the status you want to delete"<<endl;
			gets(ans);
			while(a.read((char*)&st,sizeof(st)))
			{
				if(strcmp(st.status,ans)!=0)
				{
					b.write((char*)&st,sizeof(st));
				}
			}
			a.close();
			b.close();
			remove("status1");
			rename("temp","status1");

		}
	       void newpass(char a[],char name[])  //for updating the forgot password
	       {
			ifstream c("us");
			ofstream b("temp");
			while(c.read((char*)&z,sizeof(z)))
			{
				if(strcmp(name,z.name)==0)
				{
					z.updatepass(a);
				}
				b.write((char*)&z,sizeof(z));
			}
				c.close();
			b.close();
			remove("us");
			rename("temp","us");
		}


void main()
{
	char name[100];


	one:
	clrscr();
	cout<<"01010100 01101000 01101001 01110011 00100000 01110000 01110010 01101111 01100111 01110010 01100001 01101101 00100000 01101001 01110011 00100000 01101101 01100001 01100100 01100101 00100000 01100010 01111001 00100000 01110101 01110100 01101011 01100001 01110010 01110011 01101000 00100000 01100100 01110101 01100010 01100101 01111001"<<endl;
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	cout<<"|||||||||||||||||                  THE FACEBOOK         ||||||||||||||||||||||||"<<endl;
	cout<<"||||||||||||||                                              ||||||||||||||||||||"<<endl;
	cout<<"|||||||||||    		1-login                       	       |||||||||||||||||"<<endl;

	cout<<"||||||||     		2-(new here?) signup          	          ||||||||||||||"<<endl;
	cout<<"||||||      		3-exit                         		    ||||||||||||"<<endl;
	cout<<"|||			4-admin's space				       |||||||||"<<endl;
	cout<<"|								          ||||||"<<endl;
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
	int option;
	cin>>option;
	if(option==1)
		{
			redirect:
			clrscr();

			cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
			char email[100];
			char password[100];
			strcpy(password," ");
			cout<<"Enter the name"<<endl;
			cin>>email;
			char ch;
			again:
			cout<<"enter the password"<<endl;
			int i=0;


			while(ch!='\r')
			{

				ch=getch();
				if(ch!='\b'&&ch!='\r')
				{
					cout<<"*";
					password[i]=ch;
					i++;
				}
			}
			ifstream a("us");
			int p=0;
			while(a.read((char*)&z,sizeof(z)))
			{
			if(strcmp(email,z.name)==0)
			{

				if(strcmp(password,z.rpass())!=0)
				 {	cout<<"wrong password try again "<<endl;
					char reset;
					cout<<"forgot password .?(want to reset)?(press y for yes else press any key to go back..!!!)"<<endl;
					cin>>reset;
					if(reset=='y')
					{
						clrscr();
						cout<<"wait let me see what we can do here !!!"<<endl;
						getch();
						char check[100];
						cout<<"enter the email id to reset"<<endl;
						cin>>check;
						if(strcmp(check,z.email_ID)==0)
						{
							clrscr();
							cout<<"entered email was correct ..wait processing..."<<endl;
							getch();
							char new_pass[100];
							cout<<"enter the new password"<<endl;
							cin>>new_pass;


							clrscr();
							newpass(new_pass,email);
							cout<<"new password saved ...make sure you remember it!!"<<endl;
							cout<<"you will be redirected to the login page"<<endl;
							getch();
							goto redirect;
						}
						else
						{
							cout<<"entered email was wrong make sure you either sign up or don't try to run this program furthur without any account"<<endl;
							getch();
							exit(0);
						}
					}
					else
					exit(0);

				  }
				  else
				  {
					clrscr();
					cout<<"welcome"<<endl;
					strcpy(ucli,z.name);
					internal();
				  }
				  p=1;
			}
			}
			if(p==0)
			{
				cout<<"invalid user name (kindly signup)"<<endl;
				getch();
				goto one;
			}
		a.close();
	}

	else if(option==2)
	{
		clrscr();
			cout<<"\t\t\t\t"<<" THE FACEBOOK.."<<endl;
		 cout<<"you made a wise decision to join us..THANK YOU"<<endl;

		 cout<<"It's free and maybe always will be"<<endl;
		 z.enter();
		 ofstream a("us",ios::app);
		 a.write((char*)&z,sizeof(z));
		 a.close();
		 cout<<"your account is made"<<endl;
		 char ans;
		 cout<<"wanna go back"<<endl;
		 cin>>ans;
		 if(ans=='y')
			goto one;
		 else
		 exit(0);
	}
	else if(option==3)
	exit(0);
	else if(option==4)
	{
		char password2[100];
		char ch;
		cout<<"enter the password for access"<<endl;
		strcpy(password2," ");
		int i=0;
			while(ch!='\r')
			{

				ch=getch();
				if(ch!='\b'&&ch!='\r')
				{
					cout<<"*";
					password2[i]=ch;
					i++;
				}
			}
			if(strcmp(password2,"saksham")==0)
			{
				clrscr();

				cout<<"access granted"<<endl;
				getch();
				clrscr();
				int  i=1;
				ifstream a("us");
				while(a.read((char*)&z,sizeof(z)))
				{
					cout<<"\t"<<i<<":"<<endl;
					z.disp();
					i++;
				}
				char ans;
				cout<<"wanna go back"<<endl;
				cin>>ans;
				if(ans=='y')
				{
					strcpy(password2," ");
					goto one;

				}
				else
					exit(0);
			}
			else
			{       clrscr();

				cout<<"access denied"<<endl;
				getch();
				strcpy(password2," ");
				goto one;
			}
	       }
	else
		 {
			clrscr();
			cout<<"comeon boy/girl you have entered the wrong number don't try to act smarter cause you are not select from the number mentioned otherwise if you don't wish to continue kindly exit."<<endl;
			cout<<"-message by programmer"<<endl;
			getch();

			goto one;
		 }


	getch();

}
