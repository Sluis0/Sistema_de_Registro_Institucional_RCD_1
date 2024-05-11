#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Não funciona ainda
#include <string.h>


int registro() // cadastro de usuario no sistema
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
    // criação de variaveis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); //armazena no variavel cpf a string digitada

    strcpy(arquivo, cpf); // copia o conteudo da variavel cpf para o arquivo

    FILE *file; // criando o arquivo
    file = fopen(arquivo, "a"); // abre o arquivo em modo escrita
    fprintf(file, "%s,", cpf); // escreve dentro do arquivo 'file' que vem primeiro, depois escreve ',' por meio do %s e então escreve a variavel cpf
    fclose(file); // fecha o arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s\n", cargo);
    fclose(file);

    system("pause"); // faz o sistema esperar na tela
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
    char cpf[40];
    char conteudo[200];
  
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // armazena o conteudo escrito na variavel cpf
    
    FILE *file;
    file=fopen(cpf, "r"); // abre o arquivo no modo leitura por causa do "r"

    if(file == NULL) // se o arquivo não existir
    {
    printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }
  
    while (fgets(conteudo, 200, file) !=NULL)// armazena dentro da variavel 'conteudo' com limete maximo de 200 caracteres as coisas que tem dentro de 'file'
    {
    printf("\nEssas são as informações do usuario: ");
    printf("%s", conteudo);
    printf("\n\n"); 
    }
  
    system("pause");
}

int deletar()
{
  char cpf[40];
  printf("Digite o CPF do usuario a ser deletado: ");
  scanf("%s", cpf);

  FILE *file;
  file=fopen(cpf, "r");
  
  if(file == NULL) // verifica se o arquivo existe
  {
    printf("O usuario não se encontra no sistema!.\n"); // se não existir, exibe essa mensagem
    system("pause");
  }
    else
    {
        fclose(file); // se existir, fecha o arquivo e continua

        if (remove(cpf) == 0) // deleta o arquivo
        {
            printf("Usuario deletado com sucesso!\n");
            system("pause");
        }
        
        else // se não conseguir deletar, exibe essa mensagem
        {
            printf("Erro ao deletar o usuario!\n");
            system("pause");
        }
    }


}
int main()
{
    int opcao=0; //Definição de variaveis
    int laco=1;
  
    for (laco=1;laco==1;) // cria um laço de repetição 'for' e inicia 'laco' com valor '1' 
    {// laco==1, enquanto o laco tiver valor 1 ele continuará em loop

    system("cls");

    setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
  
    printf("###Sistema de Registro Institucional RCD###\n\n"); //Inicio do menu
    printf("Escolha a opção desejada do menu:\n\n");
    printf("\t1 - Registrar nomes\n");
    printf("\t2 - Consultar nomes\n");
    printf("\t3 - Deletar nomes\n\n"); // Fim do Menu
    printf("Opção:  \n");

    scanf("%d", &opcao); //Armazenando escolha do usuario
 
    system("cls"); // limpa a tela

    switch(opcao) // switch para entrar nas funções
    {
    case 1: // se o usuario digitar 1 entra na função registro
    registro(); // chama o int registro
    break; // quando a função termidar de ser executada o break sai do switch
    
    case 2: // se o usuario digitar 2 entra na função consulta
    consulta();
    break;
    
    case 3: // se o usuario digitar 3 entra na função deletar
    deletar();
    break;

    default: // se o usuario digitar algum valor diferente das opções do switch ele da erro
    printf("Essa opção não está dispinivel\n");
    system("pause");
    break;
    }// fim do switch 

    
    // fim da seleção
    }
}
