rodando o arquivo in com N=10, temos como melhor resposta o 22108.761558914248
0-6-2-8-5-4-1-3-7-9

e a resposta demorou 0,1275s


rodando a versao sequencial do C++ o arquivo in com n=10 como melhor resposta 22108.8
0-6-2-8-5-4-1-3-7-9

e a resposta demorou 0,051s



para 12 pontos
11533.81823

python
3m14,560s

seq
0m4,952s

par com resultado errado
12566.35561
0m2,737s

par com critical
0m3,643s



g++ -O3 tsp-seq.cpp -o tsp-seq -fopenmp && ./tsp-seq < in12

g++ -O3 tsp-seq-bb.cpp -o tsp-seq-bb -fopenmp && ./tsp-seq-bb < in12

g++ -O3 tsp-par.cpp -o tsp-par -fopenmp && OMP_NUM_THREADS=4  ./tsp-par < in12

g++ -O3 tsp-bb.cpp -o tsp-bb -fopenmp && OMP_NUM_THREADS=4  ./tsp-bb < in12