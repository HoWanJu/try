int  bestdata[30]={0}; 
const int  completelevel=5;//共五關 

void  OpenData()  
{  
    int  i=0;  
    FILE* fPtr = fopen("1.dat","r");
    if (fPtr==NULL)  
    {  
        printf( "不能打開文件\n" );  
        return ;  
    } 

    while (fPtr!=NULL)  
    {  
        fread(( char  *)&bestdata[i], sizeof (bestdata[i]),1,fPtr);  
        i++;  
    }  
    fclose(fPtr);  
}  
  
void  SaveData()  
{  
	FILE* fPtr1 = fopen("1.dat","w+");
    if (fPtr1==NULL)  
    {  
        printf( "不能存入文件\n" );  
        return ;  
    }  
    for ( int  i=0;i<completelevel;i++)  
        fwrite(( char  *)&bestdata[i], sizeof (bestdata[i]),1,fPtr1);  
    fclose(fPtr1);  
  
}  
