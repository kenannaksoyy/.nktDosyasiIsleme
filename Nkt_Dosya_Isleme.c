#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct sdosya
{
    char dosyaisimi[100];
    char nktdosyaisimi[100];
    char dosyayolu[100];
    int satirsayisi;
    int yazilannoktasayisi;
    char noktalar[100];
    char noktasayisiuyumludosya[200];
    char noktasayisiuyumludosyaklasoryolu[200];
    int satirsayisi2;
    int bosluksayisi;
    char uyumludosya[100];
    char uyumludosyaklasoryolu[100];
    int satirsayisi3;
    int satirsayisi4;
    int satirsayisi5;


} dsy[100000];


struct nokta
{
    float x;
    float y;
    float z;
    int r;
    int g;
    int b;
    int taranannoktasayisi;

} nkt[100000];

int main()
{

    DIR *proglab;
    struct dirent* bulunandosyalar;
    int dosyasayac=0;
    proglab = opendir("C:\\Users\\User\\Desktop\\proglab");
    FILE *nktdosya;

    if(proglab != NULL)
    {

        while((bulunandosyalar = readdir(proglab)) != NULL)
        {
            strcpy(dsy[dosyasayac].dosyaisimi,bulunandosyalar->d_name);
            dosyasayac++;
        }
    }
    else
    {
        printf("Klasore Girmedi");
    }
    int i;
    int uzunluk;
    int nktsayac=0;
    if((nktdosya=fopen("Output.nkt","w"))!=NULL)
    {
        fprintf(nktdosya,"Klasorun icindeki dosyalar\n");
    }
    fclose(nktdosya);
    printf("Klasorun icindeki tum dosyalar\n");
    for(i=0; i<dosyasayac; i++)
    {
        if((nktdosya=fopen("Output.nkt","a"))!=NULL)
        {
            fprintf(nktdosya,"%s\n",dsy[i].dosyaisimi);
        }
        fclose(nktdosya);
        printf("%s\n",dsy[i].dosyaisimi);
        uzunluk =strlen(dsy[i].dosyaisimi);
        if(dsy[i].dosyaisimi[uzunluk-1-2]=='n'&& dsy[i].dosyaisimi[uzunluk-1-1]=='k' && dsy[i].dosyaisimi[uzunluk-1]=='t')
        {
            strcpy(dsy[nktsayac].nktdosyaisimi,dsy[i].dosyaisimi);
            nktsayac=nktsayac+1;
        }


    }
    printf("\n");
    printf(".nkt uzantili dosyalar\n");
    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
    {
        fprintf(nktdosya,"\n.nkt uzantili dosyalar\n");
    }
    fclose(nktdosya);
    int j;
    int sayacpntr=0;

    for(j=0; j<nktsayac; j++)
    {
        if((nktdosya=fopen("Output.nkt","a"))!=NULL)
        {
            fprintf(nktdosya,"%s\n",dsy[j].nktdosyaisimi);
        }
        fclose(nktdosya);

        printf("%s\n",dsy[j].nktdosyaisimi);
    }
    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
    {
        fprintf(nktdosya,".nkt uzantili olmayan dosyalar cikarildi\n");
    }
    fclose(nktdosya);

    printf(".nkt uzantili olmayan dosyalar cikarildi\n");


    char klasoryolu[100]="C:\\Users\\User\\Desktop\\proglab\\";
    FILE *dosya;
    FILE *dosyayayaz;

    int x1;

    for(x1=0; x1<nktsayac; x1++)
    {
        strcpy(dsy[x1].dosyayolu,klasoryolu);
        strcat(dsy[x1].dosyayolu,dsy[x1].nktdosyaisimi);

    }

    printf("\n");
    int secim;
    printf("Dosya kontrolu icin 1'e basiniz\n");
    printf("En yakin en uzak icin 2'e basiniz\n");
    printf("Kup icin 3'e basiniz\n");
    printf("Kure icin 4'e basiniz\n");
    printf("Nokta uzakliklari icin 5'e basiniz\n");
    printf("Programdan cikmak icin 6'ya basiniz\n");
    printf("\n");
    int b1;
    char satirkontrol;
    char noktalar[50];
    int noktasayisiuyumlusayac=1; // Sifirda null Deger donduruyor
    int b2;
    FILE *dosya2;
    char satirboslukkontrol;
    char boslukkontrol;
    char satirkontrol2;
    int bosluksayisii=0;
    int k1;
    int kkas=0;
    int uyumludosyasayac=0;
    FILE *dosya3;
    int aa=0;
    int b3;
    int b4;
    int b5;
    float enyakin=0;
    float enuzak;
    double uzaklik;
    int bir,iki;
    double gecici=0.0;
    int b6,b7;
    int uc,dort;
    double uzaklik2;
    double gecici2=1250.0;
    FILE *dosya4;
    int b8;
    int b9,b10;
    double uzaklik3;
    double toplamuzaklik=0.0;
    double ortalama;
    float fsatirsayisi;
    double tumortlama=0;
    int b11,b12,b13;
    float kmx,kmy,kmz,yaricap;
    double uzaklik4;

    FILE *dosya5;




    while(secim!=6)
    {
        printf("Seciminizi giriniz\n");
        scanf("%d",&secim);
        if(secim==1)
        {

            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
            {
                fprintf(nktdosya,"\nSecim 1\nDosya kontrolunu \n");
            }
            fclose(nktdosya);
            printf("Dosya kontrolu sectiniz \n\n\n");
            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
            {
                fprintf(nktdosya,"\nNokta bilgisi kontrolu\n");
            }
            fclose(nktdosya);

            printf("Nokta bilgisi kontrolu\n");

            for(b1=0; b1<nktsayac; b1++)
            {

                if((dosya=fopen(dsy[b1].dosyayolu,"r"))!=NULL)
                {

                    dsy[b1].satirsayisi=0;

                    while(!feof(dosya))
                    {
                        satirkontrol=getc(dosya);
                        if(satirkontrol=='\n')
                        {
                            dsy[b1].satirsayisi=dsy[b1].satirsayisi+1;
                            if( dsy[b1].satirsayisi==3)
                            {
                                if(dsy[b1].satirsayisi==3)
                                {
                                    fscanf(dosya,"%s",&dsy[b1].noktalar);
                                    fscanf(dosya,"%d",&dsy[b1].yazilannoktasayisi);
                                }


                            }
                        }
                    }
                    nkt[b1].taranannoktasayisi=dsy[b1].satirsayisi-5;

                    if(nkt[b1].taranannoktasayisi!=dsy[b1].yazilannoktasayisi )
                    {
                        printf("%s dosyasinin nokta bilgisi yanlis\n",dsy[b1].nktdosyaisimi);
                        if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                        {
                            fprintf(nktdosya,"\n%s dosyasinin nokta bilgisi yanlis\n",dsy[b1].nktdosyaisimi);
                        }
                        fclose(nktdosya);


                    }
                    else
                    {
                        printf("%s dosyasinin nokta bilgisi dogru\n",dsy[b1].nktdosyaisimi);
                        if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                        {
                            fprintf(nktdosya,"\n%s dosyasinin nokta bilgisi dogru\n",dsy[b1].nktdosyaisimi);
                        }
                        fclose(nktdosya);

                        strcpy(dsy[noktasayisiuyumlusayac].noktasayisiuyumludosya,dsy[b1].nktdosyaisimi);
                        printf("%s\n",dsy[noktasayisiuyumlusayac].noktasayisiuyumludosya);
                        strcpy(dsy[b1].noktasayisiuyumludosyaklasoryolu,klasoryolu);
                        strcat(dsy[b1].noktasayisiuyumludosyaklasoryolu,dsy[noktasayisiuyumlusayac].noktasayisiuyumludosya);
                        printf("%s\n",dsy[b1].noktasayisiuyumludosyaklasoryolu);
                        noktasayisiuyumlusayac=noktasayisiuyumlusayac+1;
                    }
                    fclose(dosya);
                }

                else
                {
                    printf("%s dosyasi bulunamadi\n",dsy[b1].nktdosyaisimi);
                }

            }
            printf("\n\n\n");
            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
            {
                fprintf(nktdosya,"\nRenk bilgisi kontrolu\n");
            }
            fclose(nktdosya);
            for(b2=1; b2<noktasayisiuyumlusayac; b2++)
            {
                if((dosya2=fopen(dsy[b2].noktasayisiuyumludosyaklasoryolu,"r"))!=NULL)
                {


                    printf("Renk bilgisi kontrolu\n");
                    dsy[b2].satirsayisi2=0;
                    dsy[b2].bosluksayisi=0;
                    kkas=0;

                    while(!feof(dosya2))
                    {
                        if(dsy[b2].satirsayisi2<5)
                        {
                            satirboslukkontrol=getc(dosya2);
                            if(satirboslukkontrol=='\n')
                            {
                                dsy[b2].satirsayisi2=dsy[b2].satirsayisi2+1;
                            }
                        }
                        else
                        {
                            bosluksayisii=0;
                            while(!feof(dosya2))
                            {
                                satirboslukkontrol=getc(dosya2);

                                if(satirboslukkontrol==' ')
                                {
                                    bosluksayisii=bosluksayisii+1;
                                }
                                else if(satirboslukkontrol=='\n')
                                {
                                    dsy[b2].satirsayisi2=dsy[b2].satirsayisi2+1;
                                    break;
                                }


                            }
                            if (feof(dosya2))
                                break;

                            if(bosluksayisii==5)
                            {
                                kkas=kkas+1;


                            }
                            else if (bosluksayisii!=5)
                            {
                                if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                                {
                                    fprintf(nktdosya,"\n%s %d. noktadaki renk bilgsi eksik\n",dsy[b2].noktasayisiuyumludosya,dsy[b2].satirsayisi2-5);
                                }
                                fclose(nktdosya);
                                printf("%s %d. noktadaki renk bilgsi eksik\n",dsy[b2].noktasayisiuyumludosya,dsy[b2].satirsayisi2-5);
                                fclose(dosya2);
                                break;

                            }


                        }

                    }

                    if(dsy[b2].satirsayisi2-5==kkas)
                    {
                        strcpy(dsy[uyumludosyasayac].uyumludosya,dsy[b2].noktasayisiuyumludosya);
                        strcat(dsy[uyumludosyasayac].uyumludosyaklasoryolu,klasoryolu);
                        strcat(dsy[uyumludosyasayac].uyumludosyaklasoryolu,dsy[uyumludosyasayac].uyumludosya);
                        if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                        {
                            fprintf(nktdosya,"\n%s tam uyumlu dosya\n",dsy[uyumludosyasayac].uyumludosya);
                        }
                        fclose(nktdosya);
                        printf("%s tam uyumlu dosya\n",dsy[uyumludosyasayac].uyumludosyaklasoryolu);
                        uyumludosyasayac=uyumludosyasayac+1;
                    }

                    fclose(dosya2);
                }



                else
                {
                    printf("Dosya bulunamadi\n");
                }



            }


        }

        else if(secim==2)
        {
            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
            {
                fprintf(nktdosya,"\nSecim 2\nEn yakin en uzak nokta bilgileri \n");
            }
            fclose(nktdosya);
            for(b3=0; b3<uyumludosyasayac; b3++)
            {
                if((dosya3=fopen(dsy[b3].uyumludosyaklasoryolu,"r"))!=NULL)
                {
                    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                    {
                        fprintf(nktdosya,"\n%s\n",dsy[b3].uyumludosya);
                    }
                    fclose(nktdosya);
                    dsy[b3].satirsayisi3=0;
                    printf("dosya bulundu\n");
                    while(!feof(dosya3))
                    {
                        satirkontrol=getc(dosya3);
                        if(satirkontrol=='\n')
                        {
                            dsy[b3].satirsayisi3=dsy[b3].satirsayisi3+1;
                            if( dsy[b3].satirsayisi3>=5 )
                            {

                                fscanf(dosya3,"%f",&nkt[dsy[b3].satirsayisi3-5].x);
                                fscanf(dosya3,"%f",&nkt[dsy[b3].satirsayisi3-5].y);
                                fscanf(dosya3,"%f",&nkt[dsy[b3].satirsayisi3-5].z);
                                fscanf(dosya3,"%d",&nkt[dsy[b3].satirsayisi3-5].r);
                                fscanf(dosya3,"%d",&nkt[dsy[b3].satirsayisi3-5].g);
                                fscanf(dosya3,"%d",&nkt[dsy[b3].satirsayisi3-5].b);
                            }


                        }
                    }



                    for(b4=0; b4<dsy[b3].satirsayisi3-5; b4++)
                    {

                        for(b5=0; b5<dsy[b3].satirsayisi3-5; b5++)
                        {
                            if(b4!=b5)
                            {

                                uzaklik=0;
                                uzaklik=pow((nkt[b5].x-nkt[b4].x),2)+pow((nkt[b5].y-nkt[b4].y),2)+pow((nkt[b5].z-nkt[b4].z),2);
                                uzaklik=sqrt(uzaklik);
                                if(gecici<uzaklik)
                                {
                                    gecici=uzaklik;
                                    bir=b4;
                                    iki=b5;

                                }

                            }


                        }

                    }
                    printf("\n");

                    for(b6=0; b6<dsy[b3].satirsayisi3-5; b6++)
                    {

                        for(b7=0; b7<dsy[b3].satirsayisi3-5; b7++)
                        {
                            if(b6!=b7)
                            {

                                uzaklik2=0;
                                uzaklik2=pow((nkt[b7].x-nkt[b6].x),2)+pow((nkt[b7].y-nkt[b6].y),2)+pow((nkt[b7].z-nkt[b6].z),2);
                                uzaklik2=sqrt(uzaklik2);
                                if(gecici2>uzaklik2)
                                {
                                    gecici2=uzaklik2;
                                    uc=b6;
                                    dort=b7;

                                }

                            }


                        }

                    }
                    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                    {
                        fprintf(nktdosya,"\nBirbirine en uzak nokta noktalarin bilgileri\n");
                        fprintf(nktdosya,"1. noktanin bilgileri \n");
                        fprintf(nktdosya,"%d. nokta x %f y %f z %f r %d g %d b %d \n",bir +1,nkt[bir].x,nkt[bir].y,nkt[bir].z,nkt[bir].r,nkt[bir].g,nkt[bir].b);
                        fprintf(nktdosya,"2. noktanin bilgileri \n");
                        fprintf(nktdosya,"%d. nokta x %f y %f z %f r %d g %d b %d \n",iki +1,nkt[iki].x,nkt[iki].y,nkt[iki].z,nkt[iki].r,nkt[iki].g,nkt[iki].b);
                        fprintf(nktdosya,"\n");
                        fprintf(nktdosya,"Birbirine en yakin noktalarin bilgileri\n");
                        fprintf(nktdosya,"1. noktanin bilgileri \n");
                        fprintf(nktdosya,"%d. nokta x %f y %f z %f r %d g %d b %d \n",uc +1,nkt[uc].x,nkt[uc].y,nkt[uc].z,nkt[uc].r,nkt[uc].g,nkt[uc].b);
                        fprintf(nktdosya,"2. noktanin bilgileri \n");
                        fprintf(nktdosya,"%d. nokta x %f y %f z %f r %d g %d b %d \n",dort +1,nkt[dort].x,nkt[dort].y,nkt[dort].z,nkt[dort].r,nkt[dort].g,nkt[dort].b);

                    }
                    fclose(nktdosya);
                    printf("\n");
                    printf("Birbirine en uzak nokta noktalarin bilgileri\n");
                    printf("1. noktanin bilgileri \n");
                    printf("%d. nokta x %f y %f z %f r %d g %d b %d \n",bir +1,nkt[bir].x,nkt[bir].y,nkt[bir].z,nkt[bir].r,nkt[bir].g,nkt[bir].b);
                    printf("2. noktanin bilgileri \n");
                    printf("%d. nokta x %f y %f z %f r %d g %d b %d \n",iki +1,nkt[iki].x,nkt[iki].y,nkt[iki].z,nkt[iki].r,nkt[iki].g,nkt[iki].b);
                    printf("\n");
                    printf("Birbirine en yakin noktalarin bilgileri\n");
                    printf("1. noktanin bilgileri \n");
                    printf("%d. nokta x %f y %f z %f r %d g %d b %d \n",uc +1,nkt[uc].x,nkt[uc].y,nkt[uc].z,nkt[uc].r,nkt[uc].g,nkt[uc].b);
                    printf("2. noktanin bilgileri \n");
                    printf("%d. nokta x %f y %f z %f r %d g %d b %d \n",dort +1,nkt[dort].x,nkt[dort].y,nkt[dort].z,nkt[dort].r,nkt[dort].g,nkt[dort].b);


                    fclose(dosya3);

                }
            }

        }
        else if(secim==3)
        {
        }
        else if(secim==4)
        {
            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
            {
                fprintf(nktdosya,"\nSecim 4\n Kullanicadan girilen kurenin icinde kalan noktalar\n\n");
            }
            fclose(nktdosya);
            printf("\nKure icinde kalan noktlar\n");
            printf("Kurenin merkez kordinatlarini ve yaricapini giriniz (float olarak)\n ");
            printf("Merkez noktanin x' ini giriniz\n");
            scanf("%f",&kmx);
            printf("Merkez noktanin y' sini giriniz\n");
            scanf("%f",&kmy);
            printf("Merkez noktanin z' sini giriniz\n");
            scanf("%f",&kmz);
            printf("Kurenin yaricapi\n");
            scanf("%f",&yaricap);

            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
            {
                fprintf(nktdosya,"Kurenin merkez kordinati (x,y,z) (%f, %f , %f)\n",kmx,kmy,kmz);
                fprintf(nktdosya,"Kurenin yaricapi: %f\n",yaricap);
            }
            fclose(nktdosya);

            for(b11=0; b11<uyumludosyasayac; b11++)
            {
                if((dosya5=fopen(dsy[b11].uyumludosyaklasoryolu,"r"))!=NULL)
                {
                    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                    {
                        fprintf(nktdosya,"%s\n",dsy[b11].uyumludosya);
                    }
                    fclose(nktdosya);
                    dsy[b11].satirsayisi5=0;
                    while(!feof(dosya5))
                    {
                        satirkontrol=getc(dosya5);
                        if(satirkontrol=='\n')
                        {
                            dsy[b11].satirsayisi5=dsy[b11].satirsayisi5+1;
                            if( dsy[b11].satirsayisi5>=5 )
                            {

                                fscanf(dosya5,"%f",&nkt[dsy[b11].satirsayisi5-5].x);
                                fscanf(dosya5,"%f",&nkt[dsy[b11].satirsayisi5-5].y);
                                fscanf(dosya5,"%f",&nkt[dsy[b11].satirsayisi5-5].z);
                                fscanf(dosya5,"%d",&nkt[dsy[b11].satirsayisi5-5].r);
                                fscanf(dosya5,"%d",&nkt[dsy[b11].satirsayisi5-5].g);
                                fscanf(dosya5,"%d",&nkt[dsy[b11].satirsayisi5-5].b);

                            }


                        }
                    }
                    printf("\n");
                    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                    {
                        fprintf(nktdosya,"\n\n");
                    }
                    fclose(nktdosya);

                    for(b12=0; b12<dsy[b11].satirsayisi5-5; b12++)
                    {
                        uzaklik4=0.0;
                        uzaklik4=pow((nkt[b12].x-kmx),2)+pow((nkt[b12].y-kmy),2)+pow((nkt[b12].z-kmz),2);
                        uzaklik4=sqrt(uzaklik4);
                        if(uzaklik4<yaricap)
                        {
                            printf("%d. nokta kurenin icindedir\n",b12+1);
                            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                            {
                                fprintf(nktdosya,"%d. nokta kurenin icindedir\n",b12+1);
                            }
                            fclose(nktdosya);

                        }


                    }

                }
            }


        }
        else if(secim==5)
        {
            if((nktdosya=fopen("Output.nkt","a"))!=NULL)
            {
                fprintf(nktdosya,"\nSecim 5\nHer bir noktanin birbirine olan uzaklik ortalamasi \n\n");
            }
            fclose(nktdosya);
            for(b8=0; b8<uyumludosyasayac; b8++)
            {
                if((dosya4=fopen(dsy[b8].uyumludosyaklasoryolu,"r"))!=NULL)
                {
                    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                    {
                        fprintf(nktdosya,"\n%s\n",dsy[b8].uyumludosya);
                    }
                    fclose(nktdosya);
                    tumortlama=0.0;
                    dsy[b8].satirsayisi4=0;
                    printf("dosya okundu \n");
                    while(!feof(dosya4))
                    {
                        satirkontrol=getc(dosya4);
                        if(satirkontrol=='\n')
                        {
                            dsy[b8].satirsayisi4=dsy[b8].satirsayisi4+1;
                            if( dsy[b8].satirsayisi4>=5 )
                            {

                                fscanf(dosya4,"%f",&nkt[dsy[b8].satirsayisi4-5].x);
                                fscanf(dosya4,"%f",&nkt[dsy[b8].satirsayisi4-5].y);
                                fscanf(dosya4,"%f",&nkt[dsy[b8].satirsayisi4-5].z);
                                fscanf(dosya4,"%d",&nkt[dsy[b8].satirsayisi4-5].r);
                                fscanf(dosya4,"%d",&nkt[dsy[b8].satirsayisi4-5].g);
                                fscanf(dosya4,"%d",&nkt[dsy[b8].satirsayisi4-5].b);

                            }


                        }
                    }


                    for(b9=0; b9<dsy[b8].satirsayisi4-5; b9++)
                    {
                        uzaklik3=0.0;
                        ortalama=0;
                        toplamuzaklik=0.0;

                        for(b10=0; b10<dsy[b8].satirsayisi4-5; b10++)
                        {
                            if(b9!=b10)
                            {


                                uzaklik3=pow((nkt[b10].x-nkt[b9].x),2)+pow((nkt[b10].y-nkt[b9].y),2)+pow((nkt[b10].z-nkt[b9].z),2);
                                uzaklik3=sqrt(uzaklik3);
                                toplamuzaklik=uzaklik3+toplamuzaklik;

                            }


                        }
                        fsatirsayisi=dsy[b8].satirsayisi4-6.0;
                        ortalama=toplamuzaklik/fsatirsayisi;
                        tumortlama=ortalama+tumortlama;





                    }
                    tumortlama=tumortlama/fsatirsayisi;
                    printf("Tum noktalarin birbirine olan uzaklik ortalamasi: %lf \n",tumortlama);
                    if((nktdosya=fopen("Output.nkt","a"))!=NULL)
                    {
                        fprintf(nktdosya,"\n Tum noktalarin birbirine olan uzaklik ortalamasi: %lf\n",tumortlama);
                    }
                    fclose(nktdosya);

                    fclose(dosya4);
                }

            }

        }
        else if(secim==6)
        {
            printf("Program kapandi\n");

        }
    }

}

