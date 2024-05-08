#inicio do programa

# Classe para representar produtos novos
class protudo_novo:
    # Método construtor para inicializar os atributos da classe
    def __init__(self, produto, nome, qtd, preco, fornecedor, prazo):
        self.produto = produto
        self.nome = nome
        self.qtd = qtd
        self.preco = preco
        self.fornecedor = fornecedor
        self.prazo = prazo

    # Método para imprimir as informações dos produtos novos
    def print_produtos_novos(self):
        print("PRODUTO", self.produto)
        print("Nome:", self.nome)
        print("Quantidade:", self.qtd)
        print("Preço:", self.preco)
        print("Fornecedor:", self.fornecedor)
        print("Prazo:", self.prazo)
        print()

# Criando instâncias da classe protudo_novo para representar produtos novos
produto1 = protudo_novo("1", "Melância", 33, 25, "Hortifruti", "10/12/2023")
produto2 = protudo_novo("2", "Chocolate", 100, 5, "Cacau Show", "03/12/2023")
produto3 = protudo_novo("3", "Notebook", 15, 1500, "Positivo Tecnologia", "01/01/2024")
produto4 = protudo_novo("4", "Mouse Gamer", 57, 200, "Hyperx Gaming", "22/12/2023")

# Criando uma lista de produtos novos
produtos_novos = [produto1, produto2, produto3, produto4]

# Iterando sobre a lista de produtos novos e chamando o método para imprimir suas informações
#inicio do for
for produto_novo in produtos_novos:
    produto_novo.print_produtos_novos()
#fim do for
#fim do programa