#include <iostream>             // Entrada e sa�da de dados
#include <iomanip>              // Manipuladores
#include <string>               // Strings de C++
#include <vector>		// Classe de vetores
#include <algorithm>		// Classe para algoritmos gen�ricos
#include <memory>               // destroe e construct
#include <cstdlib>              // Fun��o rand
#include <numeric>              // Fun��o inner_product
#include <functional>           // Fun��o 
#include <iterator>             // Iteradores

using namespace std;		// Define o uso do espa�o de nomes std

/** Classe para teste dos algoritmos gen�ricos */
class CTesteFuncoesGenericas
{
public:
  vector <int> v, v2, v3;        // Atributos
  string msg;
  CTesteFuncoesGenericas()       // Construtor
  { InicializaVetor(v);          // Preenche o vetor v com valores
    v3 = v2 = v;
    msg = "\n-------------------------------------------\n";
  }

  // M�todos p�blicos
  void EntradaUsuario (  vector <int>& vetor );
  void InicializaVetor(  vector <int>& vetor, int n=5 );
  bool Run();
private:                         // M�todos privados
  void Uso_de_fill_n();          // Preenchimento
  void Uso_de_equal();           // Compara��o
  void Uso_de_mismatch(); 
  void Uso_de_includes(); 
  void Uso_de_remove_copy_if();   // Remo��o
  void Uso_de_replace_copy_if();  // Trocas
  void Uso_de_inplace_merge();    // Misturar/mesclar/inverter
  void Uso_de_reverse_copy(); 
  void Uso_de_random_shuffle();
  void Uso_de_find_if_off();      // Pesquisa
  void Uso_de_adjacent_difference();
  void Uso_de_search_n(); 
  void Uso_de_binary_search();
  void Uso_de_advance();
  void Uso_de_next_permutation(); // Ordena��o
  void Uso_de_reverse();
  void Uso_de_rotate();
  void Uso_de_generate();         // Transforma��o
  void Uso_de_for_each(); 
  void Uso_de_transform();
  void Uso_de_nth_element();      // Matem�ticos
  void Uso_de_counf_if(); 
  void Uso_de_accumulate();
  void Uso_de_inner_product();
  void Uso_de_set_union();
  void Uso_de_set_intersection();
  void Uso_de_set_difference();
  void Uso_de_set_symmetric_difference();  
  void Uso_de_make_heap();        // Ordena��o por pilha
  void Uso_de_plus();             // Fun��es objeto
  void Uso_de_minus();
  void Uso_de_times();
  void Uso_de_multiplies();
  void Uso_de_divides();
  void Uso_de_modulus();
  void Uso_de_negate();
  void Uso_de_equal_to();
  void Uso_de_not_equal_to();
  void Uso_de_greater(); 
  void Uso_de_less();
  void Uso_de_greater_equal(); 
  void Uso_de_less_equal(); 
  void Uso_de_logical_and();       // Fun��es l�gicas
  void Uso_de_logical_or(); 
  void Uso_de_logical_not(); 
  void Uso_de_bind2nd();            // Adaptadores (not1 find_if)
  void Uso_de_men_fun_ref(const vector<string>& s);
}; // fim da classe

// Solicita valores do vetor
void CTesteFuncoesGenericas::EntradaUsuario( vector <int>& vetor )
{
  vetor.clear();  // Zera o vetor
  int data;
  do	
    {
      cout << "Entre com o dado (" << setw (3) << vetor.size () 
	   << ")(ctrl+d encerra entrada):";
      cin >> data;
      cin.get();
      if(cin.good())
	vetor.push_back(data);
    } while ( cin.good());
  cin.clear(); 	// Reseta objeto cin para estado ok
}

// Preenchendo o vetor com uma sequ�ncia de valores padr�es
void CTesteFuncoesGenericas::InicializaVetor(  vector <int>& vetor , int n)
{
  vetor.clear();
  for (int i = 0; i < n ; i++)
    vetor.push_back(i);
}

