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

void menu1(void);
void menu2(void);					
void pat1(void);
void pat2(void);
void emp(void); 
void expn1(void);
void expn2(void);
void verification(void);
void add_pat(void);
void mod_pat(void);
void search_pat(void); 
void list_pat(void);
void delete_pat(void);
void add_emp(void);
void mod_emp(void);
void search_emp(void); 
void list_emp(void);
void delete_emp(void);
void add_expn(void);
void mod_expn(void);
void search_expn(void); 
void list_expn(void);
void delete_expn(void);
			
struct address{
        	int hno;
        	char street[40];
        	char city[40];
        	char state[40];
};

struct patient{

                char name[40];
                char fname[40];
                int age;
                char bg[3];
                char gender[10];
                char regn[10];
                struct address a;
                char ph[10];
                char disease[60];
                char doc_name[40];
                char history[200];
                char date[10];
                char treatment[40];
                char med[40];
};

struct staff{

                char name[40];
                int age;
                char bg[3];
                char gender[10];
                char uid[10];
                struct address b;
                char ph[10];
                double salary;
                char desig[40];
};

struct expense{

                
                char rno[10];
                char doa[20];
                int days;
		char name[30];
		int quant;
                float price;
                float amount;
		float medp;
		float meda;
		float famount;
};
