//diretório da pasta onde o arquivo está
package lojinha;
//inicio do programa

// Importação de classes necessárias
import java.util.ArrayList;
import java.util.List;

//classe onde os atributos de todos os produtos novos estão sendo declarados
class ProdutoEstoque {
// Variáveis privadas que representam os atributos do produto
    private String produto;
    private String nome;
    private int quantidade;
    private double preco;
    private String fornecedor;

// Construtor da classe ProdutoEstoque para inicializar os atributos
    public ProdutoEstoque(String produto, String nome, int quantidade, double preco, String fornecedor) {
        this.produto = produto;
        this.nome = nome;
        this.quantidade = quantidade;
        this.preco = preco;
        this.fornecedor = fornecedor;
    }

// Método para imprimir as informações do produto no estoque
    public void printProdutoEstoque() {
        System.out.println("PRODUTO: " + this.produto);
        System.out.println("Nome: " + this.nome);
        System.out.println("Quantidade: " + this.quantidade);
        System.out.println("Preço: " + this.preco);
        System.out.println("Fornecedor: " + this.fornecedor);
        System.out.println();
    }
}

//classe onde temos o método para exibir os produtos e seus respectivos parâmetros
class lojinha_produtos {
// Método estático para visualizar os produtos no estoque
    public static void ver_produtos() {
    // Lista que armazena os produtos no estoque
        List<ProdutoEstoque> produtos = new ArrayList<>();

//Método para imprimir na tela os produtos com seus parâmetros
        produtos.add(new ProdutoEstoque("1", "Maçã", 50, 20, "hortifruti"));
        produtos.add(new ProdutoEstoque("2", "Pasta de Dente", 20, 7, "drogasil"));
        produtos.add(new ProdutoEstoque("3", "Desodorante", 50, 11, "Old Spice"));
        produtos.add(new ProdutoEstoque("4", "Miojo", 100, 2, "Nissin"));

// Iterando sobre a lista de produtos e imprimindo suas informações

//inicio do for
        for (ProdutoEstoque produtoEstoque : produtos) {
            produtoEstoque.printProdutoEstoque();
        }
//fim do for
    }
}
//fim do programa