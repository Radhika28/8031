 /*        HOSPITAL MANAGEMENT SYSTEM           */


/*****************************************************************************
 * Copyright (C) Radhika Kulkarni radhikak.sk@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pro.h"

void menu1(){							/* Main menu*/

                int choice;
                printf("\n\t\t  *** Main Menu ***");
               	printf("\n\n");
                printf("\t\t1.PATIENT");
                printf("\n\t\t2.STAFF");
		printf("\n\t\t3.EXPENSE");
                printf("\n\t\t0.EXIT");
                printf("\n\n\tEnter your choice: ");
                scanf("%d", &choice);
                

                switch(choice){
                
                                case 1:
                                                pat1();
                                                break;
                                case 2:
                                                emp();
                                                break;
                                case 3:
                                                expn1();
                                                break;
                                case 0:
                                                exit(0);
						break;
                }
}

void menu2(){							/* Main menu*/

                int choice;
                printf("\n\t\t  *** Main Menu ***");
               	printf("\n\n");
                printf("\t\t1.PATIENT");
                printf("\n\t\t2.EXPENSE");
                printf("\n\t\t0.EXIT");
                printf("\n\n\tEnter your choice: ");
                scanf("%d", &choice);
                

                switch(choice){
                
                                case 1:
                                                pat2();
                                                break;
                                case 2:
                                                expn2();
                                                break;
                                case 0:
                                                exit(0);
						break;
                }
}
void verification(){						/*Verify*/						

	char userp[] = {"passuser"};
	char adminp[] = {"passadmin"};
	char u[20];
	char a[20];
	int uchoice;
	int ucheck;
	printf("\n\tEnter choice\n \t1 - Administrator\n \t2 - User\n"); 		/*Password for Administrator - passadmin and Password for user - passuser*/
	scanf("%d" , &uchoice);
	if(uchoice == 1)		
		{
			printf("\nPlease enter the password\n");
			scanf("%s" , a);
			ucheck = strcmp(a , adminp);
			if(ucheck == 0)
				{
					printf("\t\t\tWelcome administrator\n\n");
					menu1();
				}
			else
				{
					printf("\nEntered password is wrong.Try again\n");
					printf("\nPlease ensure that selected mode is correct\n");
					verification();
				}
		}
	if(uchoice == 2)
		{
			printf("\nPlease enter the password\n");
			scanf("%s" , u);
			ucheck = strcmp(u , userp);
			if(ucheck == 0)
				{
					printf("\t\t\tWelcome user\n\n");
					menu2();
				}
			else
				{
					printf("\nEntered password is wrong.Try again\n");
					printf("\nPlease ensure that selected mode is correct\n");
					verification();
				}
		}
}