// Declara��o e defini��o da sobrecarga de << 
template <typename Tipo>
ostream & operator<< ( ostream & os , const vector < Tipo >&v)
{
  for (int i = 0; i < v.size() ; i++)
    os << setw (5) << setfill(' ') << v[i] << '\t';
  return os;
}

// Fun��o de sele��o da fun��o a ser testada
bool CTesteFuncoesGenericas::Run()
{
  vector<string> funcoes =  {   
    "fill_n", "equal", "mismatch", "includes", "remove_copy_if", "replace_copy_if", "inplace_merge", "reverse_copy", "random_shuffle", "find_if", "find_if_off", "adjacent_difference", "search_n", "binary_search", "advance", "next_permutation", "reverse", "rotate", "generate", "for_each", "transform",  "nth_element", "counf_if", "accumulate", "inner_product", "set_union", "set_intersection", "set_difference", "set_symmetric_difference", "make_heap", "plus", "minus", "times", "multiplies", "divides", "modulus", "negate", "equal_to", "not_equal_to", "greater", "less", "greater_equal", "less_equal", "logical_and", "logical_or", "logical_not", "bind2nd", "not1", "men_fun_ref", " Mostra vetor"};
    
    cout << "============================================================\n"
       << "============= Qual fun��o deseja testar ??? ================\n"
       << "============================================================\n";
  for (int i = 0; i < 30 ; i++ )
    { 
    //  funcoes.push_back(vs[i]); 
      if(funcoes[i] != "")
	cout << "Uso de " << funcoes[i] << setw(50 - funcoes[i].size()) << setfill('.') 
	     << i << endl;
    }
  int selecao;
  cin >> selecao; cin.get();
  if(selecao >= funcoes.size()) return 0;
  InicializaVetor(v);
  cout << setfill(' ')  << "Vetor  v= " << v << endl;  

  if(funcoes[selecao]=="fill_n")                 Uso_de_fill_n ();
  else if(funcoes[selecao]=="equal")             Uso_de_equal ();
  else if(funcoes[selecao]=="mismatch")          Uso_de_mismatch ();
  else if(funcoes[selecao]=="includes")          Uso_de_includes ();
  else if(funcoes[selecao]=="remove_copy_if")    Uso_de_remove_copy_if ();
  else if(funcoes[selecao]=="replace_copy_if")   Uso_de_replace_copy_if ();
  else if(funcoes[selecao]=="inplace_merge")     Uso_de_inplace_merge ();
  else if(funcoes[selecao]=="reverse_copy")      Uso_de_reverse_copy ();
  else if(funcoes[selecao]=="random_shuffle")    Uso_de_random_shuffle ();
  else if(funcoes[selecao]=="find_if")           Uso_de_bind2nd();
  else if(funcoes[selecao]=="find_if_off")       Uso_de_find_if_off ();
  else if(funcoes[selecao]=="adjacent_difference")Uso_de_adjacent_difference ();
  else if(funcoes[selecao]=="search_n")          Uso_de_search_n ();
  else if(funcoes[selecao]=="binary_search")     Uso_de_binary_search ();
  else if(funcoes[selecao]=="advance")           Uso_de_advance ();
  else if(funcoes[selecao]=="next_permutation")  Uso_de_next_permutation ();
  else if(funcoes[selecao]=="reverse")           Uso_de_reverse ();
  else if(funcoes[selecao]=="rotate")            Uso_de_rotate ();
  else if(funcoes[selecao]=="generate")          Uso_de_generate ();
  else if(funcoes[selecao]=="for_each")          Uso_de_for_each ();
  else if(funcoes[selecao]=="transform")         Uso_de_transform ();
  else if(funcoes[selecao]=="nth_element")       Uso_de_nth_element ();
  else if(funcoes[selecao]=="counf_if")          Uso_de_counf_if ();
  else if(funcoes[selecao]=="accumulate")        Uso_de_accumulate ();
  else if(funcoes[selecao]=="inner_product")     Uso_de_inner_product ();
  else if(funcoes[selecao]=="set_union")         Uso_de_set_union ();
  else if(funcoes[selecao]=="set_intersection")  Uso_de_set_intersection ();
  else if(funcoes[selecao]=="set_difference")    Uso_de_set_difference ();
  else if(funcoes[selecao]=="set_symmetric_difference")Uso_de_set_symmetric_difference ();
  else if(funcoes[selecao]=="make_heap")         Uso_de_make_heap ();
  else if(funcoes[selecao]=="plus")              Uso_de_plus ();
  else if(funcoes[selecao]=="minus")             Uso_de_minus ();
  else if(funcoes[selecao]=="times")             Uso_de_times ();
  else if(funcoes[selecao]=="multiplies")        Uso_de_multiplies ();
  else if(funcoes[selecao]=="divides")           Uso_de_divides ();
  else if(funcoes[selecao]=="modulus")           Uso_de_modulus ();
  else if(funcoes[selecao]=="negate")            Uso_de_negate ();
  else if(funcoes[selecao]=="equal_to")          Uso_de_equal_to ();
  else if(funcoes[selecao]=="not_equal_to")      Uso_de_not_equal_to ();
  else if(funcoes[selecao]=="greater")           Uso_de_greater ();
  else if(funcoes[selecao]=="less")              Uso_de_less ();
  else if(funcoes[selecao]=="greater_equal")     Uso_de_greater_equal ();
  else if(funcoes[selecao]=="less_equal")        Uso_de_less_equal ();
  else if(funcoes[selecao]=="logical_and")       Uso_de_logical_and ();
  else if(funcoes[selecao]=="logical_or")        Uso_de_logical_or ();
  else if(funcoes[selecao]=="logical_not")       Uso_de_logical_not ();
  else if(funcoes[selecao]=="bind2nd")           Uso_de_bind2nd ();
  else if(funcoes[selecao]=="not1")              Uso_de_bind2nd (); // usa not1
  else if(funcoes[selecao]=="men_fun_ref")       Uso_de_men_fun_ref (funcoes);

  // Mostra o vetor
  else if(funcoes[selecao]=="Mostra vetor")
    cout << setfill(' ') << "Vetor  v= " << v << endl;      
  // Sai do programa
  else if(funcoes[selecao]=="SAIR DO PROGRAMA" )
    return 0;

  cout <<"\a-->Pressione enter para continuar";
  cin.get();
  cin.clear();
  return 1; // se n�o escolheu sair retorna verdadeiro
}

