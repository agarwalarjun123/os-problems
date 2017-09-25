#include<iostream>
using namespace std;
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
int n;
int x;
sem_t e,y;
pthread_mutex_t s;
int in=0;
int  buf[5];
 
void *producer(void *s1){
	int x;

		sem_wait(&e);
		pthread_mutex_lock(&s);
		cout<<"enter item"<<endl;
		cin>>x;
		cout<<"the content of buffer is  ";
		
		buf[in++]=x;
		
		for(int i=0;i<in;i++)
		cout<<buf[i];
		cout<<"\n";
		pthread_mutex_unlock(&s);
		sem_post(&y);
		
			

			
	
}
void *consumer(void *s1){
	


	
	sem_wait(&y);
	pthread_mutex_lock(&s);
	
	cout<<"content of buffer is";
		
		
		if(in-1==0){
		cout<<"empty\n";
	}
		else
		{
		
		cout<<buf[in-1];
		in--;
		cout<<"\n";
		}
		

	pthread_mutex_unlock(&s);
	sem_post(&e);

}
int main(){
int i;
	cout<<"enter no of threads";
	cin>>n;
	pthread_t id[n];
	pthread_mutex_init(&s,NULL);
	sem_init(&e,0,5);
 	sem_init(&y,0,0);
	char x[n];
cout<<"enter sequence in P/C";
	for(i=0;i<n;i++)
	cin>>x[i];
		for(i=0;i<n;i++)
	{
		if(x[i]=='P'){
		pthread_create(&id[i],NULL,producer,NULL);
		
		
	}
		else if(x[i]=='C'){
		pthread_create(&id[i],NULL,consumer,NULL);
	
	}
}
	for(i=0;i<n;i++)
	{
		pthread_join(id[i],NULL);		
	}
	

		
	


	
}
