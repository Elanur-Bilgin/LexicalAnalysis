#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BOYUT 100

FILE *okunacak;
FILE *output;
char nextchar;
int satir=1,sutun=0;
char lexeme[BOYUT];
char harfKontrol[BOYUT];
int isKeyword(char *);
int isSymbol (char );
void dizi_sifirla(char*);
void karakter_buyut();
int karakter_boyut_kontrol();
void digit_identifier_ayir();
char* dizi_ata(char[]);
int main()
{
    int i=0,k=0;
    char bosluk;
    char okunacak_dosya_adi[20];
    char output_dosya_adi[20];
    char dosya_tipi[]=".txt";
    char dosya_tipi_2[]=".lex";

    for(i=0; i<20; i++)
    {
        okunacak_dosya_adi[i]=NULL;
    }

    printf("Dosya adini giriniz :");
    scanf("%s",okunacak_dosya_adi);
    for(i=0; i<20; i++)
    {
        output_dosya_adi[i]=okunacak_dosya_adi[i];
    }

    for( i=0; i<20; i++)
    {
        if(okunacak_dosya_adi[i]==NULL)
        {
            okunacak_dosya_adi[i]=dosya_tipi[k];
            output_dosya_adi[i]=dosya_tipi_2[k];
            k++;
            if(k==4)
                break;
        }
    }
    if((okunacak=fopen(okunacak_dosya_adi,"r"))==NULL)
        printf("Okunacak dosya acilamadi!!!");
    else
    {
        if((output=fopen(output_dosya_adi,"w"))==NULL)
            printf("Output dosyasi acilamadi !!!");
        else
        {
            printf("Output dosyasi basariyla acilmistir!!! \n %s \n\n",output_dosya_adi);
            while(!feof(okunacak))
            {
                nextchar=getc(okunacak);
                bosluk=getc(okunacak);
                if((nextchar=='C' || nextchar=='c') && (bosluk ==' ' || bosluk=='\n'))
                {
                    ungetc(bosluk,okunacak);
                    while(nextchar!='\n')
                    {
                        nextchar=getc(okunacak);
                    }
                    if(nextchar=='\n')
                        satir++;
                }
                else
                {
                    ungetc(bosluk,okunacak);
                    if(isalnum(nextchar))
                    {
                        i=0;
                        dizi_sifirla(lexeme);
                        while(isalnum(nextchar) || nextchar=='.' || nextchar=='_')
                        {
                            lexeme[i]=nextchar;
                            i++;
                            nextchar=getc(okunacak);
                        }
                        ungetc(nextchar,okunacak);
                        karakter_buyut(lexeme);
                        if(isKeyword(harfKontrol)==1)
                        {
                            printf("Keyword (%s) \t",lexeme);
                            fprintf(output,"\n Keyword (%s) \t",lexeme);
                        }
                        else if(isdigit(lexeme[0]))
                        {
                            if( karakter_boyut_kontrol(lexeme)==1)
                            {
                                printf("%d. satirda HATA!!! Karakter uzunlugu gecersiz...\n",satir);
                                fprintf(output,"%d. satirda HATA!!! Karakter uzunlugu gecersiz...\n",satir);
                                dizi_sifirla(lexeme);
                            }
                            else
                            {
                                digit_identifier_ayir();
                            }
                        }
                        else
                        {
                            if( karakter_boyut_kontrol(lexeme)==1)
                            {
                                printf("%d. satirda HATA!!! Karakter uzunlugu gecersiz...\n",satir);
                                fprintf(output,"%d. satirda HATA!!! Karakter uzunlugu gecersiz...\n",satir);
                                dizi_sifirla(lexeme);
                            }
                            else
                            {
                                printf("Identifier (%s) \t ",lexeme);
                                fprintf(output,"Identifier (%s) \t",lexeme);
                            }
                        }
                    }
                    else if(isSymbol(nextchar)==1)
                    {
                        continue;
                    }
                    else if(nextchar !=' ' && nextchar!='\n')
                    {
                        printf("\n%d . satirda Unknown Character... \n",satir);
                        fprintf(output,"%d . satirda Unknown Character... \t",satir);
                    }
                    else if(nextchar=='\n')
                        {satir++;
                          printf("\n\n");
                        }
                }
            }
        }
        fclose(output);
    }
    fclose(okunacak);
    return 0;
}
int isKeyword(char karakter[])
{
    if(strcmp("PROGRAM",karakter)==0 || strcmp("INTEGER",karakter)==0|| strcmp("EXTERNAL",karakter)==0 ||
            strcmp("COMMON",karakter)==0 || strcmp("PRINT",karakter)==0 ||strcmp("READ",karakter)==0 ||
            strcmp("CALL",karakter)==0 ||strcmp("END",karakter)==0 ||strcmp("SUBROUTINE",karakter)==0 ||
            strcmp("DATA",karakter)==0 ||strcmp("IF",karakter)==0 ||strcmp("THEN",karakter)==0 ||strcmp("REAL",karakter)==0 ||
            strcmp("DO",karakter)==0 ||strcmp("CONTINUE",karakter)==0 ||strcmp("STOP",karakter)==0 ||
            strcmp("DOUBLE",karakter)==0 ||strcmp("FUNCTION",karakter)==0 ||
            strcmp("ELSE",karakter)==0 ||strcmp("RETURN",karakter)==0 ||strcmp("PRECISION",karakter)==0)
        return 1;
    else return 0;
}
int isSymbol (char karakter)
{
    char mantiksal[3];
    char ilkleme_dizisi[BOYUT];
    int i=0,sonuc=0,k=0,x=0;
    switch(karakter)
    {
    case '=':
        printf("AssignmentOp \t");
        fprintf(output,"AssignmentOp \t");
        sonuc=1;
        break;
    case '/':
        dizi_sifirla(ilkleme_dizisi);
        nextchar=getc(okunacak);
        while(nextchar!=' ' && nextchar!='\n' && nextchar!='/' && nextchar!='(')
        {
            ilkleme_dizisi[k]=nextchar;
            nextchar=getc(okunacak);
            k++;
        }
        if(nextchar =='(')
        {
            ungetc(nextchar,okunacak);
        }
        if(nextchar==' '|| nextchar=='\n' || nextchar=='(')
        {
            printf("DivideOp\t");
            fprintf(output,"DivideOp\t");
            SlashIciKontrol(ilkleme_dizisi);

        }
        else
        {
            ilkleme_dizisi[(k-1)]==NULL;
            printf("Symbol (/)\t");
            fprintf(output,"Symbol (/)\t");
            SlashIciKontrol(ilkleme_dizisi);
            printf("Symbol (/)\t");
            fprintf(output,"Symbol (/)\t");
        }
        sonuc=1;
        break;
    case ',':
        printf("Symbol (,) \t");
        fprintf(output,"Symbol (,) \t");
        sonuc=1;
        break;
    case '*':
        nextchar=getc(okunacak);
        if(nextchar=='*')
        {
            printf("Exponentiation \t");
            fprintf(output,"Exponentiation \t");
        }
        else
        {
            ungetc(nextchar,okunacak);
            printf("Asteriks \t");
            fprintf(output,"Asteriks \t");
        }
        sonuc=1;
        break;
    case '(':
        printf("LeftParan \t");
        fprintf(output,"LeftParan \t");
        sonuc=1;
        break;
    case ')':
        printf("RightParan \t");
        fprintf(output,"RightParan \t");
        sonuc=1;
        break;
    case '+':
        printf("Add \t");
        fprintf(output,"Add \t");
        sonuc=1;
        break;
    case '\'' :
        printf("Symbol ( ' )\t");
        fprintf(output,"Symbol ( ' )\t");
        nextchar=getc(okunacak);
        printf("String (");
        fprintf(output,"String (");
        while(nextchar!= '\'' && nextchar !='\n')
        {
            printf("%c",nextchar);
            fprintf(output,"%c",nextchar);
            nextchar=getc(okunacak);
        }
        if(nextchar=='\n')
            satir++;
        printf(")\t");
        fprintf(output,")\t");
        if(nextchar=='\'')
        {
            printf("Symbol( ' )");
            fprintf(output,"Symbol( ' )");
        }
        else
        { printf("\n%d . satirda HATA!!! String icin tirnak kapatilmamistir...\n",satir-1);
          fprintf(output,"\n%d . satirda HATA!!! String icin tirnak kapatilmamistir...\n",satir-1);
        }
        sonuc=1;
        break;
    case '-' :
        printf("Symbol (-) \t");
        fprintf(output,"Symbol (-) \t");
        sonuc=1;
        break;
    case '.' :
        for(i=0; i<3; i++)
        {
            mantiksal[i]=getc(okunacak);
        }
        if(strcmp("EQ.",mantiksal)==0)
        {
            printf("EqualOp \t");
            fprintf(output,"EqualOp \t");
            sonuc=1;
            break;
        }
        if(strcmp("NE.",mantiksal)==0)
        {
            printf("NotEqualOp \t");
            fprintf(output,"NotEqualOp \t");
            sonuc=1;
            break;
        }
        if(strcmp("GT.",mantiksal)==0)
        {
            printf("GreaterThanOp \t");
            fprintf(output,"GreaterThanOp \t");
            sonuc=1;
            break;
        }
        if(strcmp("GE.",mantiksal)==0)
        {
            printf("GreaterThanOrEqualOp \t");
            fprintf(output,"GreaterThanOrEqualOp \t");
            sonuc=1;
            break;
        }
        if(strcmp("LT.",mantiksal)==0)
        {
            printf("LessThanOp \t");
            fprintf(output,"LessThanOp \t");
            sonuc=1;
            break;
        }
        if(strcmp("LE.",mantiksal)==0)
        {
            printf("LessThanOrEqualOp \t");
            fprintf(output,"LessThanOrEqualOp \t");
            sonuc=1;
            break;
        }
        break;
    }
    return sonuc;
}
void dizi_sifirla(char* dizi)
{
    int i=0;
    for(i=0; i<BOYUT; i++)
    {
        dizi[i]=NULL;
    }
}
void karakter_buyut()
{
    int fark,i=0;
    char karakter;
    karakter=lexeme[i];
    fark='a'-'A';
    dizi_sifirla(harfKontrol);
    while(lexeme[i]!='\0')
    {
        if(islower(karakter))
        {
            karakter=karakter-fark;
        }
        harfKontrol[i]=karakter;
        i++;
        karakter=lexeme[i];
    }
}
int karakter_boyut_kontrol()
{
    int m=0;
    while(lexeme[m]!='\0')
    {
        m++;
    }
    if(m>31)
        return 1;
    else
        return 0;
}
void digit_identifier_ayir()
{
    int i=0,kontrol=0;
    kontrol=noktaKontrol(lexeme);
    /*while(lexeme[i]!='.' && lexeme[i]!='\0')
    {
        i++;
    }*/

    if(kontrol==0)
    {
    printf("ConstantNumber(");
    fprintf(output,"ConstantNumber ( ");
    }
    else
        {
            printf("RealNumber(");
            fprintf(output,"RealNumber ( ");
        }
    while(isdigit(lexeme[i]) || lexeme[i]=='.' || lexeme[i]!='\0')
    {
        printf("%c",lexeme[i]);
        fprintf(output,"%c",lexeme[i]);
        i++;
    }
    printf(") \t");
    fprintf(output,") \t");
    if(lexeme[i]!='\0')
    {
        printf("Identifier (");
        fprintf(output," Identifier (");
        while(lexeme[i]!='\0')
        {
            printf("%c",lexeme[i]);
            fprintf(output,"%c",lexeme[i]);
            i++;
        }
        printf(")\t");
        fprintf(output," )\t");
    }
}
void SlashIciKontrol(char ilkleme_dizisi[])
{
    int kontrol=0;
    if(isdigit(ilkleme_dizisi[0]))
    {
        kontrol=noktaKontrol(ilkleme_dizisi);
        if(kontrol==0)
        {
        printf("ConstantNumber (%s) \t",ilkleme_dizisi);
        fprintf(output,"ConstantNumber (%s) \t",ilkleme_dizisi);
        }
        else
            {
              printf("RealNumber (%s) \t",ilkleme_dizisi);
              fprintf(output,"RealNumber (%s) \t",ilkleme_dizisi);
            }
    }
    else if( (ilkleme_dizisi[0]=='-' && isdigit(ilkleme_dizisi[1])))
    {
         kontrol=noktaKontrol(ilkleme_dizisi);
        if(kontrol==0)
        {
        printf("Symbol (-)\t");
        printf("ConstantNumber (%s)\t",dizi_ata(ilkleme_dizisi));
        fprintf(output,"Symbol (-)\t");
        fprintf(output,"ConstantNumber (%s)\t",dizi_ata(ilkleme_dizisi));
        }
        else
        {
            printf("Symbol (-)\t");
            printf("RealNumber (%s)\t",dizi_ata(ilkleme_dizisi));
            fprintf(output,"Symbol (-)\t");
            fprintf(output,"RealNumber (%s)\t",dizi_ata(ilkleme_dizisi));
        }
    }
    else if(isalpha(ilkleme_dizisi[0]))
    {
        printf("Identifier (%s)\t",ilkleme_dizisi);
        fprintf(output,"Identifier (%s)\t",ilkleme_dizisi);
    }
    else if( (ilkleme_dizisi[0]=='-' && isalpha(ilkleme_dizisi[1])))
    {
        printf("Symbol (-)\t");
        printf("Identifier (%s)\t",dizi_ata(ilkleme_dizisi));
        fprintf(output,"Symbol (-)\t");
        fprintf(output,"Identifier (%s)\t",dizi_ata(ilkleme_dizisi));
    }
}
char * dizi_ata(char ilkleme_dizisi[])
{
    char dizi[BOYUT];
    dizi_sifirla(dizi);
    int i=0;
    for(i=0; i<BOYUT-1; i++)
    {
        dizi[i]=ilkleme_dizisi[i+1];
    }
    return dizi;
}
int noktaKontrol(char dizi[])
{
    int i=0,kontrol=0;
    while(dizi[i]!='.' && dizi[i]!='\0')
    {
        i++;
    }
    if(dizi[i]=='.')
        kontrol=1;
    return kontrol;
}