// Preenchimento
void CTesteFuncoesGenericas::Uso_de_fill_n()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 
// Compara��o
void CTesteFuncoesGenericas::Uso_de_equal()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 
void CTesteFuncoesGenericas::Uso_de_mismatch()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// CTesteFuncoesGenericas::Uso_de_includes
void CTesteFuncoesGenericas::Uso_de_includes()
{
  v3 = v2 = v ;       v3.push_back(123);      v2.push_back(333);
  cout << setw(30)<< "Vetor  v2= "  << v2  << endl;  
  cout << setw(30)<< "Vetor  v3= "  << v3  << endl;  
  //  cout.imbue(locale("pt_BR")); // opcional
  cout << setw(30)<< "v  inclue v2 -> "<< boolalpha << 
    includes ( v.begin(),  v.end(),  v2.begin(), v2.end() )<< endl;
  cout << setw(30)<< "v3 inclue v2 -> "<< boolalpha << 
    includes ( v3.begin(), v3.end(), v2.begin(), v2.end() )<< endl;
  cout << setw(30)<< "v  inclue v3 -> "<< boolalpha << 
    includes ( v.begin(),  v.end(),  v3.begin(), v3.end() )<< endl;
  cout << setw(30)<< "v2 inclue v3 -> "<< boolalpha << 
    includes ( v2.begin(), v2.end(), v3.begin(), v3.end() )<< endl;
  cout << setw(30)<< "v2 inclue v  -> "<< boolalpha << 
    includes ( v2.begin(), v2.end(), v.begin(), v.end() )<< endl;
  cout << setw(30)<< "v3 inclue v  -> "<< boolalpha << 
    includes ( v3.begin(), v3.end(), v.begin(), v.end() ) << endl;
}

