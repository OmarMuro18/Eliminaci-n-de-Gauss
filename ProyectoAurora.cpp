#include<bits/stdc++.h>

double aCopia[20][20];
double bCopia[20];

void gauss(double a[20][20], double b[20], int n, double x[20]);
void eliminate(double a[20][20], double s[], int n, double b[20]);
void pivot(double a[20][20], double b[20], double s[], int n, int k);
void substitute(double a[20][20], int n, double b[20], double x[20]);
void imprimirValores(double b[20], int n, double x[20]);

int main()
{

	int n;
	double x[20];
	double b[20];
	double a[20][20];
	double res, ca;
	int opc ,enSa,Ncor, noA, corrienteD, nob;
	
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			a[i][j]=0;
		}
	}
	do{
		do{
			system("cls");
			printf("\tMETODO DE ELIMINACION DE GAUS");
			printf("\n\nIngrese el numero de nodos: ");
			scanf("%d",&n);
		}while(n<2 || n>20);
		
		for(int i=0; i<n; i++)
		{
			do
			{
				printf("\n¿Existe corriente directa?\n1. Si\n2.No\nOpcion: ");
				scanf("%d",& corrienteD);
			}while(corrienteD < 1 || corrienteD > 2);
			if(corrienteD == 1)
			{
				do
				{
					printf("\n¿Entra o sale?\n1. Entra\n2.Sale\nOpcion: ");
					scanf("%d",& enSa);
				}while(enSa < 1 || enSa > 2);
				if(enSa == 1)
				{
					printf("\nValor en amperes de la corriente directa [%d]: ", i+1);
					scanf("%lf",&b[i]);
				}
				else 
				{
					printf("\nValor en amperes de la corriente directa [%d]: ", i+1);
					scanf("%lf",&ca);
					
					ca= -1*ca;
					b[i]=ca;
				}
			}
			else 
			{
				b[i]=0;
			}
			printf("\n¿Cuantas corrientes hay?");
			scanf("%d",&Ncor);
			for(int j=0; j<Ncor; j++)
			{
				printf("\nCorriente I%d",j+1);
				do
				{
					printf("\n¿Entra o sale?\n1. Entra\n2.Sale\nOpcion: ");
					scanf("%d",& enSa);
				}while(enSa < 1 || enSa > 2);
				if(enSa == 1)
				{
					printf("\nIngresa el valor de la resistencia: ");
					scanf("%lf", &res);
					do
					{
						printf("\n¿De que nodo sale?");
						scanf("%d", &noA);
						noA= noA- 1;
						printf("\n¿A que nodo va?");
						scanf("%d", &nob);
						nob= nob- 1;
					}while(noA < 0 || noA >= n && nob < 0 || nob >= n);
					
					a[i][noA] -= 1/res;
					a[i][nob] += 1/res;
					
					//im
						for(int i=0; i<n; i++)
						{
							for(int j=0; j<n; j++)
							{
								printf("\t%lf",a[i][j]);
							}
							printf("\n");
						}
						system("pause");
				}
				else
				{
					do
					{
						printf("\n¿El nodo va a tierra o va a otro nodo?\n1.Tierra\n2.Nodo\nOpcion: ");
						scanf("%d",&enSa);
					}while(enSa < 1 || enSa > 2);
					printf("\nIngresa el valor de la resistencia: ");
					scanf("%lf", &res);
					
					if(enSa == 1)
					{
						do
						{
							printf("\n¿De que nodo?");
							scanf("%d", &nob);
							nob= nob- 1;
						}while(nob < 0 || nob >= n);
						a[i][nob] += 1/res;
						
						//im
						for(int i=0; i<n; i++)
						{
							for(int j=0; j<n; j++)
							{
								printf("\t%lf",a[i][j]);
							}
							printf("\n");
						}
						system("pause");
					}
					else
					{
						do
						{
							printf("\n¿De que nodo sale?");
							scanf("%d", &noA);
							noA= noA- 1;
							printf("\n¿De que nodo a donde va?");
							scanf("%d", &nob);
							nob= nob- 1;
						}while(noA < 0 || noA >= n && nob < 0 || nob >= n);
						
						a[i][noA] =a[i][noA]+ 1/res;
						a[i][nob] = a[i][nob]-1/res;
						
						//im
						for(int i=0; i<n; i++)
						{
							for(int j=0; j<n; j++)
							{
								printf("\t%lf",a[i][j]);
							}
							printf("\n");
						}
						system("pause");
					}
				}
			}
			system("cls");
		}
				
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{			
				aCopia[i][j]=a[i][j];
			}
			bCopia[i]=b[i];
		}
		
		gauss(a,b,n,x);
		
		printf("\n");		
		printf("Ingrese 0 para salir cualquier numero para continuar: ");
		scanf("%d",&opc);
	}while(opc!=0);
	
	
	return 0;
}