void pat1()
{
				int ch;
			while(1){
				printf("\n\n\t\t\tPATIENT");
                                printf("\n\t\t1.Enter a New Entry");
                                printf("\n\t\t2.Modify Existing");
                                printf("\n\t\t3.Search an Entry");
                                printf("\n\t\t4.Listing of records");
                                printf("\n\t\t5.Delete an Entry");
                                printf("\n\t\t6.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                scanf("%d",&ch);
                                
				switch(ch){
                                
						 case 1:
                                                        add_pat(); 
							break;        
								 
                				 case 2:		 
							mod_pat();
							break;
						 case 3:
							search_pat();
							break;
						 case 4:
							list_pat();
							break;
                                		 case 5:
							delete_pat();
                                			break;
                                		 case 6:
							menu1();
                                			break;
				}
			}

}

void pat2()
{
				int ch;
			while(1){
				printf("\n\n\t\t\tPATIENT");
                               	printf("\n\t\t1.Search an Entry");
                                printf("\n\t\t2.Listing of records");
                                printf("\n\t\t3.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                scanf("%d",&ch);
                                
				switch(ch){
                                
						
						 case 1:
							search_pat();
							break;
						 case 2:
							list_pat();
							break;
                                		 
                                		 case 3:
							menu2();
                                			break;
				}
			}

}
void add_pat(){							/*Adding an entry*/
								
				FILE *fp;
                		long int recsize;
                		struct patient p;
		                recsize=sizeof(p);
				fp=fopen("pat.txt","a");
				if(fp==NULL){
                        		printf("\nSorry!! Cannot open file");
                                }else{
               				printf("\nEnter the registration no. of the patient: ");
					scanf("%s",p.regn);
					printf("\nEnter the name of the patient: ");
					scanf("%s",p.name);
                                       	printf("\nEnter the name of the Guardian: ");
					scanf("%s",p.fname);
                                        printf("\nEnter the gender of the patient(M.male or F.female): ");
                                        scanf("%s",p.gender);
                                     	printf("\nEnter the Blood group of the patient: ");
                                        scanf("%s",p.bg);
                                        printf("\nEnter the age of the patient: ");
                                       	scanf("%d",&p.age);
                                        printf("\nEnter the address of the patient:\n");
                                        printf("\n\tEnter the house number: ");
                                       	scanf("%d",&p.a.hno);
                                        printf("\n\tEnter the street/colony: ");
                                        scanf("%s",p.a.street);
                                        printf("\n\tEnter the city: ");
                                        scanf("%s",p.a.city);
                                        printf("\n\tEnter the state: ");
                                        scanf("%s",p.a.state);
                                        printf("\nEnter the phone number of the patient: ");
                                        scanf("%s",p.ph);
                                       	printf("\nEnter the Disease for which he/she wants treatment: ");
                                        scanf("%s",p.disease);
					printf("enter the date of treatment given: ");
					scanf("%s",p.date);
                                        printf("\nEnter the detail of treatment given:");
					scanf("%s",p.treatment);
                                        printf("\nEnter the medicines prescribed:");
					scanf("%s",p.med);
					printf("\nEnter the name of the Doctor to which he/she is being referred: ");
                                        scanf("%s",p.doc_name);
					printf("\nEnter the history, if any, related to treatment of the patient: ");
                                       	scanf("%s",p.history);
					fwrite(&p,recsize,1,fp);
                                        printf("The record is sucessfully added\n");
                                	fclose(fp);
				}
				return;
}						
						
void mod_pat(){							/*Modification of an entry*/
				long int recsize;
                		struct patient p;
		               	recsize=sizeof(p);
                                char reg[15];
                                printf("\nEnter the Registration number of the patient to modify: ");
                                scanf("%s",reg);
				FILE *fp;
                               	fp = fopen("pat.txt","r+");
				if(fp==NULL){
                        		printf("\nSorry!! Cannot open file");
                                }else{                    
                                	while(fread(&p,recsize,1,fp)==1){
                                			if(strcmp(p.regn,reg)==0){
                                                		printf("\nEnter the new name of the patient: ");
								scanf("%s",p.name);
                                                                printf("\nEnter the new name of the Guardian: ");
                                                               	scanf("%s",p.fname);
								printf("\nEnter the new Blood group of the patient: ");
                                                                scanf("%s",p.bg);
								printf("\nEnter the new age of the patient: ");
                                                                scanf("%d",&p.age);
								printf("\nEnter the new address of the patient:\n");
                                                                printf("\n\tEnter the house number: ");
                                                                scanf("%d",&p.a.hno);
                                                                printf("\n\tEnter the street/colony: ");
                                                                scanf("%s",p.a.street);
                                                                printf("\n\tEnter the city: ");
                                                               	scanf("%s",p.a.city);
                                                                printf("\n\tEnter the state: ");
                                                               	scanf("%s",p.a.state);
								printf("\nEnter the new phone number of the patient: ");
                                                                scanf("%s",p.ph);
                                                                printf("enter the date of treatment given: ");
								scanf("%s",p.date);
                                                               	printf("\nEnter the detail of treatment given:");
								scanf("%s",p.treatment);
                                                                printf("\nEnter the medicines prescribed:");
								scanf("%s",p.med);
                                                             	fseek(fp,-recsize,SEEK_CUR);
                                                                fwrite(&p,recsize,1,fp);
                                                	}
                                	}
				fclose(fp);
				}
                                return;                 
}

void search_pat(){						/*Searching an entry*/
				long int recsize;
                		struct patient p;
		               	recsize=sizeof(p);
                                char reg[15];
				int i = 0;
                                FILE *fp;              					
				fp=fopen("pat.txt","r+");						
				printf("\nEnter registration no. of the patient to search: ");						
				scanf("%s", reg);
				if(fp == NULL){
					printf("\nSorry!! Cannot open file");
				}else{					
                            	while(fread(&p,recsize,1,fp)==1){
                                		if(strcmp(p.regn,reg)==0){
								i = 1;
                                                                break;
						}
				}
				if(i = 1){
					printf("\nRegistration Number of the Patient : %s" , p.regn);
                                        printf("\nName of the Patient : %s" , p.name);
                                        printf("\nName of the Guardian : %s" , p.fname);
                                        printf("\nAge : %d",p.age);
                                        printf("\nGender : %s",p.gender);
                                        printf("\nBlood group: %s",p.bg);                                                                      
					printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                        printf("\nphone number : +91-%s",p.ph);
                                      	printf("\nDisease : %s",p.disease);
                                       	printf("\nEarlier History : %s" , p.history);
                                        printf("\nDetails of treatment given and medicine prescribed:");
					printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
					printf("%s\t\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                        printf("\nName of the Doctor : %s" , p.doc_name);
                                }else{
					printf("Record not found\n");
					fclose(fp);
				}

				}
                              	return;
}

void list_pat(){						/*List all the entries*/

                                                
                                FILE *fp; 
                               	fp=fopen("pat.txt","r+"); 
				long int recsize;
                		struct patient p;
		               	recsize=sizeof(p);
                                if(fp==NULL){
                        		printf("\nSorry!! Cannot open file");
                                }else{                                     
                                      fseek(fp,0,SEEK_SET);
				      while(fread(&p,recsize,1,fp)==1){
                                                   printf("\nRegistration Number of the Patient : %s" , p.regn);
                                                   printf("\nName of the Patient : %s" , p.name);
                                                   printf("\nAge : %d",p.age);
                                                   printf("\nGender : %s",p.gender);
                                                   printf("\nBlood group: %s",p.bg);
						   printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                   printf("\nphone number : +91-%s",p.ph);
                                                   printf("\nDisease : %s",p.disease);
                                                   printf("\nEarlier History :%s " , p.history);
                                                   printf("\nDetails of treatment given and medicine prescribed:");
						   printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                                   printf("%s\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                   printf("\nName of the Doctor : %s" , p.doc_name);
                                                   printf("\n----------------------------------------------------\n");
   				      }
				fclose(fp);
			     	}
                              return;
			                                 
}

void delete_pat(){						/*Deleting an entry*/
				long int recsize;
                		struct patient p;
		                recsize=sizeof(p);
                                char reg[15];
                               	FILE *fp, *ft;
				printf("\nEnter the Registration number of the Patient to be deleted: ");
                                scanf("%s",reg);
				fp = fopen("pat.txt","r");
                                ft=fopen("temp.txt","w+");
                                if(fp==NULL){
                       			printf("\nSorry!! Cannot open file");
                                }else{                    
                                      	while(fread(&p,recsize,1,fp)==1){
                                        	if(strcmp(p.regn,reg)!=0)
                                                	fwrite(&p,recsize,1,ft);
                                                else
							printf("\nThe Record has been Deleted Successfully.");
                                         }

                                fclose(fp);
                                fclose(ft);
                                remove("pat.txt");
                               	rename("temp.txt","pat.txt");
                                fp=fopen("pat.txt","r+");
				}
				return;
}
void emp(){
			int ch;
			while(1){
				printf("\n\n\t\t\tEMPLOYEE");
                                printf("\n\t\t1.Enter a New Entry");
                                printf("\n\t\t2.Modify Existing");
                                printf("\n\t\t3.Search an Entry");
                                printf("\n\t\t4.Listing of records");
                                printf("\n\t\t5.Delete an Entry");
                                printf("\n\t\t6.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                scanf("%d",&ch);
                                
				switch(ch){
                                
						 case 1:
                                                        add_emp(); 
							break;        
								 
                				 case 2:		 
							mod_emp();
							break;
						 case 3:
							search_emp();
							break;
						 case 4:
							list_emp();
							break;
                                		 case 5:
							delete_emp();
                                			break;
                                		 case 6:
							menu1();
                                			break;
				}
			}

}

                
void add_emp(){							/*Adding an entry*/                           
                                FILE *fs;
                		long int recsize;
                		struct staff s;
		                recsize=sizeof(s);
				fs=fopen("emp.txt","a");
				if(fs==NULL){
                        		printf("\nSorry!! Cannot open file");
				}else{
                                        printf("\nEnter the unique ID of the employee:");
                                  	scanf("%s", s.uid);
                                        printf("\nEnter the name of the Employee: ");
                                        scanf("%s", s.name);
                                        printf("\nEnter the gender of the patient(M.male or F.female): ");
                                        scanf("%s",s.gender);
                                    	printf("\nEnter the Blood group of the Employee: ");
                                       	scanf("%s",s.bg);
                                      	printf("\nEnter the age of the Employee: ");
                                      	scanf("%d",&s.age);
                                       	printf("\nEnter the Salary of the Employee: ");
                                        scanf("%lf",&s.salary);
                                     	printf("\nEnter the address of the Employee:\n");
                                    	printf("\n\tEnter the house number: ");
                                        scanf("%d",&s.b.hno);
                                        printf("\n\tEnter the street/colony: ");
                                        scanf("%s",s.b.street);
                                        printf("\n\tEnter the city: ");
                                       	scanf("%s",s.b.city);
                                     	printf("\n\tEnter the state: ");
                                        scanf("%s",s.b.state);
                                        printf("\nEnter the phone number of the Employee: ");
                                        scanf("%s",s.ph);
                                        printf("\nEnter the Designation: ");
                                        scanf("%s", s.desig);
					fwrite(&s,recsize,1,fs);
                                        printf("The record is sucessfully added\n");
                              		fclose(fs);
				}
				return;
}
                                                               

void mod_emp(){							/*Modification of an entry*/
				long int recsize;
                		struct staff s;
		                recsize=sizeof(s);
                                char id[15];
                                printf("\nEnter the UID of the patient to modify: ");
                             	scanf("%s",id);
				FILE *fs;
                                fs = fopen("emp.txt","r+");
				if(fs==NULL){
                        		printf("\nSorry!! Cannot open file");
                                }else{                    
                                  	while(fread(&s,recsize,1,fs)==1){
                                        	if(strcmp(s.uid,id)==0){
                                                	printf("\nEnter the new name of the Employee: ");
                                                        scanf("%s",s.name);
                                                       	printf("\nEnter the new Blood group of the Employee: ");
							scanf("%s",s.bg);
							printf("\nEnter the new age of the Employee: ");
                                                        scanf("%d",&s.age);
							printf("\nEnter the new Salary of the Employee: ");
                                                      	scanf("%lf",&s.salary);
							printf("\nEnter the new address of the Employee:\n");
                                                        printf("\n\tEnter the house number: ");
                                                        scanf("%d",&s.b.hno);
                                                     	printf("\n\tEnter the street/colony: ");
                                                        scanf("%s",s.b.street);
                                                        printf("\n\tEnter the city: ");
                                                        scanf("%s",s.b.city);
                                                        printf("\n\tEnter the state: ");
                                                      	scanf("%s",s.b.state);
							printf("\nEnter the new phone number of the Employee: ");
                                                        scanf("%s",s.ph);
							fseek(fs,-recsize,SEEK_CUR);
                                                        fwrite(&s,recsize,1,fs);
                                                }
					}
 				fclose(fs);
				}
				return;
}


void search_emp(){						/*Searching an entry*/                     
				long int recsize;
                		struct staff s;
		                recsize=sizeof(s);
                                char id[15];
				int i = 0;
                                FILE *fs;
				fs=fopen("emp.txt","r+");                                             								     					printf("\nEnter the unique id of the employee: ");
                                scanf("%s" , id);
				if(fs==NULL){
                        		printf("\nSorry!! Cannot open file");
                                }else{                    
                                while(fread(&s,recsize,1,fs)==1){
						if(strcmp(s.uid,id)==0){
							i = 1;
                                                        break;
						}
                                }	              
				if(i = 1){
                                         printf("\nUID of the Employee : %s", s.uid);
                                         printf("\nName of the Employee : %s" , s.name);
                                         printf("\nAge : %d",s.age);
                                         printf("\nSalary: %lf",s.salary);
                                         printf("\nGender : %s",s.gender);
                                         printf("\nBlood group: %s",s.bg);
					 printf("\nAddress  : %d,%s,%s,%s",s.b.hno,s.b.street,s.b.city,s.b.state);
                                         printf("\nphone number : +91-%s",s.ph);
                                         printf("\nDesignation : %s",s.desig);
                                }else{
					 printf("record not found\n");
					 fclose(fs);
				}
				}
                                                                 return;
}                                                                 
                                                              
void list_emp(){						/*Listing all the entries*/

                                FILE *fs; 
                                fs=fopen("emp.txt","r+"); 
				long int recsize;
                		struct staff s;
		                recsize=sizeof(s);
				if(fs==NULL){
                        		printf("\nSorry!! Cannot open file");
                                }else{ 
				fseek(fs,0,SEEK_SET);                   
                                while(fread(&s,recsize,1,fs)==1){
                                		printf("\nUID of the Employee : %s ", s.uid);
                                                printf("\nName of the Employee :%s " , s.name);
                                                printf("\nAge : %d",s.age);
                                               	printf("\nSalary: %lf",s.salary);
                                             	printf("\nGender : %s",s.gender);
                                                printf("\nBlood group: %s",s.bg);
						printf("\nAddress  : %d,%s,%s,%s",s.b.hno,s.b.street,s.b.city,s.b.state);
                                                printf("\nphone number : +91-%s",s.ph);
                                                printf("\nDesignation : %s",s.desig);

                                                printf("\n----------------------------------------------------\n");

                                }
				fclose(fs);
				}
				return;
}                                                                
   
void delete_emp(){ 						/*Deleting an entry*/
				long int recsize;
                		struct staff s;
		                recsize=sizeof(s);
                                char id[15];
                             	FILE *fs, *fx;
				printf("\nEnter the UID of the Employee to be deleted: ");
                                scanf("%s",id);
                                fx=fopen("tem.txt","w+");
				fs = fopen("emp.txt","r");
				if(fs==NULL){
                        		printf("\nSorry!! Cannot open file");
                                }else{ 
                                while(fread(&s,recsize,1,fs)==1){
                                                   if(strcmp(s.uid,id)!=0)
                                                        fwrite(&s,recsize,1,fx);
                                                   else
							printf("\nThe Record has been Deleted Successfully.");
                                }
				fclose(fs);
                                fclose(fx);
                              	remove("emp.txt");
                               	rename("tem.txt","emp.txt");
                                fs=fopen("emp.txt","r");
				}
                                return;
                  
}

void expn1(){
	 	
                int c;
		while(1){
                                printf("\n\t\t\tEXPENSES");
                                printf("\n\t\t1.Add an Entry ");
                                printf("\n\t\t2.Modify Existing Entry");
                                printf("\n\t\t3.Search an Entry");
                                printf("\n\t\t4.List all Entries");
                                printf("\n\t\t5.Delete an Entry");
                                printf("\n\t\t6.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                scanf("%d" , &c);

                                switch(c){
						case 1:
                                                         add_expn();
							 break;
						case 2:
							 mod_expn();
							 break;       
						case 3:
							 search_expn();
							 break;
						case 4:
							 list_expn();
							 break;
						case 5:
							 delete_expn();
							 break; 
						case 6:
							 menu1();
							 break;
				}
		}
}

void expn2(){
	 	
                int c;
		while(1){
                                printf("\n\t\t\tEXPENSES");
                                printf("\n\t\t1.Search an Entry");
                                printf("\n\t\t2.List all Entries");
                             	printf("\n\t\t3.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                scanf("%d" , &c);

                                switch(c){
						   
						case 1:
							 search_expn();
							 break;
						case 2:
							 list_expn();
							 break;
						
						case 3:
							 menu2();
							 break;
				}
		}
}

void add_expn(){							/*Adding an entry*/
				FILE *fi;
				int r;
                		long int recsize;
                		struct expense v;
		                recsize=sizeof(v);
				fi=fopen("expn.txt","a");
                                                               
                                if(fi==NULL){
                        		printf("\nSorry!! Cannot open file");
				}else{
                                        printf("Enter the registration number of the patient:");
					scanf("%s" , v.rno);
                                        printf("\nEnter the Date of admission: ");
                                        scanf("%s",v.doa);
                                        printf("\nEnter the number of days patient was admitted for: ");
                                        scanf("%d",&v.days);
                                        printf("\nEnter the class of the room patient stayed in: ");
					printf("\n1.General ward\n");
					printf("\n2.Private room\n");
					printf("\n3.Semi-private room\n");
					scanf("%d" , &r);
					switch(r){
							case 1:
								v.price = 500;
								break;
							case 2:
								v.price = 1000;
								break;
							case 3:
								v.price = 700;
								break;
					}
					v.amount=v.days * v.price;
					printf("\n The expense of stay at the hospital = %f", v.amount);
					printf("\nEnter the name of the  hospital medicine : ");
					scanf("%s" , v.name);
					printf("\nEnter the Quantity of the medicine: ");
					scanf("%d" , &v.quant);
					printf("\nEnter the price of single item:");
 					scanf("%f" , &v.medp);
					v.meda = v.quant * v.medp;
					v.famount = v.amount + v.meda;
					printf("\n The total expense  = %f", v.famount);
                                        fwrite(&v,recsize,1,fi);
                                                                                
                        	}
				fclose(fi);
				return;
}

void mod_expn(){							/*Modification of an entry*/
			long int recsize;
                	struct expense v;
		        recsize=sizeof(v);
			int r;
                        char reg[15];
		 	printf("\nEnter the registration number of the patient to modify: ");
                        scanf("%s",reg);
                        FILE *fi;
                        fi = fopen("emp.txt","r+");
                        while(fread(&v,recsize,1,fi)==1){
                                                                                
                                	if(strcmp(v.rno,reg)==0){
                                                                                                                	
                                                       printf("\nEnter the new Date of admission: ");
                                                       scanf("%s",v.doa);
                                                       printf("\nEnter the number of days patient was admitted for: ");
                                                       scanf("%d",&v.days);
                                                       printf("\nEnter the class of the room patient stayed in: ");
						       printf("\n1.General ward\n");
						       printf("\n2.Private room\n");
						       printf("\n3.Semi-private room\n");
						       scanf("%d" , &r);
						       switch(r){
								case 1:
								 	v.price = 500;
									break;
								case 2:
									v.price = 1000;
									break;
								case 3:
									v.price = 700;
									break;
							}
							v.amount=v.days * v.price;
							printf("\n The expense of stay at the hospital = %f", v.amount);
							printf("\nEnter the name of the  hospital medicine : ");
							scanf("%s" , v.name);
							printf("\nEnter the Quantity of the medicine: ");
							scanf("%d" , &v.quant);
							printf("\nEnter the price of single item:");
 							scanf("%f" , &v.medp);
							v.meda = v.quant * v.medp;
							v.famount = v.amount + v.meda;
							printf("\n The total expense  = %f", v.famount);
                                                        fseek(fi,-recsize,SEEK_CUR);
                                                        fwrite(&v,recsize,1,fi);
					}
			}
		fclose(fi);
		return;
}
						                                                     
void search_expn(){						/*Searching an entry*/
                  		long int recsize;
                		struct expense v;
		                recsize=sizeof(v);
                                char reg[15];
				int i = 0;
                                FILE *fi;
				fi=fopen("expn.txt","r+");                                             							
				printf("\nEnter the registration no. of the patient");
                                scanf("%s" , reg);
                                while(fread(&v,recsize,1,fi)==1){
						if(strcmp(v.rno,reg)==0){
								i = 1;
                                                                break;
						}                                                                                              
                                }      
				if(i = 1){
                                           printf("\nThe registration no. of the patient: %s " , v.rno);
					   printf("\nThe Date of admission: %s " , v.doa);
					   printf("\nThe number of days patient was admitted for: %d" , v.days);
					   printf("\n The expense of stay at the hospital = %f", v.amount);
					   printf("\n The total expense  = %f\n", v.famount);   
                                }else{
					printf("\nrecord not found\n");
					fclose(fi);
				}
		return;
}                                
                                                                                

void list_expn(){						/*Listing all the entries*/
				 FILE *fi; 
                                 fi=fopen("expn.txt","r+"); 
				 long int recsize;
                		 struct expense v;
		                 recsize=sizeof(v);
                                 while(fread(&v,recsize,1,fi)==1){
					   printf("\nThe registration no.of the patient: %s " , v.rno);
					   printf("\nThe Date of admission: %s " , v.doa);
					   printf("\nThe number of days patient was admitted for: %d" , v.days);
					   printf("\n The expense of stay at the hospital = %f", v.amount);
					   printf("\n The total expense  = %f\n\n", v.famount);
				 }
		fclose(fi);
		return;

}

void delete_expn(){						/*Deleting an entry*/
			long int recsize;
                	struct expense v;
		        recsize=sizeof(v);
                        char reg[15];
                        FILE *fi, *fd;
			printf("\nEnter the reg no. of the patient to be deleted: ");
                        scanf("%s",reg);
                        fd = fopen("tempr.txt","w+");
			fi = fopen("expn.txt","r");
                        while(fread(&v,recsize,1,fi)==1){
                                          if(strcmp(v.rno,reg)!=0)
                                          	fwrite(&v,recsize,1,fd);
                                          else
						printf("\nThe Record has been Deleted Successfully.");
                        }

                        fclose(fi);
                        fclose(fd);
                     	remove("expn.txt");
                        rename("tempr.txt","expn.txt");
                        fi=fopen("expn.txt","r");
                        return;

}
