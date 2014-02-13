#include <stdio.h>
#include <stdlib.h>
#define boyut 5
//dosyamiz txt formatinda olmalidir
void sekil_olustur(int [][boyut]);
int sayi_al();
int main()
{
    FILE *dosya;
    int i,j;
    int satir,sutun;
    int cevap_dosya[boyut][boyut]= {{0}};
    int cevap_kontrol[boyut][boyut]= {{0}};
    int kullanici_matris[boyut][boyut]= {{0}};
    int static karsilastirici_matris[boyut][boyut]= {{0}};
    char isaret;
    int ahmet=0;
    int gul=boyut*boyut;

    if((dosya=fopen("cevap1.txt","r"))!=NULL)
    {
        for(i=0; i<boyut; i++)
        {
            for(j=0; j<boyut; j++)
            {
                fscanf(dosya,"%d",&cevap_dosya[i][j]);
            }
        }

        fclose(dosya);

       for(i=0; i<boyut; i++)
        {
            for(j=0; j<boyut; j++)
            {
                if(cevap_dosya[i][j]==1)
                    cevap_kontrol[i][j]=boyut+1;
            }
        }
        sekil_olustur(cevap_kontrol);

        for(i=0; i<boyut; i++)
        {
            for(j=0; j<boyut; j++)
            {
                printf(" %d ",kullanici_matris[i][j]);
            }
            printf("\n");
        }
        for(i=0; i<boyut; i++) // 0'a atama yapýyorum//
        {
            for(j=0; j<boyut; j++)
            {
                karsilastirici_matris[i][j]=48;
            }
        }

        do
        {

            printf("lutfen satir sayisini giriniz");
            satir=sayi_al();
            printf("lutfen sutun sayisini giriniz");
            sutun=sayi_al();

            do
            {
                printf("lutfen isaretinizi giriniz A:ac-B:bayrak\n");
                fflush(stdin);
                scanf("%c",&isaret);
                if(isaret!='A' && isaret!='B')
                    printf("Yanlis bir harf girdiniz\n");
            }
            while(isaret!='A' && isaret!='B');

            if(isaret=='B')//bayrak icin atama//
                karsilastirici_matris[satir-1][sutun-1]=15;
            else //acma ve atama
                if(cevap_kontrol[satir-1][sutun-1]==1)
                    karsilastirici_matris[satir-1][sutun-1]=49;//1den itibaren ascii kodlari//
                else if(cevap_kontrol[satir-1][sutun-1]==2)
                    karsilastirici_matris[satir-1][sutun-1]=50;
                else if(cevap_kontrol[satir-1][sutun-1]==3)
                    karsilastirici_matris[satir-1][sutun-1]=51;
                else if(cevap_kontrol[satir-1][sutun-1]==4)
                    karsilastirici_matris[satir-1][sutun-1]=52;
                else if(cevap_kontrol[satir-1][sutun-1]==5)
                    karsilastirici_matris[satir-1][sutun-1]=53;
                else if(cevap_kontrol[satir-1][sutun-1]==6)
                    karsilastirici_matris[satir-1][sutun-1]=54;
                else if(cevap_kontrol[satir-1][sutun-1]==7)
                    karsilastirici_matris[satir-1][sutun-1]=55;
                else if(cevap_kontrol[satir-1][sutun-1]==8)
                    karsilastirici_matris[satir-1][sutun-1]=56;
                else if(cevap_kontrol[satir-1][sutun-1]==0)
                {
                    karsilastirici_matris[satir-1][sutun-1]=176;
                    for(i=satir-1; i<boyut; i++)
                    {
                        for(j=sutun-1; j<boyut; j++)
                        {
                            if(cevap_kontrol[i][j]==0)
                            {
                                karsilastirici_matris[i][j]=176;
                            }
                            else
                            {
                                if(cevap_kontrol[i][j]==1)
                                    karsilastirici_matris[i][j]=49;//1den itibaren ascii kodlari//
                                else if(cevap_kontrol[i][j]==2)
                                    karsilastirici_matris[i][j]=50;
                                else if(cevap_kontrol[i][j]==3)
                                    karsilastirici_matris[i][j]=51;
                                else if(cevap_kontrol[i][j]==4)
                                    karsilastirici_matris[i][j]=52;
                                else if(cevap_kontrol[i][j]==5)
                                    karsilastirici_matris[i][j]=53;
                                else if(cevap_kontrol[i][j]==6)
                                    karsilastirici_matris[i][j]=54;
                                else if(cevap_kontrol[i][j]==7)
                                    karsilastirici_matris[i][j]=55;
                                else if(cevap_kontrol[i][j]==8)
                                    karsilastirici_matris[i][j]=56;
                                break;
                            }
                        }

                    }
                    for(i=satir-1; i>=0; i--)
                    {
                        for(j=sutun-1; j>=0; j--)
                        {
                            if(cevap_kontrol[i][j]==0)
                            {
                                karsilastirici_matris[i][j]=176;
                            }
                            else
                            {
                                if(cevap_kontrol[i][j]==1)
                                    karsilastirici_matris[i][j]=49;//1den itibaren ascii kodlari//
                                else if(cevap_kontrol[i][j]==2)
                                    karsilastirici_matris[i][j]=50;
                                else if(cevap_kontrol[i][j]==3)
                                    karsilastirici_matris[i][j]=51;
                                else if(cevap_kontrol[i][j]==4)
                                    karsilastirici_matris[i][j]=52;
                                else if(cevap_kontrol[i][j]==5)
                                    karsilastirici_matris[i][j]=53;
                                else if(cevap_kontrol[i][j]==6)
                                    karsilastirici_matris[i][j]=54;
                                else if(cevap_kontrol[i][j]==7)
                                    karsilastirici_matris[i][j]=55;
                                else if(cevap_kontrol[i][j]==8)
                                    karsilastirici_matris[i][j]=56;
                                break;
                            }
                        }
                    }


                }

            if(cevap_dosya[satir-1][sutun-1]==1 && isaret=='A')
            {
                for(i=0; i<boyut; i++)
                {
                    for(j=0; j<boyut; j++)
                    {
                        if(cevap_dosya[i][j]==1)
                        {
                            karsilastirici_matris[i][j]=233;
                        }

                        printf("%c",karsilastirici_matris[i][j]);
                    }
                    printf("\n");
                }
                printf("mayina bastin kaybettin!");
                return 0 ;
            }
            for(i=0; i<boyut; i++)
            {
                for(j=0; j<boyut; j++)
                {
                    printf("%c",karsilastirici_matris[i][j]);
                }
                printf("\n");
            }

            ahmet=0;
            for(i=0; i<boyut; i++)
            {
                for(j=0; j<boyut; j++)
                {
                    if(cevap_kontrol[i][j]==1 && karsilastirici_matris[i][j]==49)
                        ahmet++;
                    if(cevap_kontrol[i][j]==2 && karsilastirici_matris[i][j]==50)
                        ahmet++;
                    if(cevap_kontrol[i][j]==3 && karsilastirici_matris[i][j]==51)
                        ahmet++;
                    if(cevap_kontrol[i][j]==4 && karsilastirici_matris[i][j]==52)
                        ahmet++;
                    if(cevap_kontrol[i][j]==5 && karsilastirici_matris[i][j]==53)
                        ahmet++;
                    if(cevap_kontrol[i][j]==6 && karsilastirici_matris[i][j]==54)
                        ahmet++;
                    if(cevap_kontrol[i][j]==7 && karsilastirici_matris[i][j]==55)
                        ahmet++;
                    if(cevap_kontrol[i][j]==8 && karsilastirici_matris[i][j]==56)
                        ahmet++;
                    if(cevap_dosya[i][j]==1 && karsilastirici_matris[i][j]==15)
                        ahmet++;
                    if(cevap_kontrol[i][j]==0 && karsilastirici_matris[i][j]==176)
                        ahmet++;
                }
            }


        }
        while(ahmet!=gul);
        printf("tebrikler kazandiniz!");
    }
    else
    {
        printf("dosya acilamadi\n");
    }
    return 0;
}

