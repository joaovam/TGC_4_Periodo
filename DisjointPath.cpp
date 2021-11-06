// C++ program to find maximum number of edge disjoint paths

#include "DisjointPath.h"
using namespace std;


/*retorna verdadeiro caso exista um caminho da fonte 's' ao nó destino 't' no grafo residual. Também preenche o vetor
paresnt [] para guardar o caminho achado*/
bool disjoint_Path::buscaEmLargura(int rGraph[V][V], int s, int t, int parent[])
{
    //Cria um vetor (bool) de nós visitados e marca todos os vértices como não visitados 
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    //Cria uma fila de nós não visitados, enfileira o vértice fonte e o marca como visitado, colocando-o no array de visitados
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;  // s não tem pai

    // Loop da busca em largura - enquanto todos os nós não forem visitados, vai tentando achar os caminhos. 
    while (!q.empty())
    {
        int u = q.front(); 
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    //caso encontremos o nó destino na busca em largura começando do nó de partida, retorna-se true. Caso contrário, false
    return (visited[t] == true);
}



//Acha o número máximo de caminhos disjuntos em arestas de s para t. Para isso, utilizamos o algoritmo de Ford Fulkerson
int disjoint_Path::acharCaminhosDisjuntos(int **graph, int s, int t)
{
    int i, j;

    /*Cria um grafo residual e o preenche com as capacidades do grafo original como capacidades do grafo residual.*/
    int rGraph[V][V]; // Grefo residual no qual rGraph[i][j] indica a capacidade residual da aresta de i para j caso exista uma aresta. Se rGraph[i][j] = 0, não há arestas entre eles. 

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            rGraph[i][j] = graph[i][j];
        }
    }

    int parent[V]; // Esse array é preenchido com a busca em largura e guarda o caminho

    int max_flow = 0; // Não existe fluxo máximo inicialmente. 
    //Aumenta o fluxo enquanto existe caminho da fonte para o destino. 
    while (buscaEmLargura(rGraph, s, t, parent))
    {
        /*encontra a capacidade mínima residual das arestas ao longo do caminho preenchido pela busca em largura. Ou podemos dizer, 
        acha o fluxo máximo pelo camonho encontrado.*/
        
        int path_flow = INT_MAX;

        for (j = t; j != s; j = parent[j])
        {
            i = parent[j];
            path_flow = min(path_flow, rGraph[i][j]);
        }

        //atualiza as capacidades residuais das arestas e reverte as arestas ao longo do caminho. 
        for (j = t; j != s; j = parent[j])
        {
            i = parent[j];
            rGraph[i][j] -= path_flow;
            rGraph[j][i] += path_flow;
            this->graph[i][j] += path_flow;
        }
        //Adiciona o fluxo do caminho ao fluxo máximo . 
        max_flow += path_flow;
    }

    //Retorna o fluxo máximo (fluxo máximo = número de caminhos disjuntos em arestas.)
    return max_flow;
}

void disjoint_Path::procurarCaminhosDisjuntos(int **graph, int s, int t)
{
    int x = acharCaminhosDisjuntos(graph, s, t);
    cout << "O número máximo de caminhos disjuntos é :  " << x << endl;
    /*cout << "Grafo original:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    } */
    cout << "Caminhos encontrados:" << endl;
    buscaEmProfundidade(s, t);
}

void disjoint_Path::buscaEmProfundidade(int s, int t)
{
    stack<int> st;  //cria uma pilha para empilhar os nós .

    int parent[V]; //vetor que representa o pai dos nós e que guardará o caminho. 
    bool visited[V]; //vetor para representar quais nós já foram visitados. 
    memset(visited, 0, sizeof(visited)); 

    //empila o nó de partida e o coloca na lista de nós já visitados. 
    st.push(s); 
    visited[s] = true;

    //loop da busca em profundidade. Enquanto todos os nós não forem visitados, ele ocorre. Nele, vamos procurando  os caminhos e colocando 0 
    //nas arestas já visitadas para dizer que elas não estão mais disponíveis para caminhos (já que serão disjuntos).
    for (int i = 0; i < V; i++)
    {
        if (this->graph[s][i] > 0)
        {           
            cout << s ;             
            cout << " -> ";
            cout << i ;            
            if( i < V -1)
                cout << " -> ";
            this->graph[s][i] = 0;            
            buscaEmProfundidadeREC(i, t);
        }
    }
}

void disjoint_Path::buscaEmProfundidadeREC(int atual, int final)
{
    //caso cheguemos no nó final, nossa busca termina. 
    if (atual == final)
    {
        cout << endl;
    }
    else
    {
        for (int i = 0; i < V; i++)
        {
            if (this->graph[atual][i] > 0)
            {                
                cout << i;
                if(final < V-1)    
                    cout << " ->";
                //eliminamos a aresta
                this->graph[atual][i] = 0;
                //vamos andando em nosso grafo. Agora o nó atual será o próximo nó. 
                buscaEmProfundidadeREC(i, final);
            }
        }
    }
}