// Remo��o
void CTesteFuncoesGenericas::Uso_de_remove_copy_if()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Trocas
void CTesteFuncoesGenericas::Uso_de_replace_copy_if()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Misturar/mesclar/inverter
void CTesteFuncoesGenericas::Uso_de_inplace_merge()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 
  
void CTesteFuncoesGenericas::Uso_de_reverse_copy()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Embaralha os elementos do container
void CTesteFuncoesGenericas::Uso_de_random_shuffle()
{
  random_shuffle(v.begin(),v.end());
  cout << "Vetor  v ap�s random_shufle= " << v << endl; 
  sort(v.begin(),v.end());
  cout << "Vetor  v ap�s sort= "  << v  << endl;  
}

// Pesquisa
void CTesteFuncoesGenericas::Uso_de_find_if_off()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// CTesteFuncoesGenericas::Uso_de_adjacent_difference
void CTesteFuncoesGenericas::Uso_de_adjacent_difference()
{
  cout << "uso de adjacent_difference:";
  adjacent_difference(v.begin(), v.end(),ostream_iterator<int>(cout," "));
  cout <<  endl;
}

void CTesteFuncoesGenericas::Uso_de_search_n()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// CTesteFuncoesGenericas::Uso_de_binary_search
// Retorna verdadeiro se o valor for encontrado
void CTesteFuncoesGenericas::Uso_de_binary_search()
{
  cout << "Valor " << 3 << ( binary_search(v.begin(),v.end(),3) ? 
			     " encontrado ": " n�o encontrado" ) << endl;
  cout << "Valor " << 22 << ( binary_search(v.begin(),v.end(),22) ? 
			      " encontrado ": " n�o encontrado" ) << endl;
}

// Avan�a o iterador
void CTesteFuncoesGenericas::Uso_de_advance()
{
  cout << "A partir da posi��o 0, devo avan�ar quantas casas (maximo=" 
       << v.size() << "):";
  int n;
  cin >> n; cin.get();
  vector<int>::iterator it = v.begin();
  advance (it, n);
  cout << "O iterador aponta agora para o elemento na posi��o " 
       << (it -v.begin()) << " com o valor " << *it << endl; 
}

// Ordena��o
// Realiza permuta��o dos elementos do container
void CTesteFuncoesGenericas::Uso_de_next_permutation()
{
  for(int i = 0; i <  v.size() * v.size(); i++)
    {
      next_permutation(v.begin(),v.end());
      cout <<  "Vetor  v ap�s next_permutation= " << v << endl; 
    }
}

void CTesteFuncoesGenericas::Uso_de_reverse()
{
  reverse(v.begin(), v.end());
  cout << "Vetor  v ap�s reverse = " << v << endl;
}

// CTesteFuncoesGenericas::Uso_de_rotate  
void CTesteFuncoesGenericas::Uso_de_rotate()
{
  rotate(v.begin(),v.begin() + v.size()/2, v.end());
  cout << "Vetor  v ap�s rotate(v.begin(),v.begin() + v.size()/2,"
       << " v.end())= " << v << endl;  
}

// Transforma��o
// CTesteFuncoesGenericas::Uso_de_generate:a fun��o chamada por generate n�o recebe par�metro
// e retorna um elemento para o container no exemplo a seguir chama
// a fun��o rand para preencher o container com n�meros aleat�rios
void CTesteFuncoesGenericas::Uso_de_generate()
{
  generate(v.begin(),v.end(), rand);
  cout << "Vetor de n�meros aleat�rios v= " << v << endl;
}  

void CTesteFuncoesGenericas::Uso_de_for_each()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

void CTesteFuncoesGenericas::Uso_de_transform()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Matem�ticos
void CTesteFuncoesGenericas::Uso_de_nth_element()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

void CTesteFuncoesGenericas::Uso_de_counf_if()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Acumula valores no intervalo especificado
void CTesteFuncoesGenericas::Uso_de_accumulate()
{
  for ( int i = 0;   i < v.size();   i++ )
    cout << "Valor acumulado at� "<< i << " = " 
	 << accumulate (v.begin(),v.begin(),0 ) << endl; // + 1
}

