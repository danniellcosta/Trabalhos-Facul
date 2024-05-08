#inicio do programa

# Classe para exibir produtos do estoque
class exibir_produtos_do_estoque:
    def exibir_produtos_do_estoque():
        # Importando o módulo produtos_lojinha
        import produtos_lojinha

# Classe para exibir produtos novos do estoque
class exibir_produtos_novos_do_estoque:
    def exibir_produtos_novos_do_estoque():
        # Importando o módulo produtos_novos
        import produtos_novos

# Classe principal Lojinha
class lojinha:
# Mensagens de boas-vindas e informações sobre os produtos no estoque
    print("\n************************************")
    print("***Bem-Vindo(a) à nossa lojinha!!***")
    print("************************************")
    print("\n////////////////////////////////////////////////////////////////////")
    print("///Esses são os produtos que constam no nosso estoque atualmente///")
    print("///////////////////////////////////////////////////////////////////")

# Chamando o método para exibir os produtos do estoque
    exibir_produtos_do_estoque.exibir_produtos_do_estoque()

# Mensagens sobre os produtos novos que estão para chegar
    print("\n//////////////////////////////////////////////////////////////////")
    print("///Esses são os produtos novos que estão para chegar no estoque///")
    print("//////////////////////////////////////////////////////////////////")

# Chamando o método para exibir os produtos novos do estoque
    exibir_produtos_novos_do_estoque.exibir_produtos_novos_do_estoque()
#fim do programa