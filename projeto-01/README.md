# Como executar
Para executar os testes, basta digitar o seguinte comando abaixo, sendo o primeiro item o executavel e o segundo item o arquivo de entrada.
```
./main < entrada > saida
```

### Input
```
w h mu_d
N
m wr hr x y vx vy 
.... 
m wr hr x y vx vy 
dt print_freq max_iter
```
w, h e mu_d se referem ao tamanho do campo de simulação e seu coeficiente de atrito dinâmico.  
N é o número de retângulos da simulação. 
Cada linha subsequente contém um retângulo com as seguintes propriedades:  
massa m  
largura wr  
altura hr  
posição inicial (x, y)  
velocidade inicial (vx, vy)  
dt representa o tamanho do passo de simulação.  
a cada print_freq iterações o estado da simulação é mostrado na saída padrão.  
a simulação deverá rodar até max_iter vezes. Note que ela pode acabar antes.  
Note que os retângulos só recebem velocidade inicial, porém a presença de atrito causa uma aceleração neles.

## Output
A cada print_freq iterações o programa mostra o estado atual da simulação no seguinte formato.  
```
iter
x1 y1 vx1 vy1
...
xN yN vxN vyN
--------
```
Quando a simulação terminar você também deverá imprimir o estado final da simulação. Isto pode ocorrer se max_iter iterações forem feitas ou se o módulo da velocidade de todos os retângulos for menor que $0,0001 m/s$.

