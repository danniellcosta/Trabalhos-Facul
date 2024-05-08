//diretório da pasta onde o arquivo está
package lojinha;
//inicio do programa

//classe principal da lojinha
class Lojinha {
//Método principal, o ponto de entrada do programa
    public static void main(String[] args) {
//Mensagem de boas vindas, para ficar bonitinho
        System.out.println("\n************************************");
        System.out.println("***Bem-Vindo(a) à nossa lojinha!!***");
        System.out.println("************************************");
//mensagens sobre os produtos no estoque atual
        System.out.println("\n////////////////////////////////////////////////////////////////////");
        System.out.println("///Esses são os produtos que constam no nosso estoque atualmente///");
        System.out.println("///////////////////////////////////////////////////////////////////");
//importando o método do arquivo lojinha_produtos.java para exibir os produtos do estoque atual
        lojinha_produtos.ver_produtos();
//mensagem sobre os produtos que estão para chegar no estoque
        System.out.println("\n//////////////////////////////////////////////////////////////////");
        System.out.println("///Esses são os produtos novos que estão para chegar no estoque///");
        System.out.println("//////////////////////////////////////////////////////////////////");
//importando o método do arquivo lojinha_novos.java para exibir os produtos que estão para chegar no estoque
        Lojinha_novos.ver_novos();
    }
}
//fim do programa