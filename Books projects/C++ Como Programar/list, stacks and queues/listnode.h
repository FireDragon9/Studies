#ifndef LISTNODE_H
#define LISTNODE_H


//declaração antecipada da classe List necessaia para anunciar essa classe 
//List existe, portanto pode ser utilizada na declaração friend na linha 3
template<typename NODETYPE> class List;


template<typename NODETYPE>
class ListNode{

  friend class List<NODETYPE>; //torna List uma amiga (friend ) 

  public:
    ListNode(const NODETYPE&); //construtor
    NODETYPE getData() const; //retorna dados no nó

  private:
    NODETYPE data; //dados
    ListNode<NODETYPE> *nextPtr; //proximo no na list 

}; //fim da classe ListNode

//construtor
template<typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& info) : data(info), nextPtr(0){

  //corpo vazio


}//fim do construtor

//retorna cópia de dados nó
template<typename NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const{
  return data;
}//fim da função getData

#endif