void gauss(double a[20][20], double b[20], int n, double x[20])
{
	double s[n];
	for(int i=0; i<n; i++)
	{
		s[i]=abs(a[i][0]);
		for(int j=1; j<n; j++)
		{
			if( abs(a[i][j])>s[i] )
			{
				s[i]=abs(a[i][j]);
			}
		}
	}	
	eliminate(a,s,n,b);
	substitute(a,n,b,x);
	imprimirValores(b,n,x);	
}
void eliminate(double a[20][20], double s[], int n, double b[20]){
	double factor;
	
	for(int k=0; k<(n-1); k++)
	{	
		pivot(a,b,s,n,k);
		for(int i=k+1; i< n; i++)
		{
			factor=a[i][k]/a[k][k];
			for(int j=k+1; j<n; j++)
			{
				a[i][j]=a[i][j]-(factor * a[k][j]);
			}
			b[i]=b[i] - (factor * b[k]);
		}
	}
}
void pivot(double a[20][20], double b[20], double s[],int n, int k){
	int p=k;
	double dummy;
	double big = abs(a[k][k] / s[k]);
	
	for(int ii=k+1; ii<n; ii++)
	{
		dummy= abs(a[ii][k] / s[ii]);
		if(dummy > big)
		{
			big= dummy;
			p=ii;
		}
	}
	
	if( p!=k )
	{
		for(int jj=k; jj<n; jj++)
		{
			dummy=a[p][jj];
			a[p][jj]=a[k][jj];
			a[k][jj]=dummy;
		}
		dummy= b[p];
		b[p]=b[k];
		b[k]=dummy;
		dummy= s[p];
		s[p]=s[k];
		s[k]=dummy;
		
	}
}
void substitute(double a[20][20], int n, double b[20], double x[20])
{
	double sum;
	x[n]=b[n]/a[n][n];
	
	for(int i=n -1; i>-1; i--)
	{
		sum=0;
		for(int j=i+1; j<n; j++)
		{
			sum=sum + (a[i][j]*x[j]);			
		}
		x[i]=(b[i] - sum)/ a[i][i];
	}
}
void imprimirValores(double b[20], int n, double x[20])
{
	printf("\nSistema de ecuaciones: \n\n");
	char v[n];
	int flag=123-n;
	for(int i=0; i<n; i++)
	{
		v[i]=flag+i;
	}
	for(int i=0; i<n; i++)
	{
			printf("\t");
		for(int j=0; j<n; j++)
		{
			if(j!=0 && aCopia[i][j]>=0 )
			{
				printf("+");
			}else if(aCopia[i][j]<0)
			{
				aCopia[i][j]=abs(aCopia[i][j]);
				printf("-");
			}
			printf(" %lf%c ",aCopia[i][j],v[j]);
		}
		printf("= %lf \n",bCopia[i]);
	}
	printf("\n");
	printf("\nSolucion del sistema: \n\n");
	
	for(int i=0; i<n; i++)
	{
		printf("%c = %lf\n",v[i],x[i]);
	}
	
}
/*
3
1
1
4
2
2
2
6
2
2
1
5
2
3
1
1
6
2
1
9
2
2
7
3
1
2
5
2
1
2
7
2
1
*/