void CTesteFuncoesGenericas::Uso_de_inner_product()
{
  cout << "ENTRE COM OS DADOS DO VETOR v\n";
  EntradaUsuario(v);          // Entrada dos dados do vetor v
  cout << "\nENTRE COM OS DADOS DO VETOR v2\n";
  EntradaUsuario(v2);         // Entrada dos dados do vetor v2
  cout << "\n"<< "Vetor  v= "  << v  << endl;  
  cout << "Vetor  v2= " << v2 << endl;  
  cout << "ProdutoInterno v.v2 = "
       << inner_product (v.begin(),v.end(),v2.begin(),0) << endl;
}

void CTesteFuncoesGenericas::Uso_de_set_union()
{
  v3 = v2 = v ;       v3.push_back(123);      v2.push_back(333);
  cout << "Vetor  v2= "  << v2  << endl;  
  cout << "Vetor  v3= "  << v3  << endl;  
  cout << "Uni�o de v2 e v3 =";
  set_union(v3.begin(),v3.end(),v2.begin(),v2.end(), 
	    ostream_iterator<int>(cout, "\t"));
  cout <<  endl;
}

// CTesteFuncoesGenericas::Uso_de_set_intersection
void CTesteFuncoesGenericas::Uso_de_set_intersection()
{
  cout << "Interse��o de v e v2 =";
  set_intersection(v.begin(),v.end(),v2.begin(),v2.end(), 
		   ostream_iterator<int>(cout, "\t"));
  cout <<  endl;
}

// CTesteFuncoesGenericas::Uso_de_set_difference
void CTesteFuncoesGenericas::Uso_de_set_difference()
{
  cout << "diferen�a de v2 e v3 (tem em v2 e n�o tem em v3)=";
  set_difference(v2.begin(),v2.end(),v3.begin(),v3.end(), 
		 ostream_iterator<int>(cout, "\t"));
  cout <<  endl;
}

// CTesteFuncoesGenericas::Uso_de_set_symmetric_difference
void CTesteFuncoesGenericas::Uso_de_set_symmetric_difference()
{
  cout << "diferen�a sim�trica de v2 e v3 (tem em v2 e n�o tem em v3 ";
  cout << "ou tem em v3 e n�o tem em v2)=";
  set_symmetric_difference(v2.begin(),v2.end(),v3.begin(),v3.end(), 
			   ostream_iterator<int>(cout, "\t"));
  cout <<  endl;
}

// Ordena��o por pilha
void CTesteFuncoesGenericas::Uso_de_make_heap()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Fun��es objeto
// Uso da fun��o bin�ria plus e de transform
void CTesteFuncoesGenericas::Uso_de_plus()
{
  cout << "Vetor  v= "   << v   << endl;  
  cout << "Vetor  v2= "  << v2  << endl;  
  transform(v.begin(),v.end(),v2.begin(),v3.begin(), plus<int>());
  cout << "Vetor  v3 = v + v2 = " << v3 << endl;  
}

// CTesteFuncoesGenericas::Uso_de_fun��o bin�ria da stl
// Uso da fun��o bin�ria minus e de transform
void CTesteFuncoesGenericas::Uso_de_minus()
{
  cout << "Vetor  v2= "  << v2  << endl;  
  transform(v.begin(),v.end(),v2.begin(),v3.begin(), minus<int>());
  cout << "Vetor  v3 = v - v2 = " << v3 << endl;  
}

void CTesteFuncoesGenericas::Uso_de_times() 
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Uso da fun��o bin�ria multiplies e de transform
void CTesteFuncoesGenericas::Uso_de_multiplies()
{
  cout << "Vetor  v= "   << v   << endl;  
  cout << "Vetor  v2= "  << v2  << endl;  
  v.size() > v2.size() ?  v3 = v : v3 = v2;
  transform(v.begin(),v.end(),v2.begin(),v3.begin(), multiplies<int>());
  cout << "Vetor  v3 = v * v2 = " << v3 << endl;  
}

