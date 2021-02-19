#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	int Voter_ID;
	char Name[60];
	int days;
	int month;
	int year;
	char Gender[6];
	int checkvoted;
}Voter;

typedef struct
{
	int Candidate_ID;
	char Candidate_Name[60];
	char Candidate_Party[60];
	int VoteCount;
}Candidate;


int main()
{
int n1=0,n=0,j=0;
Voter v[100];
Candidate c[20];
int choice;
char ch;
	do
	{
	printf("--------------------------------------------------------------------------VOTING SYSTEM---------------------------------------------------------------------");
	printf("\n1.New Voter Registration--------------------------");
	printf("\n2.New Candidate Registration----------------------");
	printf("\n3.Display Voters----------------------------------");
	printf("\n4.Display Candidates------------------------------");
	printf("\n5.Start Voting Machine----------------------------");
	printf("\n6.Exit--------------------------------------------");
	printf("\n_________________ENTER CHOICE_____________________>>");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n_____________ New Voter Registration________________ ");
					VoterRegistration(v,n);
					n++;
					break;
			case 2:printf("\n_____________ New Candidate Registration____________ ");
					CandidateRegistration(c,n1);
					n1++;
					break;
			case 3:printf("\n\n\n_______________________________DISPLAY VOTER LIST__________________________________________\n\n");
					DisplayVoter(v,n);
					break;
			case 4:printf("\n\n\n_______________________________DISPLAY Candidate LIST__________________________________________\n\n");
					DisplayCandidate(c,n1);
					break;
			
			case 5:printf("\n Start Voting Machine \n ");
					StartVoting(c,n1,v,n);
				
					break;
			case 6:printf("Exited");
					exit(0);
					break;	
			default:printf("Invalid Option");
					break;
		
		}
	
	}while(choice!=6);

	
return 0;
}

void StartVoting(Candidate c[],int n1,Voter v[],int n)
{
	int i=0,key,Vote;
	int cnt,id;
	int flag=0,MAX;
	char ch;
	do
	{
	
	printf("\n------------------------------------------Candidate LIST-----------------------------------------------\n");
	printf("\n \t Candidate_ID \t Candidate_NAME \t  Candidate_Party \n");
	for(i=0;i<n1;i++)
	{
		printf("\n \t %d \t\t %s \t \t \t %s ",c[i].Candidate_ID,c[i].Candidate_Name,c[i].Candidate_Party);
	}
	printf("\n -------------------------------------------------------------------------------------------\n ");
	printf("\n Enter Your Voter_ID---->>>");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(v[i].Voter_ID==key)
		{
			if(v[i].checkvoted==1)
			{
				printf("\n _______!!! Your is Already Recorded !!!__________ ");
				break;
			}
			else
			{
				v[i].checkvoted=1;
			
			printf("\nEnter Your Vote((Enter CANDIDATE_ID)-------------------->>");
			scanf("%d",&Vote);
				for(i=0;i<n1;i++)
				{	
				
					if(c[i].Candidate_ID==Vote)
					{
						
						cnt=c[i].VoteCount;
						cnt++;
						c[i].VoteCount=cnt;
						
						printf("\n-------------Your Recorded Successfully---------- ");
						break;
					}
					else
					{
						
						flag=1;
					}
			
				}					
			}	
			if(flag==1)
			{
				
				v[i].checkvoted=0;
			}
		}
	}
		
printf("Press [Y/y] to continue Voting");
scanf(" %c",&ch);
}while(ch=='Y' || ch=='y');
	
	printf("\n------------------------------------------Result of Poll (Candidate LIST)-----------------------------------------------\n");
	printf("\n \t Candidate_ID \t Candidate_NAME \t  Candidate_Party \t Votes \n");
	for(i=0;i<n1;i++)
	{
		printf("\n \t %d \t\t %s \t \t \t %s \t %d",c[i].Candidate_ID,c[i].Candidate_Name,c[i].Candidate_Party,c[i].VoteCount);
	}
	printf("\n -------------------------------------------------------------------------------------------\n ");
	MAX=c[0].VoteCount;
	for(i=0;i<n1;i++)
	{
		
		
			if (MAX < c[i].VoteCount)
			{
			MAX = c[i].VoteCount;
			id=i;
			}
		
	}
	printf("\n________________________Won Candidate_________________________");
	printf("\n \t %d \t\t %s \t \t \t %s \t %d",c[id].Candidate_ID,c[id].Candidate_Name,c[id].Candidate_Party,c[id].VoteCount);
	printf("\n \n \n");
		
}


