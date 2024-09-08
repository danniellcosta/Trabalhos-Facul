using System.Collections.Generic;
using UnityEngine;

public class InimigoScatter : InimigoComportamento
{
    public float distanciaDeVerificacao = 1.0f; // Defina o valor apropriado
    public LayerMask layerMask; // Defina a camada apropriada

    private void OnTriggerEnter2D(Collider2D other)
    {
        Node node = other.GetComponent<Node>();

        if (node != null && this.enabled && !this.inimigo.assustado.enabled)
        {
            // Filtra as direções disponíveis para aquelas que não têm paredes
            List<Vector2> direcoesValidas = new List<Vector2>();
            foreach (Vector2 direcao in node.DirecoesDisponiveis)
            {
                Vector2 start = transform.position;
                Vector2 end = start + direcao * distanciaDeVerificacao;

                // Executa o Raycast para verificar se há paredes na direção
                RaycastHit2D hit = Physics2D.Raycast(start, direcao, distanciaDeVerificacao, layerMask);
                if (hit.collider == null)
                {
                    direcoesValidas.Add(direcao);
                }
            }

            if (direcoesValidas.Count > 0)
            {
                // Seleciona uma direção aleatória dentre as válidas
                int index = Random.Range(0, direcoesValidas.Count);
                Vector2 novaDirecao = direcoesValidas[index];
                this.inimigo.movimento.SetDirecao(novaDirecao);

                Debug.Log($"Nova direção: {novaDirecao}");
            }
            else
            {
                Debug.Log("Nenhuma direção válida encontrada sem paredes.");
            }
        }
        else
        {
            Debug.Log("Condições não atendidas para Scatter.");
        }
    }


}