void sekil_olustur(int cevap_kontrol[boyut][boyut])
{
    int i,j;
    int sayac=0;

    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            if(cevap_kontrol[i][j]==0)
            {
                if(cevap_kontrol[i][j+1]==boyut+1)
                    sayac++;
                if(cevap_kontrol[i+1][j]==boyut+1)
                    sayac++;
                if(cevap_kontrol[i][j-1]==boyut+1)
                    sayac++;
                if(cevap_kontrol[i-1][j]==boyut+1)
                    sayac++;
                if(cevap_kontrol[i-1][j-1]==boyut+1)
                    sayac++;
                if(cevap_kontrol[i+1][j+1]==boyut+1)
                    sayac++;
                if(cevap_kontrol[i-1][j+1]==boyut+1)
                    sayac++;
                if(cevap_kontrol[i+1][j-1]==boyut+1)
                    sayac++;

                cevap_kontrol[i][j]=sayac;
            }
            sayac=0;
        }
    }

    /*for(i=0; i<boyut; i++)//cevap anahtarimiz
    {
        for(j=0; j<boyut; j++)
        {
            if(cevap_kontrol[i][j]==boyut+1)
                printf("X");
            else
                printf("%d",cevap_kontrol[i][j]);
        }
        printf("\n");
    }*/


    /*for(i=0;i<boyut;i++)
    {
       for(j=0;j<boyut;j++)
       {
        printf("%d",cevap_kontrol[i][j]);
       }
       printf("\n");
    }*/

}
int sayi_al()
{
    int sayi;
    do
    {
        scanf("%d",&sayi);
        if(sayi<1 || sayi>boyut)
            printf("aralik disi girdiniz bastan giriniz\n");

    }
    while(sayi<1 || sayi>boyut);


    return sayi;
}
