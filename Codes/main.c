/*
* @main.c
* @Menu Kontrolleri ve Program Calistirma Fonksiyonunu Cagirma
* @Odev 1
* @02.12.2019
* @Yunus Emre Atik - yunusemre.atik@stu.fsm.edu.tr                            
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixOps.h"
#include <string.h>

int line_lenght;													
int column_lenght;
int direction;
int round_times;
int random_Number=100;

int main(int argc, char *argv[])
{	 
	if(argc==1){
		
	}
	else{
		int isdigit_Control=0;										
	int lenght_Control=0;
	if(argc==6)		// Argumanlar 6 ise Kontrol Edecegim
    {
    	int i;    	
        for(i = 1; i<argc; ++i)		// (Arguman Sayisi-1) Kadar Donersek Girdigimiz Girdiler Kadar Donmus Oluruz
        {
        	int j;        	
        	for(j=0;argv[i][j]!='\0';j++)	// i.Satirin j.Elemanlarini Gezerek Null Gostermeyenlere Girecegiz
			{   
        		if(!isdigit(argv[i][j])) 	// i.Satirin j.Elemanlarini Gezerek Digit Olmayanlari Buluyoruz 
				{					
					if(i==3)
					{
						if(argv[i][0]=='-')	// - ise 
						{	
							if(argv[i][1]!='1')	// -'den sonraki deger 1 mi diye kontrol ediyoruz
							{								
								printf("-->HATA--< Matrisin %d . girdisinin %d . indisinde => (-)'den sonra 1 yok \n",i,j+1);
								isdigit_Control++;	// Hata Gordugumuz Yerde Hata Sayisini Arttiriyoruz
							}
						}	
					}
					else
					{
						printf("-->HATA--< Matrisin %d . girdisinin %d . indisi => Isdigit'e uymuyor \n",i,j+1);
						isdigit_Control++;
					} 		
				}							
			}	
		}		
		if(lenght_Control==0) //Lenght'lerin Kontrol Edildigi Kisim
		{			
			line_lenght= atoi(argv[1]);	// atoi yardimiyla degerleri atiyorum
			column_lenght= atoi(argv[2]);
			direction= atoi(argv[3]);
			random_Number= atoi(argv[4]);
			round_times= atoi(argv[5]);	
			
			if(!(10>line_lenght>0))	//0-9 arasi olmasini istiyorum
			{				
			lenght_Control++;	
			printf("-->HATA--< Satir Sayisi 0-9 Araliginda Olmalidir \n");
			}
			
			if(!(10>column_lenght>0))	//0-9 arasi olmasini istiyorum
			{
			lenght_Control++;	
			printf("-->HATA--< Sutun Sayisi 0-9 Araliginda Olmalidir \n");
			}
			
			if(!((direction==1)||(direction==-1)))	//1 veya -1 olmasini istiyorum
			{
			lenght_Control++;	
			printf("-->HATA--< Yon -1 veya 1 Olmalidir \n");
			}
			
			if(!(101>random_Number>0))	//0-100 arasi olmasini istiyorum
			{
			lenght_Control++;
			printf("-->HATA--< Random Sayi 0-100 Araliginda Olmalidir \n");
			}
			
			if(!(10>round_times>0))	//0-9 arasi olmasini istiyorum
			{
			lenght_Control++;
			printf("-->HATA--< Tur Sayisi 0-9 Araliginda Olmalidir \n");
			}				
		}	
	}	
	else
	{
		printf("-->HATA--< Fazla Arguman Girdiniz \n");
		isdigit_Control++;	//Fazladan Arguman_Control gibi bir degisken tutmadim    	
	}
	
	if(isdigit_Control==0 && lenght_Control==0)
	{
		run_program(line_lenght,column_lenght,direction,random_Number,round_times);
	}
	else
	{
		printf(" %d Tane Hata Var\n",isdigit_Control+lenght_Control);
		printf(" Program Calismaz \n");
		printf(" Menuye Yonlendiriliyorsunuz \n");
	}
	}
	
	
//-----------------------------ARGUMAN ISLEMLERI BURADA BITIYOR-----------------------------------//
	
	int sayac=0;
	char menu_Select_Array[100]; 	// Menu'den Girilen Degerleri Kontrolu Icin Bir Dizi Tanimladim
	char line_Lenght_Array[100]; 	// Girilen Satiri Kontrol Icin Bir Dizi Tanimladim
	char column_Lenght_Array[100]; 	// Girilen Sutunu Kontrol Icin Bir Dizi Tanimladim
	char direction_Array[100]; 		// Girilen Yonu Kontrol Icin Bir Dizi Tanimladim
	char step_Number_Array[100]; 	// Girilen Adim Sayisini Kontrol Icin Bir Dizi Tanimladim
	
	int finish_loop=0;	
	while(finish_loop!=1) //Sadece 5.secmde finish_loop==1 oluyor.Olmadigi Surece Donmeye Devam Ediyor
	{
		printf("--> [1]: Uygulamayi Calistir \n");
		printf("--> [2]: Matris Olustur\n");
		printf("--> [3]: Direction\n");
		printf("--> [4]: Step Number\n");
		printf("--> [5]: Exit\n");
		
		printf("Lutfen Menu Seciminizi Yapiniz\n"); 
		scanf("%s",menu_Select_Array);	//Menu Secimi Aliyorum ve String(char) Dizime Atiyorum (Bosluga Kadar)
		
		int mistake_1=0;	//1. Hata Degiskeni	
		int menu_lenght=0;	//Menu_lengt kontrol degiskeni
		
		menu_lenght=strlen(menu_Select_Array);
		if(menu_lenght>1) // Menu Lenght 1'den fazla ise Arguman Hatasi
		{
			mistake_1++;
			printf("-->HATA--< Fazla Arguman Sayisi Girdiniz \n");	
		}
		else
		{
			if(!isdigit(menu_Select_Array[0])) // Girilen Deger Digit Degil ise isdigit hatasi
			{
				mistake_1++;
				printf("-->HATA--< Girilen Deger Isdigit'e Uymuyor\n");				
			}			
		}
		if(mistake_1==0)	// Hata Yoksa Sadece son kontrol kaldi
		{
			if((!(menu_Select_Array[0]>'0')|| !(menu_Select_Array[0]<'6'))) // Son kontrol olan, girilen deger  0-6 araliginda mi?
			{
				mistake_1++;	
				printf("HATA!! 1 ile 5 araliginda rakam giriniz \n");	// Aralikta degil ise hatayi verip en basa donuyor
			}
			else	//Hata yoksa Girilen Deger 1-5 araligindadir
			{
				switch(menu_Select_Array[0]) // Ilk degere gore switch ettik
				{					
					case '1' :
						if(line_lenght!=0 && column_lenght!=0 && ( (direction==1) || (direction==-1 ) )&&((random_Number>0)||(random_Number<101)) && round_times!=0){  // Degerler Bos ise Girmiyor
							run_program(line_lenght,column_lenght,direction,random_Number,round_times);	
							break;
						}
						else
						{
							printf("-->HATA--< Satir-Sutun-direction-Tur Verilerini Girdikten Sonra Programi Calistiriniz \n");
							printf("--> Menuye Yonlendiriliyorsunuz  <--\n");
						}											
						break;
					case '2' :	
						printf("Lutfen Matrisin Satir ve Sutun Sayisini Sirayla Giriniz ([1-5] arasi rakamlar) : \t");
						scanf("%s%s",line_Lenght_Array,column_Lenght_Array); // Diziye Atayip Kontrollerimi Yapiyorum
												
						int line_control=0;		//Line Kontrol Icin Bir Degisken
						int column_control=0;	//Column Kontrol Icin Bir Degisken
						line_control=strlen(line_Lenght_Array);	// Lenght'lerini Atiyorum
						column_control=strlen(column_Lenght_Array);
						
						if(line_control>3||column_control>3) // 3 Basamaklidan Fazla Olmasin
						{							
							printf("-->HATA--< Fazla Arguman Sayisi Girdiniz.(en fazla 3 basamakli Sayi Giriniz)\n");	
						}
						else
						{
							int kontrol_1;
							int mistake_2=0;
							
							for(kontrol_1=0;kontrol_1<line_control;kontrol_1++)
							{
								if(!isdigit(line_Lenght_Array[kontrol_1]))
								{
									printf("-->HATA--< Isdigit Hatasi Var\n");
									mistake_2++;				
								}
							}
							int kontrol_2;	
							for(kontrol_2=0;kontrol_2<column_control;kontrol_2++)
							{
								if(!isdigit(column_Lenght_Array[kontrol_2]))
								{								
									printf("-->HATA--< Isdigit Hatasi Var.\n");
									mistake_2++;				
								}
							}
							if(mistake_2==0)
							{
								column_lenght=atoi(column_Lenght_Array); // Hersey Dogruysa Atiyorum
								line_lenght=atoi(line_Lenght_Array);	// Hersey Dogruysa Atiyorum
								printf("--YENI MATRIX-- \nSatir Sayisi = %d , Sutun Sayisi = %d , direction = %d , Random Sayisi = %d , Tur Sayisi = %d\n\n",line_lenght,column_lenght,direction,random_Number,round_times);
							}		
						}			
						break;
					case '3' :	
							printf("Lutfen Matrisin Yonunu Belirleyiniz(1 veya -1 Gecerlidir) : \t");
							scanf("%s",&direction_Array);	 // Diziye Atayip Kontrollerimi Yapiyorum
							
							int mistake_3=0;
							int kontrol_3=strlen(direction_Array); //Lenght'ini Kontrol Icin Bir Degiskene Atiyorum
							
							if(kontrol_3>2)
							{	
								printf("-->HATA--< Lutfen  1 veya -1 Giriniz\n");		
								mistake_3++;
							}
							if(mistake_3==0)
							{
								int kontrol_4;
								kontrol_4=atoi(direction_Array); //Kontrol Icin Bir Degiskene Atiyorum
								
								if((kontrol_4==1)||(kontrol_4==-1))
								{
									direction=atoi(direction_Array); //Hersey Dogruysa Atiyorum
									printf("--YENI MATRIX-- \nSatir Sayisi = %d , Sutun Sayisi = %d , direction = %d , Random Sayisi = %d , Tur Sayisi = %d\n\n",line_lenght,column_lenght,direction,random_Number,round_times);
								}
								else
								{
									printf("--> HATA!!Lutfen  1 veya -1 Giriniz\n");
								}
							}							
						break;
					case '4' :
							printf("Lutfen Matrisin Tur Sayisini Belirleyiniz : \t");
							scanf("%s",&step_Number_Array);	// Diziye Atayip Kontrollerimi Yapiyorum
							
							int step_len;
							step_len=strlen(step_Number_Array);
							
							int kontrol_5;
							int mistake_4=0;							
							for(kontrol_5=0;kontrol_5<step_len;kontrol_5++)
							{
								while(mistake_4==0)
								{
									if(!isdigit(step_Number_Array[kontrol_5])) // Digit mi Diye Kontrol Ediyorum
									{
										printf("Isdigit Hatasi\n");
										mistake_4++;	
									}
									else
									{
										break;		// Degilse donguden cikiyor
									}
								}
							}
							if(mistake_4==0)
							{
								int kontrol_6;
								kontrol_6=atoi(step_Number_Array);
								
								if(kontrol_6<100)
								{
									round_times=atoi(step_Number_Array);	//Hersey Dogruysa Atiyorum
									printf("--YENI MATRIX-- \nSatir Sayisi = %d , Sutun Sayisi = %d , direction = %d , Random Sayisi = %d , Tur Sayisi = %d\n\n",line_lenght,column_lenght,direction,random_Number,round_times);
								}
								else
								{
									printf("--> HATA!!0-100 arasi Sayi Giriniz\n");
								}	
							}
							break;	
					case '5' :
							printf("Bizi Tercih Etiiginiz icin TESEKKURLER \n\n");
							finish_loop=1;	//Bir daha donguye girmesin diye degiskeni 1 e esitliyorum
							break;								
				}	
			}
		}
	}	
return 1;
}
