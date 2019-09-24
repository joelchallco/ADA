#include <iostream>

using namespace std;

void merge(int a[],int ini, int med, int fin){
  int i,j,k;
  int n = med - ini + 1;
  int aux[n];
  for( int i=0; i<n; i++){
    aux[i] = a[ ini+i ];
  }

  i=0;
  j=med+1;
  k=ini;
  while( i<n ){
    if( aux[i] <= a[j] ){
      a[k] = aux[i];
      i++;
    }
    else{
      a[k] = a[j];
      j++;
    }
    k++;
  }
  while( i<n){
    a[k] = aux[i];
    i++;
    k++;
  }
}

void mergesort(int a[],int ini,int fin){
  int med;
  if( ini < fin ){
    med = ini+(fin-ini)/2;
    mergesort(a,ini,med);
    mergesort(a,med+1,fin);
    merge(a,ini,med,fin);
  }
}

void mostrar(int a[],int n){
  for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
  }
}

int main(int argc, char const *argv[]) {
  int l[] = {6,2,8,12,4,89,0,34,7,10,1};
  mergesort(l,0,11);
  mostrar(l,11);
  return 0;
}
