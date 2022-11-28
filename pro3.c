#include <stdio.h>
#include <math.h>

    void nn();
    void nn(){
    int n,index;
	float d, longi, lati, untemp, tempd;
	float lon[n],lat[n],temp[n];



	// Calculating the nearest location from the prediction point
	tempd = sqrt((longi - lon[0]) * (longi - lon[0]) + (lati - lat[0]) * (lati - lat[0]));
	for (int j=1; j<n; j++)
	{
		d=sqrt((longi - lon[j])*(longi - lon[j]) + (lati - lat[j])*(lati - lat[j]) );
		if(d < tempd){
			tempd=d;
			index=j;
		}
	}

	printf("The temperature of the given location is: %d", temp[index]);
    }

    void knear();
    void knear(){
    int n,k,index;
	float d, longi, lati, untemp, sum=0, avg;
	float lon[n],lat[n],temp[n], temp2[n];


	printf("Enter the number of points to be considered: ");
	scanf("%d", &k);





	// Calculating the distance from the prediction point
	for (int j=0; j<n; j++)
	{
		temp2[j]=sqrt((longi - lon[j])*(longi - lon[j]) + (lati - lat[j])*(lati - lat[j]) );
	}

	//sorting of array(bubble sort)
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(temp2[i]>temp[j]){
				int r=temp2[i];
				temp2[i]=temp2[j];
				temp2[j]= r;
			}
		}
	}


	for(int s=0; s<k; s++){
		sum=sum+temp2[s];
	}

	avg= sum/k;

	printf("The predicted temperature of the given location is: %f\n", avg);
    }
    void radii();
    void radii(){
    	int n,count;
	float rad,d, longi, lati, sum=0, avg;
	float lon[n],lat[n],temp[n], temp2[n];



	printf("Enter the radius inside which the points will be considered:  ");
	scanf("%f", &rad);



	// Calculating the distance from the prediction point
	for (int j=0; j<n; j++)
	{
		d=sqrt((longi - lon[j])*(longi - lon[j]) + (lati - lat[j])*(lati - lat[j]) );

		if(d<= rad)
			sum= sum+temp[j];
			count++;
	}

	avg= sum/count;

	printf("The predicted temperature of the given location is: %f", avg);
    }
    void idw();
    void idw(){
    	int n,k,index;
	float d, longi, lati, untemp, sum1=0,sum2=0;
	float lon[n],lat[n],temp[n], dist[n], w[n];


	printf("Enter the number of points to be considered: ");
	scanf("%d", &k);



	// Calculating the distance from the prediction point
	for (int j=0; j<n; j++)
	{
		dist[j]=sqrt((longi - lon[j])*(longi - lon[j]) + (lati - lat[j])*(lati - lat[j]) );
		w[j]=1/(dist[j]*dist[j]);
		sum1= sum1+ w[j];
		sum2= sum2+(w[j]*temp[j]);
	}

	untemp= sum2/sum1;
	printf("\nThe predicted temperature is %f", untemp);
    }


void main(){
      int choice;
      float lon[50],lat[50],temp[50],longi,lati;
      int n;
      printf("Enter the number of interpolating points:");
	  scanf("%d", &n);

	  for (int i=0; i<n ; i++){
		printf("Enter the longitude of the point: ");
		scanf("%f", &lon[i]);
		printf("Enter the latitude of the point: ");
		scanf("%f", &lat[i]);
		printf("Enter the temperature of the point: ");
		scanf("%f", &temp[i]);
	  }

	  printf("Enter the longitude of the prediction point: ");
	  scanf("%d", &longi );
	  printf("Enter latitude of the prediction point: ");
	  scanf("%d",&lati);

      printf("Please enter the method you want to use: ");
      printf("1. Nearest Neighbour \n2. K-Nearest Neighbour \n 3.Radius Method \n4.Inverse Distance Weighting \n");
      scanf("%d",&choice);

      switch (choice){
       case 1:
             nn();
             break;
       case 2:
             knear();
             break;
       case 3:
             radii();
             break;
       case 4:
             idw();
             break;
       default:
            printf("Wrong choice\n ");
            break;
      }
}
