 #include <cekeikon.h>


int max_vetor (int vet[]){
 
    int i,maior=vet[0];
        
    for (i=1;i<256;i++)
        if (vet[i]>maior)
         	maior=vet[i];
             
    return(maior);        
}


int main(int argc, char** argv)
{ 
	Mat_<GRY> a;
  	le(a,argv[1]);
  
  	Mat_<GRY> c(400,350,255);
  
  
  	if(argc!=3){
		printf("Erro Sintaxe!!\nhistograma img_ent.jpg img_saida.bmp");
	   	exit(1);
  	}
  
  
	int vet_1[256];
	int vet_2[256];
	int maior;
  
    
  for (int i=0;i<256;i++)
      vet_1[i]=0;
 
  for (int l=0; l<a.rows; l++)
    for (int c=0; c<a.cols; c++)
       vet_1[a(l,c)]=vet_1[a(l,c)]+1;
  		//vet1 vai receber o numero de 0 a 255 do elemento da matriz a
  		//o indice do vetor vai receber um numero de 0 a 255 e depois vai receber 
  		//através do l e c, o vetor vai identificar qual é a posição exata(que representa uma cor de 0 a 255), e depois acrescentar + 1, para saber a quantidade de pixels de cada cor

  maior = max_vetor(vet_1);
   
  for (int i=0;i<256;i++)
      vet_2[i] = (int)(((float) vet_1[i]/maior)*300);
      //Esse calculo é para pegar os valores para depois construir o gráfico.
      //o resultado dessa equação é a posição na coluna y onde vai ser colocado no histograma
      
  for (int x=0; x<c.rows;x++)
      for (int y=0;y<c.cols;y++)
            c(x,y)=255;  
			//Vai deixar a imagem toda branca
   			//vetor_1 tem a quantidade de pixel de cada coloração e vet_2 tem a posição deles na coluna
   for (int i=0;i<256;i++){
       if (vet_2[i] != 0){ 
         for (int j=0;j<vet_2[i];j++)
              c(350-j,i)=0;  
			  //350 é o valor de x, onde ele começa o gráfico pelo lado direito e vai indo pro esquerdo, pela subtração do j nos 350.
			  //i começa no zero e vai se incrementando de um em um.            
       }
   } 
                
  imp(c,argv[2]);
  
}

