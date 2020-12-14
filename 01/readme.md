# Trabalho pratico 1
Trabalho pratico 1 da disciplina de **Recuperação de Informação 2020/2** do Departamento de Ciência da Computação (DCC) da Universidade Federal de Minas Gerais (UFMG).
<hr/>

### Como executar (**Bash Ubuntu 18.04^**)
1. Clone o repositorio:\
    ``$ git clone http://github.com/EwertonDCSilv/IR-tp1`` 
2. Acesse a pasta criada:\
    ``$ cd tp-01/``
3. Defina o caminho (``ABS_PATH``) para a pasta das bibliotecas nas variaveis de ambiente do ``bash``:\
    ``$ export LD_LIBRARY_PATH={ABS_PATH}/IR-tp01/lib:$LD_LIBRARY_PATH``
3. Para compilar, execute o makefile:\
    ``$ make``\
    se preferir compilar e executar, faça\
    ``$ make run`` 
4. Para executar apenas:\
    ``$ ./bin/main``
    ou
    ./exec {numero_teste}
