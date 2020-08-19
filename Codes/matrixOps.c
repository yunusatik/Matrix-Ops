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

int run_program(int line_lenght,int column_lenght,int direction,int random_Number,int round_times)
{		
	int **matrix;  																//2 Boyutlu Diziyi Tanimliyoruz
    srand((unsigned int)time(NULL));   											//Surekli Degisen random icin tanimlandi 
    matrix=malloc(line_lenght*sizeof(int**));  									//Bellekte Satir Sayisi Kadar Yatay Alanlar Acmak     
    
    printf("Satir Sayisi = %d , Sutun Sayisi = %d , direction = %d , Random Sayisi = %d , Tur Sayisi = %d\n\n",line_lenght,column_lenght,direction,random_Number,round_times);
    printf("--------------FIRST----------------\n");
    
    int i, j; 																	//For Degiskenleri
    for (i = 0; i < line_lenght; i++)											//Ilk basta Satir Sayisi kadar alan acabilmek icin ilk for ile satirdan donuyoruz.
	{
        *(matrix+i) = malloc(column_lenght*sizeof(int*));   					//Bellekte Sutun Sayisi Kadar Dikey Alanlar Acmak
	        for (j = 0; j < column_lenght; j++)									// Simdide sutun sayisinda gezerek satirlarin iclerini tek tek random sayi ile dolduracagiz
			{
	            *(*(matrix+i) + j) = rand() % random_Number;  					// Matris'in Icine Random Sayi Atama			 
	            printf("\t%d\t",*(*(matrix+i) + j));							// Atadigimiz Matrisi Pointer Aritmetigi Kullanarak Bastiriyoruz
	        }
        printf("\n"); 															// 1.Satir Bittikten Sonra 2.Satira Geçmek Icin Atliyoruz
    }
    
    int a = 0; 																	//While ici Degisken
    
    //-1 ve 1 Icin Ayni Algoritmayi Kullandim Lakin Farkli Konumlardan Baslayarak Dondum(Kendimi Gelistirmek Icin Denedim)
    
    if(direction==1) 															// Saga Donus 
	{
		printf("\t\t>>>>>\n");
		printf("\t\t^   v\n");
		printf("\t\t^   v\n");
		printf("\t\t%d Defa\n",round_times);
		printf("\t\t^   v\n");
		printf("\t\t^   v\n");
		printf("\t\t<<<<<\n");
		
    	while (a < round_times) 												// Tur Sayisi Kadar Donuyoruz
		{ 
	    	int current_Number,next_Number; 									// Degerleri Tutacagimiz Degiskenler
	   		int x,y,z,t; 														// For'larimizin Degiskenleri
	   		
	        //Ilk degeri Tuttugumuz Satir (ILK SAYIMIZ OLARAK 1.SATIRIN SONUNCU SUTUNUNU ALDIM)
	        current_Number =*(*(matrix) + (column_lenght-1 ) );  
	        for (x = 0; x < line_lenght-1; x++) 								//(Satirlar DEGISKEN ,Sonuncu sutun SABIT)
			{																	//		_____
	            next_Number = *(*(matrix+(x+1)) + (column_lenght-1 )) ;			//		|	V
	            *(*(matrix+(x+1)) + (column_lenght-1) ) = current_Number;		//		|   V
	            current_Number = next_Number;	        						//		|___V    
	        }																	//		Asagi Atama	              
	        
	        for (y = column_lenght-1; y > 0; y--) 								//(Sonuncu satir SABIT ,Sutunlar DEGISKEN)
			{	        														//	    _____
	            next_Number = *(*(matrix+(line_lenght-1))+(y-1));				//		|	|
	            *(*(matrix+(line_lenght-1))+(y-1)) = current_Number;			//		|   |
	            current_Number = next_Number;	            					//		<<<<<	
	        }   																//	    Sola Atama				
	            
	        for (z = line_lenght-1; z > 0; z--)									//(Satirlar DEGISKEN ,Ilk sutun SABIT)
			{																	//	     ____
	            next_Number = *(*(matrix+(z-1))+0);								//		^	|
	            *(*(matrix+(z-1))+0) = current_Number;							//		^	|
	            current_Number = next_Number;	      						    //		^___|     
	        } 																	//		Yukari Atama 
	        
	        for (t = 0; t < column_lenght; t++) 								//(Ilk satir SABIT ,Sutunlar DEGISKEN)	
			{																	//		>>>>>	
	            next_Number = *(*(matrix+0)+(t+1));								//		|	|	
	            *(*(matrix+0)+(t+1)) = current_Number;							//		|	|	
	            current_Number = next_Number;	       							//		|___|	     
	        }																	//		Saga Atama	
        a++;        
    	}
	}
	else //Sola Donus
	{
		printf("\t\t<<<<<\n");
		printf("\t\tv   ^\n");
		printf("\t\tv   ^\n");
		printf("\t\t%d Defa\n",round_times);
		printf("\t\tv   ^\n");
		printf("\t\tv   ^\n");
		printf("\t\t>>>>>\n");
		
		while (a < round_times) 												//(ILK SAYIMIZ OLARAK 1.SATIRIN ILK SUTUNUNUNU ALDIM)
		{ // 
	    	int current_Number,next_Number;
	   		int x,y,z,t;   	
	   		
	        //Ilk degeri Tuttugumuz Satir (ILK SAYIMIZ OLARAK 1.SATIRIN 1.SUTUNUNU ALDIM)
	        current_Number =*(*(matrix+0)+0);   								
	        for (x = 1; x < line_lenght; x++)									//(Satirlar DEGISKEN ,Ilk sutun SABIT)    
			{																	//	     ____
	            next_Number = *(*(matrix+x)+0);									//		V	|
	            *(*(matrix+x)+0) = current_Number;								//		V	|
	            current_Number = next_Number;									//		V___|            
	        }																	//		Asagi Atama
	        
	        for (y =0; y <column_lenght-1 ; y++) 								//(Son satir SABIT ,Sutunlar DEGISKEN)
			{																	//		_____
	            next_Number = *(*(matrix+(line_lenght-1))+(y+1));				//		|	|
	            *(*(matrix+(line_lenght-1))+(y+1))= current_Number;				//		|	|
	            current_Number = next_Number;	            					//		>>>>>
	        }    																//		Saga Atama
	        
	        for (z = line_lenght-1; z > 0; z--)									//(Satirlar DEGISKEN ,Son sutun SABIT)
			{																	//		_____
	            next_Number = *(*(matrix+(z-1))+(column_lenght-1));				//		|	 ^
	            *(*(matrix+(z-1))+(column_lenght-1))= current_Number;			//		|    ^
	            current_Number = next_Number;	            					//		|____^
	        }        															//		Yukari Atama
	        
	        for (t = column_lenght-1; t >0 ; t--)								//(Ilk satir SABIT ,Sutunlar DEGISKEN)
			{																	//		<<<<<
	            next_Number = *(*(matrix+0)+(t-1));								//		|	|
	            *(*(matrix+0)+(t-1)) = current_Number;							//		|	|
	            current_Number = next_Number;	            					//		|___|	
	        }																	//		Sola Atama
        a++;      
    	}
	}
	

    printf("\n");
    printf("---------------LAST---------------\n");
    
    int line;
    for (line = 0; line < line_lenght; line++)
	{  		      													
    	int column;								  			 					//		  
        for (column = 0; column < column_lenght; column++)						//
		{													  					//   	 Cevrilmis
            printf("\t%d\t",*(*(matrix+line)+column)); 							//  	  Matrisin
        }									   									//		Bastirilmasi
        printf("\n");						   									//
    }										   									//
    
    int p;
    for(p=0;p<line_lenght;p++)
	{																			//		Matrix'in Tum Elemanlarini  
    	free(matrix[p]);														//	 		Tek Tek Memory'e
	}    																		//			 Geri Veriyoruz
	random_Number=100; 							
    free(matrix);																//			Son Olarak Matrixi Bosaltiyoruz
    return 1;
	}
   