void CandidateRegistration(Candidate c[],int n1)
{
printf("\nEnter Candidate Name----------------------------->> ");
scanf(" %s",&c[n1].Candidate_Name);
printf("\nEnter Candidate Party---------------------------->> ");
scanf(" %s",&c[n1].Candidate_Party);
c[n1].Candidate_ID=n1;
c[n1].VoteCount=0;
printf("\nCandidate Registration Successfull Your Candidate ID =%d \n",c[n1].Candidate_ID);
}



void DisplayCandidate(Candidate c[],int n1)
{
	int i=0;
	printf("\n------------------------------------------Candidate LIST-----------------------------------------------\n");
	printf("\n \t Candidate_ID \t Candidate_NAME \t  Candidate_Party \n");
	for(i=0;i<n1;i++)
	{
		printf("\n \t %d \t\t %s \t \t \t %s ",c[i].Candidate_ID,c[i].Candidate_Name,c[i].Candidate_Party);
	}
	printf("\n -------------------------------------------------------------------------------------------\n ");
	
}



void VoterRegistration(Voter v[],int n)
{
int diff;
int days,month,year;
printf("\nEnter Your Full Name----------------------------->> ");
scanf(" %s",&v[n].Name);
printf("\nEnter Gender [Male/Female]----------------------->> ");
scanf("%s",&v[n].Gender);
printf("\nEnter Your Date_Of_Birth (dd mm yyyy)------------>> ");
scanf("%d%d%d",&days,&month,&year);
	if(days>31 || month>12 || year>9999 )
	{
		printf("Invalid Date Format");
	}
	else
	{
		diff=calculateAge(days,month,year);
	}
	if(diff==0)
	{
	printf("\n Registration Rejected \n");
	}
	else
	{
		v[n].days=days;
		v[n].month=month;
		v[n].year=year;
		v[n].Voter_ID=n;
		v[n].checkvoted=0;
		printf("\n Registration Successfull Your Voter ID =%d \n",v[n].Voter_ID);
	}
		
}


void DisplayVoter(Voter v[],int n)
{
	int i=0;
	printf("\n------------------------------------------VOTER LIST-----------------------------------------------\n");
	printf("\n \t Voter_ID \t NAME \t \t \t GENDER \t DATE_OF_BIRTH \n");
	for(i=0;i<n;i++)
	{
		printf("\n \t %d \t\t %s \t \t  %s \t \t %d%d%d",v[i].Voter_ID,v[i].Name,v[i].Gender,v[i].days,v[i].month,v[i].year);
	}
	printf("\n -------------------------------------------------------------------------------------------\n ");
	
}








/*Age Calculator (C program to calculate age).*/
/*check given year is leap year or not*/
int isLeapYear(int year, int mon) 
{
    int flag = 0;
    if (year % 100 == 0) 
    {
            if (year % 400 == 0) 
            {
                    if (mon == 2) 
                    {
                            flag = 1;
                    }
            }
    } 
    else if (year % 4 == 0) 
    {
            if (mon == 2) 
            {
                    flag = 1;
            }
    }
    return (flag);
}

int calculateAge(int days,int month,int year)
 {
 
    int DaysInMon[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    char dob[100];
    time_t ts;
    struct tm *ct;
 
    /*get current date.*/
    ts = time(NULL);
    ct = localtime(&ts);
 
    //printf("Current Date: %d/%d/%d\n",
      //      ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);
 
    days = DaysInMon[month - 1] - days + 1;
 
    /* leap year checking*/
    if (isLeapYear(year, month)) 
    {
            days = days + 1;
    }
 
    /* calculating age in no of days, years and months */
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;
 
    /* checking for leap year feb - 29 days */
    if (isLeapYear((ct->tm_year + 1900), (ct->tm_mon + 1))) 
    {
            if (days >= (DaysInMon[ct->tm_mon] + 1)) 
            {
                    days = days - (DaysInMon[ct->tm_mon] + 1);
                    month = month + 1;
            }
    } 
    else if (days >= DaysInMon[ct->tm_mon]) 
    {
            days = days - (DaysInMon[ct->tm_mon]);
            month = month + 1;
    }
 
    if (month >= 12) 
    {
            year = year + 1;
            month = month - 12;
    }
 
    /* print age */
    //printf("\n## Hey you are  %d years %d months and %d days old. ##\n", year, month, days);
 	if (year<18)
 	{
 		printf("\n Your Are Not Eligible for Voting You are UnderAge \n ");
		return 0;
	}
	else
	{
		return year;
	}

}
