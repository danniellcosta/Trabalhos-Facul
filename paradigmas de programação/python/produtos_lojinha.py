#inicio do programa

# Definição da classe produto_estoque
class produto_estoque:
# Método construtor para inicializar os atributos da classe
    def __init__(self, produto, nome, qtd, preco, fornecedor):
        self.produto = produto
        self.nome = nome
        self.qtd = qtd
        self.preco = preco
        self.fornecedor = fornecedor

# Método para imprimir as informações do produto no estoque
    def print_produtos_estoque(self):
        print("PRODUTO ", self.produto)
        print("Nome:", self.nome)
        print("Quantidade:", self.qtd)
        print("Preço:", self.preco)
        print("Fornecedor:", self.fornecedor,)
        print()

# Criando instâncias da classe produto_estoque
produto1 = produto_estoque("1", "Maçã", 50, 20, "hortifruti")
produto2 = produto_estoque("2", "Pasta de Dente", 20, 7, "drogasil")
produto3 = produto_estoque("3", "Desodorante", 50, 11, "Old Spice")
produto4 = produto_estoque("4", "Miojo", 100, 2, "Nissin")

# Criando uma lista de produtos
produtos = [produto1, produto2, produto3, produto4]

# Iterando sobre a lista de produtos e chamando o método para imprimir suas informações
#inicio do for
for produto_estoque in produtos:
    produto_estoque.print_produtos_estoque()
#fim do for
#fim do programa