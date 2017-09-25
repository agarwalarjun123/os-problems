#include<iostream>
using namespace std;
#include<pthread.h>
#include<semaphore.h>

pthread_mutex_t wsem,x;
int readcount=0;
pthread_t t[10];

void* reader(void *s2){
pthread_mutex_lock(&x);
readcount++;
if(readcount==1)
pthread_mutex_lock(&wsem); 
pthread_mutex_unlock(&x);
cout<<"reader is getting executed\n";
readcount--;
if(readcount==0)
pthread_mutex_unlock(&wsem);
pthread_mutex_unlock(&x);





}

void *writer(void *s1){
pthread_mutex_lock(&wsem);
cout<<"writer is getting executed\n";
pthread_mutex_unlock(&wsem);



}


int main(){
pthread_mutex_init(&x,NULL);
pthread_mutex_init(&wsem,NULL);
cout<<"enter no of threads";
int n;
cin>>n;
char s[n];
cout<<"\n enter sequence R/W";
for(int i=0;i<n;i++)
cin>>s[i];
for(int i=0;i<n;i++)
{

if(s[i]=='R')
pthread_create(&t[i],NULL,reader,NULL);

else if(s[i]=='W')
pthread_create(&t[i],NULL,writer,NULL);


}

for(int i=0;i<n;i++)
pthread_join(t[i],NULL);

}