// Uso da fun��o bin�ria dividies e de transform
void CTesteFuncoesGenericas::Uso_de_divides()
{
  // Cada elemento do vetor � dividido pelo valor constante
  const float valor = 2;
  vector<float> vd (v.size());
  transform( v.begin(), v.end(), vd.begin(), 
	     bind2nd(divides<float>(),valor));
  cout << "Vetor de n�meros float  vd= v/2.0= " << vd << endl;
}

// Cada elemento do vetor � dividido pelo valor constante, 
// retorna o m�dulo
void CTesteFuncoesGenericas::Uso_de_modulus()
{
  const float valor = 2;  vector<float> vd (v.size());
  transform( v.begin(), v.end(), vd.begin(), 
	     bind2nd(modulus<int>(),valor));
  cout << "Vetor de n�meros vd= %( v / 2.0) = " << vd << endl;
}

// Cada elemento do vetor � invertido
void CTesteFuncoesGenericas::Uso_de_negate()
{
  transform( v.begin(), v.end(), v.begin(), negate<int>());
  cout << "Vetor  v ap�s negate= "   << v   << endl;
}

// Cada elemento do vetor que for igual a 2 ir� para o in�cio do vetor
void CTesteFuncoesGenericas::Uso_de_equal_to()
{
  InicializaVetor(v);
  const float valor = 2;
  partition( v.begin(), v.end(),bind2nd(equal_to<int>(),valor ));
  cout << "Rearranja o vetor de forma que todos os elementos ";
  cout << "iguais a 2 v�o para o in�cio" << endl;
  cout << "Vetor  v ap�s equal_to<int>(2)= "   << v   << endl;
}

// Cada elemento do vetor que for diferente de 2 
// ir� para o in�cio do vetor
void CTesteFuncoesGenericas::Uso_de_not_equal_to()
{
  InicializaVetor(v);   const float valor = 2;
  partition( v.begin(), v.end(),bind2nd(not_equal_to<int>(),valor ));
  cout << "Rearranja o vetor de forma que todos os elementos "; 
  cout << "diferentes de 2 v�o para o in�cio"       << endl;
  cout << "Vetor  v ap�s not_equal_to<int>(2)= "    << v   << endl;
}

void CTesteFuncoesGenericas::Uso_de_greater()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Cada elemento do vetor menor que 2 ir� para o in�cio
void CTesteFuncoesGenericas::Uso_de_less()
{
  InicializaVetor(v);   const float valor = 2;
  partition( v.begin(), v.end(),bind2nd(less<int>(),valor ));
  cout << "Rearranja o vetor de forma que todos os elementos ";
  cout << "menores que 2 v�o para o in�cio"    << endl;
  cout << "Vetor  v ap�s less<int>(2)= "   << v   << endl;
}

void CTesteFuncoesGenericas::Uso_de_greater_equal()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 
  
void CTesteFuncoesGenericas::Uso_de_less_equal()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Fun��es l�gicas
void CTesteFuncoesGenericas::Uso_de_logical_and()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

void CTesteFuncoesGenericas::Uso_de_logical_or()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

void CTesteFuncoesGenericas::Uso_de_logical_not()
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 

// Adaptadores
void CTesteFuncoesGenericas::Uso_de_bind2nd() 
{
  vector<int>::iterator it = find_if(v.begin(),v.end(),
				     not1(bind2nd(greater_equal<int>(),20)));
  cout << "Valor maior que 20 localizado na posi��o " << (it - v.begin())
       << " com o valor " << *it;
}

void CTesteFuncoesGenericas::Uso_de_men_fun_ref(const vector<string>& s)
{
{ cout << msg << "Exerc�cio: Montar este exemplo. " << msg << endl; } 
  /*
  vector<int>::const_iterator it = find_if(s.begin(),s.end(),men_fun_ref(&string::empty));
  cout << "String vazia na posi��o:"  << it - s.begin() << endl;
  */
}

int main()
{
  CTesteFuncoesGenericas obj;
  while(obj.Run());
  return 0;
}
