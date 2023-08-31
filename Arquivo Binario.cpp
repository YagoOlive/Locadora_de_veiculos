#include <stdio.h>
#include <stdlib.h>
#include <String.h>

FILE *Id_Arquivo;

struct Registro_Carro
{
    char Placa[10];
    char Modelo[50];
    int Ano;
    int Flag;
    char Cor[30];
    int CpfAlugado;
    int Situacao;
};

struct Registro_Cliente
{
    char Nome[50];
    int Cpf;
    char Nascimento[10];
    int Flag;
};

void Grava_Dados(struct Registro_Carro Carro)
{
    if((Id_Arquivo = fopen("carros1.dat","a+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    } 
     
    Carro.Flag=1;

    fwrite(&Carro, sizeof(struct Registro_Carro),1, Id_Arquivo);      

    fclose(Id_Arquivo);
}

void Grava_DadosCliente(struct Registro_Cliente Cliente)
{
    if((Id_Arquivo = fopen("cliente1.dat","a+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de clientes para gravar!\n");
    } 
     
    Cliente.Flag=1;

    fwrite(&Cliente, sizeof(struct Registro_Cliente),1, Id_Arquivo);      
     
    fclose(Id_Arquivo);
}

void Le_Dados()
{
    if((Id_Arquivo = fopen("carros1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Carro Carro;
   
    while (!feof(Id_Arquivo))
    {
       
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1)
        {
            printf("Ano: %d\n",Carro.Ano);
            printf("Placa: %s\n",Carro.Placa);
            printf("Modelo: %s\n",Carro.Modelo);
            printf("Cor: %s\n",Carro.Cor);
            printf("CPF cliente: %d\n", Carro.CpfAlugado);
            printf("\n");
        }
    }
}

void Le_DadosCliente()
{
    if((Id_Arquivo = fopen("cliente1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de cliente para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Cliente Cliente;
   
    while (!feof(Id_Arquivo))
    {
       
        fread(&Cliente, sizeof(struct Registro_Cliente), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de clientes!\n");
        }
        else if(!feof(Id_Arquivo)&&Cliente.Flag==1)
        {
            printf("%s\n",Cliente.Nome);
            printf("%d\n",Cliente.Cpf);
            printf("%s\n",Cliente.Nascimento);
            printf("\n\n");
        }
    }
}

void altera(Registro_Carro CarroAlterado)
{
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Carro Carro;

    printf("*** ALTERACAO ***\n\n");
 
    int cont=-1;
    
    while (!feof(Id_Arquivo))
    {
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,CarroAlterado.Placa)==0)&&Carro.Flag==1)
        {

            fseek(Id_Arquivo, sizeof(Registro_Carro)*cont, SEEK_SET);     
    
            CarroAlterado.Flag=1;
            fwrite(&CarroAlterado, sizeof(Registro_Carro),1, Id_Arquivo);
       
            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
    fclose(Id_Arquivo);
}

void AlteraCliente(Registro_Cliente Clientealterado)
{
    if((Id_Arquivo = fopen("cliente1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo clientes para alterar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Cliente Cliente;

    printf("*** ALTERACAO ***\n\n");
    int cont=-1;
    
    while (!feof(Id_Arquivo))
    {
        
        fread(&Cliente, sizeof(struct Registro_Cliente), 1, Id_Arquivo);
        cont++;
        
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de clientes!\n");
        }
        else if((!feof(Id_Arquivo))&&(Cliente.Cpf==Clientealterado.Cpf)&&Cliente.Flag==1)
        {
    
            fseek(Id_Arquivo, sizeof(Registro_Cliente)*cont, SEEK_SET);     
            Clientealterado.Flag=1;
            
            fwrite(&Clientealterado, sizeof(Registro_Cliente),1, Id_Arquivo);

            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
    fclose(Id_Arquivo);
}

void exclui(char Placa[7])
{
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Carro Carro;

    printf("*** Exclusao ***\n\n");
    int cont=-1;
    
    while (!feof(Id_Arquivo))
    {
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,Placa)==0)&& Carro.Flag==1)
        {
 
            Carro.Flag=0;
            
            fseek(Id_Arquivo, sizeof(Registro_Carro)*cont, SEEK_SET);     

            fwrite(&Carro, sizeof(Registro_Carro),1, Id_Arquivo);
 
            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
    fclose(Id_Arquivo);
}

void excluicliente(int Cpf)
{
    if((Id_Arquivo = fopen("cliente1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de clientes para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Cliente Cliente;

    printf("*** Exclusao ***\n");

    int cont=-1;
    
    while (!feof(Id_Arquivo))
    {

        fread(&Cliente, sizeof(struct Registro_Cliente), 1, Id_Arquivo);
        
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de cliente!\n");
        }
        else if((!feof(Id_Arquivo))&&Cliente.Cpf==Cpf&& Cliente.Flag==1)
        {
            Cliente.Flag=0;
            
            fseek(Id_Arquivo, sizeof(Registro_Cliente)*cont, SEEK_SET);     
            
            fwrite(&Cliente, sizeof(Registro_Cliente),1, Id_Arquivo);

            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
    fclose(Id_Arquivo);
}

void Alugar(Registro_Carro CarroAlugado)
{
	int contAux=0;
	
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Carro Carro;
 
    int cont=-1;
    
    while (!feof(Id_Arquivo))
    {

        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,CarroAlugado.Placa)==0)&&Carro.Flag==1&&Carro.Situacao==0)
        {
            fseek(Id_Arquivo, sizeof(Registro_Carro)*cont, SEEK_SET);     
    
            Carro.Situacao=1;
            Carro.CpfAlugado = CarroAlugado.CpfAlugado;
            fwrite(&Carro, sizeof(Registro_Carro),1, Id_Arquivo);
       
            fseek(Id_Arquivo, 0, SEEK_END);
            printf("Carro alugado!\n"); 
            break;
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1&&Carro.Situacao==1)
        {
            contAux = 1;
            break;
        }
    }
    if(contAux>0)
        printf("*** CARRO INDISPONIVEL!*** \n");

    fclose(Id_Arquivo);
}

void Devolver(Registro_Carro CarroAlugado)
{
    if((Id_Arquivo = fopen("carros1.dat","r+b")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Carro Carro;
 
    int cont=-1;
    
    while (!feof(Id_Arquivo))
    {
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        
        cont++;
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if((!feof(Id_Arquivo))&&(strcmp(Carro.Placa,CarroAlugado.Placa)==0)&&Carro.Flag==1&&Carro.Situacao==1)
        {

            fseek(Id_Arquivo, sizeof(Registro_Carro)*cont, SEEK_SET);     
    
            Carro.Situacao=0;
            Carro.CpfAlugado=0;
            fwrite(&Carro, sizeof(Registro_Carro),1, Id_Arquivo);
       
            fseek(Id_Arquivo, 0, SEEK_END); 
        }
    }
    fclose(Id_Arquivo);
}

void Disponiveis()
{
    if((Id_Arquivo = fopen("carros1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Carro Carro;
   
    while (!feof(Id_Arquivo))
    {
       
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1&&Carro.Situacao==0)
        {
            printf("Ano: %d\n",Carro.Ano);
            printf("Placa: %s\n",Carro.Placa);
            printf("Modelo: %s\n",Carro.Modelo);
            printf("Cor: %s\n",Carro.Cor);
            printf("\n");
        }
    }
}


void CarrosAlugados()
{
    if((Id_Arquivo = fopen("carros1.dat","r")) == NULL)
    {
        printf("Problemas na abertura do arquivo de carros para gravar!\n");
    }  
    
    rewind(Id_Arquivo);
    
    Registro_Carro Carro;
   
    while (!feof(Id_Arquivo))
    {
       
        fread(&Carro, sizeof(struct Registro_Carro), 1, Id_Arquivo);
        if(ferror(Id_Arquivo))
        {
            printf("Problemas na leitura do arquivo de carros!\n");
        }
        else if(!feof(Id_Arquivo)&&Carro.Flag==1&&Carro.Situacao==1)
        {
            printf("Ano: %d\n",Carro.Ano);
            printf("Placa: %s\n",Carro.Placa);
            printf("Modelo: %s\n",Carro.Modelo);
            printf("Cor: %s\n",Carro.Cor);
            printf("CPF do cliente: %d\n", Carro.CpfAlugado);
            printf("\n");
        }
    }
}

int main()
{
    struct Registro_Carro Carro;
    struct Registro_Cliente Cliente;
	
	int op=1;
	char auxcad[10];
	
	while (op!=0){
        system("cls");
        printf("*** Digite a sua escolha*** \n");      
        printf("1- Cadastrar Dados: \n");      
        printf("2- Exibir Dados: \n");     
        printf("3- Alterar: \n");       
        printf("4- Excluir: \n"); 
        printf("5- Alugar Carro: \n");       
        printf("6- Devolucao de Carro: \n"); 
        printf("7- Exibir carros disponiveis:\n"); 
        printf("8- Exibir carros Alugados:\n"); 
        printf("0- Sair do Programa:\n");
        scanf("%d",&op);
        switch (op){
                 
            case 1: 
            {   
		        printf("Informe(carro/cliente): ");
                scanf("%s", &auxcad);
                if(strcmp(auxcad,"carro")==0){
               	
               	    printf("*** CADASTRO DE CARROS ***\n");
                    fflush(stdin);
                    printf("Placa: "); scanf("%s",&Carro.Placa); 
                    fflush(stdin);
                    printf("\nModelo: "); scanf("%s",&Carro.Modelo);  
                    fflush(stdin);
                    printf("\nCor: "); scanf("%s",&Carro.Cor);        
                    fflush(stdin);
                    printf("\nAno: "); scanf("%d",&Carro.Ano);
                    fflush(stdin);
                    Carro.Situacao=0;
					Carro.CpfAlugado=0; 
                    Grava_Dados(Carro);
                    system("pause");
			    }
				else if(strcmp(auxcad,"cliente")==0){
					
					printf("*** CADASTRO DE CLIENTES ***\n");
                    fflush(stdin);
                    printf("Nome: "); scanf("%s",&Cliente.Nome); 
                    fflush(stdin);
                    printf("\nCPF: "); scanf("%d",&Cliente.Cpf);  
                    fflush(stdin);
                    printf("\nData de Nascimento: "); scanf("%s",&Cliente.Nascimento);    
                    Grava_DadosCliente(Cliente);
                    system("pause");
				} 
				else{
					printf("***ENTRADA DE DADOS INVALIDA***\n");
					system("pause");
				}
            break;  
            }
            case 2: 
            {     
                printf("*** VISUALIZAR CADASTROS ***\n");
                printf("Informe(carro/cliente): ");
                scanf("%s", &auxcad);
                if(strcmp(auxcad,"carro")==0){
                	printf("\n****EXIBINDO CARROS CADASTRADOS***\n");
                	Le_Dados();
                	system("pause");
				}
				else if(strcmp(auxcad,"cliente")==0){
					printf("\n*** EXIBINDO CLIENTES CADASTRADOS ***\n");
                    Le_DadosCliente();
                    system("pause");
				}
				else{
					printf("***ENTRADA DE DADOS INVALIDA***\n");
					system("pause");
				}
            break;   
            }
            case 3: 
            {
                printf("*** ALTERAR CADASTROS ***\n");
                printf("Informe(carro/cliente): ");
                scanf("%s", &auxcad);
                if(strcmp(auxcad,"carro")==0){
                	printf("*** ALTERANDO CADASTRO DE UM CARRO ***\n");
                	printf("\nPlaca do carro a ser alterado: "); scanf("%s",&Carro.Placa); 
                    printf("\nModelo: "); scanf("%s",&Carro.Modelo);  
                    printf("\nCor: "); scanf("%s",&Carro.Cor);        
                    printf("\nAno: "); scanf("%d",&Carro.Ano);
                    altera(Carro);
                    system("pause");
				}
				else if(strcmp(auxcad,"cliente")==0){
					printf("*** ALTERANDO CADASTROS DE UM CLIENTE ***\n");
					printf("\nCPF do cliente: "); scanf("%d",&Cliente.Cpf); 
                    fflush(stdin);
                    printf("Nome: "); scanf("%s",&Cliente.Nome);  
                    fflush(stdin);
                    printf("\nData de Nascimento: "); scanf("%s",&Cliente.Nascimento);    
                    AlteraCliente(Cliente);
                    system("pause");
				}
				else{
					printf("***ENTRADA DE DADOS INVALIDA***\n");
					system("pause");
				}
				      
            break;
            }
            case 4: 
            {
                
                printf("*** EXCLUSAO DE CADASTRO ***\n");
                printf("Informe(carro/cliente): ");
                scanf("%s", &auxcad);
                if(strcmp(auxcad,"carro")==0){
                	
                	char placa[7];
                	printf("*** EXCLUINDO UM CARRO ***\n");
                    printf("\nDigite a placa do carro a ser excluido:");
                    scanf("%s", placa);
                    exclui(placa);
                    system("pause");
				}
				else if(strcmp(auxcad,"cliente")==0){
					
					int cpf;
                    printf("*** EXCLUINDO UM CLIENTE ***\n");
                    printf("\nDigite o cpf do cliente a ser excluido:");
                    scanf("%d", &cpf);
                    excluicliente(cpf);
                    system("pause");
				}
				else{
					printf("***ENTRADA DE DADOS INVALIDA***\n");
					system("pause");
				}  
            break;
            } 
            case 5: 
            {     
               	printf("\nPlaca do carro a ser alugado: "); scanf("%s",&Carro.Placa);
                fflush(stdin);
                printf("\nCPF: "); scanf("%d",&Carro.CpfAlugado);  
                fflush(stdin);
                Alugar(Carro);
				printf("*** OPERACAO CONCLUIDA ***\n");
                system("pause");
            break;  
            }
            case 6: 
            {     
               	printf("\nPlaca do carro a ser Devolvido: "); scanf("%s",&Carro.Placa);
                fflush(stdin);
                printf("\nCPF: "); scanf("%d",&Carro.CpfAlugado);  
                fflush(stdin);
               
                Devolver(Carro);
				printf("*** CARRO DEVOLVIDO ***\n");
                system("pause");
            break;   
            }
            case 7: 
            {
               	printf("\n****EXIBINDO CARROS DISPONIVEIS***\n");
                Disponiveis();
                system("pause");
            break;
            }
			case 8: 
            {
               	printf("\n****EXIBINDO CARROS ALUGADOS***\n");
                CarrosAlugados();
                system("pause");
            break;
            }      
        }      
    }
 	printf("***     FIM DO PROGRAMA     ***\n");
	system("pause");
}
