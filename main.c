#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

typedef struct{
    char street[30] , city[30] , floor[5];
}address;
typedef struct{

char fname[20],sname[20];
address a;
char num[12];
char mail[40];
}phone;
phone cont[100];
int i,counter=0;
phone temp;


void Load(){
FILE* f;
if((f=fopen("students.txt", "r")) != NULL){
        while(!feof(f)){
fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",cont[counter].fname,cont[counter].sname,cont[counter].num,cont[counter].a.floor,cont[counter].a.street,cont[counter].a.city,cont[counter].mail);
            counter++;
}}
fclose(f);}

void menu(){
    int x;system("cls");
while(1){
    printf("\n\t\t\t\t\t\t******PHONEBOOK******\n\n\n");
    printf("1-add a contact \t2-search \t\t3-modify \n4-delete \t\t5-save \t\t\t6-print the contacts \n7-quit\n");
    scanf("%d",&x);
switch(x){
 case 1:
    add(); break;
    case 2:
        search(); break;
        case 3:
            modify(); break;
          case 4:
                delete(); break;
            case 5:
                    save(); break;
               case 6:
                        print();break;
                case 7:
                       return(0);
                default:
                system("cls");
            }}
}


void add(){
system("cls");
printf("first name:");
scanf("%s",cont[counter].fname);
printf("\nsecond name:");
scanf("%s",cont[counter].sname);
printf("\nphone number:");
scanf("%s",cont[counter].num);
printf("\naddress(floor,street,city):");
scanf("%s%s%s",cont[counter].a.floor,cont[counter].a.street,cont[counter].a.city);
printf("\nE-mail:");
scanf("%s",cont[counter].mail);
counter++;
}

void search(){
  char s[20];
printf("Enter the first name:");
scanf("%s",s);
system("cls");
int flag=0;
for(i=0;i<counter;i++){
if(strcmp(s,cont[i].fname)==0){flag=1;
printf("\nfirst name:%s",cont[i].fname);
printf("\nsecond name:%s",cont[i].sname);
printf("\nphone number:%s",cont[i].num);
printf("\naddress(floor,street,city):%s,%s,%s",cont[i].a.floor,cont[i].a.street,cont[i].a.city);
printf("\nE-mail:%s\n",cont[i].mail);
     }}
    if(flag==0)
        printf("\nName Does Not Exist");

    }


void print(){
system("cls");
        for(i=0;i<counter;i++){
    printf("\n\n***%d***\n",(i+1));
    printf("first name:%s",cont[i].fname);
printf("\nsecond name:%s",cont[i].sname);
printf("\nphone number:%s",cont[i].num);
printf("\naddress(floor,street,city):%s,%s,%s",cont[i].a.floor,cont[i].a.street,cont[i].a.city);
printf("\nE-mail:%s",cont[i].mail);
     }
    }

void modify(){
   int flag=0;
    char a[20],b[20];
printf("Enter the name:");
scanf("%s%s",a,b);
system("cls");
for(i=0;i<counter;i++){
    if(strcmp(a,cont[i].fname)==0&&strcmp(b,cont[i].sname)==0){flag=1;
printf("first name:");
getchar();
scanf("%[^\n]",temp.fname);
printf("\nsecond name:");
getchar();
scanf("%[^\n]",temp.sname);
printf("\nphone number:");
getchar();
scanf("%[^\n]",temp.num);
printf("\naddress(floor,street,city):");
getchar();scanf("%[^\n]",temp.a.floor);
getchar();scanf("%[^\n]",temp.a.street);
getchar();scanf("%[^\n]",temp.a.city);
printf("\nE-mail:");
getchar();
scanf("%[^\n]",temp.mail);

 if(strcmp(temp.fname,"")!=0){
    strcpy(cont[i].fname,temp.fname);
}
if(strcmp(temp.sname,"")!=0){
    strcpy(cont[i].sname,temp.sname);
}
if(strcmp(temp.num,"")!=0){
    strcpy(cont[i].num,temp.num);
}
if(strcmp(temp.a.floor,"")!=0){
    strcpy(cont[i].a.floor,temp.a.floor);
}
if(strcmp(temp.a.street,"")!=0){
    strcpy(cont[i].a.street,temp.a.street);
}
if(strcmp(temp.a.city,"")!=0){
    strcpy(cont[i].a.city,temp.a.city);
}
if(strcmp(temp.mail,"")!=0){
    strcpy(cont[i].mail,temp.mail);
}
  break; }}
if(flag==0){
    printf("Not Found");
}}


void delete(){
    char name1[20],name2[20];
    int flag=1,j;
    printf("Enter the name you want to delete:");
    scanf("%s",name1); scanf("%s",name2);
    for(i=0;i<counter;i++){
        if(strcmp(name1,cont[i].fname)==0&&strcmp(name2,cont[i].sname)==0){
            j=i;
            for(j=0;j<counter;j++){
                cont[j]=cont[j+1];}
     printf("done");
       } counter--;
  flag=0; break; }
    if(flag==1){
        printf("Not Found");
    }
}

void save(){
FILE *f;
f=fopen("students.txt","w");
for(i=0;i<counter;i++){

fprintf(f,"%s,%s,%s,%s,%s,%s,%s\n",cont[i].fname,cont[i].sname,cont[i].num,cont[i].a.floor,cont[i].a.street,cont[i].a.city,cont[i].mail);
            fprintf(f,"\n");
        }
fclose(f);system("cls");

}


int main(){
    system("color f3");
    Load();
menu();
return 0;}
