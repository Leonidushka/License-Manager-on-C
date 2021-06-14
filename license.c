#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
 
 
int main()
{
	system("chcp 1251 > nul");
	system("color F0");
	                                                                
	// Наименование продукта 
	char sk1[20] = "Склад 19"; 
	char mag1[20] = "Магазин 18";
	char kol1[20] = "Колонка 17"; 
	char obl1[20] = "Облачко 21"; 
	int choose;
	int licdd,licmm,licyyyy; // даты лицензии в формате дд:мм:гггг
	
	
	int r,x;

	
	printf("\t Выберите продукт: \n" );
	printf("\t 1. Магазин 18 \n" );
	printf("\t 2. Склад 19 \n" );
	printf("\t 3. Колонка 17 \n" );
	printf("\t 4. Облачко 21 \n" );
	
	scanf("\t %d", &choose);
	
	// в current мы вкладываем выбранный продукт
	char current[20] = "";
	switch(choose){  
	case 1:  
	strcpy(current, mag1);
	break;
	case 2:  
	strcpy(current, sk1);
	break;
	case 3:  
	strcpy(current, kol1);
	break;
	case 4:  
	strcpy(current, obl1);
	break;
	}
	
	//printf("\t %s \n", current);
	// задаем буквы для генерации кода активации и разделитель
	
	char alphabet[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char razd = '-';
	
	char id[23];
	int block,sym;
	int idx = 0;
	for(block = 0; block < 4; block++)
	{
		for(sym = 0; sym < 5; sym++)
		{
			id[idx] = alphabet[rand() % 26];
			idx = idx + 1;
		}
		
		if(block < 3) {
			id[idx] = razd;
			idx++;
		}
	}
	
	printf("\t Введите срок окончания действия лицензии в формат ДД-ММ-ГГГГ: \n");
	scanf("\t  %02d-%02d-%04d", &licdd, &licmm, &licyyyy);
	printf("\t Срок окончания действия лицензии: \n");
	printf("\t %02d-%02d-%04d \n", licdd, licmm, licyyyy);
	printf("\t %s \n",  current);
	printf("\n");
	printf("\t Ваш код активации: \n");
	printf("\t %23s \n" , id);
	
	

	
	
	 FILE *file1;
     file1=fopen("Documents4.txt", "wt");
     fprintf(file1," Ваш продукт: %s \n Срок окончания лицензии: %02d-%02d-%04d \n Ваш код активации: %23s",current, licdd, licmm, licyyyy, id);
     fclose(file1); 
      
    

	system("pause");
	return 0;
}


