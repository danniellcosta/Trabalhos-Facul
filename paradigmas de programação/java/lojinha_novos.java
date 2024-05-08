//diretório da pasta onde o arquivo está
package lojinha;

//inicio do programa
// Importação de classes necessárias
import java.util.ArrayList;
import java.util.List;

//classe onde os atributos de todos os produtos novos estão sendo declarados
    class ProdutoNovo {
//criando as variaveis privadas dos atributos dos produtos novos
    private String produto;
    private String nome;
    private int quantidade;
    private double preco;
    private String fornecedor;
    private String prazo;
//construtor da classe ProdutoNovo para inicializar os atributos
    public ProdutoNovo(String produto, String nome, int quantidade, double preco, String fornecedor, String prazo) {
        this.produto = produto;
        this.nome = nome;
        this.quantidade = quantidade;
        this.preco = preco;
        this.fornecedor = fornecedor;
        this.prazo = prazo;
    }
//Método para imprimir os atributos dos novos produtos
    public void printProdutoNovo() {
        System.out.println("PRODUTO: " + this.produto);
        System.out.println("Nome: " + this.nome);
        System.out.println("Quantidade: " + this.quantidade);
        System.out.println("Preço: " + this.preco);
        System.out.println("Fornecedor: " + this.fornecedor);
        System.out.println("Prazo: " + this.prazo);
        System.out.println();
    }
}
//classe onde temos o método para exibir os produtos novos e seus respectivos parâmetros
    class Lojinha_novos {
//Método para imprimir na tela os produtos com seus parâmetros
    static void ver_novos() {
//cria uma lista dos produtos novos
        List<ProdutoNovo> produtos = new ArrayList<>();
//adicionando produtos à lista e passando seus parâmetros
        produtos.add(new ProdutoNovo("1", "Melância", 33, 25, "Hortifruti", "10/12/2023"));
        produtos.add(new ProdutoNovo("2", "Chocolate", 100, 5, "Cacau Show", "03/12/2023"));
        produtos.add(new ProdutoNovo("3", "Computdor", 15, 1500, "Positivo Tecnologia", "01/01/2024"));
        produtos.add(new ProdutoNovo("4", "Mouse Gamer", 57, 200, "Hyperx Gamer", "22/12/2023"));
//Iterando sobre a lista de produtos e imprimindo suas informações
//inicio do for
        for (ProdutoNovo ProdutoNovo : produtos) {
            ProdutoNovo.printProdutoNovo();
        }
//fim do for
    }
}
//fim do programa