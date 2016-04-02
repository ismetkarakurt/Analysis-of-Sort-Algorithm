#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define Size1 40000
#define Size2 25000
#define Size3 10000
#define Size4 5000

void CreateAnArray(int Array[],int size,int ArrayType,int NumberOfRandomLocations);
long int InsertionSort(int Array[],int size);
long int Merge(int Array[],int low,int mid,int high,int Size);
void MergeSort(int Array[],int low,int high,int Size,long int *Comparison);
void QuickSort(int Array[],int Low,int High,int PivotType,long int *Comparison);

int main(){
	
	
	clock_t t1, t2;
	int i;
	float diff;
	srand(time(NULL));
	int Array1[Size1];
	int Array2[Size2];
	int Array3[Size3];
	int Array4[Size4];
	
	long long int AVGBaseOp1=0,AVGBaseOp2=0,AVGBaseOp3=0,AVGBaseOp4=0;
	float AVGTime1=0,AVGTime2=0,AVGTime3=0,AVGTime4=0;
	long int Comparison;
	
	
	//**************************************************************** 
	//BEST & WORST CASES
	
	for(i=0;i<4;i++){
		//**********************
		Comparison=0;
		CreateAnArray(Array4,Size4,i+1,0);
		t1=clock();
		Comparison=InsertionSort(Array4,Size4);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime1=diff;
		AVGBaseOp1=Comparison;
		//*********************
		Comparison=0;
		CreateAnArray(Array4,Size4,i+1,0);
		t1=clock();
		MergeSort(Array4,0,Size4-1,Size4,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime2=diff;
		AVGBaseOp2=Comparison;
		
		//*********************
		Comparison=0;
		CreateAnArray(Array4,Size4,i+1,0);
		t1=clock();
		QuickSort(Array4,0,Size4-1,1,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime3=diff;
		AVGBaseOp3=Comparison;
		//********************
		Comparison=0;
		CreateAnArray(Array4,Size4,i+1,0);
		t1=clock();
		QuickSort(Array4,0,Size4-1,2,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime4=diff;
		AVGBaseOp4=Comparison;
		
		
	printf("\nBest And WOrst Cases With Array Size 5000\n");
	if(i==0)printf("Totaly Random Array\n\n");
	if(i==1)printf("Sorted Array\n\n");
	if(i==2)printf("Reverse Sorted Array\n\n");
	if(i==3)printf("Array With All Elements are Equal\n\n");
	printf("\t\tInsertionSort\t\tMergeSort\n\n");
	if(i==1 || i==3) printf("AverageBaseOp:\t%ld\t\t\t%ld\n",AVGBaseOp1,AVGBaseOp2);
	else printf("AverageBaseOp:\t%ld\t\t%ld\n",AVGBaseOp1,AVGBaseOp2);
	printf("AverageTime:\t%lf\t\t%lf\n",AVGTime1,AVGTime2);
	printf("\t\tQuickSort1\t\tQuickSort2\n\n");
	printf("AverageBaseOp:\t%ld\t\t\t%ld\n",AVGBaseOp3,AVGBaseOp4);
	printf("AverageTime:\t%lf\t\t%lf\n\n",AVGTime3,AVGTime4);

	}
	
	
	//****************************************************************
	
	for(i=0;i<30;i++){
		
		//*******************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array1,Size1,2,((i+1)*3200));
		}
		else if(i<20){
			CreateAnArray(Array1,Size1,3,((i+1)*3200));
		}
		else{
		    CreateAnArray(Array1,Size1,1,0);}
		t1=clock();
		Comparison=InsertionSort(Array1,Size1);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime1+=diff;
		AVGBaseOp1+=Comparison;
		//*********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array1,Size1,2,((i+1)*3200));
		}
		else if(i<20){
			CreateAnArray(Array1,Size1,3,((i+1)*3200));
		}
		else{
		    CreateAnArray(Array1,Size1,1,0);}
		t1=clock();
		MergeSort(Array1,0,Size1-1,Size1,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime2+=diff;
		AVGBaseOp2+=Comparison;
		//**********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array1,Size1,2,((i+1)*3200));
		}
		else if(i<20){
			CreateAnArray(Array1,Size1,3,((i+1)*3200));
		}
		else{
		    CreateAnArray(Array1,Size1,1,0);}
		t1=clock();
		QuickSort(Array1,0,Size1-1,1,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime3+=diff;
		AVGBaseOp3+=Comparison;
		//**********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array1,Size1,2,((i+1)*3200));
		}
		else if(i<20){
			CreateAnArray(Array1,Size1,3,((i+1)*3200));
		}
		else{
		    CreateAnArray(Array1,Size1,1,0);}
		t1=clock();
		QuickSort(Array1,0,Size1-1,2,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime4+=diff;
		AVGBaseOp4+=Comparison;
	}
	printf("\n\nQuickSort1: Pivot always selected as first element.\nQuickSort2: Pivot always selected as mediand of three elements\n\n\n");
	printf("ArraySize: 40000\n");
	printf("\t\tInsertionSort\t\tMergeSort\n");
	printf("AverageBaseOp:\t%ld\t\t%ld\n",AVGBaseOp1/30,AVGBaseOp2/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n",AVGTime1/30,AVGTime2/30);
	printf("\t\tQuickSort1\t\tQuickSort2\n");
	printf("AverageBaseOp:\t%ld\t\t\t%ld\n",AVGBaseOp3/30,AVGBaseOp4/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n\n",AVGTime3/30,AVGTime4/30);
	
	AVGTime1=0;AVGTime2=0;AVGTime3=0;AVGTime4=0;
	AVGBaseOp1=0;AVGBaseOp2=0;AVGBaseOp3=0;AVGBaseOp4=0;
	
	for(i=0;i<30;i++){
		
		//*********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array2,Size2,2,((i+1)*2000));
		}
		else if(i<20){
			CreateAnArray(Array2,Size2,3,((i+1)*2000));
		}
		else{
		    CreateAnArray(Array2,Size2,1,0);}
		t1=clock();
		Comparison=InsertionSort(Array2,Size2);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime1+=diff;
		AVGBaseOp1+=Comparison;
		//*********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array2,Size2,2,((i+1)*2000));
		}
		else if(i<20){
			CreateAnArray(Array2,Size2,3,((i+1)*2000));
		}
		else{
		    CreateAnArray(Array2,Size2,1,0);}
		t1=clock();
		MergeSort(Array2,0,Size2-1,Size2,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime2+=diff;
		AVGBaseOp2+=Comparison;
		//*******************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array2,Size2,2,((i+1)*2000));
		}
		else if(i<20){
			CreateAnArray(Array2,Size2,3,((i+1)*2000));
		}
		else{
		    CreateAnArray(Array2,Size2,1,0);}
		t1=clock();
		QuickSort(Array2,0,Size2-1,1,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime3+=diff;
		AVGBaseOp3+=Comparison;
		//*****************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array2,Size2,2,((i+1)*2000));
		}
		else if(i<20){
			CreateAnArray(Array2,Size2,3,((i+1)*2000));
		}
		else{
		    CreateAnArray(Array2,Size2,1,0);}
		t1=clock();
		QuickSort(Array2,0,Size2-1,2,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime4+=diff;
		AVGBaseOp4+=Comparison;
	}
	printf("ArraySize: 25000\n");
	printf("\t\tInsertionSort\t\tMergeSort\n");
	printf("AverageBaseOp:\t%ld\t\t%ld\n",AVGBaseOp1/30,AVGBaseOp2/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n",AVGTime1/30,AVGTime2/30);
	printf("\t\tQuickSort1\t\tQuickSort2\n");
	printf("AverageBaseOp:\t%ld\t\t\t%ld\n",AVGBaseOp3/30,AVGBaseOp4/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n\n",AVGTime3/30,AVGTime4/30);
	
	AVGTime1=0;AVGTime2=0;AVGTime3=0;AVGTime4=0;
	AVGBaseOp1=0;AVGBaseOp2=0;AVGBaseOp3=0;AVGBaseOp4=0;
	
	for(i=0;i<30;i++){
		
		//********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array3,Size3,2,((i+1)*800));
		}
		else if(i<20){
			CreateAnArray(Array3,Size3,3,((i+1)*800));
		}
		else{
		    CreateAnArray(Array3,Size3,1,0);}
		t1=clock();
		Comparison=InsertionSort(Array3,Size3);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime1+=diff;
		AVGBaseOp1+=Comparison;
		//*****************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array3,Size3,2,((i+1)*800));
		}
		else if(i<20){
			CreateAnArray(Array3,Size3,3,((i+1)*800));
		}
		else{
		    CreateAnArray(Array3,Size3,1,0);}
		t1=clock();
		MergeSort(Array3,0,Size3-1,Size3,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime2+=diff;
		AVGBaseOp2+=Comparison;
		//*****************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array3,Size3,2,((i+1)*800));
		}
		else if(i<20){
			CreateAnArray(Array3,Size3,3,((i+1)*800));
		}
		else{
		    CreateAnArray(Array3,Size3,1,0);}
		t1=clock();
		QuickSort(Array3,0,Size3-1,1,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime3+=diff;
		AVGBaseOp3+=Comparison;
		//****************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array3,Size3,2,((i+1)*800));
		}
		else if(i<20){
			CreateAnArray(Array3,Size3,3,((i+1)*800));
		}
		else{
		    CreateAnArray(Array3,Size3,1,0);}
		t1=clock();
		QuickSort(Array3,0,Size3-1,2,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime4+=diff;
		AVGBaseOp4+=Comparison;
	}
	printf("ArraySize: 10000\n");
	printf("\t\tInsertionSort\t\tMergeSort\n");
	printf("AverageBaseOp:\t%ld\t\t%ld\n",AVGBaseOp1/30,AVGBaseOp2/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n",AVGTime1/30,AVGTime2/30);
	printf("\t\tQuickSort1\t\tQuickSort2\n");
	printf("AverageBaseOp:\t%ld\t\t\t%ld\n",AVGBaseOp3/30,AVGBaseOp4/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n\n",AVGTime3/30,AVGTime4/30);
	
	AVGTime1=0;AVGTime2=0;AVGTime3=0;AVGTime4=0;
	AVGBaseOp1=0;AVGBaseOp2=0;AVGBaseOp3=0;AVGBaseOp4=0;
	
	for(i=0;i<30;i++){
		
		//*******************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array4,Size4,2,((i+1)*400));
		}
		else if(i<20){
			CreateAnArray(Array4,Size4,3,((i+1)*400));
		}
		else{
		    CreateAnArray(Array4,Size4,1,0);}
		t1=clock();
		Comparison=InsertionSort(Array4,Size4);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime1+=diff;
		AVGBaseOp1+=Comparison;
		//*********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array4,Size4,2,((i+1)*400));
		}
		else if(i<20){
			CreateAnArray(Array4,Size4,3,((i+1)*400));
		}
		else{
		    CreateAnArray(Array4,Size4,1,0);}
		t1=clock();
		MergeSort(Array4,0,Size4-1,Size4,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime2+=diff;
		AVGBaseOp2+=Comparison;
		//**********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array4,Size4,2,((i+1)*400));
		}
		else if(i<20){
			CreateAnArray(Array4,Size4,3,((i+1)*400));
		}
		else{
		    CreateAnArray(Array4,Size4,1,0);}
		t1=clock();
		QuickSort(Array4,0,Size4-1,1,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime3+=diff;
		AVGBaseOp3+=Comparison;
		//**********************************
		Comparison=0;
		if(i<10){
			CreateAnArray(Array4,Size4,2,((i+1)*400));
		}
		else if(i<20){
			CreateAnArray(Array4,Size4,3,((i+1)*400));
		}
		else{
		    CreateAnArray(Array4,Size4,1,0);}
		t1=clock();
		QuickSort(Array4,0,Size4-1,2,&Comparison);
		t2=clock();
		diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
		AVGTime4+=diff;
		AVGBaseOp4+=Comparison;
	}
	printf("ArraySize: 5000\n");
	printf("\t\tInsertionSort\t\tMergeSort\n");
	printf("AverageBaseOp:\t%lld\t\t%lld\n",AVGBaseOp1/30,AVGBaseOp2/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n",AVGTime1/30,AVGTime2/30);
	printf("\t\tQuickSort1\t\tQuickSort2\n");
	printf("AverageBaseOp:\t%lld\t\t\t%lld\n",AVGBaseOp3/30,AVGBaseOp4/30);
	printf("AverageTime:\t%lf\t\t%lf\n\n\n",AVGTime3/30,AVGTime4/30);
	


}
	//************************************************************************************
	long int InsertionSort(int Array[],int size){
	
	int Comparison=0;
	int n=size;
	int i,v,j;
	for(i=1;i<n;i++){
		 v=Array[i];
		 j=i-1;
		while ((j>=0) && (Array[j]>v)){  
			Comparison=Comparison+2;
			Array[j+1]=Array[j];
			Array[j]=v;
			j=j-1;
		}
	}
	return Comparison;
	}
	//*************************************************************************************
	void MergeSort(int arr[],int low,int high,int size,long int *Comparison){

    int mid;
	int Cmp;
	
    if(low<high){
         mid=(low+high)/2;
         MergeSort(arr,low,mid,size,Comparison);
         MergeSort(arr,mid+1,high,size,Comparison);
         Cmp=Merge(arr,low,mid,high,size);
         *Comparison+=Cmp;
    }
	}
	//**************************************************************************************
	long int Merge(int arr[],int low,int mid,int high,int size){

    int i,m,k,l,*temp;
    int Comp=0;
    
	temp=(int *)malloc(size*sizeof(int));
    
    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++,Comp++;
         }
         else{
             temp[i]=arr[m];
             m++,Comp++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++,Comp++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++,Comp++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
    free(temp);
    return Comp;
	}	
	//***************************************************************************************
	void CreateAnArray(int Array[],int size,int type,int loc){
	int i,tmp1;
	if(type==1){	
		for(i=0;i<size;i++){
			Array[i] =rand();	
		}
	}
	if(type==2){
		i=1;Array[0]=0;
		while(i<size){
			tmp1=0;
			while(tmp1<i && (i+tmp1)<size){
				Array[i+tmp1]=i;
			tmp1++;
				}
	    	i=2*i;
		}	
		for(i=0;i<loc;i++){
			tmp1=rand()%size;
			Array[tmp1]=rand();
		}
	}
	if(type==3){
		for(i=0;i<size;i++){
			Array[i]=size-i;
		}
		
		for(i=0;i<loc;i++){
			tmp1=rand()%size;
			Array[tmp1]=rand();
		}
	}
	if(type==4){
		for(i=0;i<size;i++){
			Array[i]=50;
		}
	}
	
	}
	//*********************************************************************************************
	void QuickSort(int x[],int first,int last,int type,long int *Comparison){
    int pivot,j,temp,i;
    int mid,temp2,Cmp=0;

     if(first<last){
     	
		if(type==1)
         pivot=first;
        else{
        		mid=(first+last)/2;
         	if((x[first]<x[last] && x[first]>x[mid]) || (x[first]>x[last] && x[first]<x[mid]))
			 pivot=first;
         	else if((x[last]<x[first] && x[last]>x[mid]) || (x[last]>x[first] && x[last]<x[mid])){
         		temp2=x[first];
         		x[first]=x[last];
         		x[last]=temp2;
         		pivot=first;
			 }
         	else{
         		temp2=x[first];
         		x[first]=x[mid];
         		x[mid]=temp2;
         		pivot=first;
         }	
         
        }
         
         i=first;
         j=last; 

         while(i<j){
             while(x[i]<=x[pivot] && i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
                  Cmp+=2;
             }
         }
         
         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         Cmp+=2;
         *Comparison+=Cmp;
         
         QuickSort(x,first,j-1,type,Comparison);
         QuickSort(x,j+1,last,type,Comparison);

    }
	}
	//************************************************************************************************
	
	
	
