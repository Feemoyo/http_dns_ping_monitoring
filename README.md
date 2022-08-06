# Documentação 

Olá, este projeto tem como intuito monitorar protocolo HTTP, PING e DNS (obviamente existe espaço para adicionar o que desejar). Esta documentação é dividida em 3 partes:

1- Minha rotina para a confecção do projeto;

2- Código;	

3- Agradecimentos.

A execução é  atraves do:
```txt
make all
```
que irá gerar o arquivel executável


## 1- Minha rotina para a confecção do projeto:

>	Meus quatro primeiros dias foram de reflexão sobre o problema apresentado e como poderia fazê-lo com meu conhecimento atual (claramente um lapso de procrastinação).

>	No quinto dia comecei a produzir coisas pequenas, pensando em futuras opções de ferramentas/tecnologias como, por exemplo, um esqueleto de uma MAIN e outros 3 arquivos com algumas funções básicas para executar tudo relacionado a HTTP, PING e DNS respectivamente. Também tive problemas com bibliotecas, pois inicialmente estava seguindo conteúdos enviados no chat do labs, onde decidi instalar WSL (perdi boa parte do sexto dia por causa de teimosia e apego ao workspace).

>	No sexto dia conheci o magnifico "popen", que daria então oportunidade para fazer os 3 protocolos com apenas "uma" única ferramenta, precisei ler muito sua documentação para ter noção do que estava fazendo, junto a um punhado de testes que eu acreditava ser necessário.

>	O sétimo dia foi quando comecei realmente a pôr em prática boa parte dos testes e perceber que meus testes não adiantaram de quase nada. Não tinha noção do que era PING (apenas brincava de pingar o “google.com” quando a internet caia), DNS e não fazia ideia do que precisava trazer com o CURL, mas produzi mesmo assim.

>	Finalmente no oitavo dia (data de entrega), faltando "--simplify", um timer descente e a documentação para fazer, cá estou eu, produzindo ela sem nunca ter feito antes, com base nos dois primeiros links que achei na pesquisa.

## 2- Código

>	Este projeto contém apenas 8 arquivos “.c”, divididos entre os necessários para o HTTP, PING, DNS, MAIN e um exclusivo para setar o tipo de protocolo que estaremos trabalhando (este está facilmente montado para caso precise adicionar algum tipo de protocolo).

>	Os arquivos a respeito de HTTP, PING e DNS são idênticos, portanto irei usar como exemplo o HTTP quando for falar sobre as possíveis melhorias para o código.

>	Estarei usando alguns sinais no início da linha para apontar problemas e melhorias.
>	     "*" para melhoria;
>	     "!" para problemas;


### structs (monitoring.h)

	> t_protocol  - recebe os 3 primeiros parâmetros do monitoring.db;

	> t_http	- recebe t_protocol e os parâmetros necessários para o mesmo;

	> t_ping	- recebe t_protocol e os parâmetros necessários para o mesmo;

	> t_dns	- recebe t_protocol e os parâmetros necessários para o mesmo;


### ft_main.c

>ft_get_next_line junto com ft_split envia uma string formatada para uma função do arquivo ft_set_protocol.c com uma struct contendo 3 parâmetros do arquivo .db;


### ft_set_protocol.c
	recebe a string do primeiro protocolo do monitoring.db;

	cria e formata structs para suportar cada tipo de protocolo;

	preenche os 3 primeiros valores da struct padrão;

	identifica o protocolo que recebeu e entra em sua respectiva função;
	(ambas a funções tem espaço para ampliar os protocolos tratados com facilidade)

	!- não existe free nas structs após a finalização da função;


### ft_http.c (ft_ping.c e ft_dns.c provavelmente tem os mesmos erros e qualidades)
	verifica o método recebido;
	inicia o popen para executar comandos do bash;
	finaliza o popen com o pclose;
	!- não tem opção de simplify
	* tem capacidade para implementar edições que facilitam a leitura do .log


### ft_http_utils.c (ft_ping_utils.c e ft_dns_utils.c tem as mesmas propriedades)
	recebe sua respectiva struct;
	ordena os parâmetros do .db na devida struct;



## 3- Testes

	Irei documentar alguns testes realizados:

	passar diversas linhas para o monitoring.db (OK);

	verificação do log (OK);

	!- não testei passar parâmetros errados;

	!- por favor NÃO passe o valgrind;

	!- não contém --simplify;
